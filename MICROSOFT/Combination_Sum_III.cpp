class Solution {
public:
int summ(vector<int>& temp){
        int sum = 0;
        for(auto x: temp){
            sum += x;
        }
        return sum;
    }
void dp(vector<vector<int>>&dev,int k, int n, vector<int>& temp, int num){
        if(k == 0){
            if(summ(temp) == n ){
                dev.push_back(temp);
            }
            return;
        }
        if(num > 9) return;
        temp.push_back(num); 
        dp(dev,k - 1, n, temp, num + 1);
        temp.pop_back(); 
        dp(dev,k, n, temp, num + 1);    
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>dev;
        vector<int>temp;
        int num=1;
        dp(dev,k,n,temp,num);
        return dev;
    }
};