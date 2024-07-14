const int N = 2e5+5;
struct Node{
    int l,r;
    int sum;
}t[N<<5];
int tot;
int copy(int o){
    t[++tot]=t[o];
    return tot;
}
int rt[N];
int build(int l,int r){
    int o=++tot;
    if(l==r)return o;
    int mid=(l+r)>>1;
    t[o].l=build(l,mid);
    t[o].r=build(mid+1,r);
    t[o].sum=0;
    return o;
}
int modify(int o,int l,int r,int qi){
    o=copy(o);
    if(l==r){
        t[o].sum++;
        return o;
    }

    int mid=(l+r)>>1;
    if(qi<=mid)t[o].l=modify(t[o].l,l,mid,qi);
    else       t[o].r=modify(t[o].r,mid+1,r,qi);
    t[o].sum=t[t[o].l].sum+t[t[o].r].sum;
    return o;
}
int query(int u,int v,int l,int r,int k){
    if(l==r)return t[v].sum-t[u].sum;
    int mid=(l+r)>>1;
    if(k<=mid)return query(t[u].l,t[v].l,l,mid,k);
    else return query(t[u].r,t[v].r,mid+1,r,k);
}