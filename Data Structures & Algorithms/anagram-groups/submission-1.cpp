#include <map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<char>, vector<string>> anagrams;
        for (string str : strs) {
            vector<char> key(26);
            for (char i : str) {
                key[i - 'a']++;
            }
            anagrams[key].push_back(str);
        }

        vector<vector<string>> output;
        for (auto i : anagrams) {
            output.push_back(i.second);
        }

        return output;
    }
};
