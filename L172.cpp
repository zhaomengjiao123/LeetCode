// 阶乘后的0  n!的尾随0的数量


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

// 思路只有2*5才能得到0
// 5出现的次数一定比2少，所以只需要找到5以及5的倍数出现的次数
int trailingZeroes(int n) {
    int ans = 0;
    for (int i = 5; i <=n; i = i+5)
    {
        // 如果是5的倍数？
        for (int x = i; x%5==0; x=x/5)
        {
            ans++;
        }
        
    }

    return ans;
    
        
}

int main(){
    int num;
    cin >> num;
    int ans = trailingZeroes(num);
    cout << ans << endl;
}
