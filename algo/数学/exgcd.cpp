ll exgcd(ll a,ll b,ll& x,ll& y){
    if(!b){x=1,y=0;return a;}
    ll g = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return g;
}