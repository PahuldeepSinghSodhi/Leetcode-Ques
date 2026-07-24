class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {

        unordered_set<string> vis;
        queue<string> q;

        vis.insert(s);
        q.push(s);

        string ans = s;
        int n = s.size();

        while (!q.empty()) {

            string cur = q.front();
            q.pop();

            ans = min(ans, cur);

            // Operation 1: Add 'a' to all odd indices
            string add = cur;
            for (int i = 1; i < n; i += 2) {
                add[i] = ((add[i] - '0' + a) % 10) + '0';
            }

            if (!vis.count(add)) {
                vis.insert(add);
                q.push(add);
            }

            // Operation 2: Rotate right by b positions
            string rot = cur.substr(n - b) + cur.substr(0, n - b);

            if (!vis.count(rot)) {
                vis.insert(rot);
                q.push(rot);
            }
        }

        return ans;
    }
};