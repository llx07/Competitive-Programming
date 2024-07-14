struct SGB{
    const int INF = 1e9;
    struct Node{
        ll sum,mx,md,cnt;
        int tag;
        friend Node operator+(const Node& a,const Node& b){
            Node c;
            c.sum = a.sum+b.sum;
            if(a.mx == b.mx) c.mx = a.mx,c.md = max(a.md, b.md),c.cnt = a.cnt+b.cnt;
            else if(a.mx<b.mx) c.mx = b.mx,c.cnt = b.cnt,c.md = max(a.mx, b.md);
            else c.mx = a.mx,c.cnt = a.cnt,c.md = max(b.mx, a.md);
            c.tag = 0;
            return c;
        }
    }t[N*4];
    
private:
    void modify(int o,int k){ // 最大值加上t
        t[o].sum += t[o].cnt * k;
        t[o].mx += k;
        t[o].tag += k;
    }
    void pushdown(int o){
        int lch=o<<1,rch=o<<1|1;
        int maxn = max(t[lch].mx,t[rch].mx);
        if(t[lch].mx==maxn)modify(lch,t[o].tag);

        if(t[rch].mx==maxn)modify(rch,t[o].tag);
        t[o].tag = 0;
    }
public:
    void print(int o,int l,int r){
        if(l==r){cout << t[o].sum << ' ';return;}
        int lch=o<<1,rch=o<<1|1;
        int mid=(l+r)>>1;
        pushdown(o);
        print(lch,l,mid);print(rch,mid+1,r);
    }

    void update_min(int o,int l,int r,int ql,int qr,int k){
        if(k>=t[o].mx)return;
        if(ql<=l&&r<=qr && t[o].md<k){
            modify(o, k-t[o].mx);
            return;
        }
        pushdown(o);

        int lch=o<<1,rch=o<<1|1;
        int mid=(l+r)>>1;
        if(ql<=mid)update_min(lch,l,mid,ql,qr,k);
        if(qr>mid) update_min(rch,mid+1,r,ql,qr,k);
        t[o] = t[lch]+t[rch];
    }

    Node query(int o,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr)return t[o];
        pushdown(o);
        int lch=o<<1,rch=o<<1|1;
        int mid=(l+r)>>1;
        if(qr<=mid)return query(lch,l,mid,ql,qr);
        if(ql>mid)return query(rch,mid+1,r,ql,qr);
        return query(lch,l,mid,ql,qr)+query(rch,mid+1,r,ql,qr);
    }

    template<typename RandomIterator>
    void build(int o,int l,int r,const RandomIterator& arr){
        t[o].tag = 0;
        if(l==r){
            t[o] = {arr[l],arr[l],-INF,1,0};
            return;
        }
        int lch=o<<1,rch=o<<1|1;
        int mid=(l+r)>>1;
        build(lch,l,mid,arr);build(rch,mid+1,r,arr);
        t[o] = t[lch] + t[rch];
    }
}t;