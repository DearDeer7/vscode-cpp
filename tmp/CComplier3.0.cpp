/**
 * Created by DearDeer on 2020/10/18
 * 简单的C语言子集词法分析器
 */
#include<bits/stdc++.h>
using namespace std;

// 分析结果的结构
struct T{
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
// relop的对应表  like relop["<="] = LE
unordered_map<string, string> relops; 

// 初始化函数
void init() {
    vector<string> strs = {
        "while","if","else","switch","case","id", "num", "+","-","*", 
        "relop","=",";",
        "(",")","{","}",":" // 扩展
    };
    for(int i = 0; i < strs.size(); ++i) {
        binds[strs[i]] = i + 1;
    }
    relops["<="] = "LE";
    relops["<"] = "LT";
    relops["=="] = "EQ";

}

// 读取一个字符，方便回退
bool flag = false;
char old;
char readChar() {
    if(flag) {
        flag = false;
        return old;
    }
    old = getchar();
    return old;
}

// 判断字符是否是字母
bool isChar(char c) { 
    return (c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z');
}
// 判断字符是否是数字
bool isDigit(char c) { 
    return (c >= '0') && (c <= '9');
}

// 词法分析
vector<T> analysis() {
    vector<T> ans;
    unordered_map<string, int> ids;
    unordered_map<string, int> nums;
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
            // 字符串是关键字
            if(it != binds.end()) {
                ans.push_back({word, it->second, it->first, "-"});
            }
            // 字符串是标识符
            else {
                // 如果是新的标识符记录
                if(ids.find(word) == ids.end())
                    ids[word] = idx_id++;
                ans.push_back({word, binds["id"], "id", to_string(ids[word])});
            }
        }

        // 分析数字
        else if(isDigit(ch)) {
            word.push_back(ch);
            while(isDigit(ch = readChar())) {
                word.push_back(ch);
            }
            flag = true; // 回退字符
            // 如果是新的常数记录
            if(nums.find(word) == nums.end())
                nums[word] = idx_num++;
            ans.push_back({word, binds["num"], "num", to_string(nums[word])});
        }

        // 分析 + - * ; :
        else if(ch == '+' || ch == '-' || ch == '*' || ch == ';' || ch == ':') {
            word.push_back(ch);
            ans.push_back({word, binds[word], word, "-"});
        }

        // 分析 < <= = ==
        else if(ch == '<' || ch == '=') {
            word.push_back(ch);
            // <= or ==
            if((ch = readChar()) == '=') {
                word.push_back(ch);
                ans.push_back({word, binds["relop"], "relop", relops[word]});
            }
            // < or =
            else {
                // =
                if(word == "<") {
                    ans.push_back({word, binds["relop"], "relop", relops[word]});
                }
                // <
                else {
                    ans.push_back({word, binds[word], word , relops[word]});     
                }
                flag = true; // 回退字符
            }
        }

        // 扩展：处理 '(' ')' '{' '}'
        else if(ch == '(' || ch == ')' || ch == '{' || ch == '}') {
            word.push_back(ch);
            ans.push_back({word, binds[word], word, "-"});
        }

        // 非法输入
        else {
            cout << "存在非法字符" << ch << "!" << endl;
            exit(0);
        }
    }
    return ans;
}

int main() {

    init();
    
    vector<T> ans = analysis();

    /**
     * 输出词法分析的结果
     * 格式为：（助记符，内码值）
     */
    for(auto i : ans) {
        // cout << i.word << ' ' << i.type << ' ' << i.helper << ' ' << i.internalVal << endl;
        printf("（%s，%s）\n", i.helper.c_str(), i.internalVal.c_str());
    }

    return 0;
}


