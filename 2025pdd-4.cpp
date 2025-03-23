/***
 * 多多最新在研究一种神奇的字符串替换，该字符串可以通过一种方式进行替换，替换后可以得到另一种字符串。
假设给定两个由小写字母组成的字符串A和B，对应的字符串长度分别为n和m;另外，还有一个由m个元素组成的转换数组X={index, index2 ....., indexm}，数组的元素记录了字符串A中某些元素的下标（字符串中元素的下标从1到n)，这些元素可能是重复的，也就是数组中任意元素满足:
1<= index(i); <=n。
多多可以通过随意调整数组中元素的顺序，也可以随意调整字符串B中元素的顺序。
调整顺序之后，多多需要从左向右遍历数组×中的元素，
假设当前遍历到的是第i个元素，该元素的值为index(i);，
多多就会将字符串A中第index(i);个元素替换为字符串B中第i个元素;
就这样，多多一共会替换m次，替换后得到的字符串是A'。
现在，多多想知道通过调整×中元素的顺序，再调整字符串B中元素的顺序后，在所有的可能情况下，如何让替换后得到的字符串A'的字典序最小。
请你帮助多多解决这个问题。

m,m<=100000
 */

 #include<vector>
 #include<iostream>
#include<algorithm>
#include <string>
using namespace std;


string minLexicographicalString(string A, string B, vector<int> X) {
    int n = A.size();
    int m = B.size();
    
    // 统计每个位置的替换次数
    vector<int> count(n, 0);
    for (int idx : X) {
        count[idx-1]++; // 转换为0-based索引
    }
    
    // 排序字符串 B
    sort(B.begin(), B.end());
    
    // 贪心替换
    int bPtr = 0;
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            // 选择最小的可用字符进行替换
            A[i] = B[bPtr];
            bPtr++;
        }
    }
    
    return A;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string A, B;
        vector<int> X;
        int n, m, x;
        
        cin >> n >> m;
        cin >> A >> B;
        for (int i = 0; i < m; i++) {
            cin >> x;
            X.push_back(x);
        }

        string result = minLexicographicalString(A, B, X);
        cout << result << endl;


    }

}