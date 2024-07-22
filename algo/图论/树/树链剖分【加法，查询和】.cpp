template<typename T= int >
struct HLDecomposition{
    vector<vector<int>> G;
    vector<int> dep,fa,sz,hson,dfn,top;
    int d,root;
    Seg<T> seg;
    HLDecomposition(int n,int _root):G(n+1),dep(n+1),fa(n+1),sz(n+1),hson(n+1),dfn(n+1),top(n+1),seg(n){
        d = 0, root = _root;
    }
    void add_edge(int u,int v){G[u].push_back(v);G[v].push_back(u);}
    void dfs1(int u,int f){
        dep[u]=dep[f]+1;
        fa[u]=f;sz[u]=1;
        for(int v:G[u]){
            if(v==f)continue;
            dfs1(v,u);sz[u]+=sz[v];
            if(sz[v]>sz[hson[u]])hson[u]=v;
        }
    }
    void dfs2(int u,int t){
        dfn[u]=++d;top[u]=t;
        if(hson[u])dfs2(hson[u],t);
        for(int v:G[u]){
            if(v==fa[u] || v==hson[u])continue;
            dfs2(v,v);
        } 
    }
    void init(){dfs1(root,0);dfs2(root,root);}
    template<typename Iter>
    void assign(Iter a){
        vector<T> b(d+1);
        for(int i=1;i<=d;i++)b[dfn[i]]=a[i];
        seg.build(1,1,d,b.begin());
    }
    void add_subtree(int u,T w){seg.add(1,1,d,dfn[u],dfn[u]+sz[u]-1,w);}
    void add_path(int u,int v,T w){
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            seg.add(1,1,d,dfn[top[u]],dfn[u],w);
            u = fa[top[u]];
        }
        
        if(dep[u]<dep[v])swap(u,v);
        seg.add(1,1,d,dfn[v],dfn[u],w);
    }
    T query_subtree(int u){return seg.query(1,1,d,dfn[u],dfn[u]+sz[u]-1);}
    T query_path(int u,int v){
        T ans = 0;
        while(top[u]!=top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            ans += seg.query(1,1,d,dfn[top[u]],dfn[u]);
            u = fa[top[u]];
        }
        if(dep[u]<dep[v])swap(u,v);
        ans += seg.query(1,1,d,dfn[v],dfn[u]);
        return ans;
    }
};
