// 从数据中选择最小到第K小的数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * @brief 
 * 选择基准值（pivot）：从数组中选择一个基准值，通常可以随机选择或选择中间元素。
分区操作：将数组分为两部分，一部分是小于基准值的元素，另一部分是大于基准值的元素。
递归选择：根据 k 的位置，递归地在左半部分或右半部分继续查找，直到找到第 k 小的元素。
调整数组：在查找过程中，通过分区操作调整数组，使得前 k 个元素是最小的 k 个数。
 */

// 分区函数 返回基准值的最终位置
int partitionPos(vector<int>& nums, int left, int right){
    // 选择基准值的方法  使用 随机选择
    int randomIndex = left + rand()% (right-left+1);
    // 把基准值放在最末尾
    swap(nums[right], nums[randomIndex]);
    // 那么现在基准值就是
    int privot = nums[right];
    int i= left;
    // 把比基准值小的都放到左边
    for(int j=left;j<right;j++){
        if(nums[j]<=privot){
            swap(nums[j], nums[i]);
            i++;
        }
    }
    // 把基准值放回应该在的位置
    swap(nums[i],nums[right]);
    // 基准值的位置就是 i 左边都是比基准值小的，右边都是比基准值大的
    return i;
}

// 快速选择函数，返回最小到第k小的数
vector<int> qucikSelcet(vector<int>& nums, int k){
    int left = 0, right = nums.size()-1; //左右指针
    while (true)
    {
        // 基准值位置
        int privotIndex = partitionPos(nums, left, right);
        // 看下这个位置是不是刚好是第K个位置  也就是索引为k-1
        if(privotIndex == k-1){
            vector<int> res(nums.begin(), nums.begin()+k);
            return res;
        }else{
            // 看下在左边 还是在右边
            if(privotIndex > k-1 ){
                // s说明前K个小的元素在左边
                right = privotIndex -1;
            }else{
                // 在右边
                left = privotIndex + 1;
            }
        }
    }
    

}



int main(){
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 5;
    vector<int> result = qucikSelcet(nums, k);

    cout << "最小到第" << k << "小的数是：";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}