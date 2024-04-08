#include<iostream>
#include<vector>
#define Maxsize 100
using namespace std;
struct SqStack     //顺序栈
{
    int data[Maxsize];
    int top;
};
void InitStack(SqStack *&s)
{
    s=(SqStack *)malloc(sizeof(SqStack));
    s->top=-1;
};
void DestroyStack(SqStack *&s)
{
    free(s);
};
bool StackEmpty(SqStack *&s)
{
    return(s->top==-1);
};
bool StackPush(SqStack *&s,int e)
{
    if(s->top==Maxsize-1)
    {
        return false;
    }
    s->top++;
    s->data[s->top]=e;
    return true;
};
bool StackPop(SqStack *&s,int &e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    s->top--;
    return true;
};
bool StackGetTop(SqStack *s,int e)
{
    if(s->top==-1)
    {
        return false;
    }
    e=s->data[s->top];
    return true;
};
int main()
{
    vector<int> nums={2,1,0,0,4,3,5,0};
    int n=nums.size();
    SqStack *s;
    s=(SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    for(int i=0;i<n;i++)
    {
        StackPush(s,nums[i]);
        cout<<s->data[i]<<'\t';
    }
    cout<<'\0'<<endl;
    cout<<"top now:"<<s->top<<endl;
    cout<<"Is the stack empty?:  "<<StackEmpty(s)<<endl;
    int e;
    for(int j=0;j<n;j++)
    {
        StackPop(s,e);
        cout<<e<<'\t';
    }
    cout<<'\0'<<endl;
    cout<<"Is the stack empty?:  "<<StackEmpty(s)<<endl;
}