class Solution {
public:
    bool compare(string str1, string str2,int i){
        int n=str2.length();
        int j=0;
        int m=str1.length();
        while(i<n&&j<m){
            cout<<str1[j]<<str2[i]<<endl;
            if(str1[j]!=str2[i]){
                return false;
            }
            i++;
            j++;
        }
        if(j==m){
            return true;
        }
        return false;
    }
    bool helper(string s, vector<string>& wordDict,int i,vector<int>&dp){
        if(i==s.length()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool result=false;
        for(string word:wordDict){
            if(compare(word,s,i)){
                result=helper(s,wordDict,i+word.length(),dp)||result;
            }
        }
        dp[i]=result;
        return result;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int i=0;
        int n=s.length();
        int m=wordDict.size();
        vector<int>dp(n+1,-1);
        return helper(s,wordDict,i,dp);
    }
};
