// 比较版本号  修订号比较少的 缺失的位数 视为0，并且忽视前导0


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

int compareVersion(string version1, string version2) {

    // 将两个字符串 按照. 分割
    vector<int> v1, v2;
    string tmp1, tmp2;
    stringstream ss1(version1);
    stringstream ss2(version2);
    while (getline(ss1, tmp1, '.'))
    {
        // 转换为数字存储
        v1.push_back(stoi(tmp1));
    }
    while (getline(ss2, tmp2, '.'))
    {
        v2.push_back(stoi(tmp2));
    }
    int s1 = v1.size();
    int s2 = v2.size();
    if (s1>=s2)
    {
        // 以s2的长度遍历
        for (int i = 0; i < s2; i++)
        {
            if (v1[i]>v2[i])
            {
                return 1;
            }else if (v1[i]<v2[i])
            {
                return -1;
            }
            
            
        }
        // 遍历完了检查剩下的是不是有大于0的数
        for (int i = s2; i < s1;i++)
        {
            if (v1[i]>0)
            {
                return 1;
            }
            
        }
        
        
    }else{
         // 以s1的长度遍历
        for (int i = 0; i < s1; i++)
        {
            if (v1[i]>v2[i])
            {
                return 1;
            }else if (v1[i]<v2[i])
            {
                return -1;
            }
            
            
        }
        // 遍历完了检查剩下的是不是有大于0的数
        for (int i = s1; i < s2;i++)
        {
            if (v2[i]>0)
            {
                return -1;
            }
            
        }
        
    }

    return 0;
    
    
    
    

        
}

int main(){
    string version1, version2;
    cin>>version1;
    cin>>version2;

    int ans = compareVersion(version1,version2);
    cout << ans << endl;
}