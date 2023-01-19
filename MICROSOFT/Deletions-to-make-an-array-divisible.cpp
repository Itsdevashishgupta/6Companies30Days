class Solution {
public:
       int minOperations(vector<int>& A, vector<int>& numsDivide) {
        int dev = numsDivide[0];
        for (int a: numsDivide)
            dev = gcd(dev, a);
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size() && A[i] <= dev; ++i)
            if (dev % A[i] == 0)
                return i;
        return -1;
    }
};