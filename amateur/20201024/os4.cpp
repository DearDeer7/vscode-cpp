#include<bits/stdc++.h>
using namespace std;

// 时间最大值
const int TIME_LIMIT = 100;
const int MEM_LIMIT = 320;
const int INIT_ADDR = 0;
int num = 0;

//可用表
struct avail {
    int num;
    int length;
    int begin_addr;
    avail *next;
    avail() {}

    // avail() :
    //     num(0), length(0), next(nullptr),
    //     begin_addr(0) {}
    avail(int num, int length, int begin_addr, avail* next) :
        num(num), length(length), next(next),
        begin_addr(begin_addr) {}
} * availTab;

//分区说明表
struct info {
    int num;
    int length;
    int begin_addr;
    string status;
    info *next;
    // info() :
    //     num(0), length(0), next(nullptr),
    //     begin_addr(0), status("") {}
    info() {}

    info(int num, int length, int begin_addr, string status, info* next) :
        num(num), length(length), next(next),
        begin_addr(begin_addr), status(status) {}
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
    // 定义可用表初始信息
    availTab = new avail(1, MEM_LIMIT, INIT_ADDR, nullptr);
    // 定义分区说明表初始信息
    infoTab = new info(1, MEM_LIMIT, INIT_ADDR, "未分配", nullptr);
}

//显示分区说明表
void showInfo() {
    info *inode = new info;
    inode = infoTab;
    cout << "分区说明表更新为:" << endl;
    cout << "分区号 起始地址 分区长度 状态" << endl;
    while (inode != nullptr) {
        cout << inode->num << "    " 
             << (inode->begin_addr == 0 ? inode->begin_addr : inode->begin_addr + 1)
             << "    " << inode->length << "    " << inode->status << endl;
        cout << endl;
        inode = inode->next;
    }

    //显示可用表
    avail *anode = new avail;
    anode = availTab;
    cout << "可用表更新为:" << endl;
    cout << "分区号 起始地址 分区长度" << endl;
    while (anode != nullptr) {
        cout << anode->num << "    " << anode->begin_addr + 1 << "    "
             << anode->length << endl;
        cout << endl;
        if (anode->length == 320)
            break;
        else
            anode = anode->next;
    }
}

// int Pan() {
//     struct info *ii = new info;
//     ii = infoTab;
//     while (ii != NULL) {
//         if (ii->status == "已分配") return 0;
//         ii = ii->next;
//     }
//     return 1;
// }

// sort by begin_addr from small to large
void sortBySmallbeginAddr() {
    struct avail *next = NULL;
    struct avail *q = NULL;
    struct avail *t = NULL;

    if (availTab->next == NULL) {
        return;
    }
    for (next = availTab; next != NULL; next = next->next) {
        for (q = availTab; q->next != NULL; q = q->next) {
            if (q->begin_addr > q->next->begin_addr) {
                swap(q->length, q->next->length);
                swap(q->num, q->next->num);
                swap(q->begin_addr, q->next->begin_addr);
            }
        }
    }
}

void sort(int a) {
    struct avail *next = NULL;
    struct avail *q = NULL;
    struct avail *t = NULL;

    if (availTab->next == NULL) {
        return;
    }
    if (a == 1) {  //最佳排序
        // sort by length from small to large
        for (next = availTab; next != NULL; next = next->next) {
            for (q = availTab; q->next != NULL; q = q->next) {
                if (q->length > q->next->length) {
                    swap(q->length, q->next->length);
                    swap(q->num, q->next->num);
                    swap(q->begin_addr, q->next->begin_addr);
                }
            }
        }

    } else {  //最坏排序
        // sort by length from large to small
        for (next = availTab; next != NULL; next = next->next) {
            for (q = availTab; q->next != NULL; q = q->next) {
                if (q->length < q->next->length) {
                    swap(q->length, q->next->length);
                    swap(q->num, q->next->num);
                    swap(q->begin_addr, q->next->begin_addr);
                }
            }
        }
    }
}


int finished = 0;  //记录已经执行完的进程的个数，用于控制程序停止
void process(int n) {
    cout << "请输入进程个数";
    int m;
    cin >> m;
    job jb[m];
    cout << "请输入进程的进程名，进程长度，到达时间，执行时间：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> jb[i].name >> jb[i].length >> jb[i].arri_time >> jb[i].exec_time;
    }
    int j = 0, addNum = 1;  //进程数组下标j,增加的分区号 addNum
    int needModify;             //保存需要修改的进程号
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
                    needModify = q->num;
                    num++;

                    jb[j].adress = q->begin_addr;
                    jb[j].num = q->num;

                    //修改可用表
                    q->length = q->length - jb[j].length;
                    q->num = ++addNum;
                    q->begin_addr = q->begin_addr + jb[j].length;

                    isAllocated = 1;  //表示内存分配成功，用于后面更改进程的到达时间

                    //修改分区说明表
                    info *ti = new info;
                    ti = infoTab;
                    while (ti->num != needModify) {
                        ti = ti->next;
                    }
                    // info *tmp = new info(addNum, ti->begin_addr + jb[j].length,
                    //     ti->length - jb[j].length,"未分配",ti->next);
                    info *tmp = new info;
                    tmp->num = addNum;
                    tmp->begin_addr = ti->begin_addr + jb[j].length;
                    tmp->length = ti->length - jb[j].length;
                    tmp->status = "未分配";
                    tmp->next = ti->next;
                    ti->length = jb[j].length;
                    ti->status = "已分配";
                    ti->next = tmp;

                    jb[j].arri_time = i;
                    j++;

                    cout << "   内存起始地址为:" 
                         <<  (ti->begin_addr == 0 ? ti->begin_addr : ti->begin_addr + 1) 
                         << endl << endl;

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
                    q = q->next;
                }

                if (isAllocated == 0) {
                    for (int k = j; k < m; k++) {
                        if (jb[k].arri_time <= i) jb[k].arri_time = i;
                    }
                }
                isAllocated = 0;  //重置标识
            }
        }

        //判断是否有进程执行结束
        for (int k = 0; k <= j; k++) {
            if (jb[k].exec_time + jb[k].arri_time == i) {
                finished++;
                cout << "进程" << jb[k].name << "执行完毕" << endl;
                info *ti = infoTab;

                int mergeDown = 0;
                int mergeUp = 0;
                while (ti != NULL) {
                    if (ti->num == jb[k].num) {
                        ti->status = "未分配";
                        if (ti->next->status == "未分配") {
                            ti->length += ti->next->length;
                            info* useless = ti->next;
                            ti->next = ti->next->next;
                            free(useless); // 释放结点
                            mergeDown = 1;
                        }
                        info *inode = infoTab;
                        while (inode->next != ti && inode != ti) {
                            inode = inode->next;
                        }
                        if (inode->status == "未分配" && inode != ti) {
                            inode->length += ti->length;
                            inode->next = ti->next;
                            mergeUp = 1;
                        }
                        break;
                    } else {
                        ti = ti->next;
                    }
                }

                //更新可用表
                //合并前对可用表按照首地址从小到大进行排列，这样合并算法可以多用
                if (n == 2 || n == 3) sortBySmallbeginAddr();
                avail *q = new avail;
                q->num = ti->num;
                q->begin_addr = ti->begin_addr;
                q->length = ti->length;
                avail *pp = availTab;
                //若此结束的进程占用第一块内存，则特殊处理
                if (q->num == 1) {
                    q->next = pp;
                    availTab = q;
                    showInfo();
                    break;
                }
                while (pp->next->begin_addr < q->begin_addr) {
                    pp = pp->next;
                }

                //判断说明表更新的时候是否发生合并
                if (mergeDown == 1 && mergeUp == 1) {  //向上向下合并都发生
                    q->length = ti->length;
                    q->next = pp->next->next;
                    pp->next = q;
                    pp->length += q->length;
                    pp->next = q->next;
                } else if (mergeDown == 1) {  //仅发生向下合并
                    q->length = ti->length;
                    q->next = pp->next->next;
                    pp->next = q;
                } else if (mergeUp == 1) {  //仅发生向上合并
                    pp->length += ti->length;
                }

                else {  //没有合并发生
                    q->next = pp->next;
                    pp->next = q;
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
    process(n);
}

int main() {
    init();
    menu();
    return 0;
}
