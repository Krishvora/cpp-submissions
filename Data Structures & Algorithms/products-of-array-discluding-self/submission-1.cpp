class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
                Prefix array -> p[i] = product of all elements before i
                Suffix array -> p[i] = product of all elements after i
        */
        int n = nums.size();
        vector<int> result(n);
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 1;
        suff[n - 1] = 1;

        for (int i = 1; i < n; ++i) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }

        for (int i = n - 2; i >= 0; --i) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i) {
            result[i] = pref[i] * suff[i];
        }

        return result;
    }
};
