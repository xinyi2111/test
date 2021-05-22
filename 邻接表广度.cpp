//v0-v7依次为a-h
#include<iostream>
#define MaxVertexNum 6
#define MaxSize 7
using namespace std;

//抽象数据类型
typedef char vertextype;
typedef int datatype;
//队列
typedef struct
{
    datatype Q[MaxSize];
    int front;
    int rear;
}SeqQueue;
//边结点类型
typedef struct edge
{
    int mark;
    int no;
    struct edge *next;
}edgetype;
//点结点类型
typedef struct
{
    int mark;
    vertextype vertex;
    edgetype *firstArc;
}vertexNode;
//图
typedef struct
{
    vertexNode vex[MaxVertexNum];
    int n,e;
}ALGraph;
ALGraph G;
edgetype *p;//用于遍历边结点

//置空队
void ClearQueue(SeqQueue &QU)
{
    QU.front=0;
    QU.rear=0;
}

//入队，使用循环队列
void EnQueue(SeqQueue &QU,datatype x)
{
    //参数检查
    if(QU.front==(QU.rear+1)%MaxSize)
    {
        cout<<"overflow!"<<endl;
        return;
    }
    QU.Q[QU.rear]=x;
    QU.rear=(QU.rear+1)%MaxSize;
}

//出队
void DeQueue(SeqQueue &QU,datatype &x)
{
    //参数检查
    if(QU.rear==QU.front)
    {
        cout<<"underflow!"<<endl;
        return;
    }
    x=QU.Q[QU.front];
    QU.front=(QU.front+1)%MaxSize;
}

//判断队是否为空，为空则返回1，不为空则返回0
int QueueEmpty(SeqQueue &QU)
{
    if(QU.rear==QU.front)
        return 1;
    return 0;
}

//构造无向图邻接表

//图的广度优先遍历
void BFS(ALGraph &G,int i)
{
    edgetype *p;
    int k;
    SeqQueue QU;
    ClearQueue(QU);
    G.vex[i].mark=1;
    EnQueue(QU,i);
    while(!QueueEmpty(QU))
    {
        DeQueue(QU,k);
        cout<<(char)G.vex[k].vertex<<endl;
        p=G.vex[k].firstArc;
        while(p!=NULL)
        {
            if(G.vex[p->no].mark==0)
            {
                G.vex[p->no].mark=1;
                p->mark=1;
                EnQueue(QU,p->no);
            }
            p=p->next;
        }
    }
}
//广度优先遍历图的算法
void BFS_Component(ALGraph &G)
{
    int i;
    for(i=0;i<8;i++)
        if(G.vex[i].mark==0)
            BFS(G,i);
    cout<<endl;
}

//测试函数
int main()
{
    create(G);
    BFS_Component(G);
    return 0;
}

