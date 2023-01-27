class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        int n=c.size();
        int maxi=1e+9;
        map<int,int>dev;
        for(int i=0;i<n;i++){
           if(dev.find(c[i])!=dev.end()){
               maxi=min(maxi,i-dev[c[i]]+1);
           }
           dev[c[i]]=i;
        }
        if(maxi==1e+9) {return -1;}
        else{
    return maxi;}
    }
};