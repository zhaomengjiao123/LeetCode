/***
 * 统计两个字符串相同位置相同字符的个数，如“TTTTGGG”，“GGGTTTT”，输出占比；

输入：“4T3G”，“3G4T”；
输出：“1/7”
 */

 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<sstream>
 using namespace std;


 // 把简写扩展为真是的字符串
 string expand(string& s){
    string res;
    for(int i=0;i<s.size();){
        // 可能是多位数字的情况
        if(isdigit(s[i])){
            int count = 0;
            string numStr;
            while (isdigit(s[i]))
            {
                /* code */
                numStr+=s[i];
                i++;
            }
            // 将数字字符串转换成  数字
            stringstream ss(numStr);
            ss >> count;
            char c = s[i];
            i++;
            res.append(count,c);
            
        }else{
            // 如果是单个字母直接加上
            res += s[i];
        }

    }

    return res;

 }

 string countSame(string& s1, string& s2){
    //先将简写扩展为原来的字符串
    string ex_s1 = expand(s1);
    string ex_s2 = expand(s2);
    int ans = 0;
    int n = ex_s1.size();
    for (int i = 0; i < n; i++)
    {
        /* code */
        if(ex_s1[i]==ex_s2[i]){
            ans++;
        }
    }
    return to_string(ans)+"/"+to_string(n);
    
 }

 int main(){
    string str1 = "4T3G";
    string str2 = "3G4T";
    
    string result = countSame(str1, str2);
    cout << result << endl;

 }