// 跳跃游戏 判断能否达到最后一个下标
// 遍历一次  维护一个最远的位置
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

bool canJump(vector<int>& nums) {
    int n =nums.size();
    int maxFar = 0;
    for (int i = 0; i < n; i++)
    {
        // 先判断当前位置是否可达
        if (i<=maxFar)
        {
            // 可达 更新最远位置
            maxFar = max(maxFar, i + nums[i]);
        }else{
            continue;
        }
        
    }
    if (maxFar>=n-1)
    {
        return true;
    }
    return false;
    
    

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
     bool ans = canJump(nums);
     cout << ans << endl;
}