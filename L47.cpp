// 返回一个可以包含重复数字的序列的  全排列

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>
#include<unordered_set>
using namespace std;

vector<vector<int>> ans;
vector<int> tmp; /// 暂时存储每次的排列
vector<bool> visited;

void dfs(vector<int>& nums, int index){
    if (tmp.size()==nums.size()||index>=nums.size())
    {
        // 找到一个集合  入队
        ans.push_back(tmp);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        // 查看当前值 是否被访问了？
        // 为了避免重复 每次填入的时候查看是不是已经填过了
        // 如果已经访问过  或者  前一个重复的数
        // 保证每次取的是 从左往右第一个没有被填过的数
        // 限制两个重复的数的读取顺序，一定是从左往右读一次，那么如果之前的那个相同的数
        // 还灭又被访问过，就不可以先访问当前这个相同的数
        if (visited[i]||(i>0&&nums[i]==nums[i-1]&&!visited[i-1]))
        {
            continue;
        }
        
            // 尝试将当前值放到这个位置
            tmp.push_back(nums[i]);
            // 标记为已访问
            visited[i]=true;
            // 探索下一个
            dfs(nums, index+1);
            // 回溯
            tmp.pop_back();
            visited[i]=false;
        
        

    }
    
    

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    
    if (n==1)
    {
        res.push_back({nums[0]});
        return res;
    }
    // 初始化访问数组
    visited.resize(n,false);
    // 排序  保证重复的数是相邻的
    sort(nums.begin(),nums.end());
    dfs(nums, 0);
    // 构建答案
    for (auto cur:ans)
    {
        res.push_back(cur);
    }
    return res;
    
    
        
}

int main(){
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = permuteUnique(nums);

    for (auto num:ans)
    {
        for (auto cur:num)
        {
            cout << cur << " ";
        }
        cout <<endl;
        
    }
    
}