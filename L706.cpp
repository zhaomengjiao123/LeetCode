// 自己实现哈希映射

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<list>
using namespace std;


class MyHashMap {
    vector<list<pair<int,int>>> map;
    static const int base = 769;
    int hash(int key){
        return key%base;
    }
public:
    MyHashMap() {
        map.resize(base);
        
    }
    
    void put(int key, int value) {
        int h = hash(key);
        for (auto it = map[h].begin(); it!=map[h].end();it++)
        {
            if(it->first==key){
                // 更新value
                it->second = value;
                return;
            }
        }
        map[h].push_back({key,value});
        
        
    }
    
    int get(int key) {
        int h = hash(key);
        for (auto it = map[h].begin(); it!=map[h].end();it++)
        {
            if(it->first==key){
                // 更新value
                return it->second;
            }
        }
        return -1;
        
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = map[h].begin(); it!=map[h].end();it++)
        {
            if(it->first==key){
                // 移除
                map[h].erase(it);
                return;
            }
        }
        return;
        
    }
};
