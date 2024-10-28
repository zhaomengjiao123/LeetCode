// 文本左右对齐
// 每行恰有 x 哥字符，并且左右对齐，尽可能均匀分配单词间的空格数量
// 如果空格不能均匀分配，左侧的空格数>右边的空格数

// 模拟


#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

//返回长度为n的空格字符串
string blank(int n){
    return string(n, ' ');
}


// 返回用 sep (相当于一种间隔符)拼接的字符串  [left, right) 左开右闭
string join(vector<string>& words, int left, int right, string sep){
    string s = words[left];
    for (int i = left+1; i < right; i++)
    {
        s = s + sep + words[i];
    }
    return s;
    

}

// 贪心   每行放尽可能多的 单词
vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int right = 0, n = words.size();
        // 每两个单词之间至少有一个空格
        while (true)
        {
            // 记录当前行的第一个单词在  words 数组中的位置
            int left = right;
            // 这一行的单词的长度之后和
            int sumLen = 0;
            // 循环尝试放入单词  right-left  代表每两个单词之间至少有一个空格
            while (right<n&&sumLen+words[right].length()+(right-left)<=maxWidth)
            {
                sumLen = sumLen + words[right].length();
                right++;
            }
            // 当前行满了
            // 判断是不是遍历到了最后一个单词（最后一个单词肯定是放在了最后一行）
            // 最后一行：单词左对齐，并且单词之间只有一个空格，不够的长度填充空格
            if (right==n)
            {
                // 拼接最后一行的单词 ，直接返回字符串
                string s = join(words, left, n, " ");
                ans.push_back(s+blank(maxWidth-s.length()));
                return ans;
            }
            // 统计本行的单词书
            int numworrds = right-1 - left+1;
            int numBlanks = maxWidth - sumLen; // 需要填充的空格数
            // 如果当前行只有一个 单词，那么空格全部放在最右边，不用拆开
            if (numworrds==1)
            {
                ans.emplace_back(words[left]+blank(numBlanks));
                continue;
            }
            // 如果当前行不只一个单词，需要将空格平均分配
            // 并且左边的空格数 > 右边的空格数
            // 平均分配到两个单词之间的空格数
            int avgBlank = numBlanks/(numworrds-1);
            // 计算还剩下多少空格数没有被分配，平均的分到左边
            int etraBlanks = numBlanks % (numworrds-1);
            // 左边的单词+空格
            string s1 = join(words, left, left+etraBlanks+1, blank(avgBlank+1));
            // 右边的单词+空格
            string s2 = join(words, left+etraBlanks+1, right, blank(avgBlank));
            ans.emplace_back(s1+blank(avgBlank)+s2);

            
            
            
        }

        return ans;
        
}


int main(){
    vector<string> vs = {
"This", "is", "an", "example", "of", "text", "justification." };
    int num = 16;

    vector<string> ans = fullJustify(vs, num);

    for (auto &s:ans)
    {
        cout << s << endl;
    }
    
}