/**
 * @file L118.cpp 杨辉三角
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-09-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * 两头的数一定是1，中间的数，例如  fi中的numj = f i-1 中的 nnum j + num j-1
 * 0<j<i-1  fi (num j) = fi-1(num j + num j-1) 
 * 
 */
#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
using namespace std;


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<int> inV;
    inV.push_back(1);
    ans.push_back(inV);
    if (numRows == 1)
    {
        /* code */
        
        return ans;
    }
    vector<int> inV2;
    inV2.push_back(1);
    inV2.push_back(1);
    ans.push_back(inV2);
    if (numRows == 2)
    {
        /* code */
        return ans;
    }

    
    for (int i = 2; i < numRows; i++)
    {
        vector<int> tmp;
        tmp.push_back(1);
    
        for (int j = 1; j <= i-1; j++)
        {
            /* code */
            int current = ans[i-1][j] + ans[i-1][j-1]; 
            tmp.push_back(current);
        }
        // 最后放一个 1
        tmp.push_back(1);
        
        ans.push_back(tmp);
    }
    return ans;
    
    
    
    

}

int main(){
    int numRows;
    cin >> numRows;

    vector<vector<int>> ans = generate(numRows);

    for (auto &numV : ans)
    {
        /* code */
        for (auto &num: numV)
        {
            /* code */
            cout << num << " ";
        }
        cout << endl;

    }
    
}