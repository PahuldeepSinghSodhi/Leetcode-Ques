class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int l = 0, r = 0,maxlen = 0,len,n = s.size();

        vector<int> lastSeen(256,-1);
        while(r<n){
            if(lastSeen[s[r]] != -1){
                if(lastSeen[s[r]] >= l){
                     l = lastSeen[s[r]] + 1;
                    lastSeen[s[r]] = r;
                   
                   
                }
            }
            lastSeen[s[r]] = r;
            len = r-l+1;
            maxlen = max(maxlen,len);
            r++;
        }
        return maxlen;
    }
};