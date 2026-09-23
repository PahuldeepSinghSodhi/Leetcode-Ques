class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        string result;
        int i = 0;

        while (i < len) {
            while (i < len && s[i] == ' ')
                i++;

            if (i >= len)
                break;

            int j = i + 1;

            while (j < len && s[j] != ' ')
                j++;

            string sub = s.substr(i, j - i);

            if (result.length() == 0)
                result = sub;
            else
                result = sub + ' ' + result;

            i = j;  
        }

        return result;
    }
};