// 找到所有的数对距离中  第K小的

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
using namespace std;


// 思路是双指针+二分？  排序+二分
// 我们需要先找到第K小的距离是多少
// 肯定是 0~数组中的最大值-最小值之间的一个数

// lower_bound()：在给定的区间中查找第一个不小于给定值的值的位置
int smallestDistancePair(vector<int>& nums, int k) {
    // 先给数组排序
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int left = 0, right = nums[n-1]-nums[0];
    // 二分查找第K小的数对距离
    while (left<=right)
    {
        int mid = (right-left)/2 + left;
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            // 目的是查找所有数对距离小于mid的所有数对的数目
            //枚举 每个数对的左端点，mid > num i - numj   num i > num j - mid
            // mid <= num i - numj  num i >= mid-numj
            // 找到右端点 i 的位置
            int i = lower_bound(nums.begin(),nums.begin()+j, nums[j]-mid) - nums.begin();
            cout << i << endl;
            cnt = cnt + (j-i);

        }
        // 如果  <mid 的数对距离的数对数量多余了k，那么说明第k小的应该在左边
        if (cnt>=k)
        {
            right=mid-1;
        }else{
            left = mid+1;
        }
        
        
    }
    return left;
    
        
}

int main(){
    vector<int> nums = {1,3,1};
    int k = 1;

    int ans = smallestDistancePair(nums, k);

    cout << ans <<endl;
}