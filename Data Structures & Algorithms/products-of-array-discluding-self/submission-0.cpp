class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            Brute Force
                - calculate products at each index by going through remaining index
                - for each elements, go through other elements and compute products
                - Time O(N^2)
                - Space O(N)


            Division Approach
                - Each output[i] is the total product of all elements divided by nums[i]
                - compute total products
                - fill in output by product/nums[i]
                - for zero all except zero value idx will be 0
                - for negative integers, multiply normally with product
                - divide will ass sign
        */

        int totalProduct = 1;
        int zeroCount = 0;

        for (int num : nums) {
            if (num != 0) {
                totalProduct *= num;
            } else {
                ++zeroCount;
            }
        }

        vector<int> output(nums.size(), 0);

        if (zeroCount > 1) {
            return output;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (zeroCount == 1) {
                if (nums[i] == 0) {
                    output[i] = totalProduct;
                    return output;
                }
            } else {
                output[i] = totalProduct / nums[i];
            }
        }

        return output;
    }
};
