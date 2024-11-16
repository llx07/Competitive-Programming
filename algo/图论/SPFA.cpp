struct Edge{
    int v,w;
};
vector<Edge> G[N];

int n,m;

int d[N], cnt[N];
bool vis[N];
// return(bool) 是否有负环
bool spfa(int s){
    memset(d, 0x3f, sizeof(d));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    d[s]=0,cnt[s]=0;
    queue<int> q;
    q.push(s);vis[s]=1;
    while(q.size()){
        int u = q.front();q.pop();vis[u]=0;
        for (auto& e:G[u]){
            int v=e.v,w=e.w;
            if(d[v] > d[u]+w){
                d[v]   = d[u]+w;
                cnt[v]++;
                if(cnt[v]>n)return 1;
                if(!vis[v])q.push(v),vis[v]=1;
            }
        }
    }
    return 0;
}