#include<iostream>
#include<vector>
#define Maxsize 10
using namespace std;
struct Qutype    //环形队列
{
    int data[Maxsize];
    int front;
    int count;
};
void InitQueue(Qutype *&q)
{
    q=(Qutype *)malloc(sizeof(Qutype));
    q->front=0;
    q->count=0;
};
bool EnQueue(Qutype *&q,int e)
{
    int rear;
    if(q->count==Maxsize-1)
    {
        return false;
    }
    rear=(q->front+q->count)%Maxsize;   //注意这里是％除余符号，别用成除号/了！！！;
    rear=(rear+1)%Maxsize;
    q->data[rear]=e;
    q->count++;
    return true;
};
bool DeQueue(Qutype *&q,int &e)
{
    if(q->count==0)
    {
        return false;
    }
    q->front++;
    e=q->data[q->front];//注意q->front和e=q->data[q->front]的相对位置，
    //因为front总是在存数据的前一个位置，所以dequeue时要先将front++才能输出正确位置的数据
    q->count--;
    return true;
};
bool QueueEmpty(Qutype *&q)
{
    return(q->count==0);
};
void FreeQueue(Qutype *&q)
{
    free(q);
};
int main()
{
    Qutype *q;
    InitQueue(*&q);
    vector<int> nums={2,1,0,0,4,3,5,0};
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        EnQueue(*&q,nums[i]);
        cout<<q->data[(q->front+1+i)%Maxsize];
    }
    cout<<'\0'<<endl;
    cout<<QueueEmpty(*&q)<<endl;
    for(int j=0;j<n;j++)
    {
        int e;
        DeQueue(*&q,e);
        cout<<e<<'\t';
    }
    cout<<'\0'<<endl;
    cout<<QueueEmpty(*&q)<<endl;
    FreeQueue(*&q);
}