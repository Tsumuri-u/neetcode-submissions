class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int left = 0, right = 0, output = 0, dom = 0;

        while (right < s.size()) {
            freq[s[right]]++;

            if (freq[s[right]] > dom)
                dom = freq[s[right]];

            if ((right - left + 1 - dom) > k) {
                freq[s[left]]--;
                left++;
            }
            
            output = max((right - left + 1), output);
            right++;
        }

        return output;
    }
};
