// 插入区间

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

// 创建一个新数组  遍历旧数组一次
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        // 已经按照升序排列了，所以可以一次遍历
        vector<vector<int>> ans;
        if (n==0)
        {
            ans.push_back(newInterval);
            return ans;
        }
        
        bool flag = false; //标志  是否插入
        for (int i = 0; i < n; i++)
        {
            // 找到插入位置  找到比新的区间的开始值大的
            // 或者结束位置比要插入的开始位置小的
            if (intervals[i][1]<newInterval[0]&&!flag)
            {
                ans.push_back(intervals[i]);
            }else{
                //如果还没插入
                if(!flag){
                    // 查看是否和这个区间有交集
                    if (intervals[i][0]>newInterval[1])
                    {
                        // 2个都直接插入  没有交集
                        ans.push_back(newInterval);
                        ans.push_back(intervals[i]);
                    }else{
                        // 两者有交集
                        int newStart = min(intervals[i][0],newInterval[0]);
                        int newEnd = max(intervals[i][1], newInterval[1]);
                        // 放入新的
                        vector<int> tmp = {newStart,newEnd};
                        ans.push_back(tmp);
                    }
                    flag = true;
                    
                }else{
                    // 已经插入了，检查需不需要合并区间？
                    // 只看结尾值即可
                    if (intervals[i][0]<=ans.back()[1])
                    {
                        // 更新最后一个的结尾值
                        ans.back()[1]=max(ans.back()[1],intervals[i][1]);
                    }else{
                        // 没有交集直接插入
                        ans.push_back(intervals[i]);
                    }
                    
                }
            }
            
            
            
            
        }
        // 如果遍历完了还没插入 直接插入到最后面
        if (!flag)
        {
            ans.push_back(newInterval);
        }
        

        return ans;
        
}

int main(){
    vector<vector<int>> inters={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> in = {4,8};

    vector<vector<int>> ans = insert(inters, in);
    for (auto num:ans)
    {
        cout << num[0]<<" "<<num[1]<<endl;
    }
    
}