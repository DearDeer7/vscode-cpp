/**
 * Created by DearDeer on 2020/10/24
 */
#include <bits/stdc++.h>
using namespace std;

const int MEM = 320;
const int ADDR = 40;
int time = 0;

struct avail {
    int id;
    int length;
    int begin_addr;
    avail(int id, int length, int begin_addr)
        : id(id), length(length), begin_addr(begin_addr) {}
};

struct request {
    string id;
    int length;
    int arrival_time;
    int run_time;
    int begin_time;
    int end_time;

    request(string id, int length, int arrival_time
            , int run_time,int begin_time = 0, int end_time = 0)
        : id(id),
          length(length),
          arrival_time(arrival_time),
          run_time(run_time),
          begin_time(begin_time),
          end_time(end_time) {}
};

struct info {
    int id;
    int length;
    int begin_addr;
    bool status;
    info(int id, int length, int begin_addr, bool status) 
        : id(id), length(length), begin_addr(begin_addr), status(status) {} 
};

list<info> info_table{{1,MEM,ADDR}};
list<avail> avail_list{{1, MEM, ADDR}};
deque<request> req_table;

void FirstFit() {
    while(req_table.size()) {
        time++;
        request curr = req_table.front(); req_table.pop_front();
        for(auto it = avail_list.begin(); it != avail_list.end(); ++it) {
            auto i = *it;
            if(i.length >= curr.length) {
                if(i.length == curr.length) {
                    info_table.
                    cout << "进程" << curr.id << "在内存中占用" << curr.length << "KB." << endl;
                    avail_list.erase(it);
                }
            }
        }
    }
}

void BestFit() {}

void WorstFit() {}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        request t;
        cin >> t.id >> t.length >> t.arrival_time >> t.run_time;
        req_table.push_back(t);
    }

    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            FirstFit();
            break;
        case 2:
            BestFit();
            break;
        case 3:
            WorstFit();
            break;
        default:
            cout << "请输入合法的的选项！" << endl;
            break;
    }

    return 0;
}