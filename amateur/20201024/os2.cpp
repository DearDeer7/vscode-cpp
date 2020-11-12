#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const int TIME_LIMIT = 100;
int num = 0;
int ns[999999] = {0};  //标识此进程是否已经结束

//可用表
struct avail {
    int num;
    int length;
    int begin_addr;
    avail *p;
} * availTab;


//分区说明表
struct info {
    int num;
    int length;
    int begin_addr;
    string status;
    info *p;
} * infoTab;

//进程表
struct job {
    char name;
    int length;
    int arri_time;
    int exec_time;
    int adress;  //进程占用内存后的首地址，便于内存回收
    int num;     //记录分区号
};

//初始化
void init() {
    availTab = new avail;
    infoTab = new info;

	// 定义可用表初始信息
    availTab->num = 1;
    availTab->length = 320;
    availTab->begin_addr = 0;
    availTab->p = NULL;

	// 定义分区说明表初始信息
    infoTab->num = 1;
    infoTab->length = 320;
    infoTab->begin_addr = 0;
    infoTab->status = "未分配";
    infoTab->p = NULL;
}

//显示分区说明表
void showInfo() {
    struct info *Fi = new info;
    Fi = infoTab;
    cout << "分区说明表更新为:" << endl;
    cout << "分区号 起始地址 分区长度 状态" << endl;
    while (Fi != NULL) {
        if (Fi->begin_addr == 0) {
            cout << Fi->num << "      " << Fi->begin_addr << "                     "
                 << Fi->length << "      " << Fi->status << endl;

        } else {
            cout << Fi->num << "      " << Fi->begin_addr + 1 << "      "
                 << Fi->length << "      " << Fi->status << endl;
        }
        cout << endl;
        Fi = Fi->p;
    }

    //显示可用表
    struct avail *Uii = new avail;
    Uii = availTab;
    cout << "可用表更新为:" << endl;
    cout << "分区号 起始地址 分区长度" << endl;
    while (Uii != NULL) {
        cout << Uii->num << "      " << Uii->begin_addr + 1 << "         "
             << Uii->length << endl;
        cout << endl;
        if (Uii->length == 320)
            break;
        else
            Uii = Uii->p;
    }
}

int Pan() {
    struct info *ii = new info;
    ii = infoTab;
    while (ii != NULL) {
        if (ii->status == "已分配") return 0;
        ii = ii->p;
    }
    return 1;
}

// sort by begin_addr from small to large
void sort1() {
    struct avail *p = NULL;
    struct avail *q = NULL;
    struct avail *t = NULL;

    if (availTab->p == NULL) {
        return;
    }
    for (p = availTab; p != NULL; p = p->p) {
        for (q = availTab; q->p != NULL; q = q->p) {
            if (q->begin_addr > q->p->begin_addr) {
                swap(q->length, q->p->length);
                swap(q->num, q->p->num);
                swap(q->begin_addr, q->p->begin_addr);
            }
        }
    }
}

void sort(int a) {
    struct avail *p = NULL;
    struct avail *q = NULL;
    struct avail *t = NULL;

    if (availTab->p == NULL) {
        return;
    }
    if (a == 1) {  //最佳排序
        // sort by length from small to large
        for (p = availTab; p != NULL; p = p->p) {
            for (q = availTab; q->p != NULL; q = q->p) {
                if (q->length > q->p->length) {
                    swap(q->length, q->p->length);
                    swap(q->num, q->p->num);
                    swap(q->begin_addr, q->p->begin_addr);
                }
            }
        }

    } else {  //最坏排序
        // sort by length from large to small
        for (p = availTab; p != NULL; p = p->p) {
            for (q = availTab; q->p != NULL; q = q->p) {
                if (q->length < q->p->length) {
                    swap(q->length, q->p->length);
                    swap(q->num, q->p->num);
                    swap(q->begin_addr, q->p->begin_addr);
                }
            }
        }
    }
}
int finished = 0;  //记录已经执行完的进程的个数，用于控制程序停止
void First(int n) {
    cout << "请输入进程个数";
    int m;
    cin >> m;
    job jb[m];
    cout << "请输入进程的进程名，进程长度，到达时间，执行时间：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> jb[i].name >> jb[i].length >> jb[i].arri_time >> jb[i].exec_time;
    }
    int j = 0, a = 1;  //进程数组下标j,增加的分区号 a
    int l;             //保存需要修改的进程号
    int isAllocated = 0;      //保存内存分配是否成功

    //用循环模拟时间流逝，i的值代表了当前的时间
    for (int i = 0; i < TIME_LIMIT; i++) {
        cout << "时间：" << i << endl;
        if (jb[j].arri_time <= i) {
            struct avail *q = new avail;
            q = availTab;
            while (q != NULL) {
                if (q->length >= jb[j].length && q != NULL) {
                    cout << "进程" << jb[j].name << "内存分配成功，进入内存"
                         << endl;
                    cout << "该进程使用内存大小为:" << jb[j].length << "KB";
                    l = q->num;
                    num++;

                    jb[j].adress = q->begin_addr;
                    jb[j].num = q->num;

                    //修改可用表
                    q->length = q->length - jb[j].length;
                    q->num = ++a;
                    q->begin_addr = q->begin_addr + jb[j].length;

                    isAllocated = 1;  //表示内存分配成功，用于后面更改进程的到达时间

                    //修改分区说明表
                    struct info *T = new info;
                    T = infoTab;
                    while (T->num != l) {
                        T = T->p;
                    }
                    struct info *tt = new info;
                    tt->num = a;
                    tt->begin_addr = T->begin_addr + jb[j].length;
                    tt->length = T->length - jb[j].length;
                    tt->status = "未分配";
                    tt->p = T->p;
                    T->length = jb[j].length;
                    T->status = "已分配";
                    T->p = tt;

                    jb[j].arri_time = i;
                    j++;

                    if (T->begin_addr == 0)
                        cout << "   内存起始地址为:" << T->begin_addr << endl
                             << endl;
                    else
                        cout << "   内存起始地址为:" << T->begin_addr + 1 << endl
                             << endl;

                    //判断是否为最佳或最坏算法，进行相应排序
                    if (n == 2) {
                        sort(1);
                    } else if (n == 3) {
                        sort(2);
                    }
                    showInfo();
                    isAllocated = 1;
                    break;
                } else {
                    q = q->p;
                }

                if (isAllocated == 0) {
                    for (int u = j; u < m; u++) {
                        if (jb[u].arri_time <= i) jb[u].arri_time = i;
                    }
                }
                isAllocated = 0;  //重置标识
            }
        }

// look here
        //判断是否有进程执行结束
        for (int k = 0; k <= j; k++) {
            if (jb[k].exec_time + jb[k].arri_time == i) {
                finished++;
                ns[k] = 1;
                cout << "进程" << jb[k].name << "执行完毕" << endl;
                struct info *T = new info;
                T = infoTab;

                int fi = 0;
                int up = 0;
                while (T != NULL) {
                    if (T->num == jb[k].num) {
                        T->status = "未分配";
                        if (T->p->status == "未分配") {
                            T->length += T->p->length;

                            T->p = T->p->p;
                            fi = 1;
                        }
                        struct info *L = new info;
                        L = infoTab;
                        while (L->p != T && L != T) {
                            L = L->p;
                        }
                        if (L->status == "未分配" && L != T) {
                            L->length += T->length;
                            L->p = T->p;
                            up = 1;
                        }
                        break;
                    } else {
                        T = T->p;
                    }
                }

                //更新可用表
                //合并前对可用表按照首地址从小到大进行排列，这样合并算法可以多用
                if (n == 2 || n == 3) sort1();
                struct avail *q = new avail;
                q->num = T->num;
                q->begin_addr = T->begin_addr;
                q->length = T->length;
                struct avail *pp = new avail;
                pp = availTab;
                //若此结束的进程占用第一块内存，则特殊处理
                if (q->num == 1) {
                    q->p = pp;
                    availTab = q;
                    showInfo();
                    break;
                }
                while (pp->p->begin_addr < q->begin_addr) {
                    pp = pp->p;
                }

                //判断说明表更新的时候是否发生合并
                if (fi == 1 && up == 1) {  //向上向下合并都发生
                    q->length = T->length;
                    q->p = pp->p->p;
                    pp->p = q;
                    pp->length += q->length;
                    pp->p = q->p;
                } else if (fi == 1) {  //仅发生向下合并
                    q->length = T->length;
                    q->p = pp->p->p;
                    pp->p = q;
                } else if (up == 1) {  //仅发生向上合并
                    pp->length += T->length;
                }

                else {  //没有合并发生
                    q->p = pp->p;
                    pp->p = q;
                }
                if (n == 2) {  //重新对可用表按照分配策略进行排序
                    sort(1);
                } else if (n == 3) {
                    sort(2);
                }
                showInfo();
            }
        }

        if (finished == m) {
            cout << "所有进程已经运行完毕" << endl;
            break;
        }
    }
}

// 菜单
void menu() {
	cout << "请选择分配策略（1.最先适应 2.最佳适应 3.最坏适应）：";
	int n;
    cin >> n;  //借用n判断是否使用排序
    First(n);
}

int main() {
    init();
    menu();
    return 0;
}
