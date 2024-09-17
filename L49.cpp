#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include <sstream>
using namespace std;

// 字母异位词分组
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    // 遍历一遍数组，将每个单词的排序作为键
    for (string& str: strs){
        string key = str;
        // 每个单词先排序作为key
        sort(key.begin(), key.end());
        // 蒋倩倩这个元素添加到 容器的末尾
        // emplace_back 将这个元素添加到制定的容器末尾
        mp[key].emplace_back(str);
        
    }
    // 构建答案序列
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        /* code */
        // it-> second 取出其值的部分
        ans.emplace_back(it->second);

    }
    return ans;

}

int main(){
    // 输入的字符串
    vector<string> strs;
    string line;
    getline(cin, line); // 读取整行输入
    stringstream ss(line);
    string word;

    // 从输入流中提取单词
    while (ss >> word)
    {
        /* code */
        strs.push_back(word);
    }

    vector<vector<string>> ans = groupAnagrams(strs);

    int n = ans.size();

    
    cout << "字母异位词分组结果：" << endl;
    for (const auto& group : ans) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    
    

}