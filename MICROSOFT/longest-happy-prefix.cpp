class Solution {
public:
    vector<int> prefix_function(string s){
        int n=s.size();
        vector<int> dev(n,0);
        for(int i=1;i<n;++i){
            int j = dev[i-1];
            while(j>0 && s[i]!=s[j]) 
                j=dev[j-1];
            if(s[i]==s[j])
                 ++j;
            dev[i]=j;
        }
        return dev;
    }
    string longestPrefix(string s) {
        vector<int> temp = prefix_function(s);
        string str="";
        int n=s.size();
        str = s.substr(0,temp[n-1]);
        return str;
    }
};