template<typename T= int >
struct HLDecomposition{
    vector<vector<int>> G;
    vector<int> dep,fa,sz,hson,dfn,id,top;
    int d,root,edge_cnt,n;
    struct SegHLD{
        vector<T> t,lazy;
        SegHLD(int n):t(n*4+1),lazy(n*4+1){};
        void apply(int o,int l,int r,T w){t[o] += (r-l+1)*w,lazy[o] += w;}
        void pushdown(int o,int l,int r){
            int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
            apply(lch,l,mid,lazy[o]),apply(rch,mid+1,r,lazy[o]);
            lazy[o]=0;
        }
        void add(int o,int l,int r,int ql,int qr,T qk){
            // assert(ql<=qr);
            if(ql<=l&&r<=qr)return apply(o,l,r,qk);
            pushdown(o,l,r);
            int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
            if(ql<=mid)add(lch,l,mid,ql,qr,qk);
            if(qr>mid) add(rch,mid+1,r,ql,qr,qk);
            t[o]=t[lch]+t[rch];
        }
        T query(int o,int l,int r,int ql,int qr){
            // assert(ql<=qr);
            if(ql<=l&&r<=qr)return t[o];
            pushdown(o,l,r);
            int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
            if(qr<=mid)return query(lch,l,mid,ql,qr);
            if(ql>mid)return query(rch,mid+1,r,ql,qr);
            return query(lch,l,mid,ql,qr)+query(rch,mid+1,r,ql,qr);
        }
        template<typename Iter>
        void build(int o,int l,int r,const Iter& a){
            lazy[o]=0;
            if(l==r){t[o]=a[l];return;}
            int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
            build(lch,l,mid,a),build(rch,mid+1,r,a);
            t[o]=t[lch]+t[rch];
        }
    }seg;
private:
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
        dfn[u]=++d,id[dfn[u]]=u,top[u]=t;
        if(hson[u])dfs2(hson[u],t);
        for(int v:G[u]){
            if(v==fa[u] || v==hson[u])continue;
            dfs2(v,v);
        } 
    }
    void init(){dfs1(root,0);dfs2(root,root);}

public:   
    HLDecomposition(int _n,int _root):G(_n+1),dep(_n+1),fa(_n+1),sz(_n+1),hson(_n+1),dfn(_n+1),id(_n+1),top(_n+1),seg(_n){
        d = 0, root = _root , edge_cnt =0, n = _n;
        if(_n==1)init();
    }
    void add_edge(int u,int v){
        edge_cnt++;
        G[u].push_back(v);G[v].push_back(u);
        if(edge_cnt==n-1)init();
    }

    template<typename Iter>
    void assign(const Iter& a){
        vector<T> b(d+1);
        for(int i=1;i<=d;i++)b[dfn[i]]=a[i];
        seg.build(1,1,d,b.begin());
    }
    int lca(int u,int v){
        while(top[u] != top[v]){
            if(dep[top[u]]<dep[top[v]])swap(u,v);
            u=fa[top[u]];
        }
        if(dep[u]>dep[v])swap(u,v);
        return u;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-(dep[lca(u,v)]<<1);
    }  
    int kth_fa(int u,int k){
        while(k>=dfn[u]-dfn[top[u]]+1&&u!=root){
            k-=(dfn[u]-dfn[top[u]]+1);
            u=fa[top[u]];
        }
        return id[dfn[u]-k];
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
