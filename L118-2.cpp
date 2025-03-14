// 杨辉三角  模拟


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<vector<int>> generate(int numRows){
    vector<vector<int>> ans;
    // 第一行
    vector<int> num1;
    num1.push_back(1);
    ans.push_back(num1);
    if(numRows==1){
        return ans;
    }
    for(int i=1;i<numRows;i++){
        //存储本行数据
        vector<int> tmp;
        tmp.push_back(1);
        //计算中间的数据
        for(int j=1;j<=i-1;j++){
            int num = ans[i-1][j-1]+ans[i-1][j];
            tmp.push_back(num);
        }
        // 放入最后一个1
        tmp.push_back(1);
        ans.push_back(tmp);

    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans = generate(n);
    for(auto num:ans){
        for(int n:num){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}

