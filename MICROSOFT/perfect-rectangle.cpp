class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>dev;
        for(auto it:rectangles){
            dev[{it[0],it[1]}]++;
            dev[{it[2],it[3]}]++;
            dev[{it[0],it[3]}]--;
            dev[{it[2],it[1]}]--;
        }
        int count=0;
        for( auto it=dev.begin();it!=dev.end();it++){
            if(abs(it->second)==1){
                count++;
            }
            else if(abs(it->second)!=1&&it->second!=0){
                return false;
            }
        }
        return count==4;
    }
};