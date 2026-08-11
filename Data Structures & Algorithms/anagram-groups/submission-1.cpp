class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        Create hasmap using lower case count of letters
        iterate through each string and check if it matches, if it matches, add to vector

        lower case of letter counter
        create array 26 size wide
        increment the 
        */
        unordered_map<string, vector<string>> anagramMap{};
        for(const auto& s: strs){
            vector<int> count(26,0);
            for(char c : s){
                ++count[c - 'a'];
            }

            string key = to_string(count[0]);
            for(int i = 1; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }
            anagramMap[key].push_back(s);
        }

        vector<vector<string>> result{};
        for(const auto& pairs: anagramMap){
            result.push_back(pairs.second);
        }

        return result;
    }
};
