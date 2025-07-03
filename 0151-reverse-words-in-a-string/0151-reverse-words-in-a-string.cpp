class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        reverse(s.begin(),s.end());

        for(int i=0; i<n ;i++){
            string words = "";
            while(i<n && s[i]!= ' '){
                words += s[i];
                i++;
            }

            reverse(words.begin(),words.end());
            if(words.length()>0){
                result += " " + words;
            }
        }
        return result.substr(1);
    }
};