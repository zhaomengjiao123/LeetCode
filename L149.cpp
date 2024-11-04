// 直线上 最多的点数
// 最多多少点在同一个直线上？


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
#include<unordered_map>
using namespace std;

// 思路：在同一个直线上的点，斜率是相同的 y=kx+c k=(y-c)/x
// 思路：三点确定一条直线 经过i,j,k的直线， i,j 的斜率 和 i,k的斜率相同
// 用哈希表存储 斜率作为key?  这样不好，因为涉及到除法，可能有误差
// 所以key 用y/x表示，但是要化简 x/gcd(x,y),y/gcd(x,y)

// 求最大公约数

int gcd(int a,int b){
    if (b==0)
    {
        return a;
    }else{
        return gcd(b,a%b);
    }
    
}


int maxPoints(vector<vector<int>>& points) {
    int n = points.size();

    if (n<=2)
    {
        return n; // 如果是两个点 一定实在同一条直线上
    }

    int ret = 0;
    // 枚举每一个点 i
    for (int i = 0; i < n; i++)
    {
        unordered_map<string,int> mp;
        int t=2;
        // 遍历 i之后的点与i点的斜率
        for (int j = i+1; j < n; j++)
        {
            int xcha = points[j][0]-points[i][0];
            int ycha = points[j][1]-points[i][1];
            // 因为输入中不存在两个相同的点  
            // 因此不存在  除数为0的情况
            // 约分 求最大公约数
            int yue = gcd(xcha, ycha);
            string key = to_string(xcha/yue)+""+to_string(ycha/yue);
            cout << key <<endl;
            mp[key]++;
            t=max(t,mp[key]+1); // 在本次遍历中的最大值

        }
        ret = max(ret,t);
         
    }

    return ret;
        
}


int main(){
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    int ans = maxPoints(points);
    cout << ans << endl;
}