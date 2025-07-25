int fa[N][20],dep[N];
vector<int> G[N];
void dfs(int u,int f){
    dep[u]=dep[f]+1;
    fa[u][0]=f;
    // 递推求出fa[u][i]
    for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1]; 
    for(int v:G[u]){
        if(v==f)continue;
        dfs(v,u);
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    // 将两个节点高度设置为相同
    while(dep[u]!=dep[v])u=fa[u][__lg(dep[u]-dep[v])];
    if(u==v)return u;
    // 向上跳尽量多，使得两个节点依然不同
    for(int i=19;i>=0;i--){
        if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    }
    // 此时 u,v 的父亲就是 LCA
    return fa[u][0];
}