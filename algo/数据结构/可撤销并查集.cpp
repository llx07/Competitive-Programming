struct Revdsu{
    int fa[N],sz[N];
    vector<pair<int&,int>> his;
    void init(int n){
        for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
        his.clear();
    }
    int find(int x){
        while(x!=fa[x])x=fa[x];
        return x;
    }
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        his.push_back({fa[v],fa[v]});
        his.push_back({sz[u],sz[u]});
        fa[v]=u;sz[u]+=sz[v];
    }
    int S(){return his.size();}
    void rev(int S){
        while(his.size()>S){auto [a1,a2]=his.back();his.pop_back();a1=a2;}
    }
}dsu;