class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int trees = fruits.size(),maxlen=0,l=0,r=0;
        unordered_map<int,int> mpp;
        while(r<trees){
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
        
    }
};