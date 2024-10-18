// 环路上有n个加油站 gas[i]升油
// 看是否可以环绕一周

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;



// 只有这个加油站所提供的油> 到下一个加油站所需要的油，那么这个站点才有可能作为出发点

// 操他妈的 超时了
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n =gas.size();
    vector<int> strat; // 存储可能作为出发点的站点
    for (int i = 0; i < n; i++)
    {
        if (gas[i]>=cost[i] && gas[i]!=0)
        {
            strat.push_back(i);
        }
        
    }
    
    // 从站点开始循环
    for (int i = 0; i < strat.size(); i++)
    {
        // 当前站点
        int station = strat[i];
        
        int g = gas[station]-cost[station];
        int cur = station + 1;
        cur = (cur+n)%n;
        int flag = true;
        while ((cur+n)%n!=station)
        {
            cout << "当前所在站点："<<cur<<" 汽油值："<<g <<endl;
            if (g+gas[cur]>=cost[cur])
            {
                g = g + gas[cur] -cost[cur];
                cur++;
                cur = (cur+n)%n;
            }else{
                flag = false;
                break;
            }   
        }
        if (flag)
        {
            return station;
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