// 最后一个单词的长度

// 返回给定字符串中最后一个单词的长度？

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

int lengthOfLastWord(string s) {
    stringstream ss(s);

    string single;
    vector<string> my;
    while (ss>>single)
    {
        my.push_back(single);
    }

    return my[my.size()-1].length();
    

        
}