class Solution {
public:
    bool isValid(string s) {
        stack<char> seen;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                seen.push(c);
                cout << c;
            }
            if (c == ')' || c == '}' || c == ']') {
                if (!seen.empty() && (seen.top() == c-1 || seen.top() == c-2)) {
                    seen.pop();
                }
                else {
                    return false;
                }
            }
        }
        return seen.empty() ? true : false;

    }
};
