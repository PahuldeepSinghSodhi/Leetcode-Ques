class Solution {
public:
    int compress(vector<char>& chars) {

        int n = chars.size();
        int write = 0;

        for(int read = 0; read < n; ) {

            char ch = chars[read];
            int count = 0;

            // Count consecutive characters
            while(read < n && chars[read] == ch) {
                count++;
                read++;
            }

            // Store character
            chars[write++] = ch;

            // Store count if greater than 1
            if(count > 1) {

                string cnt = to_string(count);

                for(char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};