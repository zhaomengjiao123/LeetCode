// 最小的基因变化


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;



int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> cnt;
    unordered_set<string> visited;
    char keys[4] = {'A','C','G','T'};
    for (auto & w:bank)
    {
        cnt.emplace(w); // 将  字典存储到 哈希表中 方便查询
    }
    if (startGene==endGene)
    {
        return 0;
    }
    // 如果目标基因序列不在  哈希表中 肯定无法变换得到 直接返回
    if (!cnt.count(endGene))
    {
        return -1;
    }
    queue<string> q;
    q.emplace(startGene);
    // 标记为已访问
    visited.emplace(startGene);
    int step = 1;
    while (!q.empty())
    {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            string curr = q.front();
            q.pop();
            // 注意题目细节 开始基因序列和结束的基因序列都是8
            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    // 尝试所有可能的变化后的基因
                    if (keys[k]!=curr[j])
                    {
                        // 如果遍历到的某个字母不是合法的字母
                        string nex = curr;
                        nex[j]=keys[k]; // 变成合法的
                        if (!visited.count(nex)&&cnt.count(nex))
                        {
                            // 如果构造出来的这个基因序列没有被访问过
                            // 并且还是一个合法的基因序列
                            if (nex==endGene)
                            {
                                return step;
                            }
                            q.emplace(nex);
                            visited.emplace(nex);
                            
                        }
                        

                    }
                    
                }
                
            }
            
        }
        step++;

        
    }

    return -1;
    
    
    
    
    
        
}

int main(){
    string strat = "AACCGGTT", end = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};
    int ans = minMutation(strat, end, bank);
    cout << ans << endl;
}