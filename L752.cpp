// 打开转盘锁

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

// 模拟转盘的两个函数
// 向前转动一个  前一个相邻的字符？
char num_prev(char x){
    if (x=='0')
    {
        // 前一个是9
        return '9';
    }else{
        return x-1;
    }
    
}
// 返回转盘上的下一个数字
char num_next(char x){
    // 9的下一个是0
    if (x=='9')
    {
        return '0';
    }else{
        return x+1;
    }
    
}

// 得到下一个能够到达的组合
vector<string> get_next(string& status){
    vector<string> ret;
    // 因为一共四位数字
    for (int i = 0; i < 4; i++)
    {
        char num = status[i]; // 状态转换的话就是目前的这四位数，每一位可以换成别的
        status[i]=num_prev(num);//换成前一个
        // 放入
        ret.push_back(status);
        //换成下一个
        status[i]=num_next(num);
        ret.push_back(status);
        // 回溯，放回去
        status[i]=num;
    }
    return ret;
    
}

// BFS  搜索可以通过转盘达到的下一个组合
int openLock(vector<string>& deadends, string target) {
    // 如果目标值本身不需要转动
    if (target=="0000")
    {
        return 0;
    }
    // 存储死亡组合，方便验证

    unordered_set<string> dead(deadends.begin(),deadends.end());
    // 如果初始值就是死亡组合，直接返回 不可能有结果
    if (dead.count("0000"))
    {
        return -1;
    }
    // 队列  广度优先搜索
    queue<pair<string,int>> q; //字符串，到达这个字符串的步数
    q.emplace("0000",0);

    // 标记数组，看是否遍历过
    unordered_set<string> visited = {"0000"};

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        string cur_status = cur.first;
        int cur_step = cur.second;
        // 遍历下一步能达到的组合
        for (auto&& next_status:get_next(cur_status))
        {
            // 判断是否访问过，是否是死亡组合？
            if (!visited.count(next_status)&&!dead.count(next_status))
            {
                // 是否是目标值？
                if (next_status==target)
                {
                    return cur_step+1;
                }
                //添加到队列
                q.emplace(next_status,cur_step+1);
                // 标记为已访问
                visited.insert(next_status);
                
            }
            
        }
        
    }

    return -1;
    
    
    
        
}