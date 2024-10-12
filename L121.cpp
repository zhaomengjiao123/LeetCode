// 股票 最大利润
// 遍历一次  每次都假设是今天卖出
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


int maxProfit(vector<int>& prices) {
    int lirun = INT16_MIN;
    int minPrice = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        lirun = max(lirun, prices[i]-minPrice);
        minPrice=min(minPrice, prices[i]);
    }
    return lirun;
    

}

int main(){
    vector<int> nums;
    string s;
    getline(cin, s);

    int num;
    stringstream ss(s);
    while (ss >> num)
    {
        nums.push_back(num);
    }

    int ans = maxProfit(nums);
    cout << ans << endl;
    

}