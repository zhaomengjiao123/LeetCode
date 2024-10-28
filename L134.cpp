// 环路上有n个加油站 gas[i]升油
// 看是否可以环绕一周

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;



// 只有这个加油站所提供的油> 到下一个加油站所需要的油，那么这个站点才有可能作为出发点

// 操他妈的 超时了
// int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//     int n =gas.size();
//     vector<int> strat; // 存储可能作为出发点的站点
//     // 如果  所花费的油量>加油站提供的  就绝对不可能环绕一周
//     int sum_gas = 0;
//     int sum_cost=0;
//     for (int i = 0; i < n; i++)
//     {
//         sum_gas = sum_gas + gas[i];
//         sum_cost = sum_cost + cost[i];
//     }
//     // 判断
//     if (sum_cost>sum_gas)
//     {
//         return -1;
//     }
    
    
//     for (int i = 0; i < n; i++)
//     {
//         if (gas[i]>=cost[i] && gas[i]!=0)
//         {
//             strat.push_back(i);
//         }
        
//     }
    
//     // 从站点开始循环
//     for (int i = 0; i < strat.size(); i++)
//     {
//         // 当前站点
//         int station = strat[i];
        
//         int g = gas[station]-cost[station];
//         int cur = station + 1;
//         cur = (cur+n)%n;
//         int flag = true;
//         while ((cur+n)%n!=station)
//         {
//             cout << "当前所在站点："<<cur<<" 汽油值："<<g <<endl;
//             if (g+gas[cur]>=cost[cur])
//             {
//                 g = g + gas[cur] -cost[cur];
//                 cur++;
//                 cur = (cur+n)%n;
//             }else{
//                 flag = false;
//                 break;
//             }   
//         }
//         if (flag)
//         {
//             return station;
//         }  
//     }
//     return -1;    
    
        
// }

// 官方思想 如果从x到不了第一个到达不了的站点y，那么 xy之间的任一个站点都到达不了y的下一个站点
// 所以从0开始环绕，不行的话，就再从第一个到达不了的站点环绕
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0; // 从第一个站点开始环绕
    while (i<n)
    {
        int sum_gas = 0;
        int sum_cost = 0;
        int cnt = 0; /// 计算所能达到的站点的数量
        while (cnt<n)
        {
            int j = (i+cnt)%n;
            // 耗油计算
            sum_gas = sum_gas+gas[j];
            sum_cost=sum_cost+cost[j];
            // 判断能否到达 j+1？
            if (sum_cost>sum_gas)
            {
                break;
            }
            // 能到到
            cnt++;
            
        }
        if (cnt==n)
        {
            // 已经环绕一周了
            return i;
        }else{
            // 不能环绕一周  找到第一个不能到达的站点 的下一个站点（这就是为什么+1）
            i = i+cnt+1;
        }
        
        

    }
    return -1;
    

}

// 加油站 二刷
int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
    // 记住这个理论，如果y是从x开始不能到达的第一个站点
    // 那么xy之间的任意一个站点都不能达到y的下一个站点
    // 所以下一次尝试就从y的下一个站点开始
    int n = gas.size();
    int i = 0;
    while (i<n)
    {
        int sum_gas = 0;
        int sum_cost = 0;
        int cnt = 0; //可以达到的站点的数量
        while (cnt<n)
        {
            int j = (i+cnt)%n; 
            sum_cost = sum_cost + cost[j];
            sum_gas = sum_gas + gas[j];
            if (sum_gas<sum_cost)
            {
                break; // 到不了
            }
            // 能到
            cnt++;
            
        }
        // 查看能不能到
        if (cnt==n)
        {
            return i;
        }else{
            // 从不能到的站点的下一个站点开始尝试
            i = i + cnt +1;
        }
        
        
    }
    return -1;
    

}



int main(){
    vector<int> gas;
    vector<int> cost;

    string g;
    getline(cin, g);
    string c;
    getline(cin,c);

    stringstream gg(g);
    int gnum;
    while (gg >> gnum)
    {
        /* code */
        gas.push_back(gnum);
    }

    stringstream cc(c);
    int cnum;
    while (cc>>cnum)
    {
        /* code */
        cost.push_back(cnum);
    }

    int ans = canCompleteCircuit(gas, cost);
    cout << ans <<endl;
    
    
}