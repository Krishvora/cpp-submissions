class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        /*
        create hashmap of all distinct nums
        create another hasmap with nums from which sequence can begin
            iterate through previous map to check longest sequence that can be made
        */

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};
