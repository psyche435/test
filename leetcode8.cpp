#include<iostream>
#include<math.h>
#include<vector>
#include<string>
using namespace std;
int main()
{
    string s="abcabcbb";
    //创建桶(数组)，设定128个元素对应0-127ASCII码值，全部赋0
    vector<int> m(128, 0);
        //存最大长度
    int maxlen = 0;
        //head表示窗口最左边的字母序号：如果出现重复的，比如两个相同的字母a，上一个a在桶里存的m[s[i]]是a+1表示a的下一个位置
        //那么第二个a出现时，head就=a+1也就是max(head,m[s[i]])，去除了窗口里上一个a，保证窗口里无重复字母
    int head = 0;
        //遍历字符串
    for (int i = 0; i < s.size(); i++) {
            //修改最左边的字母序号head
        head = max(head, m[s[i]]);
        cout<<"head:"<<head<<endl;
            //当前字母对应的ASCII码桶里存下一个位置(i+1)，用于更新head
        m[s[i]] = i + 1;
            //更新长度
        cout<<"m:"<<m[s[i]]<<endl;
        maxlen = max(maxlen, i - head + 1);
    }
    cout<<maxlen<<endl;
}