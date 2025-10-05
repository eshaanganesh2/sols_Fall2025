class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,1);
        int left_prod=1;
        int right_prod=1;
        for(int i=1;i<n;i++){
            left_prod*=nums[i-1];
            result[i]=left_prod;
        }
        for(int i=n-2;i>=0;i--){
            right_prod*=nums[i+1];
            result[i]=right_prod*result[i];
        }
        return result;
    }
};
