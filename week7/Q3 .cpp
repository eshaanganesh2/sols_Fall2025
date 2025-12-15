class Solution {
public:
    bool helper(int numCourses, vector<vector<int>>&adj, int i, vector<int>&visited, stack<int>&stk){
        visited[i]=1;
        bool flag=true;
        for(auto x:adj[i]){
            if(visited[x]==1){
                flag=false;
                return false;
            }
            else{
                if(visited[x]!=2){
                    if(!helper(numCourses,adj,x,visited,stk)){
                        return false;
                    }
                }
            }
        }
        if(!flag){
            return false;
        }
        else{
            stk.push(i);
            visited[i]=2;
            return true;
        }
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            int src=prerequisites[i][1];
            int dest=prerequisites[i][0];
            adj[src].push_back(dest);
        }
        stack<int>stk;
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]!=2&&!helper(numCourses,adj,i,visited,stk)){
                return {};
            }   
        }
        vector<int>result;
        while(!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};
