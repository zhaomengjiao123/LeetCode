#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(vector<int> a, vector<int> b){
    // 攻击力从高到低  防御力 从低到高
    return a[0]>b[0]?a[0]>b[0]:a[1]<b[1];
}

int numOfWeakRoles(vector<vector<int> >& properties) {
        // write code here
        // 排序
        // 这里是严格大于
       sort(properties.begin(), properties.end(), [](vector<int> a, vector<int> b){
            return a[0] > b[0] ||(a[0]==b[0] &&a[1] < b[1]);
        });
        // 最高防御力
        int max_de = 0;
        int ans = 0;
        for(int i=0;i<properties.size();i++){
            // 因为攻击力从搞到底，因此只需要比较防御力
            if(properties[i][1]<max_de){
                ans++;
            }else{
                // 更新最大方预支
                max_de=properties[i][1];
            }
        }

        return ans;

}