/**
 * Created by DearDeer on 2020/10/18
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

class T{
public: 
    string word;
    int type;
    string helper;
    string internalVal;

    T(string word, int type, string helper, string internalVal) {
        this->word = word;
        this->type = type;
        this->helper = helper;
        this->internalVal = internalVal;
    }
};

// 建立一个哈希表，key助记符，val为种别编码
unordered_map<string, int> binds;

void init() {
    vector<string> strs = {
        "while","if","else","switch","case","relop"
        ,"=",";","<=","==","+","-","*","(",")","{","}"
    };
    for(int i = 0; i < strs.size(); ++i) {
        binds[strs[i]] = i + 1;
    }
}

// 读取一个字符，方便回退
bool flag = false;
char readChar() {
    char ch;
    if(flag) {
        flag = false;
        return ch;
    }
    ch = getchar();
    return ch;
}

// 判断字符是否是字母
bool isChar(char c) { 
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

// 判断字母是否是数字
bool isDigit(char c) { 
    return c >= '0' && c <= '9';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    
    vector<T> ans;
    int idx_id = 0, idx_num = 0;
    char ch;
    while((ch = readChar()) != EOF) {
        // 处理空格等空白字符
        while(ch == ' ' || ch == '\t' || ch == '\n') ch = readChar();
        if(ch == EOF) break;

        string word = "";
        // 分析字母
        if(isChar(ch)) {
            word.push_back(ch);
            while(isChar(ch = readChar()) || isDigit(ch)) {
                word.push_back(ch);
            }
            flag = true; // 回退字符
            auto it = binds.find(word);
            if(it != binds.end()) {
                ans.push_back({word, it->second, it->first, "-"});
            }
            else {
                ans.push_back({word, 6, "id", to_string(idx_id++)});
            }
        }
        // 分析数字
        else if(isDigit(ch)) {
            word.push_back(ch);
            while(isDigit(ch = readChar())) {
                word.push_back(ch);
            }
            flag = true; // 回退字符
            ans.push_back({word, 7, "num", to_string(idx_num++)});
        }
        // 分析 + - * ;
        else if(ch == '+' || ch == '-' || ch == '*' || ch == ';') {
            word.push_back(ch);
            ans.push_back({word, binds[word], word, "-"});
        }
        // 分析 < <= = ==
        else if(ch == '<' || ch == '=') {
            word.push_back(ch);
            if((ch = readChar()) == '=') {
                word.push_back(ch);
                ans.push_back({word, binds[word], word, "-"});
            }
            else {
                ans.push_back({word, binds[word], word, "-"});
                flag = true;
            }
        }
        // 非法输入
        else {
            cout << "存在非法字符" << ch << "!" << endl;
            exit(0);
        }
    }

    for(auto i : ans) {
        cout << i.word << ' ' << i.type << ' ' << i.helper << ' ' << i.internalVal << endl;
    }

    return 0;
}

if a < 1 ;
while b <= az;
c  = d * e;