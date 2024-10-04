/**
 * @file L4.cpp 找到两个正序数组的中位数
 * @author zmj
 * @brief 
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
// 转化成找第k小的数
#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;



// 找到第K小的数
int getKth(vector<int>& nums1, vector<int>& nums2, int k){
    // 表明前面的都舍弃，因为肯定不是第K小的数
    int m = nums1.size();
    int n = nums2.size();
    int index1 = 0, index2=0;
    while (true)
    {
        // 判断边界情况
        // 如果数组1为空 那么中位数就是数组2的中位数
        // 也就是指针指到最后了
        if (index1==m)
        {
            return nums2[index2+k-1];
        }
        if (index2==n)
        {
            return nums1[index1+k-1];
        }
        if (k==1)
        {
            // 肯定是在 两个数组开头比较小的那个
            return min(nums1[index1], nums2[index2]);
        }
        // 正常情况下  判断一下，别超过边界值
        int newIndex1 = min(index1+k/2-1, m-1);
        int newIndex2 = min(index2+k/2-1, n-1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1<=pivot2)
        {
            //说明 newINdex1之前的都不可能是了，所以要更新index
            // 先计算前面有多少个元素
            k = k -(newIndex1-index1+1);
            // index1 继续向右移动
            index1 = newIndex1 + 1;
        }else{
            // 说明 nums 2 中 newindex2 之前的都不是了，所以
            k = k-(newIndex2-index2+1);
            index2=newIndex2+1;
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n= nums1.size();
    int m=nums2.size();
    // 那两个数组的中位数的 下标是....
    // 如果总长度是奇数个
    if ((m+n)%2==1)
    {
        // 那就是找中间的值 k = 中间值 向上取整
        return getKth(nums1,nums2, (m+n+1)/2);
    }else{
        return (getKth(nums1,nums2, (m+n)/2)+getKth(nums1,nums2,(m+n)/2+1))/2.0;
    }
    

}
