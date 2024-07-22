template <class S,
          class F, auto mapping>
struct SegBase{
    static_assert(std::is_convertible_v<decltype(mapping), std::function<S(S, F)>>,"mapping must work as S(F, S)");
    
    vector<S> t;
    vector<F> lazy;
    SegBase(int n):t(n*4+1),lazy(n*4+1){};
    void apply(int o,int l,int r,F& w){
        t[o]=mapping(t[o],w);
        lazy[o]=lazy[o]+w;
    }
    void pushdown(int o,int l,int r){
        int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
        apply(lch,l,mid,lazy[o]),apply(rch,mid+1,r,lazy[o]);
        lazy[o]=F{};
    }
    void modify(int o,int l,int r,int ql,int qr,F qk){
        if(ql<=l&&r<=qr)return apply(o,l,r,qk);
        pushdown(o,l,r);
        int lch=o<<1,rch=o<<1|1,mid=(l+r)>>1;
        if(ql<=mid)modify(lch,l,mid,ql,qr,qk);
        if(qr>mid) modify(rch,mid+1,r,ql,qr,qk);
        t[o]=t[lch]+t[rch];
    }
    S query(int o,int l,int r,int ql,int qr){
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