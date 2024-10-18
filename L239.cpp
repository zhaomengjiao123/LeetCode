// L239  滑动窗口最大值
// 只能看到滑动窗口内的数字  每次向右滑动一位
// 求滑动窗口中的最大值？


// 怎么第一想法就是暴力 -_-||

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 维护一个滑动窗口的最大值，每次向右滑动的时候，更新
    // 因为k<=length
    int n = nums.size();
    // 大根堆  优先队列 如果活动窗口已经划过了这个值 删除
    priority_queue<pair<int, int>> q; // 其中一个存储  值的位置
    // 先存入第一个哈东窗口
    for (int i = 0; i < k; i++)
    {
        q.emplace(nums[i],i);
    }
    // 因为是大根堆  所以堆顶的元素就是最大值
    
    
    
    vector<int> ans;
    ans.push_back(q.top().first);
    // 开始遍历
    for (int i = k; i < n; i++)
    {
        // 把当前元素放入堆中
        q.emplace(nums[i],i);
        // 检查有没有滑动窗口已经划过的值 弹出  其实只要最大值 不是已经划过的就可以
        // 我们不关心其他的值
        while (q.top().second<=i-k)
        {
            q.pop();
        }
        ans.push_back(q.top().first);
        
    }
    return ans;

}

int main(){
    string s;
    vector<int> nums;
    int k;
    getline(cin, s);
    cin >> k;

    stringstream ss(s);

    int num;

    while (ss>>num)
    {
        nums.push_back(num);
    }
    vector<int> ans = maxSlidingWindow(nums, k);

    for (auto num:ans)
    {
        /* code */
        cout << num <<" ";
    }
    
    
}