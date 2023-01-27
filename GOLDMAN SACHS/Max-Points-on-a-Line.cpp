class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       
        int n=points.size();
        int maxi=1;
        for(int i=0;i<n-1;i++){
             map<double,int>dev;
            for(int j=i+1;j<n;j++){
                if(points[i][1]==points[j][1]){
                    dev[-90]++;
                }
                else{
                    double x=(double)(points[j][0]-points[i][0])/(double)(points[j][1]-points[i][1]);
                    dev[x]++;
                }
            }
        
        int temp=0;
        for(auto x:dev){
            temp=max(temp,x.second+1);}
            maxi=max(maxi,temp);
        }
return maxi;
    }
};