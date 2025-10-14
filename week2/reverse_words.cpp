class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int left=0;
        int right=n-1;
        string result="";
        vector<string>words;
        string temp="";
        while(left<n){
            if(s[left]==' '){
                left++;
                if(temp!=""){
                    words.push_back(temp);
                    temp="";
                }
                continue;
            }
            temp+=s[left];
            left++;
        }
        if(temp!=""){
            words.push_back(temp);
        }
        for(int i=words.size()-1;i>=0;i--){
            result+=words[i]+" ";
        }
        int k=result.length();
        return result.substr(0,k-1);
    }
};
