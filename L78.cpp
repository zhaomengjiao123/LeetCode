// 子集

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


// 迭代枚举子集  每个的构成
vector<vector<int>> ans;
vector<int> t;
void dfs(int cur, vector<int>& nums){
    // cur 表示当前的位置 n 表示 序列的总长度
    if (cur==nums.size())
    {
        // 记录答案
        // 遍历到最后的了  放入答案
        ans.push_back(t);
        return;

    }
    // 否则的话就继续构建当前这个子集
    // 当前这个位置有两个选择， 放入或者不放入
    t.push_back(nums[cur]);
    // 遍历下一个
    dfs(cur+1, nums);
    // 不放入
    t.pop_back();
    dfs(cur+1, nums);

    
}

vector<vector<int>> subsets(vector<int>& nums) {
    dfs(0, nums);
    return ans;

}

int main(){
    string s;
    vector<int> nums;
    getline(cin, s);

    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    vector<vector<int>> ans = subsets(nums);

    for (auto &a:ans)
    {
        for (auto &b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    
}