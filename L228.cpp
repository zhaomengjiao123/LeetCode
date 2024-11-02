// 汇总区间
// 一个无重复有序的数组

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> ans;
    if (n==0)
    {
        return ans;
    }
    if (n==1)
    {
        ans.push_back(to_string(nums[0]));
        return ans;
    }

    int i = 0;
    int j = 1;
    while (j<n)
    {
        while (j<n&&nums[j-1]==nums[j]-1)
        {
            j++;
        }
        cout << i <<" "<<j<<endl;
        if(i==j-1){
            ans.push_back(to_string(nums[i]));
            cout<<nums[i]<<endl;
        }else{
            string tmp = to_string(nums[i])+"->"+to_string(nums[j-1]);
            ans.push_back(tmp);
            cout<<tmp<<endl;
        }
        i=j;
        if (j+1>=n)
        {
           ans.push_back(to_string(nums[i])); 
            cout<<nums[i]<<endl;

        }
        j++;
        

        
    }

    return ans;
    
    
    
        
}

int main(){
    vector<int> nums = {0,1,2,4,5,7};
    vector<string> ans = summaryRanges(nums);
}