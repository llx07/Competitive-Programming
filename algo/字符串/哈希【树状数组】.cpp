const int MOD = 1e9+7;
const int B   = 19260817;

inline int lowbit(int x){return x&-x;}

int n;

int bp[N];
struct BIT{
    int t[N];
    void add(int x,int v){
        v = (v+MOD)%MOD; v = (ll)v*bp[x]%MOD;
        for(int i=x;i<=n;i+=lowbit(i))t[i]=(t[i]+v)%MOD;
    }
    int query(int r){
        int ans = 0;
        for(int i=r;i;i-=lowbit(i))ans=(ans+t[i])%MOD;
        return ans;
    }
    int query(int l,int r){
        int res = (query(r)-query(l-1)+MOD)%MOD;
        return (ll)res*bp[n-r]%MOD;
    }
}



    bp[0]=1;
    for(int i=1;i<N;i++)bp[i]=(ll)bp[i-1]*B%MOD;



    