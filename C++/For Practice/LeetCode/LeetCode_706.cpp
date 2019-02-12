// HashMap
// 4.11% time 1.11% space AC

#include <iostream>

using namespace std;

class MyHashMap {
private:
    int map[1000001];

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        for(int i=0; i<1000001; i++)
            map[i] = -1;

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        map[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return map[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        map[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

int main() {
    MyHashMap test;
    int param_1;
    int param_2;
    int param_3;
    int param_4;
    test.put(1, 1);
    test.put(2, 2);
    param_1 = test.get(1);
    param_2 = test.get(3);
    test.put(2, 1);
    param_3 = test.get(2);
    test.remove(2);
    param_4 = test.get(2);
    
    cout << "param_1: " << param_1 << endl;
    cout << "param_2: " << param_2 << endl;
    cout << "param_3: " << param_3 << endl;
    cout << "param_4: " << param_4 << endl;
    return 0;
}
