class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        /*

        integers are not sorted
        if sorted, what is longest consequtive sequence

        sorting solution
            sort array
            iterate from left to right
            keep a sliding window tracking the biggest size of sequence

            return biggest sequence

            [2,3,4,5,10,11,12,13,...]
             [.       ]                 [  ]
            start a first idx
            keep incrementing window until sequence ends or array ends
                once sequence ends, log sequence
            move idx to sequence end + 1 idx;
        */
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int longestSequence = 1;
        int n = nums.size();
        int windowStart = 0;

        while (windowStart < n) {
            int windowEnd = windowStart + 1;
            int sequence = 1;

            while (windowEnd < n) {
                if (nums[windowEnd] == nums[windowEnd - 1] + 1) {
                    ++sequence;
                    ++windowEnd;
                } else if (nums[windowEnd] == nums[windowEnd - 1]) {
                    ++windowEnd;
                } else {
                    break;
                }
            }

            longestSequence = max(longestSequence, sequence);
            windowStart = windowEnd;
        }

        return longestSequence;
    }
};
