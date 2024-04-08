#include<iostream>
#include<vector>
#define Maxsize 10
using namespace std;
struct SqQueue      //顺序队列
{
    int data[Maxsize];
    int front,rear;
};
void InitQueue(SqQueue *&q)
{
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=-1;
};
bool QueueEmpty(SqQueue *&q)
{
    return(q->front==q->rear);//有return的都要将函数类型设置为bool；
};
void DestroyQueue(SqQueue *&q)
{
    free(q);
};
bool EnQueue(SqQueue *&q,int e)
{
    if(q->rear==Maxsize-1)
    {
        return false;
    }
    q->rear++;
    q->data[q->rear]=e;
    return true;
};
bool DeQueue(SqQueue *&q,int &e)
{
    if(q->rear==q->front)
    {
        return false;
    }
    q->front++;
    e=q->data[q->front];
    return true;
};
int main()
{
    SqQueue *q;
    InitQueue(*&q);
    int e;
    vector<int> nums={2,1,0,0,4,3,5,0};
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        EnQueue(*&q,nums[i]);
    }
    cout<<QueueEmpty(*&q)<<endl;
    for(int j=0;j<n;j++)
    {
        DeQueue(*&q,e);
        cout<<e<<'\t';
    }
    cout<<'\0'<<endl;
    cout<<QueueEmpty(*&q)<<endl;
}