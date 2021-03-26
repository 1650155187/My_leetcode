class Solution {
public:
    void dfs(const string &s, int k, int pos, int &total, int &len, int sum)
    {
        if (pos > s.length()) {
            return;
        }
        if (pos == s.length() && k == 0) {
            total++;
            len = sum;
            return;
        }
        if (s[pos] >= '0' && s[pos] <= '9') {
            int cur = k * 10 + s[pos] - '0';
            if (cur > 0) {
                dfs(s, 0, pos + cur + 1, total, len, sum + cur);
                dfs(s, cur, pos + 1, total, len, sum);
            }
        }
    }

    int GetLength(string encodedString)
    {
        int total = 0;
        int len = -1;
        dfs(encodedString, 0, 0, total, len, 0);
        if (total == 1) {
            return len;
        }
        return -1;
    }
};
