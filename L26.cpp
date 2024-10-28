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

// 删除有序数组中的重复项  2刷
// 非严格递增的数组，原地删除重复出现的元素，让他只出现一次

int removeDuplicates2(vector<int>& nums) {

    int n = nums.size();
    if (n==0||n==1)
    {
        return n==0?0:1; 
    }

    // 定义左右2个指针
    int l=0, r=1;
    while (r<n)
    {
        if (nums[l]==nums[r])
        {
            r++;
        }else if(nums[l]!=nums[r]){
            // 从下一个位置开始复制，因为要保持有一个
            // 复制到后一个位置上，如果本身相邻，这个就相当于自己复制，不会有问题
            nums[l+1]=nums[r];
            l++;
            r++;
        }
        
    }

    return l+1; // 为什么这里和之前的不一样要+1?因为这个位置本身也是要算的 
    
    

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