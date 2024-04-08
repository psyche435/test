#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    for(vector<int>::iterator it=num.begin();it!=num.end();it++)
    {
        cout<<* it<<endl;
    }
    return 0;
}