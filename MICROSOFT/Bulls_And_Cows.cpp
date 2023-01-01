class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int count1=0,count2=0;
        map<int,int> dev1;
        map<int,int> dev2;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                count1++;
            else
            {
                dev1[secret[i]-'0']++;
                dev2[guess[i]-'0']++;
            }
            
        }
        for(auto it:dev1)
        {
            if(dev2.find(it.first)!=dev2.end())
            count2+=min(dev2[it.first],it.second);
        }
        string s="";
        s=to_string(count1)+"A"+to_string(count2)+"B";
        return s;
    }
};