// 统计树种好节点的数量


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>
#include<unordered_map>
using namespace std;

int dfs(vector<vector<int>>& mp, int& ans,int key, int parent){
    bool valid = true;
    int treeSize = 0;
    int subTreeSize = 0;
    // 找到节点的子节点
    for (int child:mp[key])
    {
        //跳过父节点？因为是邻接 的
        if (child!=parent)
        {
            // 查看子树的节点的数目
            int size = dfs(mp, ans, child, key);
            // 设置子树的大小
            if (subTreeSize==0)
            {
                // 第一次初始化
                subTreeSize=size;
            }else if(subTreeSize!=size){
                // 不是第一次的话 需要判断 是否和之前的字数大小条相同
                valid = false; // 不是好节点
            }
            // key这个树的整体大小
            treeSize = treeSize + size;
            
        }
        
    }
    // 如果是好节点
    if (valid)
    {
        ans++;
    }
    return treeSize+1; // 加上key这个根节点  
};

int countGoodNodes(vector<vector<int>>& edges) {
    // 保存图？邻居节点
    // 节点的数量比边多一个
    int n = edges.size()+1;
    // 构建邻接表
    vector<vector<int>> g(n);
    for (auto& egde:edges)
    {
        g[egde[0]].push_back(egde[1]);
        g[egde[1]].push_back(egde[0]);
    }
    
    // 用哈希表超时了
    // unordered_map<int,vector<int>> mp;
    // for (int i = 0; i < edges.size(); i++)
    // {
    //     mp[edges[i][0]].push_back(edges[i][1]);
    //     // mp[edges[i][1]].push_back(edges[i][0]);
    // }
    int ans = 0; // 记录好节点的数量
    dfs(g,ans,0,-1);
    return ans;
    

        
}

int main(){
    vector<vector<int>> nums = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    int ans = countGoodNodes(nums);
    cout << ans <<endl;
}