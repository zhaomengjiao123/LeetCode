// IPO 从给定的项目中选择最多K个不同项目的列表，以最大化最终资本为目的  输出最终可以获得的资本


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<queue>
using namespace std;

// 比较函数的定义：希望大的优先级高 居勇小于，希望下小的优先级高 就用大于
struct Compare
{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
         if (a.first!=b.first)
    {
        return a.first>b.first;
    }else{
        return a.second<b.second;
    }
    }
};

struct Compare2
{
    // 比较函数：如果  a的优先级小于 b，函数应该返回true
    bool operator()(pair<int, int>& a, pair<int, int>& b){
         return a.second<b.second;
    }
};


int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        // 《资本。 利润》
        // 2个优先队列  比w小的按照利润 大到小  大根堆
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare2> q1;
        // 比 w大的资本的 就用小根堆，资本小的在前
        priority_queue<pair<int,int>, vector<pair<int, int>>, Compare> q2; 

        for (int i = 0; i < n; i++)
        {
            if (capital[i]<=w)
            {
                // 放到 大根堆
                q1.emplace(capital[i],profits[i]);
                cout <<"q1:"<< q1.top().first<<" "<<q1.top().second<<endl;
            }else{
                // 放到小根堆
                q2.emplace(capital[i],profits[i]);
            }
            
        }
        // 开始投资
        int ans = w;
        cout << q1.size()<<" "<<q2.size()<<endl;
        for (int i = 0; i < k; i++)
        {
            // 每次从 大根堆取出可以投资的最大利润的公司，然后删除它，然后维护这两个堆
            // 使大根堆<w，小跟堆>w
            if (!q1.empty()&&q1.top().first<=ans)
            {
                cout << q1.top().first<<" "<<q1.top().second<<endl;
                ans = ans + q1.top().second;
                q1.pop();
                // 维护这两个堆
                while (!q2.empty()&&q2.top().first<=ans)
                {
                    cout << "trans:"<<q2.top().first<<" "<<q2.top().second<<endl;
                    q1.push(q2.top());
                    q2.pop();
                }
                
            }
            
        }
        
       return ans;
        

        
}

int main(){
    string p;
    string c;
    getline(cin,p);
    getline(cin,c);
    int k;
    int w;
    cin>>k;
    cin>>w;
    vector<int> pros;
    vector<int> cap;
    
    stringstream ss1(p);
    int pnum;
    while (ss1>>pnum)
    {
        pros.push_back(pnum);
    }
    stringstream ss2(c);
    int cnum;
    while (ss2>>cnum)
    {
        cap.push_back(cnum);
    }

    int ans = findMaximizedCapital(k, w, pros, cap);
    cout << ans <<endl;
    
    
}