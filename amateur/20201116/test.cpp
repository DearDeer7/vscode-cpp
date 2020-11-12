#include<bits/stdc++.h>
using namespace std;

int main1(){}
int main(){
    cout<<main1<<endl;
    cout<<main1()<<endl;
}


/**
 * philosopher
 */
#define TASK_STK_SIZE 128
#define N_STK 5

OS_STK TaskStk[TASK_STK_SIZE][TASK_STK_SIZE];

INT8U TaskData[N_STK];
OS_EVENT *chopsticks[N_STK];

static void Task(void *pdata) ;

void main() {
    INT8U err;
    INT8U i;
    OSInit();

    for(i = 0; i < N_STK; ++i) {
        chopsticks[i] = OSSemCreate(i);
    }

    for(i = 0; i < N_STK; ++i) {
        TaskData[i] = i;
        OSTaskCreate(Task, (void*) &TaskDate[i], &TaskStk[i][TASK_STK_SIZE - 1], i + 12);
    }

    OSStart();
}

void Task(void *pdata) {
    INT8U i, j;
    INT8U err;

    i = *(int *)pdata;
    j = (i + 1) % N_STK;

    while(TRUE) {
        OS_Printf("philosopher%d is hungry!", i + 1);
        OSSemPend(chopsticks[i], 0, &err);
        OSSemPend(chopsticks[j], 0, &err);
        OS_Printf("philosopher%d is eating!", i + 1);

        OSTimeDly(200);
        OSSemPost(chopsticks[i], 0, &err);
        OSSemPost(chopsticks[j], 0, &err);

        OS_Printf("philosopher%d is full!", i + 1);
        OSTimeDly(200);
    }
}

/**
 * 消息邮箱
 * 发送字符串接受打印
 */
#define TASK_STK_SIZE 128

OS_STK TaskStk[TASK_STK_SIZE][TASK_STK_SIZE];
OS_EVENT *commMBox;

void Task1(void *pata);
void Task2(void *pata);

void main() {
    INT8U err;
    OSInit();

    CommMBox = OSMBoxCreate((void*)0);

    OSTaskCreate(Task1, NULL, (OS_STK*) &TaskStk[0][TASK_STK_SIZE - 1], 9);
    OSTaskCreate(Task2, NULL, (OS_STK*) &TaskStk[1][TASK_STK_SIZE - 1], 10);

    OSStart();
}

void Task1(void *pata) {
    char msg[100];
    INT8U err;
    int cnt = 0;
    while(1) {
        sprintf(msg, "Task1 %d", cnt++);
        err = OSMBoxPost(CommMbox, (void*) &msg);
        OSTimeDly(100);
    }
}

void Task2(void *pata) {
    void *msg;
    INT8U err;

    while(1) {
        msg = OSMBoxPend(CommMBox, 0, &err);
        if(err == OS_NO_ERROR) OS_Printf("%s\n", msg);
        OSTimeDly(200);
    }
}

/**
 * 统计小于 n 的素数有多少
 */
int countPrime(int n) { 
    int cnt = 0;
    for(int i = 2; i <= n; ++i) {
        int j;
        for(j = 0; j < i; ++j) {
            if(i % j == 0) break;
        }
        if(j == i) cnt++;
    }
    return cnt;
}

/**
 * philosopher again
 */
#define TASK_STK_SIZE 128
#define N_TASK 5 

OS_STK TaskStk[N_TASK][TASK_STK_SIZE];
OS_EVENT *chopsticks[N_STK];
INT8U TaskData[N_STK];

void Task(void *pdata);

void main() {

    INT8U err;
    INT8U i;
    OSInit();

    for(i = 0; i < N_STK; ++i) chopsticks[i] = OSSemCreate(1);
    for(i = 0; i < N_STK; ++i) {
        TaskData[i] = i;
        OSTaskCreate(Task, (void*) &TaskData[i], &TaskStk[i][TASK_STK_SIZE - 1], 12 + i);
    }
    OSStart();
}

void Task(void *pdata) {
    INT8U err;
    INT8U i,j;
    i = *(int*)pdata;
    j = (i + 1) % N_STK;

    while(1) {
        OS_Prinf("philosopher%d is hungry!", i + 1);
        OSSemPend(chopsticks[i], 0, &err);
        OSSemPend(chopsticks[j], 0, &err);
        OS_prinf("philosopher%d is eating!", i + 1);
        OSTimedly(200);
        OS_Prinf("philosopher%d is full!", i + 1);
        OSSemPost(chopsticks[i], 0, &err);
        OSSemPost(chopsticks[j], 0, &err);
    }
}

{
    commMBox = OSMboxCreate(NULL);
    OSMboxPend(commMBox, 0, &err);
    err = OSMBoxPost(commMBox, &msg[0]);

    void *msg[10];
    commQ = OSQCreate(&msg[0], 10);
    void *num;
    num = OSQPend(commQ, 0, &err);
    err = OSQPost(commQ, (void*) &input);
}

/**
 * 统计素数
 */
#define TASK_STK_SIZE 128
#define N_TASK 2
OS_STK TaskStk[N_TASK][TASK_STK_SIZE - 1];
OS_EVENT *commMBox;
OS_EVENT *sem;

void Task1(void *pdata);
void Task2(void *pdata);

void main() {
    INT8U err;
    OSInit();

    commMBox = OSMBoxCreate(NULL);
    sem = OSSemCreate(1);

    OSTaskCreate(Task1, NULL, &TaskStk[0][TASK_STK_SIZE - 1], 9);
    OSTaskCreate(Task2, NULL, &TaskStk[1][TASK_STK_SIZE - 1], 10);

    OSStart();
}

void Task1(void *pata) {
    INT8U err;
    srand(time(NULL));
    int num;

    while(commMBox == NULL) {
        OSSemPend(sem, 0, &err);
        num = rand() % 100000 * 10;
        OS_Prinf("Task1 is sending %d...", num);
        OSMBoxPost(commMBox, (void*) &num);
        OSTimeDly(200);
    }
}

void Task2(void *pata) {
    INT8U err;
    void *msg;
    int num, cnt = 0;
    while(1) {
        msg = OSMBoxPend(CommMBox, 0, &err);
        if(err == OS_NO_ERROR) {
            num = *(int*) num;
            for(int i = 2; i <= n; ++i) {
                int j;
                for(j = 0; j < i; ++j) {
                    if(i % j == 0) break;
                }
                if(j == i) cnt++;
            }
            OSSemPost(sem, 0, &err);
            OS_Prinf("fdgfds")
        }
    }
}