#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(NULL){};
    ListNode(int x):val(x),next(NULL){};
}sqList;
void Listinsert(ListNode *&node,int x)
{
    ListNode *p=new ListNode(x);
    p->next=node->next;
    node->next=p;
}
void CreatList1(ListNode *&node,vector<int> a,int n)
{
    ListNode *x;
    node=(ListNode *)malloc(sizeof(ListNode));
    node->next=NULL;
    for(int i=0;i<n;i++)
    {
        x=(ListNode *)malloc(sizeof(ListNode));
        x->val=a[i];
        x->next=node->next;
        node->next=x;
    }
}
int main()
{
    vector<int> list1={1,9,1,2,4};
    vector<int> list2={3,2,4};
    int n1=list1.size();
    int n2=list2.size();
    ListNode *node1;
    ListNode *node2;
    CreatList1(node1,*&list1,n1);
    CreatList1(node2,*&list2,n2);
    ListNode *a1=node1->next;
    ListNode *a2=node2->next;
    int loc1=n1;
    int loc2=n2;
    int temp;
    while(a1&&a2)
    {
        if(a1->val!=a2->val)
        {
            cout<<"loc1:"<<loc1<<endl;
            cout<<"loc2:"<<loc2<<endl;
            cout<<"the meet spot =="<<temp<<endl;
            break;
        }
        if(a1->val==a2->val)
        {
            temp=a1->val;
            a1=a1->next;
            a2=a2->next;
            loc1--;
            loc2--;
        }
        if(loc1==n1&&loc2==n2)
        {
            cout<<"no common list"<<endl;
        }
    }
}