vector<int> G[N];
int cur[N];
void dfs(int u){
    for(int& i=cur[u];i<G[u].size();){ 
        i++; // 提前加 i
        dfs(G[u][i-1]); 
        // 在这里往栈中加入边 (u -> G[u][i-1])
    }
    // 在这里加入点 u
    ans.push(u);
}