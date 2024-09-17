/**
 * @file L3.cpp 无重复字符的最大子串
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<unordered_set>
#include<string>

using namespace std;


// 找出给定的字符串中不含重复字符的最长子串   滑动窗口
int lengthOfLongestSubstring(string s) {
    // 左右两个指针
    int left = 0;
    int right = -1;
    // 必须初始化为0  因为有可能是空字符串
    int length = 0;
    unordered_set<char> mystr;

    int  n = s.size();
    // 从左向右遍历
    for (int i = 0; i < n; i++)
    {
        //同时左指针每次向右移动一个
        if (i!=0)
        {
            /* code */
            // 把哈希表中这个字符移除
            mystr.erase(s[i-1]);
        }
        
        /* code */
        // 右指针不断地向右移动，并且右指针的下一个不为重复的字符
        while (right+1 < n && !mystr.count(s[right+1]))
        {
            /* code */
            // 下一个字符符合条件，因此将其插入到哈希表中 右指针也不断地移动
            mystr.insert(s[right+1]);
            right++;
        }
        // 每次都更新最长的长度
        length = max(length, right-i+1);
        

    }
    return length;
    



}

int main(){
    string s;
    cin >> s;
    int ans = lengthOfLongestSubstring(s);
    cout<<ans<<endl;

}

