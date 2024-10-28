// 合并2个有序数组


#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int sort(vector<int>& v1, int l, int r){
    // 随机去一个位置
    int pivot = rand()%(r-l+1) + l;
    // 调换 pivot 和 left 位置的值
    int tmp= v1[l];
    v1[l]=v1[pivot];
    v1[pivot]=tmp;

    pivot = v1[l];
    while (l<r)
    {
        // 右指针移动的情况
        while (l<r && v1[r]>=pivot)
        {
            r--;
        }
        // 右边出现了比 pivot 小的数
        v1[l]=v1[r];
        // 左指针移动
        while (l<r && v1[l]<=pivot)
        {
            l++;
        }
        // 左边出现了比 pivot 大的数
        v1[r]=v1[l];
        


        
    }
    // 把 原来的值 放回去
    v1[l]=pivot;
    return l;
}

void quick_sort(vector<int>& nums, int l, int r){
    if (l>=r)
    {
        return;
    }
    // 找到中间值
    int mid = sort(nums, l, r);
    // 递归排序
    quick_sort(nums, l, mid-1);
    quick_sort(nums, mid+1,r);
    
}


// 思路 两个数组合并  试试快排
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    if (n==0)
    {
        return;
    }
    

    for (int i = m; i < m+n; i++)
    {
        nums1[i]=nums2[i-m];
    }

    //快排

    quick_sort(nums1, 0, nums1.size()-1);



    
        
}

int main(){
    vector<int> nums1 = {
      1,2,3,0,0,0  
    };

    vector<int> nums2 = {
        2,5,6
    };

    merge(nums1,3,nums2,3);
    for (auto num:nums1)
    {
        cout << num << " ";
    }
    
}