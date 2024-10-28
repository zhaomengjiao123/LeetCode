// 移除元素  原地移除所有等于val的元素



#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// 双指针 删除 
int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    if (n==0)
    {
        return 0;
    }

    int count = 0;
    int start=0,end=0;

    while (end<n)
    {
        if (nums[end]!=val)
        {
            swap(nums[start], nums[end]);
            start++;
            end++;
        }else{
            end++;
        }
        
    }
    return start;
    
    
        
    

    
    
    
        
}

int main(){
    vector<int> nums = {
        0,4,4,0,4,4,4,0,2
    };

    int ans = removeElement(nums, 4);
    cout << ans <<endl;
    for (auto num:nums)
    {
        cout << num <<" ";
    }
    
}