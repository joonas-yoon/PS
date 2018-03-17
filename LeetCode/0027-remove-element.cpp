/*
 * Keywords: List, Erase, Two Pointer
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if( nums.empty() ) return 0;
        // vector.erase(first, last) => [first, last)
        for(auto it = nums.begin(); it != nums.end();){
            auto end = it;
            while( end != nums.end() && *end == val ) end++;
            if( end != it ) it = nums.erase(it, end);
            else ++it;
        }
        return nums.size();
    }
};