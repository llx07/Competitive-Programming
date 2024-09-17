template<typename T = int >
struct BIT{
    int n;
    vector<T> t;
    BIT(int _n):n(_n+1),t(_n+2){}
    void add(int i,T x){i++;for(;i<=n;i+=i&-i)t[i]+=x;}
    void add(int l,int r,T x){add(l,x);add(r+1,-x);}
    T query(int i){i++;T da=0;for(;i;i-=i&-i)da+=t[i];return da;}
    T query(int l,int r){return query(r)-query(l-1);}
};