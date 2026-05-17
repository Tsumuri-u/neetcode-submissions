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

        for (auto i : smap) {
            if (tmap.find(i.first) == tmap.end()) {
                return false;
            }
            if (tmap[i.first] != i.second) {
                return false;
            }

        }

        return true;
    }
};
