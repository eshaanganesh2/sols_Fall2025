class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        while(i<n){
            if(s[i]==' '){
                i++;
            }
            else{
                break;
            }
        }
        bool neg_flag=false;
        if(s[i]=='+'||s[i]=='-'){
            neg_flag=s[i]=='-'?true:false;
            i++;
        }
        int result=0;
        while(i<n&&s[i]>='0'&&s[i]<='9'){
            if(INT_MAX/10<result||INT_MAX/10==result&&s[i]>'7'){
                if(neg_flag){
                    result=INT_MIN;
                }
                else{
                    result=INT_MAX;
                }
                return result;
            }
            result=(result*10)+(s[i]-'0');
            i++;
        }
        if(neg_flag){
            result=-result;
        }
        return result;
    }
};
