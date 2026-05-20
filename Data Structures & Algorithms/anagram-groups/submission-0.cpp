#include <map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for (string str : strs) {
            string temp = str;
            std::sort(temp.begin(), temp.end());
            anagrams[temp].push_back(str);
        }

        vector<vector<string>> output;
        for (auto str : anagrams) {
            output.push_back(str.second);
        }

        return output;
    }
};
