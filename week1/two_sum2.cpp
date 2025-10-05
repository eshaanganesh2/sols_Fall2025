class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        int lptr=0;
        int rptr=n-1;
        vector<int>result;
        while(lptr<rptr){
            int sum=numbers[lptr]+numbers[rptr];
            if(sum==target){
                result.push_back(lptr+1);
                result.push_back(rptr+1);
                break;
            }
            if(sum<target){
                lptr++;
            }
            if(sum>target){
                rptr--;
            }
        }
        return result;
    }
};
