class Solution {
public:
    /*
        Encode based on string size
            number#string
        Edge cases
            - empty string
                - 0#
    */
    string encode(vector<string>& strs) {
        string res = "";
        for(const auto& s : strs ){
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }

        return res;
    }

    /*
        decode based on the number#string pattern
            each string will have number#string
            identify # to find how many positions to extract from following string
                put string into vector
            start search for # from idx of next string. stop at first # found. repeat   process.

        
    */

    vector<string> decode(string s) {
        vector<string> res{};

        int i = 0;

        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                ++j;
            }

            int length = stoi(s.substr(i, j - i));

            i = j + 1;
            res.push_back(s.substr(i, length));

            j = i + length;
            i = j;
        }

        return res;
    }
};
