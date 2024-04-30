int fa[N],sz[N];
vector<pair<int&,int>> hisfa,hissz;
int find(int x){
    while(x!=fa[x])x=fa[x];
    return x;
}
void unite(int u,int v){
    u=find(u),v=find(v);
    if(u==v)return;
    if(sz[u]<sz[v])swap(u,v);
    hisfa.push_back({fa[v],fa[v]});
    hissz.push_back({sz[u],sz[u]});
    fa[v]=u;sz[u]+=sz[v];
}
void rev(int S){
    while(hisfa.size()>S){
        auto [a1,a2]=hisfa.back();hisfa.pop_back();
        a1=a2;
        auto [b1,b2]=hissz.back();hissz.pop_back();
        b2=b2;
    }
}