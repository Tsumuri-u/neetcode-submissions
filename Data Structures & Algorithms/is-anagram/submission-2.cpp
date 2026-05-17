#include <map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        map<char, int> smap;
        map<char, int> tmap;

        for (int i = 0; i < s.length(); i++) {
            smap[s[i]] = smap[s[i]] + 1;
            tmap[t[i]] = tmap[t[i]] + 1;
        }

        return smap == tmap;
    }
};
