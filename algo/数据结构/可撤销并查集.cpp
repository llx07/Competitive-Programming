struct Revdsu{
    int fa[N],sz[N];
    vector<pair<int&,int>> hisfa,hissz;
    void init(int n){
        for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
        hisfa.clear();hissz.clear();
    }
    int find(int x){
        while(x!=fa[x])x=fa[x];
        return x;
    }
    void unite(int u,int v){
        debug(u,v);
        u=find(u),v=find(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        hisfa.push_back({fa[v],fa[v]});
        hissz.push_back({sz[u],sz[u]});
        fa[v]=u;sz[u]+=sz[v];
    }
    int S(){return hisfa.size();}
    void rev(int S){
        while(hisfa.size()>S){
            auto [a1,a2]=hisfa.back();hisfa.pop_back();a1=a2;
            auto [b1,b2]=hissz.back();hissz.pop_back();b1=b2;
        }
    }
}p;