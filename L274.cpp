// 找到给定数组中中位数



#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

// 思路 ：好像就是找中位数啊

int hIndex(vector<int>& citations) {
    sort(citations.begin(),citations.end());
    int n = citations.size();
    int num = 0;
    for (int i = n-1; i >=0 ; i--)
    {
        if (citations[i]<=num)
        {
            return num;
        }else{
            num++;
        }
        
    }
    return num;
    
    
        
}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);

    stringstream ss(s);
    int num;
    while (ss>>num)
    {
        /* code */
        nums.push_back(num);
    }

    int ans = hIndex(nums);
    cout << ans <<endl;
    
}
