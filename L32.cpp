// 最长的有效括号
// 序列只包含() 找出最长有效（格式正确且连续）括号子串的长度

 // 是不是只要左括号的数量==右括号就可以呢  是的
 // 所以从左往右遍历一遍 再从右往左遍历一遍

 #include<iostream>
 #include<algorithm>
 #include<vector>
 #include<sstream>
 using namespace std;

// f i 以 i为结尾的最长有效的子串长度？
// 但是必须 两个检查一次 fi = fi-2 + 2  && s[i]==) s[i-1]==(
int longestValidParentheses(string s) {
    int n = s.size();
    int left = 0, right = 0;
    // 从左到右遍历 每当left=right的时候  括号刚好闭合
    // 一旦右括号的数量大于左括号  这个序列的长度就没有增长的可能性了
    // 归零
    int maxLeft = 0;
    int p = 0; // 记录位置
    for (int i = 0; i < n; i++)
    {
       
        if (s[i]=='(')
        {
            left++;
        }else if (s[i]==')')
        {
            right++;
        }

         cout<< i<<" "<< left<<" "<<right<<" "<<maxLeft << " "<<p<<endl;

         if (left==right && i!=0)
        {
            // 计算长度
            int length = i-p+1;
            cout << "length:" <<length<<endl;
            // 只记录最大长度
            maxLeft = max(maxLeft, length);
            
        }else if (right>left)
        {
            right=0;
            left=0;
            // 重新计数  从下一个位置开始 因为当前位置的括号已经被计数在内了
             p=i+1>=n?n-1:i+1;
        }

       
           
    }
    // 从右往左遍历
    p=n-1;
    int maxRight = 0;
    left = 0;
    right=0;
    cout<< "&&&&"<<endl;
    for (int i = n-1; i >= 0; i--)
    {
        
         if (s[i]=='(')
        {
            left++;
        }else if (s[i]==')')
        {
            right++;
        }
        cout<< i<<" "<< left<<" "<<right<<" "<<maxLeft << " "<<p<<endl;


         if (left==right&& i!=0)
        {
            // 计算长度
            int length = p-i+1;
            cout<<"right length:"<<length<<endl;
            // 只记录最大长度
            maxRight = max(maxRight, length);
           
        }else if (left>right)
        {
            right=0;
            left=0;
             // 重新计数
            p=i-1<0?0:i-1;
            cout<< maxRight << " "<<p<<endl;

        }
       
    }
    int ans = max(maxLeft, maxRight);
    return ans;
}

int main(){
    string s;
    getline(cin, s);

    int ans = longestValidParentheses(s);
    cout << ans << endl;
}