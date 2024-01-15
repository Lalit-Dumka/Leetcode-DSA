class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        vector<int> indegree(numCourses,0);
        
        for(int i=0; i<numCourses; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> sol;
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            sol.push_back(cur);
            
            for(auto it: adj[cur]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(sol.size()==numCourses) return sol;
        return {};
        
    }
};