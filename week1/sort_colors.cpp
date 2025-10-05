class Solution {
public:
    void swap(vector<int>&nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int lb=0;
        int ub=n-1;
        int mid=0;
        for(int i=0;i<n;i++){
            if(nums[mid]==1){
                mid++;
            }
            else
            if(nums[mid]==0){
                swap(nums,lb,mid);
                lb++;
                mid++;
            }
            else
            if(nums[mid]==2){
                swap(nums,mid,ub);
                ub--;
            }
        }
    }
};
