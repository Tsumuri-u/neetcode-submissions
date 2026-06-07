class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tfreq, sfreq;
        pair<int, int> best = {0, s.size()};
        bool solution = 0;
        int l = 0, r = 0, scurr = 0;
        
        for (char c : t)
            tfreq[c]++;

        while (l < s.size()) {
            if (tfreq.find(s[l]) != tfreq.end()) {
                r = l;
                break;
            }
            l++;
        }

        while (r < s.size() && l < s.size()) {
            if (tfreq.find(s[r]) != tfreq.end()) {
                sfreq[s[r]]++;

                if (sfreq[s[r]] == tfreq[s[r]])
                    scurr++;

                if (scurr == tfreq.size()) {
                    solution = 1;
                    if ((r - l) < (best.second - best.first)) {
                        best.second = r;
                        best.first = l;
                    }
                    sfreq[s[l]]--;
                    sfreq[s[r]]--;
                    scurr--;
                    if (s[l] != s[r] && sfreq[s[l]] < tfreq[s[l]])
                        scurr--;
                    l++;
                    while (tfreq.find(s[l]) == tfreq.end()) {
                        l++;
                        if (r < l)
                            break;
                    }
                }
                else 
                    r++;
            }
            else 
                r++;
        }

        if (solution)
            return s.substr(best.first, (best.second - best.first + 1));
        else
            return "";
    }
};
