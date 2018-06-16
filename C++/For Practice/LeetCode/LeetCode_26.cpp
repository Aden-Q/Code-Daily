class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur;
        vector<int>::iterator iter;
        cur = -100;
        for(iter = nums.begin(); iter != nums.end();)
        {
            if(*iter == cur)
                nums.erase(iter);
            else{
                cur = *iter;
                iter++;
            }
        }
        return nums.size();
    }
};
