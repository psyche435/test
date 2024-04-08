#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int row,col,left,right,top,buttom,i,j;
    vector<int> ans;
    row=matrix.size();
    col=matrix[0].size();
    left=0;
    right=col-1;
    top=0;
    buttom=row-1;
    i=0;
    j=0;
    while(left<=right&&top<=buttom)
    {
        for(j=left;j<=right;j++)
        {
            
            ans.push_back(matrix[top][j]);
        }
        for(i=top+1;i<=buttom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        if(left<right&&top<buttom)//注意这里是if而不是while，这里有这个if是为了避免到最后一层没有环形时继续转弯
        {
            for(j=right-1;j>=left;j--)
            {
                ans.push_back(matrix[buttom][j]);
            }
            for(i=buttom-1;i>top;i--)
            {
                ans.push_back(matrix[i][left]);
            }
        }
        top++;
        left++;
        right--;
        buttom--;;
    }
    for(auto x:ans)
    {
        cout<<x<<endl;
    }
}