//盛最多水的容器

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int minvalue = 0;
        int maxarea = 0;
        int area;
        for(int i=0;i<height.size();i++){
            for(int j=height.size()-1;j>=i;j--){
                minvalue = height[i] < height[j] ? height[i]:height[j];
                area = minvalue * (j-i);
                if(area > maxarea){
                    maxarea = area;
                }
            }
        }
        return maxarea;
    }
};

int main(){
    Solution test;
    int r;
    int vv[] = {1,8,6,2,5,4,8,3,7};
    vector<int> v(vv, vv+9);
    //cout << v.size() << endl;
    r = test.maxArea(v);
    cout << r << endl;
    return 0;
}    
