class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int ans = 0;
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
            indegree[u]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cour = q.front();
            q.pop();
            ans++;

            for(auto it : adj[cour]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans == numCourses;

    }
};
