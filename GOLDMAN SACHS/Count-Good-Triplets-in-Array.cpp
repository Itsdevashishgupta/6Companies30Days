class Solution {
public:
  constexpr int static n = 100000;
int bt[n + 1] = {};
int pre(int i) {
    int sum = 0;
    for (i = i + 1; i > 0; i -= i & (-i))
        sum += bt[i];
    return sum;
}
void add(int i, int val) {
    for (i = i + 1; i <= n; i += i & (-i))
        bt[i] += val;
}
long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    long long res = 0, n = nums1.size();
    vector<int> dev(n);
    for (int i = 0; i < n; ++i)
        dev[nums2[i]] = i;
    for (int i = 0; i < n - 1; ++i) {
        int mid = dev[nums1[i]], sm = pre(mid), gr = n - 1 - mid - (i - sm);
        res += (long long)sm * gr;
        add(mid, 1);
    }
    return res;
}
};