template<typename T= int >
struct Seg{
    vector<T> t,lazy;
    Seg(int n):t(n*4+1),lazy(n*4+1){};
    void apply(int o,int l,int r,T w){t[o] += (r-l+1)*w,lazy[o] += w;}
    void pushdown(int o,int l,int r){
        int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
        apply(lch,l,mid,lazy[o]),apply(rch,mid+1,r,lazy[o]);
        lazy[o]=0;
    }
    void add(int o,int l,int r,int ql,int qr,T qk){
        if(ql<=l&&r<=qr)return apply(o,l,r,qk);
        pushdown(o,l,r);
        int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
        if(ql<=mid)add(lch,l,mid,ql,qr,qk);
        if(qr>mid) add(rch,mid+1,r,ql,qr,qk);
        t[o]=t[lch]+t[rch];
    }
    T query(int o,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr)return t[o];
        pushdown(o,l,r);
        int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
        if(qr<=mid)return query(lch,l,mid,ql,qr);
        if(ql>mid)return query(rch,mid+1,r,ql,qr);
        return query(lch,l,mid,ql,qr)+query(rch,mid+1,r,ql,qr);
    }
    template<typename Iter>
    void build(int o,int l,int r,Iter a){
        lazy[o]=0;
        if(l==r){t[o]=a[l];return;}
        int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
        build(lch,l,mid,a),build(rch,mid+1,r,a);
        t[o]=t[lch]+t[rch];
    }
};