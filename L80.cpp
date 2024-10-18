// 删除有序数组中的重复项
// 要求原地删除  出现多余两次的元素只出现两次

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n==1||n==2)
    {
        return n==1?1:2;
    }
    // 官方的思路是检查两个元素以前
    int p = 2, q = 2;
    while (q<n)
    {
       if (nums[p-2]!=nums[q])
        {
            /* code */
            nums[p]=nums[q];
            p++;

        }
        q++;
        
        
    }
    return p;
    

    


        
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
