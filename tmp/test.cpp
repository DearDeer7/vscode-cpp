#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int num=0;
int ns[999999]={0}; 	//标识此进程是否已经结束 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//可用表 
struct U{
	int U_num;	//分区号 
	int U_lengh;	//分区长度 
	int U_Start;	//起始地址 
	U *U_p;			//链表 
}*usin;
//分区说明表 
struct instructions{ 
	int In_num;		 //分区号 
	int In_lengh;	//分区长度 
	int In_Start;	//起始地址 
	string In_How;	//状态 
	instructions *In_p;
}*ins;
 
//进程表 
struct JinCheng{
	char name;		 //进程名称 
	int lon;		 //长度 
	int time;		// 到达时间 
	int need_time;	// 执行时间		
	int adress;		//进程占用内存后的首地址，便于内存回收 
	int num;		//记录分区号 
}; 
 
void menu(){
	cout<<"请选择分配策略："<<endl; 
	cout<<"1.最先适应算法";
	cout<<"2.最佳适应算法";
	cout<<"3.最坏适应算法";
	cout<<endl;
}
 
//初始化 
void init(){
	/*usin=new U;//可用表 
	ins=new instructions;//分区说明表 
	//初始化 还没有进程，即可用表 
	ins->In_num=1;
	ins->In_lengh=320;
	ins->In_Start=0;
	ins->In_How="未分配";
	ins->In_p=NULL;
	
	usin->U_num=1;
	usin->U_lengh=320;
	usin->U_Start=0;
	usin->U_p=NULL;*/
} 
 
void show(){
 
	//显示分区说明表
	struct instructions *Fi=new instructions;
	Fi=ins;
	cout<<"分区说明表更新为:"<<endl;
	cout<<"分区号 起始地址 分区长度 状态"<<endl; 
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
	
	//显示可用表 
	struct U *Uii=new U;
	Uii=usin;
	cout<<"可用表更新为:"<<endl;
	cout<<"分区号 起始地址 分区长度"<<endl; 
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
		if(ii->In_How=="已分配")
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
	if(a==1){	//最佳排序 
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
	else{	//最坏排序 
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
int how=0;			//记录已经执行完的进程的个数，用于控制程序停止 
void First(int n){
		usin=new U;//可用表 
	ins=new instructions;//分区说明表 
	//初始化 还没有进程，即可用表 
	ins->In_num=1;
	ins->In_lengh=320;
	ins->In_Start=0;
	ins->In_How="未分配";
	ins->In_p=NULL;
	
	usin->U_num=1;
	usin->U_lengh=320;
	usin->U_Start=0;
	usin->U_p=NULL;
	cout<<"请输入进程个数";
	int m;
	cin>>m;
	JinCheng Jc[m];
	cout<<"请输入进程的进程名，进程长度，到达时间，执行时间："<<endl;
	for(int i=0;i<m;i++){ 
	    cin>>Jc[i].name>>Jc[i].lon>>Jc[i].time>>Jc[i].need_time;
	}
	int j=0,a=1;			//进程数组下标j,增加的分区号 a
	int l;				//保存需要修改的进程号 
	int Biao=0;			//保存内存分配是否成功	 
	
	
	//用循环模拟时间流逝，i的值代表了当前的时间 
	for(int i=0;i<100;i++){
	    cout<<"-----------------"<<"当前时间："<<i<<"-----------------------"<<endl;
	    if(Jc[j].time<=i){ //到达时间小于等于当前时间 
		struct U *q=new U;
		q=usin;
		while(q!=NULL){
		    if(q->U_lengh>=Jc[j].lon&&q!=NULL){	 
			cout<<"进程"<<Jc[j].name<<"内存分配成功，进入内存"<<endl;
			cout<<"该进程使用内存大小为:"<<Jc[j].lon; 
			l=q->U_num;
			num++;
				
			Jc[j].adress=q->U_Start;
			Jc[j].num=q->U_num; 
					
			//修改可用表
			q->U_lengh=q->U_lengh-Jc[j].lon;
			q->U_num=a+1;
			a=a+1;
			q->U_Start=q->U_Start+Jc[j].lon;
					
			Biao=1; //表示内存分配成功，用于后面更改进程的到达时间
					
			//修改分区说明表 
			struct instructions *T=new instructions;
			T=ins;
			while(T->In_num!=l){
				T=T->In_p;
			} 
			struct instructions *tt=new instructions;
			tt->In_num=a;
			tt->In_Start=T->In_Start+Jc[j].lon;
			tt->In_lengh=T->In_lengh-Jc[j].lon;
			tt->In_How="未分配";
			tt->In_p=T->In_p;
			T->In_lengh=Jc[j].lon;
			T->In_How="已分配";
			T->In_p=tt;
					
					
			Jc[j].time=i;			
			j++; 
					
					
			if(T->In_Start==0)
				cout<<"   内存起始地址为:"<<T->In_Start<<endl<<endl;
			else
				cout<<"   内存起始地址为:"<<T->In_Start+1<<endl<<endl;
						
			//判断是否为最佳或最坏算法，进行相应排序 
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
		    Biao=0;		//重置标识 
				
	        }
 
        }
 
		
		
	//判断是否有进程执行结束
	for(int k=0;k<=j;k++){
		/*cout<<k<<"-=-=-=-=-=-="<<endl;
		if(k==9||k==8||k==7)
		{
			cout<<"-=-=-=-=-=-=-="<<Jc[k].need_time<<endl;
		}*/
            if(Jc[k].need_time+Jc[k].time==i&&ns[k]==0){
                how++;
                ns[k]=1;	
                cout<<"进程"<<Jc[k].name<<"执行完毕"<<endl;
                struct instructions *T=new instructions;
		T=ins;
				
		int fi=0;		
		int up=0; 		
		while(T!=NULL){
		    if(T->In_num==Jc[k].num){		
			T->In_How="未分配";
			if(T->In_p->In_How=="未分配"){
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
			if(L->In_How=="未分配"&&L!=T){
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
	    //更新可用表
		//合并前对可用表按照首地址从小到大进行排列，这样合并算法可以多用 
		if(n==2||n==3)
			sort1();
		struct U *q=new U;
		q->U_num=T->In_num;
		q->U_Start=T->In_Start;
		q->U_lengh=T->In_lengh;
		struct U *pp=new U;
		pp=usin;
		//若此结束的进程占用第一块内存，则特殊处理 
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
				
		//判断说明表更新的时候是否发生合并 
		if(fi==1&&up==1){			//向上向下合并都发生 
			q->U_lengh=T->In_lengh;
			q->U_p=pp->U_p->U_p;
			pp->U_p=q;
			pp->U_lengh+=q->U_lengh;
			pp->U_p=q->U_p;
		}	
		else if(fi==1){				//仅发生向下合并 
			q->U_lengh=T->In_lengh;
			q->U_p=pp->U_p->U_p;
			pp->U_p=q;
		}
		else if(up==1){				//仅发生向上合并
			pp->U_lengh+=T->In_lengh;
		}
		else{						//没有合并发生 
			q->U_p=pp->U_p;
			pp->U_p=q;
		}
		if(n==2){		//重新对可用表按照分配策略进行排序 
			sort(1);
		} 
		else if(n==3){
			sort(2);
		}
		show();
	    }
	}
	if(how==m){
		cout<<"所有进程已经运行完毕"<<endl;
		break;
	}	
    }
}
 
 
 
int main(){
	
	init();		
	menu();
	cout<<"请选择分配策略：";
	cout<<"1.最优    2.最佳   3.最坏\n";
	int n;
	cin>>n;	//借用n判断是否使用排序 
	First(n);
	return 0;
}
 
