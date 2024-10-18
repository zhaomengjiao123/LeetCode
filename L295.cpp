// 数据流的中位数
// 有序整数列表的中间值

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

// 思路 中位数 左边  属于一个堆 右边属于一个堆
// 那么中位数是大根堆的 最大数，也就是左边那一半  小跟堆的最小数，也就是右边那一版
// 或者是两个的平均值

class MedianFinder {
private:
    priority_queue<int> maxHeap; // 默认是大根堆
    priority_queue<int, vector<int>, greater<int>> minHeap; // 指定排序  小跟堆  堆顶是最小的元素

public:

    MedianFinder() {
        // 最大堆（存储较小的一半）
        maxHeap = priority_queue<int>();  
        // 最小堆（存储较大的一半）
        minHeap = priority_queue<int, vector<int>, greater<int>>();  

    }
    
    void addNum(int num) {
        // 每次添加的时候，直接添加到大根堆
        // 保证中位数是大根堆的顶部元素
        // 那么大根堆的元素数量=小跟堆元素数量+1
        maxHeap.push(num);
        // 确保 整个序列是升序的
        // 大根堆的最大元素<=小跟堆的最小元素
        // 大根堆一定不为空 甘冈加紧元素去了，所以判断小跟堆是否为空
        if (!minHeap.empty()&&maxHeap.top()>minHeap.top())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        // 平衡两个堆的数量
        if (maxHeap.size()>minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if (minHeap.size()>maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
    }
    
    double findMedian() {
        // 如果元素的数量是奇数
        // 中位数就是大根堆的堆顶元素
        int n = maxHeap.size();
        int m = minHeap.size();
        if ((m+n)%2==1)
        {
            return maxHeap.top();
        }else{
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        

    }
};