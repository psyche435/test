#include<iostream>
#include<vector>
using namespace std;
struct DListNode     //双链表
{
    int val;
    DListNode *prior;
    DListNode *next;
    DListNode():val(0),prior(NULL),next(NULL){};
    DListNode(int x):val(x),prior(NULL),next(NULL){};
};
void CreatDList1(DListNode *&L,vector<int> a,int n)//CreatDList1是顺序建表
{
    DListNode *s,*pre;
    L=(DListNode *)malloc(sizeof(DListNode));
    L->next=NULL;
    L->prior=NULL;
    pre=L;
    for(int i=0;i<n;i++)
    {
        s=(DListNode *)malloc(sizeof(DListNode));
        s->val=a[i];
        pre->next=s;
        s->prior=pre;//因为是尾插法，所以只用将新结点和pre链接起来就可以了，中途不用考虑NULL，而在最后一个插入完后再加尾结点NULL；
        pre=s;
    }
    pre->next=NULL;
};
void CreatDList2(DListNode *&L,vector<int> a,int n)//CreatDList2是逆序建表
{
    DListNode *s;
    L=(DListNode *)malloc(sizeof(DListNode));
    L->next=NULL;
    L->prior=NULL;
    for(int i=0;i<n;i++)
    {
        s=(DListNode *)malloc(sizeof(DListNode));
        s->val=a[i];
        s->next=L->next;
        if(L->next!=NULL)       //这里的if语句十分重要，如果缺失此个if语句将导致列表创建失败
            {L->next->prior=s;} //因为初始状态时，L->next可能为空，为空的时候L->next->prior根本不存在，所以就更不能赋值，因此如果没有if语句会报错
        s->prior=L;//只有头插法需要考虑上一个结点的后继结点，而尾插法的后继结点固定是NULL，所以中途不需要考虑next结点；
        L->next=s;
    }
};
void DispList(DListNode *&L)
{
    DListNode *a;
    a=(DListNode *)malloc(sizeof(DListNode));
    a=L->next;
    while(a!=NULL)
    {
        cout<<a->val<<endl;
        a=a->next;
    }
};
bool ListInsert(DListNode *&L,int i,int &e)
{
    if(i<0)
    {
        return false;
    }
    DListNode *s,*p;
    s=(DListNode *)malloc(sizeof(DListNode));
    p=(DListNode *)malloc(sizeof(DListNode));
    int j=0;
    p=L;
    while(j<i&&p!=NULL)
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    {
        return false;
    }
    s->val=e;
    s->next=p->next;
    if(p->next!=NULL)
    {
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;
    return true;
}
bool ListDelete(DListNode *&L,int i,int &e)
{
    if(i<0)
    {
        return false;
    }
    DListNode *p=L,*q;
    int j=0;
    while(j<i-1&&p!=NULL)//注意这里是小于i－1而不是i因为i代表第几个数字，在变为数组下标时本身要减一
    //而这个j是用来找第i个数的前面一个结点的，所以要比i小一，用<而不是<=。
    {
        p=p->next;
        j++;
    }
    if(p==NULL)
    {
        return false;
    }
    else
    {
        q=p->next;
        if(q==NULL)
        {
            return false;
        }
        e=q->val;
        p->next=q->next;
        if(q->next!=NULL)
        {
            q->next->prior=p;
        }
        free(q);
        return true;
    }
}
int main()
{
    vector<int> list={2,1,0,0,4,3,5,0};
    int n=list.size();
    DListNode *L;
    CreatDList1(*&L,list,n);
    cout<<"the delete-pre numbers:"<<endl;
    DispList(*&L);
    int e1,e2,i;
    i=6;
    e2=6;
    ListDelete(*&L,i,e1);
    cout<<"the numbers after delete i=6:"<<endl;
    DispList(*&L);
    cout<<"the delete number:"<<e1<<endl;
    ListInsert(*&L,i-1,e2);
    cout<<"the numbers after insert e2:"<<endl;
    DispList(*&L);
}