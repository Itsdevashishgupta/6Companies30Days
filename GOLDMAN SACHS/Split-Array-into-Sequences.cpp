class Solution {
public:
    bool isPossible(vector<int>& A) {
        unordered_map<int, int> dev1, dev2;
        for (int i: A) {
            dev1[i]++;
        }
        for (int i: A) {
            if (dev1[i] == 0) continue;
            dev1[i]--;
            if (dev2[i - 1] > 0) {   
                dev2[i - 1]--;
                dev2[i]++;
            } else if (dev1[i + 1] > 0 && dev1[i + 2] > 0) {
                dev1[i + 1]--;
                dev1[i + 2]--;
                dev2[i + 2]++;
            } else {   
                return false;
            }
        }
        return true;
    }
};