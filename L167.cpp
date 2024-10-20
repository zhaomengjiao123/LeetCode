// 两数之和  输入有序数组
// 数组已经按非递减顺序排列

// 等一下  好像是  二分查找？


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    vector<int> ans;

    if (n==2)
    {
        ans.push_back(numbers[0]+1);
        ans.push_back(numbers[1]+1);
        return ans;
    }


    
    for (int i = 0; i < n; i++)
    {
        int cur = target - numbers[i];
        int left = i+1, right=n-1;
        while (left<=right)
        {
            int mid = (right-left)/2+left;

            if (numbers[mid]==cur)
        {
            
            ans.push_back(i+1);
            ans.push_back(mid+1);
            return ans;
        }else if (numbers[mid]>cur)
        {
            // 想要的值在左边
            right = mid-1;
        }else{
            // 想要的值在右边
            left = mid + 1;
        }
        }
    }
    
        
}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);

    int target;
    cin >> target;

    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }

    vector<int> ans = twoSum(nums, target);

    for (auto i:ans)
    {
        /* code */
        cout << i <<" ";
    }
    
    
}