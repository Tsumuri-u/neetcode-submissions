class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;
        int start = 0, count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (chars.find(s[i]) == chars.end()) {
                chars[s[i]] = i;
            } else {
                if (start <= chars[s[i]])
                    start = chars[s[i]] + 1;
                chars[s[i]] = i;
            }
            count = max((i - start + 1), count);
        }
        return count;
    }
};
