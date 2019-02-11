// Keys and Rooms
// 94.34% time 0.86% space AC
// BFS with Queue

#include <iostream>
#include <queue>

using namespace std;

class Solution {
private:
        queue<int> keys;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
                if(rooms.empty())
            return true;
        
        bool rooms_open[rooms.size()] = {false};
        for(int i=0; i<rooms[0].size(); i++)
            keys.push(rooms[0][i]);
        rooms_open[0] = true;
        
        int new_key;
        while(!keys.empty()) {
            new_key = keys.front();
            keys.pop();
            if(rooms_open[new_key] == false) {
                rooms_open[new_key] = true;
                for(int i=0; i<rooms[new_key].size(); i++)
                    keys.push(rooms[new_key][i]);
            }
        }

        for(int i=0; i<rooms.size(); i++)
            if(!rooms_open[i])
                return false;

        return true;
    }
};

int main() {
    return 0;
}
