int dep[N], dfn[N], tot, st[N][20];
vector<int> G[N];

void dfs(int u,int fa){
    st[++tot][0]=fa;  // 直接记录父亲
    dfn[u]=tot;
    dep[u]=dep[fa]+1;
    for(int v:G[u]){
        if(v==fa)continue;
        dfs(v,u);
    }
}
 
int n;
int get(int u,int v){ // 返回深度较浅的节点
    return dep[u]<dep[v]?u:v;
}
void init(){ // 初始化 ST 表
    for(int j=1;j<20;j++){
        for(int i=1;(i+(1<<j))-1<=n;i++){
            st[i][j] = get(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int lca(int u,int v){
    if(u==v)return u;
    // 记得给左端点+1
    int l=min(dfn[u],dfn[v])+1,r=max(dfn[u],dfn[v]);
    int o = __lg(r-l+1);
    return get(st[l][o],st[r-(1<<o)+1][o]);
}