// 跳跃游戏2
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// 因为题目说 测试用例一定可以到达 n-1  所以不必测试是否可以到达
int jump(vector<int>& nums) {
    // 每次都泰岳最大 只要maxFar >= n-1 就可以了
    int minJump = 0;
    int maxFar = 0;
    // 右边界
    int end = 0;
    int n = nums.size();
    // 因为一定可以达到
    for (int i = 0; i < n-1; i++)
    {
        if (maxFar>=i)
        {
            // 当前位置可达
            // 更新最远可达位置
            maxFar = max(nums[i]+i, maxFar);
            if (i==end)
            {
                // 到了可右边界
                end = maxFar;
                // 为什么到了右边节就要跳呢？因为再到下一个位置就必须跳一次了，上次只能跳到这里
                minJump++;
            }
            

        }
    }
        
        
       
    return minJump;
    

}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);

    stringstream ss(s);
    int num;
    while (ss>> num)
    {
        nums.push_back(num);
    }
    int ans = jump(nums);
     cout << ans << endl;
}