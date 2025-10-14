class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m=p.length();
        int n=s.length();
        unordered_map<char,int>MAP;
        int count=0;
        for(int i=0;i<m;i++){
            MAP[p[i]]++;
        }
        int len=m;
        vector<int>result;
        for(int i=0;i<n;i++){
            MAP[s[i]]--;
            if(MAP[s[i]]>=0){
                len--;
            }
            // Removing char from window
            if(i>=m){
                MAP[s[i-m]]++;
                if(MAP[s[i-m]]>0){
                    len++;
                }
            }
            if(len==0){
                result.push_back(i-m+1);
            }
        }
        return result;
    }
};
