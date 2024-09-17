/**
 * @file L347.cpp  找出数组中出现频率 前 K 高的元素
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 个人思路   ： 如果使用优先队列的做法，先遍历一遍  存储出现的频率 然后找到  前K高

#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 需要自己定义一个比较算法
static bool cmp(pair<int, int>& m ,pair<int, int>& n){
    return m.second > n.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    // 先遍历一遍数组 存储出现的额频率  键 是nums i 对应的值时出现的频率
    unordered_map<int, int> mp;
    for (auto &num:nums)
    {
        /* code */
        // 如果存在
        if (mp.find(num)!=mp.end())
        {
            /* code */
            mp[num] = mp[num] + 1;

        }else{
            mp[num] = 1;

        }
        
    }
    // 构建优先级队列 小根堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
    // 两个队列  一个放元素
    vector<int> ans;
    // 遍历哈希表
    for (auto& [num, count] : mp)
    {
        /* code */
        if (q.size()<k)
        {
            /* code */
            // 还没满
            q.emplace(num, count);
        }else if (q.top().second<count)
        {
            /* code */
            q.pop();
            q.emplace(num, count);
        }    
    }
    while (!q.empty())
    {
        /* code */
        ans.push_back(q.top().first);
        q.pop();
    }
    

    return ans;

}

int main(){
    string input;
    int k;

    getline(cin, input);
    cin >> k;

    vector<int> nums;
    int num;

    stringstream ss(input);
    while (ss >> num)
    {
        /* code */
        nums.push_back(num);
    }
    
    vector<int> ans = topKFrequent(nums, k);

    for (auto &num: ans)
    {
        /* code */
        cout << num << " ";
    }

    cout << endl;
    
}

