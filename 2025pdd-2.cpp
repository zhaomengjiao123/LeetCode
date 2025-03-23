#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;


// 给定一个范围[L,R],这个范围中有多少数字是幸运数字？幸运数字就是数字中有一个连续的子串，这个子串是3的倍数

// 子串的和 是3的倍数
bool islucky(long long num){
    string s = to_string(num);
    long long n = s.size();
    long long prefixSum =0;
    unordered_set<long long> remainderSet;
    remainderSet.insert(0);
    for(long long i=0;i<n;i++){
        prefixSum +=(s[i]-'0');
        long long remainder = prefixSum %3;

        if(remainderSet.find(remainder)!=remainderSet.end()){
            return true;
        }
        remainderSet.insert(remainder);
    }
    return false;
}
// 还是超时  数位 DP
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;


// bool islucky(long long num) {
//     string s = to_string(num);
//     long long n = s.size();
//     long long prefixSum = 0;
//     unordered_set<long long> remainderSet;
//     remainderSet.insert(0);
//     for (long long i = 0; i < n; i++) {
//         prefixSum += (s[i] - '0');
//         long long remainder = prefixSum % 3;

//         if (remainderSet.find(remainder) != remainderSet.end()) {
//             return true;
//         }
//         remainderSet.insert(remainder);
//     }
//     return false;
// }

bool islucky(long long num) {
    // 开销大
    // string s = to_string(num);
    // long long n = s.size();
    long long prefixSum = 0;
    unordered_set<long long> remainderSet;
    remainderSet.insert(0);

    while (num>0)   
    {
        /* code */
        int digit = num%10;
        prefixSum += digit;
        int remainder = prefixSum % 3;
        if (remainderSet.find(remainder) != remainderSet.end()) {
            return true;
        }
        remainderSet.insert(remainder);
        num /= 10;
    }
    
    
    // for (long long i = 0; i < n; i++) {
    //     prefixSum += (s[i] - '0');
    //     long long remainder = prefixSum % 3;

    //     if (remainderSet.find(remainder) != remainderSet.end()) {
    //         return true;
    //     }
    //     remainderSet.insert(remainder);
    // }
    return false;
}

// ll dp[20][8][3]; // pos, mask (bitset for mod 0,1,2), current_mod
// vector<int> digits;

// // 将数字转换为数位数组
// void getDigits(ll num) {
//     digits.clear();
//     while (num > 0) {
//         digits.push_back(num % 10);
//         num /= 10;
//     }
//     reverse(digits.begin(), digits.end());
// }

// // 数位DP计算不符合条件的数字数量
// ll dfs(int pos, int mask, int mod, bool tight, bool lead) {
//     if (pos == digits.size()) {
//         // 所有前缀余数必须不重复且不含0、3、6、9
//         return (lead) ? 0 : 1; // lead为true表示全0，不计入
//     }
//     if (!tight && !lead && dp[pos][mask][mod] != -1) {
//         return dp[pos][mask][mod];
//     }

//     int limit = tight ? digits[pos] : 9;
//     ll cnt = 0;

//     for (int d = 0; d <= limit; ++d) {
//         bool new_lead = lead && (d == 0);
//         if (!new_lead && (d == 0 || d == 3 || d == 6 || d == 9)) {
//             continue; // 包含禁用数字，跳过
//         }

//         int new_mod = (mod + d) % 3;
//         int new_mask = mask;
//         if (!new_lead) { // 非前导零时处理余数
//             if ((mask & (1 << new_mod)) {
//                 continue; // 余数重复，存在和为3的倍数的子串，跳过
//             }
//             new_mask |= (1 << new_mod);
//         }

//         bool new_tight = tight && (d == limit);
//         cnt += dfs(pos + 1, new_mask, new_mod, new_tight, new_lead);
//     }

//     if (!tight && !lead) {
//         dp[pos][mask][mod] = cnt;
//     }
//     return cnt;
// }

// // 计算[1, num]中不满足条件的数字数量
// ll countNotLucky(ll num) {
//     if (num == 0) return 0;
//     getDigits(num);
//     memset(dp, -1, sizeof(dp));
//     return dfs(0, 0, 0, true, true);
// }

// // 计算[L, R]中的幸运数字数量
// ll solve(ll L, ll R) {
//     ll total = R - L + 1;
//     ll notLucky = countNotLucky(R) - countNotLucky(L - 1);
//     return total - notLucky;
// }

// int main() {
//     int T;
//     cin >> T;
//     while (T--) {
//         ll L, R;
//         cin >> L >> R;
//         cout << solve(L, R) << endl;
//     }
//     return 0;
// }

// int main(){
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         long long l,r;
//         cin>>l>>r;
//         long long ans = 0;
//         long long total = r-l+1;
//         long long notLucky = countNotLucky(r) - countNotLucky(l - 1);

//         // for(long long num =l;num<=r;num++){
//         //     if(islucky(num)){
//         //         ans++;
//         //     }
//         // }
//         cout <<ans<<endl;

//     }
// }

// 还是超时