class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int first = 0;
        int second = 1;

        while(second < nums.size()){
            if(nums[second] == nums[first]){
                return true;
            }
            ++first;
            ++second;
        }

        return false;
    }
};