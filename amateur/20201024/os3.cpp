/**
 * Created by DearDeer on 2020/10/26
 */
#include<bits/stdc++.h>
using namespace std;

// 时间最大值
const int TIME_LIMIT = 100;
const int MEM_LIMIT = 320;
const int INIT_ADDR = 0;

// 可用表结构
struct avail {
    int num;
    int length;
    int begin_addr;

    avail(int num, int length, int begin_addr) :
        num(num), length(length), 
        begin_addr(begin_addr) {}
};

// 分区说明表结构
struct info {
    int num;
    int length;
    int begin_addr;
    string status;
    info(int num, int length, int begin_addr, string status) :
        num(num), length(length), 
        begin_addr(begin_addr), status(status) {}
};

struct job {
    int nim;
    int length;
    int arri_time;
    int exec_time;
    int addr;
    int num;
};



// 初始化 availTab infoTab
vector<avail> availTab{{1,MEM_LIMIT,INIT_ADDR}};
vector<info> infoTab{{1,MEM_LIMIT,INIT_ADDR,"未分配"}};

void showInfo() {
    // 打印分区说明表
    cout << "分区说明表更新为:" << endl;
    cout << "分区号 起始地址 分区长度 状态" << endl; 
    for(auto t : infoTab) {
        cout << t.num << "    " 
             << (t.begin_addr == 0 ? t.begin_addr : t.begin_addr + 1) 
             << "    " << t.length << "    " 
             << t.status << endl;
    }
    cout << endl;

    // 打印可用表
    cout << "可用表更新为:" << endl;
    cout << "分区号 起始地址 分区长度" << endl;
    for(auto i : availTab) {
        cout << i.num << "    " << i.begin_addr + 1 << "    "
             << i.length << endl;
        cout << endl;
        if (i.length == 320)
            break;
    }
}

void sort1() {} // sort by begin_addr

int finished = 0; // 记录已经执行完的进程的个数，用于控制程序停止
void process(int n) {
    cout << "请输入进程个数";
    int m;
    cin >> m;
    vector<job> jb = vector<job>(m);
    cout << "请输入进程的进程名，进程长度，到达时间，执行时间：" << endl;
    for (int i = 0; i < m; i++) {
        cin >> jb[i].name >> jb[i].length >> jb[i].arri_time >> jb[i].exec_time;
    }
    int addRegion = 1, needModify;
    bool isAllocated = false;
    int j = 0;

    for(int time = 0; time < TIME_LIMIT; ++time) {
        cout << "时间：" << time << endl; 
        if(jb[j].arri_time <= time) {
            for(auto ta : availTab) {
                if(ta.length >= jb[j].length) {
                    cout << "进程" << jb[j].name << "内存分配成功，进入内存"
                         << endl;
                    cout << "该进程使用内存大小为:" << jb[j].length << "KB";
                    needModify = ta.num;
                    // num++;

                    jb[j].addr = ta.begin_addr;
                    jb[j].num = ta.num;

                    // 修改可用表
                    ta.length -= jb[j].length;
                    ta.num == ++addRegion;
                    ta.begin_addr += jb[j].length;

                    // 表示内存分配成功，记录用于后面更改进程的到达时间
                    isAllocated = true;

                    // 修改分区说明表
                    for(auto it = infoTab.begin(); it != infoTab.end(); ++it) {
                        if(it->num == needModify) {
                            info tmp{addRegion, 
                                ti.begin_addr + jb[j].length, 
                                ti.length - jb[j].length, "未分配"};

                            it->length = jb[j].length;
                            it->status = "已分配";
                            infoTab.insert(it, tmp);    
                        }
                    }

                    jb[j].arri_time = i;
                    j++;

                    cout << "   内存起始地址为:" 
                         <<  (ta.begin_addr == 0 ? ta.begin_addr : ta.begin_addr + 1) 
                         << endl << endl;

                    if(n == 2) {
                        sort(availTab.begin(), availTab.end(), cmpBySmallLength);
                    }
                    else if(n == 3) {
                        sort(availTab.begin(), availTab.end(), cmpByLargeLength);
                    }

                    showInfo();
                    isAllocated = true;
                    break;
                }

                if(isAllocated == false) {
                    for(int k = j; k < m; k++) {
                        if(jb[k].arri_time <= i) jb[k].arri_time = i;
                    }
                }

                isAllocated = false; // 重置
            }
        }

        // 判断是否有进程执行结束
        for(int k = 0; k <= j; k++) {
            if(jb[k].exec_time + jb[k].arri_time == i && ns[k] == 0) {
                finished++;
                ns[k] = 1;
                cout << "进程" << jb[k].name << "执行完毕" << endl;
                for(auto i : )

            }
        }
    }
}

int main() {
    
    // showInfo();
    cout << availTab.back().length << " " << infoTab.back().status << endl;
    
    return 0;
}