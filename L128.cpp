/**
 * @file L128.cpp 最长的连续序列
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<sstream>
using namespace std;

// 找到最长的连续序列，在原数组中可以不连续
int longestConsecutive(vector<int>& nums) {
        // 使用哈希解决
        // unordered_set  值唯一性   unorderded_map 键唯一性
        unordered_set<int> num_set;
        // 现将数组中的所有值 都存储到 哈希表中
        for (const int& num :nums)
        {
            /* code */
            num_set.insert(num);
        }

        // 这个最长数组的长度
        int longestStreak = 0;

        for (const int& num: num_set)
        {
            /* code */
            // 先判断这个数有么有已经存在的序列了
            if(!num_set.count(num-1)){
                // 如果已经存在，就说明这个数已经属于某个序列了，不必再遍历。跳过
                // 这个是不存在的情况，以当前的数为起点遍历
                // 当前一个数不存在的时候，就以当前的数为起点
                int currentNum = num;
                // 当前的这个长度
                int currentStreak = 1;
                // 遍历整个set，直到下一个数不存在
                while (num_set.count(currentNum+1))
                {
                    /* code */
                    //更新当前的数值
                    currentNum = currentNum + 1;
                    currentStreak = currentStreak + 1;
                }
                // 更新最长的值
                longestStreak = max(longestStreak, currentStreak);
                
            }

        }
        return longestStreak;

}

int main(){
    string input;
    vector<int> nums;

    getline(cin, input);

    // 使用输入流处理
    stringstream in(input);
    int number;
    while (in >> number)
    {
        /* code */
        nums.push_back(number);
    }

    for (const auto& n : nums)
    {
        /* code */
        cout << n << " ";
    }
    

    int ans = longestConsecutive(nums);

    cout<< "最长序列长度是："<<ans<<endl;
    


}