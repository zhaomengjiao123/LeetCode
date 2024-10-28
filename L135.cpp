// 分糖果

// 计算所需要的最少的糖果数

// 每个人至少一个


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;


int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n==1)
    {
        return 1;
    }
    // 两次遍历，左规则一次，右规则一次
    vector<int> left(n);
    for (int i = 0; i < n; i++)
    {
        if (i>0 && ratings[i-1]<ratings[i])
        {
            left[i]=left[i-1]+1;
        }else{
            left[i]=1;
        }
        
    }
    vector<int> right(n);
    for (int i = n-1; i >=0; i--)
    {
        if (i<n-1 && ratings[i]>ratings[i+1])
        {
            right[i]=right[i+1]+1;
        }else{
            right[i]=1;
        }
        
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans + max(left[i],right[i]);
    }
    return ans;
    
    
    
    
    
        
}

int main(){
    vector<int> nums = {1,0,2};
    int ans = candy(nums);

    cout << ans << endl;
}