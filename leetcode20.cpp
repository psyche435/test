#include<iostream>
#include<vector>
using namespace std;  
int main()      //旋转矩阵；
{
    vector<vector<int>> matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n=matrix.size();
    int i,j;
    auto matrix_new=matrix;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            matrix[j][n-i-1]=matrix_new[i][j];
        }
    }
    for(auto x:matrix)
    {
        for(auto y:x)
        {
            cout<<y<<'\t';
        }
        cout<<'\n'<<endl;
    }

}