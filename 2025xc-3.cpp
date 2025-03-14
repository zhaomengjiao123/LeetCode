#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// 求一个数的质因子个数
int countP(int x){
    if(x<=1){
        return 0;
    }
    int num = 0;
    if(x%2==0){
        num++;
        // 一直除
        while (x%2==0)
        {
            x = x/2;
        }
        
    }
    // 检查技术因子
    for(int i =3;i<sqrt(x);i+=2){
        if(x%i==0){
            num++;
            while (x%i==0)
            {
                x =x/i;
            }
            
        }
    }
    // 如果最后还有  x市直属
    if(x>2){
        num++;
    }
    return num;

}


int getAns(int n, int k, vector<int>& nums){
    // 权值数组
    vector<int> qz;
    int sum = 0;
    for(int i=0;i<n;i++){
        int tmp = countP(nums[i]);
        qz.push_back(tmp);
        sum += tmp;
    }
    //判断特殊情况
    if(k==0){
        return sum;
    }
    if(k>=n){
        return 0;
    }
    // 滑动窗口权值
    int cur = 0;
    int min_sum = 0;
    //滑动窗亏 找到权值和最小的窗口
    for(int i=0;i<k;i++){
        cur+=qz[i];
    }
    min_sum = cur;
    for(int i=k;i<n;i++){
        // 抛弃左边的，加入右边的
        cur = cur - qz[i-k] + qz[i];
        min_sum = min(min_sum, cur);
    }

    return sum-min_sum;


}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        nums.push_back(a);
    }
    int ans = getAns(n, k, nums);
    cout << ans <<endl;
}