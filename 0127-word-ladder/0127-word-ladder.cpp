class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> set(wordList.begin(),wordList.end());
        set.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if( word == endWord ) return steps;

            for(int i = 0 ; i < word.size() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(set.find(word) != set.end()){
                        set.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            }

        }
        
        return 0;
    }
};