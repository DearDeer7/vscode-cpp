#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define num_const_list 100//�������С
#define num_identifier 100//��ʶ�����С
/**
 * Author:Oda
 * 
 * for lj ����ԭ��
 * lj�̲�P12ҳC�����Ӽ��Ĵʷ�����
 * ��չ����
 * 1 ע��
 * 2 �����ʱ�
 *  �ֱ���� ���Ƿ� ����ֵ
 *  14 ( -
 *  15 ) -
 *  16 { -
 *  17 } -
 */
namespace Oda{

string symbol[100]=//����ԭ��lj�̲�P12ҳ�����Ƿ�
        {"","while","if","else","switch","case"
        ,"id","num","+","-","*"
        ,"relop","=",";","(",")"
        ,"{","}"}; 
unordered_map<string,int> keyWord;//�ؼ���
class OdaWord{
    int type=0;//����ԭ��lj�̲�P12ҳ���ֱ����
    /*
    ������
    */
    int subType=0;//����ԭ��lj�̲�P12ҳ������ֵ
public:
    static const int LE=1;
    static const int LT=2;
    static const int EQ=3;
    OdaWord(){}
    OdaWord(int t,int st){
        type=t;subType=st;
    }
    void print(int mark){
        printf("%d �ֱ����%d,���Ƿ�%s,����ֵ%d\n",mark,type,symbol[type].c_str(),subType);
    }
    /*
    bool operator=(const OdaWord& b){
        type=b.type;
        subType=b.subType;
    }
    */
}wordList[100];int n_w;//�ʱ�
ll const_list[num_const_list];int n_cl;//������
string identifier[num_identifier];int n_id;//��ʶ����
unordered_map<string,int> mapp;

char t;int f_t;//��¼read()������ַ��Թ�����
inline char read(){
    if(f_t){
        f_t=0;return t;
    }
    t=getchar();return t;
}

int m[300];//��ĸ���
void init_Alpha_set();
int main(){
    init_Alpha_set();
    //ctrl+z��������ʱ��EOF��Ϊ��������Ľ�����
    char first,second;
    int isVaild=1;string notVaild;//�ʷ�����
    while((first=read())!=EOF){
        //�հ׷�1
        if(m[first]==1) continue;
        //ע��2 
        else if(m[first]==2){
            second=read();
            if(second=='/') while(read()!='\n');//����ע��
            else if(second=='*'){//����ע��/**/
                char t1=read();char t2;
                if(t1==EOF){f_t=1;continue;}
                while((t2=read())!=EOF){
                    if(t1=='*'&&t2=='/') break;
                    t1=t2;
                }
                if(t2==EOF){f_t=1;continue;}
            }
            else{//������û��/�������������������
                isVaild=0;notVaild="\'/\'��������";break;
            }
        }
        //����3
        else if(m[first]==3){//������ֻ������long long����
            char tmp[22];tmp[0]=first;int i;
            //����Ϊ21λ��long long���������п������������û���жϣ�����
            for(i=1;i<22;i++){
                tmp[i]=read();
                if(tmp[i]<'0'||tmp[i]>'9') break;
            }
            if(i!=22){
                f_t=1;//����
                //���ﳣ��¼�볣����û�������ع���������������չ
                for(int j=0;j<i;j++){
                    const_list[n_cl]*=10;
                    const_list[n_cl]+=tmp[j]-'0';
                }
                wordList[n_w]=OdaWord(7,n_cl);n_w++;//¼���
                n_cl++;
            }
            else{isVaild=0;notVaild="����λ������";break;}
        }
        //��ĸ�»���4
        else if(m[first]==4){
            string tmp="";
            tmp.append(1,first);
            while(1){
                char t1=read();
                if(t1>='0'&&t1<='9') tmp.append(1,t1);
                else if(m[t1]==4) tmp.append(1,t1);
                else break;
            }
            f_t=1;//����
            //�ؼ���
            if(keyWord.find(tmp)!=keyWord.end()){
                wordList[n_w]=OdaWord(keyWord[tmp],0),n_w++;
            }
            //��ʶ��
            else if(mapp.find(tmp)==mapp.end()){
                identifier[n_id]=tmp;
                mapp[tmp]=n_id;//¼���ʶ����
                wordList[n_w]=OdaWord(6,n_id);n_w++;
                n_id++;
            }
            else{
                wordList[n_w]=OdaWord(6,mapp[tmp]);n_w++;
            }
        }
        //����5
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
            //��չ����
            else if(first=='(') wordList[n_w]=OdaWord(14,0),n_w++;
            else if(first==')') wordList[n_w]=OdaWord(15,0),n_w++;
            else if(first=='{') wordList[n_w]=OdaWord(16,0),n_w++;
            else if(first=='}') wordList[n_w]=OdaWord(17,0),n_w++;
        }
        //�˴�����չ
        //�Ƿ��ַ�
        else{isVaild=0;notVaild="�Ƿ��ַ�:";notVaild.append(1,first);break;}
    }

    //����ʷ��������
    if(isVaild){
        printf("\n�ʷ��������\n");
        for(int i=0 ; i<n_w ; i++){
            wordList[i].print(i+1);
        }
        printf("\n������\n");
        for(int i=0 ; i<n_cl ; i++){
            printf("%3d:%24lld\n",i+1,const_list[i]);
        }
        printf("\n��ʶ����\n");
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
    //��ʼʶ������
    //�հ׷�1
    char block[50]={' ','\t','\n'};
    for(int i=0;i<3;i++) m[block[i]]=1;
    //ע��2
    char note[50]={'/'};
    for(int i=0;i<1;i++) m[note[i]]=2;
    //����3
    for(char c='0';c<='9';c++) m[c]=3;
    //��ĸ�»���4
    for(char c='a';c<='z';c++) m[c]=4;
    for(char c='A';c<='Z';c++) m[c]=4;
    m['_']=4;
    //����5
    char operator1[50]={'+','-','*','<','='
                        ,';','(',')','{','}'};
    for(int i=0;i<10;i++) m[operator1[i]]=5;

    //�ؼ���
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