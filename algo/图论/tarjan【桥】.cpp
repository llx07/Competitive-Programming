struct Edge{
    int v,w,id;
};
vector<Edge> G[N];
int low[N],dfn[N],d;
bool bg[N];

void tarjan(int u,int fa){
    dfn[u] = low[u] = ++d;
    for(auto [v,w,id]:G[u]){
        if(v==fa)continue; // 一定不能用父亲更新 low[u]
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v] > dfn[u]){
                bg[id] = 1;
            }
        }
        else{
            low[u]=min(low[u],dfn[v]);
        }
    }
}