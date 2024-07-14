struct BIT{
    int t[N];
    void add(int i,int x){for(;i<N;i+=i&-i)t[i]+=x;}
    int query(int i){int da=0;for(;i;i-=i&-i)da+=t[i];return da;}
    int query(int l,int r){return query(r)-query(l-1);}
}t;