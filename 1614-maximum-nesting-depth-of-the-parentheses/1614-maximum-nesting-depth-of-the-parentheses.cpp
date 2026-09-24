class Solution {
public:
    int maxDepth(string s) {

        int curr = 0, res = 0;

        for(auto c : s){
            if(c == '(') res = max(++curr,res);
            if(c == ')') curr--;
        }

        return res;
        
    }
};