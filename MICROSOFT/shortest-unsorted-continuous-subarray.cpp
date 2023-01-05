class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxleft(n);  
        vector<int> minright(n);   
        for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minright[i] = minr = min(minr, nums[i]);
        for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxleft[i] = maxl = max(maxl, nums[i]);

        int i = 0, j = n - 1;
        while (i < n && nums[i] <= minright[i]) i++;
        while (j > i && nums[j] >= maxleft[j]) j--;

        return j + 1 - i;
    }
};