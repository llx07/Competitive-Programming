int dep[N],dfn[N],sz[N],tot,fa[N][20];
vector<int> G[N];

void dfs(int u,int f){
    dep[u] = dep[f] + 1;
    sz[u] = 1; dfn[u] = ++tot;
    fa[u][0] = f;
    for(int i=1;i<=__lg(dep[u]);i++){
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }
    for(int v:G[u]){
        if(v==f)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int lca(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    while(dep[u]<dep[v])v = fa[v][__lg(dep[v]-dep[u])];
    if(u==v)return u;
    for(int i=__lg(dep[u]);i>=0;i--){
        if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}

int n;
struct BIT{
    int t[N]; // 可能需要开 long long！
    void add(int x,int v){
        if(!x)return; // 忽略 x = 0
        for(;x<=n;x+=x&-x)t[x]+=v;
    }
    int query(int x){
        int ans = 0;
        for(;x;x-=x&-x)ans+=t[x];
        return ans;
    }

    // type 1: 单点加，路径查询
    void add_u(int u,int x){
        add(dfn[u],x);
        add(dfn[u]+sz[u],-x);
    }
    int query_path(int u,int v){
        int w = lca(u,v);
        return query(dfn[u])+query(dfn[v])-query(dfn[w])-query(dfn[fa[w][0]]);
    }
}bit;