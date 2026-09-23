class Solution {
public:
    string removeOuterParentheses(string s) {
        int len = s.size();
        string ans;
        int cnt = 0;
        for(int i = 0 ; i < len ; i++){
            if(s[i] == ')') cnt--;
            if(cnt != 0) ans += s[i];
            if(s[i] == '(') cnt++;
        }
        return ans;
    }
};