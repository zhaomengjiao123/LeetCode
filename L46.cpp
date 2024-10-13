// 全排列

// 返回所有可能得排列
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len)
{
    // 如果所填的位置是最后一个位置  代表所有的数都尝试过了  因此直接返回
    if(first==len){
        res.emplace_back(output);
        return;
    }

    for (int i = first; i < len; i++)
    {
        // 这些是需要尝试的数
        // 动态维护数组
        swap(output[i], output[first]);
        // 递归填写下一个数
        backtrack(res, output, first+1, len);
        // 撤销  这个操作
        swap(output[i], output[first]);
    }
    

}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtrack(ans, nums, 0, (int)nums.size());
    return ans;

}