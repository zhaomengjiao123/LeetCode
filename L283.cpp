#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// 移动零
void moveZeroes(vector<int>& nums) {
    // 两个指针  i,j
    int n=nums.size(), i = 0, j = 0;
    while (i<n)
    {
        // 如果 i 指针 所指向的位置不为 0 那么和 j所指向的位置调换
        if(nums[i]){
            swap(nums[i],nums[j]);
            j++;
        }
        i++;
    }
}


int main(){
    vector<int> nums;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
    moveZeroes(nums);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;


}