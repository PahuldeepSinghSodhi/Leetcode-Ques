class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        for(auto current : s){
            freq[current]++;
        }

        vector<pair<int,char>> v;

        for(auto current : freq){
            v.push_back({current.second,current.first});
        }
        string ans = "";

        sort(v.rbegin(),v.rend());

        for(auto c : v){
            ans += string(c.first,c.second);
        }
        return ans;
        
    }
};