#include <bits/stdc++.h>

using namespace std;

class MyHashMap {
public:
    unordered_map<int, int> funnyMap;

    MyHashMap() {
    }
    
    void put(int key, int value) {
        funnyMap[key] = value;
    }
    
    int get(int key) {
        if (funnyMap.find(key) == funnyMap.end()) {
            return -1;
        } else {
            return funnyMap[key];
        }
    }
    
    void remove(int key) {
        funnyMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */