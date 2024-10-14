// 组合总和

// 给 无重复元素的  数组 使 数字和 未 target的不同组合  每个数字无限制

// 所有寻找可行解的问题 都使用 回溯
// 不含 剪枝的做法

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

// 对每一个数 可以选择跳过或者不跳过
// 不跳过的话，事实上 下一步还是搜索这个数 因为一个数  是可以无限制取用的
vector<vector<int>> ans;
vector<int> tmp; // 子集

void dfs(vector<int>& candidates, int target, int index){
    // 如果target已经达到了或者到末尾元素了  结束这次搜索
    if (target==0)
    {
        ans.emplace_back(tmp);
        return;
    }
    if (index>candidates.size()-1)
    {
        if (target==0)
        {
            ans.push_back(tmp);
        }
        return;
        
    }
    // 直接跳过当前数
    dfs(candidates, target, index+1);
    // 只有在剩余的target 大于 当前数的时候  才会下一个
    // 使用当前的数
    if (target-candidates[index]>=0)
    {
        target = target - candidates[index];
        tmp.push_back(candidates[index]);
         // 继续搜索这个位置
        dfs(candidates, target, index);
        tmp.pop_back();

    }
    
    
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
// 先判断特殊情况， 小于最小值  不可能实现
    int min = *min_element(candidates.begin(), candidates.end());
    if (target<min)
    {
        return ans;
    }

    // 正常情况下   dfs
    dfs(candidates, target, 0);
    return ans;
    
    
    
        
}


int main(){
    
    string s;
    getline(cin, s);
    int target;
    cin>> target;
    int num;
    vector<int> nums;
    stringstream ss(s);
    while (ss>>num)
    {
        nums.push_back(num);
    }

    vector<vector<int>> res = combinationSum(nums, target);
    for (auto vec:res)
    {
        for (auto num:vec)
        {
            cout << num << " ";
        }
        cout <<endl;
        
    }
    
    
}