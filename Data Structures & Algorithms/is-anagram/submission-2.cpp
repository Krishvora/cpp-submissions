class Solution {
   public:
    bool isAnagram(string s, string t) {
        /*

        Contains exact same characters
        length should be same
        order might be different

        First Solution
            - Keep an hashmap and iterate through one string
            - push all chars into the hashmap
            - iterate through the second string
            - check if all chars present
                - will need to keep track of count of chars since count needs to be the same
            - return true if everything checks
            - Time O(S)
            - Space O(S) every char is distinct
        */
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> characterMap{};

        for (char c : s) {
            if (characterMap.count(c)) {
                characterMap[c] += 1;
            } else {
                characterMap[c] = 1;
            }
        }

        for (char c : t) {
            auto it = characterMap.find(c);
            if (it != characterMap.end() && it->second) {
                characterMap[c] -= 1;
            } else {
                return false;
            }
        }

        return true;
    }
};
