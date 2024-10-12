bool vis[N];
ll d[N];

void dijkstra(int s){
    memset(vis,0,sizeof(vis));
    priority_queue<pair<ll,int>> pq;
    pq.push({0,s});
    d[s]=0;
    while(pq.size()){
        int u = pq.top().second;pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto [v,w]:G[u]){
            if(d[v] == d[u]+w)continue;
            else if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                pq.push({-d[v],v});
            }
        }
    }
}