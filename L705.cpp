// 自己实现哈希集合

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<list>
using namespace std;

class MyHashSet {
    vector<list<int>> map;
    static const int base = 769;
    int hash(int key){
        return key%base;
    }

public:
    MyHashSet() {
        map.resize(base);
        
    }
    
    void add(int key) {
        int h = hash(key);
        for (auto it = map[h].begin(); it!=map[h].end();it++)
        {
            if(*it==key){
                return;
            }
        }
        map[h].push_back(key);

        
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = map[h].begin(); it!=map[h].end();it++)
        {
            if(*it==key){
                map[h].erase(it);
                return;
            }
        }
        return;
        
    }
    
    bool contains(int key) {
         int h = hash(key);
        for (auto it = map[h].begin(); it!=map[h].end();it++)
        {
            if(*it==key){
                return true;
            }
        }
        return false;
        
    }
};