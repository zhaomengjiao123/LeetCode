// 以  o1 的时间 插入 删除  获取随机元素

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp[val])
        {
            return false;
        }else{
            int index = nums.size();
            nums.emplace_back(val);
            mp[val]=index;
            
            return true;
        }
        
    }
    
    bool remove(int val) {
        if (mp[val])
        {
            int index = mp[val];
            int last = nums.back();
            // 为什么要交换？不交换的话 map维护的位置就不对了
            nums[index]=last;
            // 更新map维护的位置
            mp[last]=index;
            nums.pop_back();
            mp.erase(val);
            return true;
        }else{
            return false;
        }
        
        
    }
    
    int getRandom() {
        int n = nums.size();
        int p = rand()%n;
        int tmp = nums[p];
        return tmp;
        
    }
};
