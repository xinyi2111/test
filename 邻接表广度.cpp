//v0-v7����Ϊa-h
#include<iostream>
#define MaxVertexNum 6
#define MaxSize 7
using namespace std;

//������������
typedef char vertextype;
typedef int datatype;
//����
typedef struct
{
    datatype Q[MaxSize];
    int front;
    int rear;
}SeqQueue;
//�߽������
typedef struct edge
{
    int mark;
    int no;
    struct edge *next;
}edgetype;
//��������
typedef struct
{
    int mark;
    vertextype vertex;
    edgetype *firstArc;
}vertexNode;
//ͼ
typedef struct
{
    vertexNode vex[MaxVertexNum];
    int n,e;
}ALGraph;
ALGraph G;
edgetype *p;//���ڱ����߽��

//�ÿն�
void ClearQueue(SeqQueue &QU)
{
    QU.front=0;
    QU.rear=0;
}

//��ӣ�ʹ��ѭ������
void EnQueue(SeqQueue &QU,datatype x)
{
    //�������
    if(QU.front==(QU.rear+1)%MaxSize)
    {
        cout<<"overflow!"<<endl;
        return;
    }
    QU.Q[QU.rear]=x;
    QU.rear=(QU.rear+1)%MaxSize;
}

//����
void DeQueue(SeqQueue &QU,datatype &x)
{
    //�������
    if(QU.rear==QU.front)
    {
        cout<<"underflow!"<<endl;
        return;
    }
    x=QU.Q[QU.front];
    QU.front=(QU.front+1)%MaxSize;
}

//�ж϶��Ƿ�Ϊ�գ�Ϊ���򷵻�1����Ϊ���򷵻�0
int QueueEmpty(SeqQueue &QU)
{
    if(QU.rear==QU.front)
        return 1;
    return 0;
}

//��������ͼ�ڽӱ�

//ͼ�Ĺ�����ȱ���
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
//������ȱ���ͼ���㷨
void BFS_Component(ALGraph &G)
{
    int i;
    for(i=0;i<8;i++)
        if(G.vex[i].mark==0)
            BFS(G,i);
    cout<<endl;
}

//���Ժ���
int main()
{
    create(G);
    BFS_Component(G);
    return 0;
}

