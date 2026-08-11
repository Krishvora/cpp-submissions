class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*

        First Solution
            loop through each string
                create hashmap tracking chars
                loop through inner string
                check if numbers match
        
        Time - O()
        Space - O(N*M)
        */
        
        unordered_map<string, vector<string>> anagramMap{};

        for(const auto& s: strs){
            string sortedString = s;
            sort(sortedString.begin(), sortedString.end());
            anagramMap[sortedString].push_back(s);
        }

        vector<vector<string>> result{};

        for(auto& pairs : anagramMap){
            result.push_back(pairs.second);
        }

        return result;
    }
};
