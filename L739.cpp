// 每日温度

#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<sstream>
using namespace std;


// 下一个温度更高的天气出现在几天之后
// 遍历的形式   超时！！
// vector<int> dailyTemperatures(vector<int>& temperatures) {
//     int  n = temperatures.size();
//     // 找到当前的数组的最大值
//     int max = *max_element(temperatures.begin(), temperatures.end());
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         int maxNext = i;
//         // 寻找下一个比当前数大的数的位置
//         bool flag = false; // 标记是否找到最大值
//         // 如果当前已经是最大值了，后面不会有比这个大的了，直接返回
//         if (temperatures[i]!=max)
//         {
//              while (maxNext<n)
//         {
//             if (temperatures[maxNext]>temperatures[i])
//             {
//                 flag=true;
//                 break;
//             }
//             maxNext++;    
//         }
            
//         }
        
       
//         // 判断最后的临界条件
//        if (flag)
//        {
//         ans.push_back(maxNext-i);
//        }else{
//         ans.push_back(0);
//        }
       
       
        
//         cout<< "maxN:"<<maxNext <<" i:"<<i<<endl;        
//     }
//     return ans;
    
        
// }

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> nextHighTmps(n);
    for (int i = n-2; i >=0; i--)
    {
        // 前一个 标记后面大的数值的位置
        int k = i+1;
        while (temperatures[k]<=temperatures[i]&&nextHighTmps[k]!=0)
        {
            // ！=  意味着后面还有更大的数
            // 前一个值< 当前的值，那么当前的值是大的
            k = k + nextHighTmps[k];
        }
        if (nextHighTmps[k]==0&&temperatures[k]<=temperatures[i])
        {
            // 后面没有比当前值更大的了  就不用管了
            continue;
        }
        nextHighTmps[i]=k-i;
        
        
    }
    return nextHighTmps;
}

int  main(){
    vector<int> nums;
    string s;
    getline(cin, s);
    stringstream ss(s);

    int num;
    while (ss>>num)
    {
        nums.push_back(num);
    }
    vector<int> ans = dailyTemperatures(nums);

    for (auto &num : ans)
    {
        cout << num << " ";
    }
    
    
}