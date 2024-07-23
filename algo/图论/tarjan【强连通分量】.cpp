vector<int> G[N];
int low[N],dfn[N],bel[N],d,scc;
stack<int> s;

void tarjan(int u){
    low[u]=dfn[u]=++d;
    s.push(u);
    for(int v:G[u]){
        if(!dfn[v])tarjan(v),low[u] = min(low[u], low[v]);
        else if(!bel[v])low[u] = min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u]){
        ++scc;
        while(s.top()!=u)bel[s.top()]=scc,s.pop();
        bel[u]=scc,s.pop();
    }
}