// 给两个整数 n k 返回【1，n】所有可能的k个数的组合？


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;


// 回溯？
vector<int> tmp;
vector<vector<int>> ans;

void dfs(int cur, int k,int n){
    if (tmp.size()==k)
    {
        ans.push_back(tmp);
        return;
    }
    if (tmp.size()>k||cur>n)
    {
        return;
    }
    
    
         // 在当前位置放下一个数
        tmp.push_back(cur);
        // 探索下一个位置，放下一个数
        dfs(cur+1,k,n);
        tmp.pop_back();
        // 不用当前这个数
        dfs(cur+1,k,n);
    
    
    
   
    
}

vector<vector<int>> combine(int n, int k) {

    dfs(1,k,n);
    for (auto num:ans)
    {
        for (auto t:num)
        {
            cout << t<<" ";
        }
        cout << endl;
        
    }

    return ans;
    
        
}

int main(){
    int n,k;
    cin>>n >>k;
    vector<vector<int>> ans = combine(n,k);
}