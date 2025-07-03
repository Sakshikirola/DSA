class Solution {
public:
    bool isPalindromeRange(const string& s, int st, int end) {
        while (st < end) {
            if (!isalnum(s[st])) {
                st++; continue;
            }
            if (!isalnum(s[end])) {
                end--; continue;
            }
            if (tolower(s[st]) != tolower(s[end]))
                return false;
            st++; end--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        while (st < end) {
            if (!isalnum(s[st])) {
                st++; continue;
            }
            if (!isalnum(s[end])) {
                end--; continue;
            }
            if (tolower(s[st]) != tolower(s[end])) {
                return isPalindromeRange(s, st + 1, end) || isPalindromeRange(s, st, end - 1);
            }
            st++; end--;
        }
        return true;
    }
};
