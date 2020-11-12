// create by deardeer at 18:42 on 2020/10/6
//采用最先适应算法进行分配与释放
#include <stdio.h>
const int N = 5;  //假设分区划分为5个
struct block {
    int m_num;  //分区号
    int m_size;  //大小
    int m_addr;  //起始地址
    int m_status;  //分配状态
} memoryBlock[N] = {{1, 20, 100, 0},
                {2, 40, 120, 0},
                {3, 100, 160, 0},
                {4, 200, 260, 0},
                {5, 50, 500, 0}};
//各作业分配表
//最多15个作业
struct mdist {  
    int m_addr;
    int m_size;
    int m_status;
} md[15];

// 内存分配
int distribute(int size) {
    int i;
    int regint;

    int flag = 0;
    for (i = 0; i < N; i++) {
        regint = memoryBlock[i].m_addr;

        if (memoryBlock[i].m_status == 0) {  //表示该分区未被分配

            if (memoryBlock[i].m_size >= size) {
                // memoryBlock[i].m_addr += size;
                memoryBlock[i].m_size -= size;
                flag = 1;
            }

            if (memoryBlock[i].m_size == 0) {
                //如果该分区完全被分配则将其分配状态改为1
                memoryBlock[i].m_status = 1;  
                // memoryBlock[i].m_addr += size;
                // memoryBlock[i].m_size = 0;
                printf("此时第%d分区已完全分配\n", i+1);
            }
            if (flag) break;
        }
        //如果所有分区都无法满足该作业要求的分区则执行下一个作业
    }
    return regint;  //返回分配的起始地址
}

// 内存回收
int free(int startsize, int startaddr) {  
    int i, addr, size;

    //释放作业的起始地址和大小
    addr = startaddr;
    size = startsize;

    // printf("addr=%d size=%d\n", addr, size);

    for (i = 1; i < N; ++i) {

        if(memoryBlock[i-1].m_addr <= addr && 
        memoryBlock[i].m_addr > addr) {
            memoryBlock[i-1].m_size += size;
            break;
        }
    }
    return 0;
}

// 图形化显示当前分区表的信息
void showTable() {
    printf("当前分区表：\n");
    printf("|-----------------------------------------|\n");
    printf("|分区号|    大小|    起始地址|    分配状态|\n");
    printf("|-----------------------------------------|\n");
    for (int i = 0; i < N; i++) {
        printf("|%6d|    %4d|    %8d|    %8d|\n", i + 1, 
                memoryBlock[i].m_size,
                memoryBlock[i].m_addr, memoryBlock[i].m_status);
        printf("|------|--------|------------|------------|\n");
    }
    printf("\n");
}
// 显示作业的分配情况
void showJob(int id) {
    for (int i = 0; i < id; i++) {
        if (md[i].m_status == 1) {
            printf("作业 %d 已结束！回收内存 %d kb\n", 
                    i + 1, md[i].m_size);
        }
        else printf("作业 %d 分配的内存地址从 %d 开始，占据 %d kb\n", 
                    i + 1,md[i].m_addr, md[i].m_size);
    }
    printf("\n");
}

// 主函数
int main() {
    int id = 0, size, i, k;
    int cd;

    // 为作业分配内存
    do {
        printf("请输入作业所需分配的空间大小：");
        scanf("%d", &size);  //输入需要分配内存的作业所要分配的内存空间
        printf("\n");

        md[id].m_size = size;
        md[id].m_addr = distribute(md[id].m_size);
        md[id].m_status = 0;
        id++;

        printf("是否继续分配（1或0）？：");  //是否继续分配内存
        scanf("%d", &cd);
        printf("\n");

    } while (cd != 0);

    // 显示作业分配情况
    showJob(id);

    // 图形化显示分区说明表信息
    showTable();

    printf("是否要回收内存（0或1）？：");
    scanf("%d", &k);
    printf("\n");

    // 回收作业内存
    do {
        printf("请输入要回收内存的作业号：");  //请输入要释放内存的作业号
        scanf("%d", &i);
        printf("\n");

        free(md[i - 1].m_size, md[i - 1].m_addr);
        md[i - 1].m_status = 1;

        printf("是否继续回收（0或1）？：");  //请选择是否继续释放
        scanf("%d", &cd);
        printf("\n");

    } while (cd != 0);
    // 显示作业分配情况
    showJob(id);
    // 图形化显示分区说明表信息
    showTable();
    return 0;
}