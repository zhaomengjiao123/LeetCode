/**
 * @file L136.cpp 只出现一次的数字  找到数组中只出现一次的数字
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 遍历  维护一个只出现一次的数字的值
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;
// 哈希
int singleNumber(vector<int>& nums) {
    unordered_map<int,int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
        
        
    }
    for (auto it = hash.begin(); it!=hash.end(); it++)
    {
        if (it->second==1)
        {
            return it->first;
        }
        
    }    

}
// 官方最好的解法：位运算  异或~~~~
int main(){
    vector<int> nums;

    string s;
    getline(cin, s);
    stringstream ss(s);

    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    cout << singleNumber(nums)<<endl;
    
}