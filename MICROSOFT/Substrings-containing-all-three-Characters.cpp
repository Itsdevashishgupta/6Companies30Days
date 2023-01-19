class Solution {
public:
      int numberOfSubstrings(string s) {
        int coun[3] = {0, 0, 0},dev = 0 , i = 0, n = s.length();
        for (int j = 0; j < n; ++j) {
            ++coun[s[j] - 'a'];
            while (coun[0] && coun[1] && coun[2])
                --coun[s[i++] - 'a'];
            dev += i;
        }
        return dev;
    }
};