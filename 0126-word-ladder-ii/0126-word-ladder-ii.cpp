class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string> &path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto &par : parent[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);

        bool found = false;

        while (!currentLevel.empty() && !found) {

            for (auto &word : currentLevel)
                dict.erase(word);

            for (auto &word : currentLevel) {

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        temp[i] = ch;

                        if (dict.count(temp)) {

                            nextLevel.insert(temp);
                            parent[temp].push_back(word);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            currentLevel = nextLevel;
            nextLevel.clear();
        }

        if (!found)
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};