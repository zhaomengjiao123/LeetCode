// 长度最小的子数组

// z找到数组中满足和>=target的长度最小的子数组


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int ans = INT_MAX;
    int n = nums.size();
    queue<int> q;
    int cur = 0;
    int i=0;
    bool flag = false;
    while(i<n)
    {
        // 每个做  滑动窗口的第一个
        while (cur<target && i<n)
        {
            cur = cur + nums[i];
            q.push(nums[i]);
            i++;
        }
        if (cur>=target)
        {
        flag = true;
        }
        
        while (cur>=target)
        {
            // 记录当前长度
            ans = min(ans, (int)q.size());
            cout << " pop :" << q.front()<<endl;
            cur = cur - q.front();
            q.pop();

        }
        
       
    }
    if (!flag)
    {
        return 0;
    }
   
    
    return ans;
    
    
    

        
}

int main(){
    string s;
    getline(cin, s);
    vector<int> nums;
    int target ;
    cin >> target;

    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    
    int ans = minSubArrayLen(target, nums);

    cout << ans <<endl;
}