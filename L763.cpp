// 划分字母区间  同一个字母最多出现在一个片段中
// 要求  划分的片段尽可能多
#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> partitionLabels(string s) {
    // 先使用hash存储所有字母的最后出现的位置
    int n = s.length();
    unordered_map<char, int> hash;
    for (int i = 0; i < n; i++)
    {
        hash[s[i]]=i;
    }
    vector<int> ans;
    // 遇见一个字符  就找到它最后出现的位置  就是end  如果到end了，并且end没有更新
    // 那么这就是一个片段
    int start = 0, end = 0;
    for (int i = start; i < n; i++)
    {
        cout<< "i: "<<i<<" end:"<<end<<endl;
        end=max(end, hash[s[i]]);
        // 如果到底了
        if (end==i)
        {
            ans.push_back(i-start+1);
            if (end==n-1)
        {
            return ans;
        }
        start = i+1;
        end = i+1;
        }
        
        
        
    }
    return ans;
    

}

int main(){
    string s;
    getline(cin, s);
    vector<int> ans = partitionLabels(s);
    for (auto num : ans)
    {
        cout<< num << " ";
    }
    
}