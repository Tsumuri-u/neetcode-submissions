#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string output;
        for (string str : strs) {
            for (char c : str) {
                output += to_string(((int)c));
                output += ',';
            }
            output += ';';
        }
        return output;
    }

    vector<string> decode(string s) {
        vector<string> output;
        string word = "";
        string letter = "";
        for (char c : s) {
            if (c == ';') {
                output.push_back(word);
                word = "";
            } else if (c == ',') {
                word += (char)std::stoi(letter);
                letter = "";
            } else {
                letter += c;
            }
        }
        return output;
    }
};
