class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        vector<double> dev(2, 0); 
        dev[0] = 1.0/n;
        for(int i = 3; i <= n; ++i)
            dev[0] = dev[1] = dev[0] + dev[0]/(n-i+2);
        return 1 - dev[0];
    }
};