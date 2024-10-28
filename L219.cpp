// 存在重复元素  判断给定的数组中是不是有两个值相同的元素，并且相隔小于等于k

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<sstream>
using namespace std;



bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // 思路：直接哈希遍历  存储 计算<=k
    int n = nums.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        // 不存在的时候插入
        if (mp.find(nums[i])==mp.end())
        {
            mp[nums[i]]=i;
        }else{
            if (mp[nums[i]]!=i && abs(i-mp[nums[i]])<=k)
            {
                return true;
            }else{
                mp[nums[i]]=i; //更新索引，  因为有可能出现了好几次  只有一次是满足要求的
            }
            
        }
        
    }

    return false;
    
        
}

int main(){

    vector<int> nums = {1,0,1,1};
    int k = 1;
    bool ans = containsNearbyDuplicate(nums, k);
    cout << ans <<endl;

}