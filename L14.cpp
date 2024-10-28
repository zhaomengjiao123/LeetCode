// 寻找  最长公共前缀

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;



string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();

    // 第一个想法：暴力遍历
    string ans = "";
    if (n==0)
    {
        return ans;
    }
    if (n==1)
    {
        return strs[0];
    }

    // 把字符串按照长度排序
    sort(strs.begin(), strs.end(), [](string& a, string& b){
        return a.size()<b.size();
    });

    for (int i = 0; i < strs[0].size(); i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (strs[j][i]!=strs[0][i])
            {
                if (i==0&&j<n-1)
                {
                    return "";
                }else{
                    return strs[0].substr(0,i);
                }
                
            }
            
        }
        
    }

    return strs[0];
    
    
    

        
}

int main(){
    vector<string> strs = {
        "dog","racecar","car"
    };

    string ans = longestCommonPrefix(strs);
    cout << ans << endl;
}