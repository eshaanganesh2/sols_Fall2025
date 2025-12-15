class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>MAP;
        for(int i=0;i<n;i++){
            MAP[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto x:MAP){
            pq.push({x.second,x.first});
        }
        vector<int>result;
        while(k>0){
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};
