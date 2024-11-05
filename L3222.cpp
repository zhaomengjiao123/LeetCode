// 找出硬币游戏的赢家

// 每次必须拿到  和为115,肯定只能拿一次75,看看剩下的后不够 115-75=40/10=4
// 看看剩下的10元硬币有没有四个？

#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;



string losingPlayer(int x, int y) {

    // 查看可以玩的次数  不输的额情况下，每次都要1个x，4个y
    int ops = min(x,y/4);

    if (ops%2==1)
    {
        // 操作次数是奇数 因为是ALice先开始的
        return "Alice";
    }
    return "Bob";
    
        
}

int main(){
    int x, y;
    cin>>x>>y;
    string ans = losingPlayer(x,y);
    cout << ans << endl;
}