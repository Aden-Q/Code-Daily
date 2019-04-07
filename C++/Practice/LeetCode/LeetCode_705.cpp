// Design HashSet
// 40.00% time and 1.39% space AC


#include <iostream>

using namespace std;

class MyHashSet {
private:
    bool set[1000001];

public:
    /** Initialize your data structure here. */
    MyHashSet() {       
        for(int i=0; i<1000001; i++)
            set[i] = false;
    }
            
    void add(int key) {
        set[key] = true;
    }
            
    void remove(int key) {
        set[key] = false;
    }
            
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return set[key]; 
    }
        
};


int main() {
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    bool param_1 = hashSet.contains(1);
    bool param_2 = hashSet.contains(3);
    hashSet.add(2);
    bool param_3 = hashSet.contains(2);
    hashSet.remove(2);
    bool param_4 = hashSet.contains(2);
    cout << "param_1: " << param_1 << endl;
    cout << "param_2: " << param_2 << endl;
    cout << "param_3: " << param_3 << endl;
    cout << "param_4: " << param_4 << endl;

    return 0;
}
