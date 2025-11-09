class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>stk;
        int n=temperatures.size();
        vector<int>result(n,0);
        for(int i=n-1;i>=0;i--){
            while(!stk.empty()){
                if(temperatures[i]<stk.top().first){
                    break;
                }
                stk.pop();
            }
            if(stk.empty()){
                result[i]=0;
            }
            else{
                result[i]=stk.top().second-i;
            }
            stk.push({temperatures[i],i});
        }
        return result;
    }
};
