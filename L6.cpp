// Z字形变换

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


// 大佬思路：模拟， 转向标志位


string convert(string s, int numRows) {
    int n = s.size();
    // 判断特殊情况，如果一行 就不需要别的操作
    if (numRows==1)
    {
        return s;
    }
    vector<string> zs(numRows);
    // 行转向标志
    int flag = 1;
    // 重要！！！ 行下标索引
    int idex_row = 0;
    for (int i = 0; i < n; i++)
    {
        zs[idex_row].push_back(s[i]);
        idex_row = idex_row + flag;
        // 判断是否需要转向  在最后一行或者在第一行
        if (idex_row==numRows-1 || idex_row == 0)
        {
            flag = -flag;
        }
        
    }

    string ans ;
    for (auto &row:zs)
    {
        ans = ans + row;
    }
    return ans;
    
    
    
        
}

int main(){
    string s;
    cin>>s;
    int numRows;
    cin>>numRows;
    string ans = convert(s,numRows);
    cout<<ans<<endl;
}