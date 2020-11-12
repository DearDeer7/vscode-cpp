/**
 * Created by DearDeer on 2020/10/15/19:51
 */
#include <bits/stdc++.h>
using namespace std;

bool FindQueue(queue<int>q, int tar) {  
    //遍历队列,看tar是否在驻留集队列中，
    //在则返回true
    while(q.size()){
        if(q.front() == tar) 
        return true;
        q.pop();
    }
    return false;
}

void FIFO(vector<int>& pageFrame, int waitSpace)  { //利用队列模拟FIFO算法
    int pageCount = pageFrame.size();
    int hitCount = 0;       //记录命中次数
    int missPageCount = 0;  //记录缺页次数
    vector<int> fallPage;          //记录淘汰页号
    queue<int> q;           //队列
    for (int j =0; j < pageCount; j++) {
        if (FindQueue(q, pageFrame[j])) {
            ++hitCount;
            continue;
        } else if (q.size() < waitSpace) {
            q.push(pageFrame[j]);
            ++missPageCount;
        } else {
            int n = q.front(); q.pop();
            q.push(pageFrame[j]);
            ++missPageCount;
            fallPage.push_back(n); //保存淘汰页号hitCount
        }
    }
    cout << "产生的缺页数为：" << missPageCount << endl;
    cout << "淘汰的页号为:";
    for(int i : fallPage) cout << i << ' ';
    cout << endl;
    cout << "命中率为:" << hitCount << "/" << pageCount;
}

int main() {
    int pageCount;  //页面号
    int waitSpace;  //驻留集
    cout << "请输入访问页面总数：";
    cin >> pageCount;
    vector<int> pageFrame = vector<int>(pageCount);  //访问序列串
    cout << "请输入所访问的页面号顺序：";
    for (int i = 0; i < pageCount; i++) {
        cin >> pageFrame[i];
    }
    cout << "请输入驻留集大小：";
    cin >> waitSpace;
    cout << endl;
    FIFO(pageFrame, waitSpace);  //调用FIFO()
    return 0;
}