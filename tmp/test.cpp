#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int num=0;
int ns[999999]={0}; 	//��ʶ�˽����Ƿ��Ѿ����� 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//���ñ� 
struct U{
	int U_num;	//������ 
	int U_lengh;	//�������� 
	int U_Start;	//��ʼ��ַ 
	U *U_p;			//���� 
}*usin;
//����˵���� 
struct instructions{ 
	int In_num;		 //������ 
	int In_lengh;	//�������� 
	int In_Start;	//��ʼ��ַ 
	string In_How;	//״̬ 
	instructions *In_p;
}*ins;
 
//���̱� 
struct JinCheng{
	char name;		 //�������� 
	int lon;		 //���� 
	int time;		// ����ʱ�� 
	int need_time;	// ִ��ʱ��		
	int adress;		//����ռ���ڴ����׵�ַ�������ڴ���� 
	int num;		//��¼������ 
}; 
 
void menu(){
	cout<<"��ѡ�������ԣ�"<<endl; 
	cout<<"1.������Ӧ�㷨";
	cout<<"2.�����Ӧ�㷨";
	cout<<"3.���Ӧ�㷨";
	cout<<endl;
}
 
//��ʼ�� 
void init(){
	/*usin=new U;//���ñ� 
	ins=new instructions;//����˵���� 
	//��ʼ�� ��û�н��̣������ñ� 
	ins->In_num=1;
	ins->In_lengh=320;
	ins->In_Start=0;
	ins->In_How="δ����";
	ins->In_p=NULL;
	
	usin->U_num=1;
	usin->U_lengh=320;
	usin->U_Start=0;
	usin->U_p=NULL;*/
} 
 
void show(){
 
	//��ʾ����˵����
	struct instructions *Fi=new instructions;
	Fi=ins;
	cout<<"����˵�������Ϊ:"<<endl;
	cout<<"������ ��ʼ��ַ �������� ״̬"<<endl; 
	while(Fi!=NULL){
	    if(Fi->In_Start==0){
            cout<<Fi->In_num<<"\t"<<Fi->In_Start<<"\t"<<Fi->In_lengh<<"\t"<<Fi->In_How<<endl;	
	    }
	    else{
			cout<<Fi->In_num<<"\t"<<Fi->In_Start+1<<"\t"<<Fi->In_lengh<<"\t"<<Fi->In_How<<endl;
	    }
	    cout<<endl;
	    Fi=Fi->In_p;
}
	
	//��ʾ���ñ� 
	struct U *Uii=new U;
	Uii=usin;
	cout<<"���ñ����Ϊ:"<<endl;
	cout<<"������ ��ʼ��ַ ��������"<<endl; 
	while(Uii!=NULL){
	    cout<<Uii->U_num<<"\t"<<Uii->U_Start+1<<"\t"<<Uii->U_lengh<<endl;
	    cout<<endl;
	    if(Uii->U_lengh==320) 
		break;
	    else
		Uii=Uii->U_p;
	}	
}
 
int Pan(){
	struct instructions *ii=new instructions;
	ii=ins;
	while(ii!=NULL){
		if(ii->In_How=="�ѷ���")
			return 0;
		ii=ii->In_p; 
	}
	return 1;
}
void sort1(){
    struct U *p = NULL;
    struct U *q = NULL;
    struct U *t = NULL;
     
    if(usin->U_p == NULL)
    {
        return;
    }
	for(p = usin; p != NULL; p = p->U_p)
	{
	    for(q = usin; q->U_p!= NULL; q = q->U_p)
	    {
	        if(q->U_Start> q->U_p->U_Start)
	        {
	            swap(q->U_lengh, q->U_p->U_lengh);
	            swap(q->U_num, q->U_p->U_num);
	            swap(q->U_Start, q->U_p->U_Start);
	        }
	    }
	}
		
} 
void sort(int a){
    struct U *p = NULL;
    struct U *q = NULL;
    struct U *t = NULL;
     
    if(usin->U_p == NULL)
    {
        return;
    }
	if(a==1){	//������� 
	    for(p = usin; p != NULL; p = p->U_p)
	     {
	        for(q = usin; q->U_p!= NULL; q = q->U_p)
	         {
	            if(q->U_lengh> q->U_p->U_lengh)
	            {
	               swap(q->U_lengh, q->U_p->U_lengh);
	               swap(q->U_num, q->U_p->U_num);
	               swap(q->U_Start, q->U_p->U_Start);
	            }
	        }
	    }
	}
	else{	//����� 
	    for(p = usin; p != NULL; p = p->U_p)
	     {
	        for(q = usin; q->U_p!= NULL; q = q->U_p)
	         {
	            if(q->U_lengh< q->U_p->U_lengh)
	            {
	               swap(q->U_lengh, q->U_p->U_lengh);
	               swap(q->U_num, q->U_p->U_num);
	               swap(q->U_Start, q->U_p->U_Start);
	            }
	        }
	    }
	}
}
int how=0;			//��¼�Ѿ�ִ����Ľ��̵ĸ��������ڿ��Ƴ���ֹͣ 
void First(int n){
		usin=new U;//���ñ� 
	ins=new instructions;//����˵���� 
	//��ʼ�� ��û�н��̣������ñ� 
	ins->In_num=1;
	ins->In_lengh=320;
	ins->In_Start=0;
	ins->In_How="δ����";
	ins->In_p=NULL;
	
	usin->U_num=1;
	usin->U_lengh=320;
	usin->U_Start=0;
	usin->U_p=NULL;
	cout<<"��������̸���";
	int m;
	cin>>m;
	JinCheng Jc[m];
	cout<<"��������̵Ľ����������̳��ȣ�����ʱ�䣬ִ��ʱ�䣺"<<endl;
	for(int i=0;i<m;i++){ 
	    cin>>Jc[i].name>>Jc[i].lon>>Jc[i].time>>Jc[i].need_time;
	}
	int j=0,a=1;			//���������±�j,���ӵķ����� a
	int l;				//������Ҫ�޸ĵĽ��̺� 
	int Biao=0;			//�����ڴ�����Ƿ�ɹ�	 
	
	
	//��ѭ��ģ��ʱ�����ţ�i��ֵ�����˵�ǰ��ʱ�� 
	for(int i=0;i<100;i++){
	    cout<<"-----------------"<<"��ǰʱ�䣺"<<i<<"-----------------------"<<endl;
	    if(Jc[j].time<=i){ //����ʱ��С�ڵ��ڵ�ǰʱ�� 
		struct U *q=new U;
		q=usin;
		while(q!=NULL){
		    if(q->U_lengh>=Jc[j].lon&&q!=NULL){	 
			cout<<"����"<<Jc[j].name<<"�ڴ����ɹ��������ڴ�"<<endl;
			cout<<"�ý���ʹ���ڴ��СΪ:"<<Jc[j].lon; 
			l=q->U_num;
			num++;
				
			Jc[j].adress=q->U_Start;
			Jc[j].num=q->U_num; 
					
			//�޸Ŀ��ñ�
			q->U_lengh=q->U_lengh-Jc[j].lon;
			q->U_num=a+1;
			a=a+1;
			q->U_Start=q->U_Start+Jc[j].lon;
					
			Biao=1; //��ʾ�ڴ����ɹ������ں�����Ľ��̵ĵ���ʱ��
					
			//�޸ķ���˵���� 
			struct instructions *T=new instructions;
			T=ins;
			while(T->In_num!=l){
				T=T->In_p;
			} 
			struct instructions *tt=new instructions;
			tt->In_num=a;
			tt->In_Start=T->In_Start+Jc[j].lon;
			tt->In_lengh=T->In_lengh-Jc[j].lon;
			tt->In_How="δ����";
			tt->In_p=T->In_p;
			T->In_lengh=Jc[j].lon;
			T->In_How="�ѷ���";
			T->In_p=tt;
					
					
			Jc[j].time=i;			
			j++; 
					
					
			if(T->In_Start==0)
				cout<<"   �ڴ���ʼ��ַΪ:"<<T->In_Start<<endl<<endl;
			else
				cout<<"   �ڴ���ʼ��ַΪ:"<<T->In_Start+1<<endl<<endl;
						
			//�ж��Ƿ�Ϊ��ѻ���㷨��������Ӧ���� 
			if(n==2){
				sort(1);
			} 
			else if(n==3){
				sort(2);
			}
			show();			 
			Biao=1;			
			break;	
		    }
		    else{
		        q=q->U_p;
		    }
				
				
		    if(Biao==0){
		        for(int u=j;u<m;u++){
			    if(Jc[u].time<=i)
			        Jc[u].time=i;
		        }
					
		    }
		    Biao=0;		//���ñ�ʶ 
				
	        }
 
        }
 
		
		
	//�ж��Ƿ��н���ִ�н���
	for(int k=0;k<=j;k++){
		/*cout<<k<<"-=-=-=-=-=-="<<endl;
		if(k==9||k==8||k==7)
		{
			cout<<"-=-=-=-=-=-=-="<<Jc[k].need_time<<endl;
		}*/
            if(Jc[k].need_time+Jc[k].time==i&&ns[k]==0){
                how++;
                ns[k]=1;	
                cout<<"����"<<Jc[k].name<<"ִ�����"<<endl;
                struct instructions *T=new instructions;
		T=ins;
				
		int fi=0;		
		int up=0; 		
		while(T!=NULL){
		    if(T->In_num==Jc[k].num){		
			T->In_How="δ����";
			if(T->In_p->In_How=="δ����"){
            	T->In_lengh+=T->In_p->In_lengh;
			    T->In_p=T->In_p->In_p; 
			    fi=1;
		        }
			struct instructions *L=new instructions;
			L=ins;
			/**/
			while(L->In_p!=T&&L!=T){	
			    L=L->In_p;
			}
			if(L->In_How=="δ����"&&L!=T){
			    L->In_lengh+=T->In_lengh;
			    L->In_p=T->In_p;
			    up=1;
			}
			break;
		    }
		    else{
		        T=T->In_p;
		    }
	        }
	        cout<<T->In_num+"================"<<endl; 
	    //���¿��ñ�
		//�ϲ�ǰ�Կ��ñ����׵�ַ��С����������У������ϲ��㷨���Զ��� 
		if(n==2||n==3)
			sort1();
		struct U *q=new U;
		q->U_num=T->In_num;
		q->U_Start=T->In_Start;
		q->U_lengh=T->In_lengh;
		struct U *pp=new U;
		pp=usin;
		//���˽����Ľ���ռ�õ�һ���ڴ棬�����⴦�� 
		if(q->U_num==1){
			q->U_p=pp;
			usin=q;
			show();
			break;
		}
		cout<<pp->U_p->U_Start<<"???????????????"<<endl;
		while(pp->U_p->U_Start<q->U_Start){
			pp=pp->U_p;
		}
				
		//�ж�˵������µ�ʱ���Ƿ����ϲ� 
		if(fi==1&&up==1){			//�������ºϲ������� 
			q->U_lengh=T->In_lengh;
			q->U_p=pp->U_p->U_p;
			pp->U_p=q;
			pp->U_lengh+=q->U_lengh;
			pp->U_p=q->U_p;
		}	
		else if(fi==1){				//���������ºϲ� 
			q->U_lengh=T->In_lengh;
			q->U_p=pp->U_p->U_p;
			pp->U_p=q;
		}
		else if(up==1){				//���������Ϻϲ�
			pp->U_lengh+=T->In_lengh;
		}
		else{						//û�кϲ����� 
			q->U_p=pp->U_p;
			pp->U_p=q;
		}
		if(n==2){		//���¶Կ��ñ��շ�����Խ������� 
			sort(1);
		} 
		else if(n==3){
			sort(2);
		}
		show();
	    }
	}
	if(how==m){
		cout<<"���н����Ѿ��������"<<endl;
		break;
	}	
    }
}
 
 
 
int main(){
	
	init();		
	menu();
	cout<<"��ѡ�������ԣ�";
	cout<<"1.����    2.���   3.�\n";
	int n;
	cin>>n;	//����n�ж��Ƿ�ʹ������ 
	First(n);
	return 0;
}
 
