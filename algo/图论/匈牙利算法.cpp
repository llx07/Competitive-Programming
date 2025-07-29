vector<int> G[N];

int match[N];
bool used[N];

bool dfs(int u){
    for(int v:G[u]){
        if(used[v])continue;
        used[v]=1;
        if(match[v]==0 || dfs(match[v])){
            match[v]=u;
            return 1;
        }
    }
    return 0;
}

int solve(){
    int ans;
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        ans+=dfs(i);
    }
    return ans;
}