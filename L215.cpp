/**
 * @file L215.cpp 数组中第 K 个最大的数
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * @ 维护一个长度为  K的 优先队列  
 * 
 * @param nums 
 * @param k 
 * @return int 
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<sstream>
using namespace std;

// 找第K大的数，用小跟堆，找第K小的数，用大根堆
int findKthLargest(vector<int>& nums, int k) {
    // 创建优先队列  队列：先进先出  默认是leess   大根堆，是最大值优先，，greater是小跟堆最小值优先
    priority_queue<int, vector<int>, greater<>> q; // 指定优先队列是从小到大排序
    // 遍历数组  如果新数比头元素要大，那么更新
    for (const auto &num:nums)
    {
        /* code */
        if (q.size()<k)
        {
            /* code */
            // 还不到k个元素  持续加入
            q.push(num);
        }else if (q.top() < num)
        {
            /* code */
            // 更新
            q.pop(); // 删除最后一个元素
            q.push(num);
        }
        
        
    }
    return q.top();
      
}

// 二刷 第K大的数  前面的元素用大根堆存储，维持大根堆的大小为K
int findKthLargest2(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<>> bigStk; // 默认是大根堆
    for (int i = 0; i < n; i++)
    {
        if (bigStk.size()<k)
        {
            bigStk.push(nums[i]);
        }else{
            if (bigStk.top()<nums[i])
            {
                bigStk.pop();
                bigStk.push(nums[i]);
            }
            
        }
        
    }
    return bigStk.top();
    
}

int main(){
    string input;
    int k;
    getline(cin, input);
    cin >> k;

    stringstream ss(input);
    int num;
    vector<int> nums;

    while (ss >> num)
    {
        /* code */
        nums.push_back(num);
    }

    int ans = findKthLargest2(nums ,k);

    cout << ans << endl;
    
}
