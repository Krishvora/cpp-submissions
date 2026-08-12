class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
         input integers
         integer k
         return k most freqeunt elements atlest k times
         answer is always unique

         Sorting Solution
         sort array
         start from start and check if each elements has a >=k occurence
         resume from where you stopped

         Time - O(N)
         Space - O(1)
        */

        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({p.second, p.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
};
