int L[N],R[N],tot;
int ver[N],sz[N],big[N];
void dfs0(int u,int fa){
    L[u] = ++tot;
    ver[tot]=u;
    sz[u] = 1;
    for(int v:G[u]){
        if(v!=fa){
            dfs0(v,u);
            sz[u]+=sz[v];
            if(!big[u] || sz[big[u]]<sz[v])big[u]=v;
        }
    }
    R[u] = tot; 
}

void dfs(int u,int fa,bool keep){
    for(int v:G[u]){
        if(v!=fa && v!=big[u])
            dfs(v,u,false);
    }
    if(big[u]) dfs(big[u],u,true);

    for(int v:G[u]){
        for(int i=L[v]; i<=R[v]; i++){
            //【加入】 ver[i] 贡献
        }
    }

    //【加入】 u 贡献
    
    if(!keep){
        for(int i=L[u]; i<=R[u]; i++){
            //【删除】 ver[i] 贡献
        }
    }
}