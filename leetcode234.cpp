#include<iostream>
#include<vector>
#define Maxsize 100
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(0):val=0,next=NULL{};
    ListNOde(int n):val=0,next=NULL{};
};
void CreatList(ListNode *&p,vector<int> nums,int n)
{
    ListNode *p1;
    for(int i=0;i<n;i++)
    {
        p1=(ListNode *)malloc(sizeof(ListNode));
        p1->val=nums[i];
        p->next=p1;
    }
}
int main()
{
    vector<int> nums={1,2,3,2,1};
    int n=nums.size;
}