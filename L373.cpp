// 查找 和最小的K对数字
// 给2个非递减排序的两个数组
// 找到和最小的K对数

// 和最小？贪心，第一个数是nums1中最小的，第二个数数nums2最小的，合起来肯定也最小
// 两个数组分别用 小根堆
// 因为每个数不限次取，所以每次取完，弹出两个数中比较大的那一个
// 思路错误

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<queue>
using namespace std;


struct Compare
{
    bool operation(vector<int>& nums1, vector<int>& nums2, pair<int, int>& a, pair<int, int>& b){
        return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
    }
};


vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };


        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(k,n); i++)
        {
            q.emplace(i,0); // 相当于填充大根堆，里面的位置，其中一个位置是数组的每个位置，另一个是0
        }
        while (k-->0&&!q.empty())
        {
            // 拿到  位置对
            auto [x,y] = q.top();
            q.pop();
            ans.emplace_back(initializer_list<int>{nums1[x],nums2[y]});
            // 相当于枚举右边界
            if (y+1<m)
            {
                q.emplace(x,y+1);
            }
            
        }

        return ans;
        
        



        
        
        


}

int main(){
    vector<int> n1 = {1,1,2};
    vector<int> n2 = {1,2,3};
    int k = 2;
    vector<vector<int>> ans = kSmallestPairs(n1,n2,k);
    for (auto n:ans)
    {
        for (auto num:n)
        {
            cout << num << " ";
        }
        cout <<endl;
        
    }
    
}