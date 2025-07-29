bool vis[N];
vector<int> G[N];
int sum,rt; // 当前总节点数，根
int sz[N],maxsz[N]; // 子树大小，儿子最大子树
void getrt(int u,int fa){
    sz[u]=1;maxsz[u]=0;
    for(int v:G[u]){
        if(!vis[v] && v!=fa){
            getrt(v,u);
            sz[u]+=sz[v];
            maxsz[u] = max(maxsz[u], sz[v]);
        }
    }
    maxsz[u] = max(maxsz[u], sum-sz[u]);
    if(maxsz[u]<maxsz[rt])rt=u;
}
void dfs(int u,int fa){
    // 统计点分治子树内容
    for(int v:G[u]){
        if(v==fa || vis[v])continue;
        dfs(v,u);
    }
}

void calc(int u){
    for(int v:G[u]){
        if(vis[v])continue;
    
        dfs(v,u);
        // 统计该子树的贡献
    }
}
void dfz(int u){
    vis[u]=1;
    calc(u);
    for(auto v:G[u]){
        if(vis[v])continue;
        sum=sz[v];rt=0;
        getrt(v,0);dfz(rt);
    }
}

void solve(){
    maxsz[0] = 1e9; // 把 0 的最大子树设置为无穷大

    // 读入树

    rt=0;sum=n;
    getrt(1,0);dfz(rt);

    // 统计并输出答案

    for(int i=1;i<=n;i++)G[i].clear(),vis[i]=0;
}