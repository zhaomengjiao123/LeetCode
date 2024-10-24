// 最小覆盖子串
// 

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// 我的思路：都存入哈希表  找到子串的最小坐标 和最大坐标直接 截取
// 因为题目规定 这个可以覆盖的子串是唯一的  理解错了 这个不对

// string minWindow(string s, string t) {
//     int n = s.size();
//     int m = t.size();
//     // 判断特殊情况 如果 t 的长度更长，显然是不符合要求的
//     if (m>n)
//     {
//         return "";
//     }
//     // 将s全部存入哈希表  以及数量  
//     unordered_map<char, pair<int, int>> hash;
//     for (int i = 0; i < n; i++)
//     {
//         hash[s[i]].first=i;
//         hash[s[i]].second++;
//     }
//     int maxP = INT16_MIN, minP=INT16_MAX;
//     // 遍历 t  找到最大坐标和最小坐标
//     // t 也存入  因为有可能有重复
//     unordered_map<char, int> t_hash;
//     for (int i = 0; i < m; i++)
//     {
//         t_hash[t[i]]++;
//     }
//     // 遍历 t
//     for (auto it = t_hash.begin(); it!=t_hash.end();it++)
//     {
//         // 如果某个值不存在
//         if (hash.count(it->first)==0)
//         {
//             return "";
//         }
//         // 找到对应的值
//         int num = hash[it->first].second;
//         if (num<it->second)
//         {
//             // 数量不匹配
//             return "";
//         }
//         cout << hash[it->first].first << " "<<it->first<<endl;
//         // 维护最大值和最小值
//         maxP = max(maxP, hash[it->first].first);
//         minP = min(minP, hash[it->first].first);
        
        
//     }
//     // 防止最小的位置的开始不是这个
//     if (t_hash[s[minP]]>1)
//     {
//         minP =minP - t_hash[s[minP]]+1;
//     }
     
//     cout << minP << " "<<maxP<<endl;
//     cout<< s.substr(minP, maxP-minP+1) <<endl;
//     return s.substr(minP, maxP-minP+1);
    
    
    
    

// }

// 定义两个哈希表 一个存储 t 中元素出现的次数  一个存储滑动窗口中元素出现的次数
// 
unordered_map<char, int> t_hash, s_hash;

// 检查当前的窗口是否是合格的窗口
// 合格的窗口就是完全覆盖子串的t中的所有元素，滑动窗口中某元素出现的次数>=t中对应元素出现的次数
bool check(){
    for (auto c:t_hash)
    {
        if (c.second>s_hash[c.first])
        {
            // 不够数量 一定不成立
            return false;
        }
        
    }
    return true;

    
}

string minWindow(string s, string t){
    int n = s.size();
    int m = t.size();
    if (m>n)
    {
        return "";
    }
    // 最小窗口的长度
    int len = INT16_MAX;
    // 最小窗口的左边界的指针
    int ans_left = -1;
    // 给t构造哈希表
    for (int i = 0; i < m; i++)
    {
        t_hash[t[i]]++;
    }
    //-平常滑动窗口的左右边界指针
    int left = 0, right = 0;
    // 滑动窗口的右侧指针  遍历整个字符串
    for ( int right = 0; right < n; right++)
    {
        // 每遍历一个元素  更新s——hash  记录当前已经遍历过的字符串
        s_hash[s[right]]++;
        // 如果遍历到的元素  恰好是 t中的 那么说明这次遍历的更新是有效的
        if(t_hash.count(s[right])>0){
            // 对于有效的  找到在t 中字符 就检查一次 是不是覆盖子串
            while (check()&&left<=right)// 为什么要求left<right? 保持滑动窗口
            {
                // 判断是不是最小窗口 更新窗口信息
                if (len>right-left+1)
                {
                    // 更新最小窗口的信息
                    len = right-left+1;
                    ans_left = left;
                }
                // 当前子串合法  移动左边界
                // 左边界的对应的元素也在滑动窗口中删除
                s_hash[s[left]]--;
                left++; // 左边界向右移动
                

                
            }
            
        }
    }
    if(ans_left==-1){
        return "";
    }
    return s.substr(ans_left, len);
    

    
    

}


// 最小覆盖子串 二刷

bool checkHash(unordered_map<char,int>& smap, unordered_map<char,int>& tmap){
    for (auto &tt:tmap)
    {
        cout << tt.second <<" "<<smap[tt.first]<<endl;
        // 为什么这里必须是大于？因为我们使用这个判断之后
        // 只要s滑动窗口中的相应的字母的数量等于或者大于t中相应字母的数量就可以
        if (tt.second>smap[tt.first])
        {
            return false;
        }
        
    }
    return true;
    
}

string minWindow2(string s, string t){
    int sl = s.size();
    int tl = t.size();
    if (tl>sl)
    {
        return "";
    }
    int left=0, right=0;
    unordered_map<char,int> tmap;
    unordered_map<char,int> smap;
    int ans_start=0,ans_end=0;
    int minL = INT_MAX;
    for (int i = 0; i < tl; i++)
    {
        tmap[t[i]]++;
    }
    // 寻找每一个可能得起点
    while (right<sl)
    {
        // 记录每个遍历过的字符
        smap[s[right]]++;
        if (tmap.count(s[right]))
        {
            
            cout<<"r:"<<right<<" "<<s[right]<<endl;
            // 检查
            // 更新最小窗口
            while (checkHash(smap,tmap)&&left<=right)
            {
                 int l = right-left+1;
            if (minL>l)
            {
                minL = l;
                ans_start=left;
                ans_end=right;
            }
            // 左移 还要减去相应的值
            smap[s[left]]--;
            left++;
                
            }
            
        }
        right++;

        
        
    }

    return s.substr(ans_start,minL);
    
    
    
    
}

int main(){
    string s;
    cin>>s;
    string t;
    cin >>t;

    // string ans = minWindow(s, t);
    string ans = minWindow2(s, t);

    cout<<ans;
}
