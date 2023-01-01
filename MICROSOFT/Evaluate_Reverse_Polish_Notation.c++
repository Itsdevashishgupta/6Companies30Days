class Solution {
public:
 int evalRPN(vector<string>& tokens) {
    stack<long> dev;

    for(auto s:tokens) {
        if(s.size()>1 || isdigit(s[0])) dev.push(stoi(s));
        else {
            auto x2=dev.top(); dev.pop();
            auto x1=dev.top(); dev.pop();
            switch(s[0]) {
                case '+': x1+=x2; break;
                case '-': x1-=x2; break;
                case '*': x1=(x1*x2); break;
                case '/': x1/=x2; break;
            }
            dev.push(x1);
        }
    }
    return dev.top();
}
};