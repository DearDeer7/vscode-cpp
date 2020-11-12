#include <bits/stdc++.h>
using namespace std;

const int TIME_LIMIT = 100; // 时间最大值
const int MEM_LIMIT = 320; // 内存最大值

//可用表
struct avail {
    int num; //分区号
    int length; //分区长度
    int begin_addr; //起始地址
    avail *next; //下一项指针

    avail() {} // 无参构造函数
    avail(int num, int length, int begin_addr, avail* next) :
        num(num), length(length), next(next),
        begin_addr(begin_addr) {} // 有参构造函数
} *availTab;

//分区说明表
struct info {
    int num; //分区号
    int length; //分区长度
    int begin_addr; //起始地址
    string status; //状态
    info *next; //下一项指针

    info() {} // 无参构造函数
    info(int num, int length, int begin_addr, string status, info* next) :
        num(num), length(length), next(next),
        begin_addr(begin_addr), status(status) {} // 有参构造函数
} *infoTab;

//进程请求表
struct process {
    char name; //进程名称
    int length; //长度
    int arri_time; // 到达时间
    int exec_time; // 执行时间
    int address; //进程占用内存后的首地址，便于内存回收
    int num; //记录分区号
};

void showInfo() {
    //显示分区说明表
    info *inode = infoTab;
    cout << "分区说明表更新为:" << endl;
    cout << "分区号 起始地址 分区长度 状态" << endl;
    while (inode != nullptr) {
        if (inode->begin_addr == 0) {
            cout << inode->num << "\t" 
                 << inode->begin_addr << "\t" 
                 << inode->length << "\t" 
                 << inode->status << endl;
        } else {
            cout << inode->num << "\t" 
                 << inode->begin_addr + 1 << "\t"
                 << inode->length << "\t" 
                 << inode->status << endl;
        }
        cout << endl;
        inode = inode->next;
    }

    //显示可用表
    avail *anode = availTab;
    cout << "可用表更新为:" << endl;
    cout << "分区号 起始地址 分区长度" << endl;
    while (anode != nullptr) {
        if(anode->length != 0) {
            cout << anode->num << "\t" 
                << anode->begin_addr + 1 << "\t" 
                << anode->length << endl;
            cout << endl;
        }
        if (anode->length == MEM_LIMIT)
            break;
        else
            anode = anode->next;
    }
}

// 交换结点内容
void swap(avail* p, avail* q) {
    swap(p->length, q->length);
    swap(p->num, q->num);
    swap(p->begin_addr, q->begin_addr);
}

// 根据option选择三种不同的算法
void sort(int option) {
    avail *p, *q;

    if (availTab->next == nullptr) {
        return;
    }

    if(option == 1) { // 最先适应 sort by small begin_addr
        for (p = availTab; p != nullptr; p = p->next) {
            for (q = availTab; q->next != nullptr; q = q->next) {
                if (q->begin_addr > q->next->begin_addr) {
                    swap(q, q->next);
                    // swap(q->length, q->next->length);
                    // swap(q->num, q->next->num);
                    // swap(q->begin_addr, q->next->begin_addr);
                }
            }
        }
    }
    else if (option == 2) { // 最佳适应 sort by small length
        for (p = availTab; p != nullptr; p = p->next) {
            for (q = availTab; q->next != nullptr; q = q->next) {
                if (q->length > q->next->length) {
                    swap(q, q->next);
                    // swap(q->length, q->next->length);
                    // swap(q->num, q->next->num);
                    // swap(q->begin_addr, q->next->begin_addr);
                }
            }
        }
    } else {  // 最坏适应 sort by large length
        for (p = availTab; p != nullptr; p = p->next) {
            for (q = availTab; q->next != nullptr; q = q->next) {
                if (q->length < q->next->length) {
                    swap(q, q->next);
                    // swap(q->length, q->next->length);
                    // swap(q->num, q->next->num);
                    // swap(q->begin_addr, q->next->begin_addr);
                }
            }
        }
    }
}

// 进程执行函数
int finished = 0;  //记录已经执行完的进程的个数，用于控制程序停止
void execute(int n) {
    availTab = new avail(1, MEM_LIMIT, 0, nullptr); // 初始可用表
    infoTab = new info(1,MEM_LIMIT, 0, "未分配", nullptr);  //初始化分区说明表

    // //初始化 还没有进程，即可用表
    // infoTab->num = 1;
    // infoTab->length = MEM_LIMIT;
    // infoTab->begin_addr = 0;
    // infoTab->status = "未分配";
    // infoTab->next = nullptr;

    // availTab->num = 1;
    // availTab->length = MEM_LIMIT;
    // availTab->begin_addr = 0;
    // availTab->next = nullptr;
    cout << "请输入进程个数";
    int m;
    cin >> m;
    vector<process> proc(m); // 进程请求表proc
    cout << "请输入进程的进程名，进程长度，到达时间，执行时间：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> proc[i].name >> proc[i].length 
            >> proc[i].arri_time >> proc[i].exec_time;
    }
    int j = 0, addNum = 1;  //进程数组下标j,增加的分区号addNum
    int needModify;  //保存需要修改的进程号
    int isAllocated = 0; //保存内存分配是否成功

    //用循环模拟系统时间，i的值代表了当前的时间
    for (int i = 0; i < TIME_LIMIT; i++) {
        cout << "---"<< "当前时间：" << i 
             << "-------" << endl;
        if (proc[j].arri_time <= i) {  //到达时间小于等于当前时间
            avail *q = availTab;
            while (q != nullptr) {
                if (q->length >= proc[j].length) {
                    cout << "进程" << proc[j].name << "内存分配成功，进入内存"
                         << endl;
                    cout << "该进程使用内存大小为:" << proc[j].length;
                    needModify = q->num;

                    proc[j].address = q->begin_addr;
                    proc[j].num = q->num;

                    //修改可用表
                    q->length = q->length - proc[j].length;
                    q->num = ++addNum;
                    q->begin_addr = q->begin_addr + proc[j].length;

                    isAllocated = 1;  //表示内存分配成功，用于后面更改进程的到达时间

                    //修改分区说明表
                    info *ti = infoTab; // temp info
                    while (ti->num != needModify) {
                        ti = ti->next;
                    }
                    info *tmp = new info(
                        addNum, ti->length - proc[j].length, 
                        ti->begin_addr + proc[j].length,"未分配",ti->next
                    );
                    // info *tmp = new info();
                    // tmp->num = addNum;
                    // tmp->length = ti->length - proc[j].length;
                    // tmp->begin_addr = ti->begin_addr + proc[j].length;
                    // tmp->status = "未分配";
                    // tmp->next = ti->next;

                    ti->length = proc[j].length;
                    ti->status = "已分配";
                    ti->next = tmp;

                    proc[j].arri_time = i;
                    j++;

                    if (ti->begin_addr == 0)
                        cout << "   内存起始地址为:" << ti->begin_addr << endl
                             << endl;
                    else
                        cout << "   内存起始地址为:" << ti->begin_addr + 1 << endl
                             << endl;

                    //判断是否为最佳或最坏算法，进行相应排序
                    sort(n);
                    showInfo();
                    isAllocated = 1;
                    break;
                } else {
                    q = q->next;
                }

                if (isAllocated == 0) {
                    for (int k = j; k < m; k++) {
                        if (proc[k].arri_time <= i) proc[k].arri_time = i;
                    }
                }
                isAllocated = 0;  //重置标识
            }
        }

        //判断是否有进程执行结束
        for (int k = 0; k <= j; k++) {
            if (proc[k].exec_time + proc[k].arri_time == i) {
                finished++;
                cout << "进程" << proc[k].name << "执行完毕" << endl;
                info *ti = infoTab;

                int mergeDown = 0;
                int mergeUp = 0;
                while (ti != nullptr) {
                    if (ti->num == proc[k].num) {
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
                // cout << ti->num + "================" << endl;
                //更新可用表
                //合并前对可用表按照首地址从小到大进行排列，这样合并算法可以多用
                if (n == 2 || n == 3) sort(1);
                avail *q = new avail(
                    ti->num, ti->length, ti->begin_addr, nullptr
                );
                // q->num = ti->num;
                // q->length = ti->length;
                // q->begin_addr = ti->begin_addr;
                avail *anode = availTab;
                //若此结束的进程占用第一块内存，则特殊处理
                if (q->num == 1) {
                    q->next = anode;
                    availTab = q;
                    showInfo();
                    break;
                }
                // cout << anode->next->begin_addr << endl;
                while (anode->next->begin_addr < q->begin_addr) {
                    anode = anode->next;
                }

                //判断说明表更新的时候是否发生合并
                if (mergeDown == 1 && mergeUp == 1) {  //向上向下合并都发生
                    q->length = ti->length;
                    q->next = anode->next->next;
                    anode->next = q;
                    anode->length += q->length;
                    anode->next = q->next;
                } else if (mergeDown == 1) {  //仅发生向下合并
                    q->length = ti->length;
                    q->next = anode->next->next;
                    anode->next = q;
                } else if (mergeUp == 1) {  //仅发生向上合并
                    anode->length += ti->length;
                } else {  //没有合并发生
                    q->next = anode->next;
                    anode->next = q;
                }
                if (n == 2) sort(1);  //重新对可用表按照分配策略进行排序
                else if (n == 3) sort(2);
                showInfo();
            }
        }
        if (finished == m) {
            cout << "所有进程已经运行完毕" << endl;
            break;
        }
    }
}

void menu() {
    cout << "请选择分配策略（1.最先适应 2.最佳适应 3.最坏适应）：";
	int n;
    cin >> n;  //借用n判断是否使用排序
    execute(n);
}

int main() {
    menu();
    return 0;
}
