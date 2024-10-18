// 删除有序数组中的重复项

// 非严格递增  原地删除重复出现的数组，让每个元素只出现一次

#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    // 我的思路 删除一样的元素
    int n = nums.size();
    // 两个指针
    if (n==1)
    {
        return 1;
    }
    
    int p=0,q=1;
    while (q<n)
    {
        if (nums[p]==nums[q])
        {
            // q右移
            q++;
        }else if (nums[p]!=nums[q])
        {
            // 把 q复制到p+1上，并且p q持续右移
            nums[p+1]=nums[q];
            p++;
            q++;
        }
        
        
    }
    return p+1; // 数组长度 最后一位的下标+1
    

    
        
}


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

    int ans = removeDuplicates(nums);
    cout << ans <<endl;
    

}