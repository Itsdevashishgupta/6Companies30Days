class Solution {
public:
   int trailingZeroes(int n) {
    int dev = 0;
    for(long long i=5; n/i>0; i*=5){
        dev += (n/i);
    }
    return dev;
}
};