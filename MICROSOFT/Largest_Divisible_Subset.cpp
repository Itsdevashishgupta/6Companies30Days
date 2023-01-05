class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(), maxi=1, num=-1;
        vector<int>v;
        sort(nums.begin(), nums.end());
        vector<int>dev(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(!(nums[i]%nums[j]) && dev[i]<dev[j]+1){
                    dev[i]=dev[j]+1;
                    if(maxi<dev[i]){
                        maxi=dev[i];
                    }
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(maxi==dev[i] && (num==-1 || !(num%nums[i]))){
                v.push_back(nums[i]);
                maxi--;
                num=nums[i];
            }
        }
        return v;
    }
};