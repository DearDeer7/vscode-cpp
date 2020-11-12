#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define num_const_list 100//常数表大小
#define num_identifier 100//标识符表大小
/**
 * Author:Oda
 * 
 * for lj 编译原理
 * lj教材P12页C语言子集的词法分析
 * 拓展部分
 * 1 注释
 * 2 新增词表
 *  种别编码 助记符 内码值
 *  14 ( -
 *  15 ) -
 *  16 { -
 *  17 } -
 */
namespace Oda{

string symbol[100]=//编译原理lj教材P12页的助记符
        {"","while","if","else","switch","case"
        ,"id","num","+","-","*"
        ,"relop","=",";","(",")"
        ,"{","}"}; 
unordered_map<string,int> keyWord;//关键字
class OdaWord{
    int type=0;//编译原理lj教材P12页的种别编码
    /*
    新增项
    */
    int subType=0;//编译原理lj教材P12页的内码值
public:
    static const int LE=1;
    static const int LT=2;
    static const int EQ=3;
    OdaWord(){}
    OdaWord(int t,int st){
        type=t;subType=st;
    }
    void print(int mark){
        printf("%d 种别编码%d,助记符%s,内码值%d\n",mark,type,symbol[type].c_str(),subType);
    }
    /*
    bool operator=(const OdaWord& b){
        type=b.type;
        subType=b.subType;
    }
    */
}wordList[100];int n_w;//词表
ll const_list[num_const_list];int n_cl;//常数表
string identifier[num_identifier];int n_id;//标识符表
unordered_map<string,int> mapp;

char t;int f_t;//记录read()读入的字符以供回退
inline char read(){
    if(f_t){
        f_t=0;return t;
    }
    t=getchar();return t;
}

int m[300];//字母标记
void init_Alpha_set();
int main(){
    init_Alpha_set();
    //ctrl+z单行输入时是EOF作为程序输入的结束符
    char first,second;
    int isVaild=1;string notVaild;//词法错误
    while((first=read())!=EOF){
        //空白符1
        if(m[first]==1) continue;
        //注释2 
        else if(m[first]==2){
            second=read();
            if(second=='/') while(read()!='\n');//单行注释
            else if(second=='*'){//多行注释/**/
                char t1=read();char t2;
                if(t1==EOF){f_t=1;continue;}
                while((t2=read())!=EOF){
                    if(t1=='*'&&t2=='/') break;
                    t1=t2;
                }
                if(t2==EOF){f_t=1;continue;}
            }
            else{//本例中没有/运算符，后续可以完善
                isVaild=0;notVaild="\'/\'单独出现";break;
            }
        }
        //数字3
        else if(m[first]==3){//本例中只有整数long long常数
            char tmp[22];tmp[0]=first;int i;
            //长度为21位的long long整数还是有可能溢出，这里没有判断！！！
            for(i=1;i<22;i++){
                tmp[i]=read();
                if(tmp[i]<'0'||tmp[i]>'9') break;
            }
            if(i!=22){
                f_t=1;//回退
                //这里常数录入常数表没有做判重工作，后续可以扩展
                for(int j=0;j<i;j++){
                    const_list[n_cl]*=10;
                    const_list[n_cl]+=tmp[j]-'0';
                }
                wordList[n_w]=OdaWord(7,n_cl);n_w++;//录入词
                n_cl++;
            }
            else{isVaild=0;notVaild="常数位数过大";break;}
        }
        //字母下划线4
        else if(m[first]==4){
            string tmp="";
            tmp.append(1,first);
            while(1){
                char t1=read();
                if(t1>='0'&&t1<='9') tmp.append(1,t1);
                else if(m[t1]==4) tmp.append(1,t1);
                else break;
            }
            f_t=1;//回退
            //关键字
            if(keyWord.find(tmp)!=keyWord.end()){
                wordList[n_w]=OdaWord(keyWord[tmp],0),n_w++;
            }
            //标识符
            else if(mapp.find(tmp)==mapp.end()){
                identifier[n_id]=tmp;
                mapp[tmp]=n_id;//录入标识符表
                wordList[n_w]=OdaWord(6,n_id);n_w++;
                n_id++;
            }
            else{
                wordList[n_w]=OdaWord(6,mapp[tmp]);n_w++;
            }
        }
        //符号5
        else if(m[first]==5){
            if(first=='+') wordList[n_w]=OdaWord(8,0),n_w++;
            else if(first=='-') wordList[n_w]=OdaWord(9,0),n_w++;
            else if(first=='*') wordList[n_w]=OdaWord(10,0),n_w++;
            else if(first=='<'){
                char t1=read();
                if(t1=='=') wordList[n_w]=OdaWord(11,OdaWord::LE),n_w++;
                else wordList[n_w]=OdaWord(11,OdaWord::LT),n_w++,f_t=1;
            }
            else if(first=='='){
                char t1=read();
                if(t1=='=') wordList[n_w]=OdaWord(11,OdaWord::EQ),n_w++;
                else wordList[n_w]=OdaWord(12,0),n_w++,f_t=1;
            }
            else if(first==';') wordList[n_w]=OdaWord(13,0),n_w++;
            //拓展部分
            else if(first=='(') wordList[n_w]=OdaWord(14,0),n_w++;
            else if(first==')') wordList[n_w]=OdaWord(15,0),n_w++;
            else if(first=='{') wordList[n_w]=OdaWord(16,0),n_w++;
            else if(first=='}') wordList[n_w]=OdaWord(17,0),n_w++;
        }
        //此处可拓展
        //非法字符
        else{isVaild=0;notVaild="非法字符:";notVaild.append(1,first);break;}
    }

    //输出词法分析结果
    if(isVaild){
        printf("\n词法分析结果\n");
        for(int i=0 ; i<n_w ; i++){
            wordList[i].print(i+1);
        }
        printf("\n常数表\n");
        for(int i=0 ; i<n_cl ; i++){
            printf("%3d:%24lld\n",i+1,const_list[i]);
        }
        printf("\n标识符表\n");
        for(int i=0 ; i<n_id ; i++){
            printf("%3d:%s\n",i+1,identifier[i].c_str());
        }
    }
    else{
        printf("\nerror:%s\n",notVaild.c_str());
    }
    return 0; 
}
void init_Alpha_set(){
    //初始识别类型
    //空白符1
    char block[50]={' ','\t','\n'};
    for(int i=0;i<3;i++) m[block[i]]=1;
    //注释2
    char note[50]={'/'};
    for(int i=0;i<1;i++) m[note[i]]=2;
    //数字3
    for(char c='0';c<='9';c++) m[c]=3;
    //字母下划线4
    for(char c='a';c<='z';c++) m[c]=4;
    for(char c='A';c<='Z';c++) m[c]=4;
    m['_']=4;
    //符号5
    char operator1[50]={'+','-','*','<','='
                        ,';','(',')','{','}'};
    for(int i=0;i<10;i++) m[operator1[i]]=5;

    //关键字
    string keyWordList[50]={"while","if","else","switch","case"};
    int keyMark[50]={1,2,3,4,5};
    for(int i=0;i<5;i++) keyWord[keyWordList[i]]=keyMark[i];

}


}//namespace end
int main(){
    return Oda::main();
}
/*
if(m<=n) m=n+1;else m=m*2;
while(t==1){if(m<20000000000000000) s=-s+1;}
*/