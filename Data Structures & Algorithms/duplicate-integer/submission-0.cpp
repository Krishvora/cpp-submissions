class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /*
            Integer array
            more than once, false

            Sort Solution
                - Sort the array
                - compare first element with next element
                    - return true if same
                    - return false at end
                - Time O(NlogN)
                - Space O(1)

            Hash Map Solution
                - Iterate through array and keep map of all numbers appearing
                    - if one number appears more than once, return true
                    - return false at end
                - Time O(N)
                - Space O(N)
        */

        unordered_map<int, int> dupMap{};

        for(int i = 0; i < nums.size(); ++i){
            if(dupMap.count(nums[i])){
                return true;
            }else{
                dupMap[nums[i]] = 1;
            }
        }
        
        return false;

    }
};