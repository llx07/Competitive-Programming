const int N = 1e5+5;
vector<int> G[N];

int dfn[N],low[N],d=0;
bool cut[N];

void tarjan(int u,int fa){
    dfn[u]=low[u]=++d;
    int cnt = 0;
    for(int v:G[u]){
        if(!dfn[v]){
            cnt++;
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if((low[v]>=dfn[u] && u!=fa) // 不是根
                || (u==fa && cnt>1)){    // 是根
                cut[u]=1;
            }
        }
        else{ // 可以用父亲更新 low[u]
            low[u]=min(low[u],dfn[v]);
        }
    }

}