// 给一个数组，nlogn 完成升序排序

// 快排  选取一个哨兵，保证第一部分的元素都小于第二部分的元素，不断分区
// 直至都有序

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;


// 随机化快排：随机选择排序区间的中的某个值，与 num【left】互换，  把nums[]left 设置pivot值
// 比它小的都放在左边，比他大的都放在右边

int sort(vector<int>& nums, int l ,int r){
    // 随机选取一个位置  对这个区间的长度取模
    int pivot = rand() % (r-l+1) + l;
    int tmp = nums[l]; //标杆值
    // 把标杆值放到最左侧的位置  交换这两个数的位置
    nums[l]=nums[pivot];
    nums[pivot]=tmp;
    // 设置标杆值
    pivot = nums[l];
    // 当指针不重合的时候
    while (l<r)
    {
        // 右侧我们放大的值  所以 右指针移动
        while (l<r&&nums[r]>=pivot)
        {
            r--;
        }
        // 循环停下说明遇到了比标杆值小的了，需要移动到左侧
        nums[l]=nums[r];
        // 开始移动左指针
        while (l<r&&nums[l]<=pivot)
        {
            l++;
        }
        // 遇到了比标杆值大的数 ，需要移动到右侧
        nums[r]=nums[l];
        
        
    }
    // 给被冲掉的值重新赋值
    nums[l]=pivot;
    return l; // 中间位置  分区的 位置
    

    
    
}
// 快排
void quick_sort(vector<int>& nums, int l, int r){
    // 左侧指针一定要比右侧指针小，否则说明已经排序完了
    if (l>=r)
    {
        return;
    }
    // 找到分区位置
    int mid = sort(nums, l, r);
    // 左侧的分区再做快排
    quick_sort(nums,l,mid-1);
    // 右侧分区做快排
    quick_sort(nums,mid+1,r);
    
}

vector<int> sortArray(vector<int>& nums) {
    quick_sort(nums,0, nums.size()-1);
    return nums;
        
}

