#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode():val(0),next(NULL){}
    ListNode(int n):val(n),next(NULL){}
};
int main()
{
    vector<int> nums={1,2,3,4,5};
    ListNode *node1=new ListNode();
    int n=nums.size();
    int i;
    for(i=0;i<n;i++)
    {
        ListNode *p=new ListNode(nums[i]);
        p->next=node1->next;
        node1->next=p;
        cout<<p->val<<endl;
    }
    ListNode *a=node1->next;
    while(a!=NULL)
    {
        cout<<a->val<<endl;
        a=a->next;
    }
}