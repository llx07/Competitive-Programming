template<typename Cap> struct Dinic{
    struct Edge{int u,v;Cap c,f;};
    int n;
    vector<Edge> edges;
    vector<vector<int>> G;
    vector<int> dis,cur;
    explicit Dinic(int _n):n(_n+1),G(_n+1),dis(_n+1),cur(_n+1){}

    int s,t;
    void add_edge(int u,int v,Cap w){
        edges.push_back(Edge{u,v,w,0}),edges.push_back(Edge{v,u,0,0});
        int m = edges.size();
        G[u].push_back(m-2),G[v].push_back(m-1);
    }

    bool bfs(){
        vector<bool> vis(dis.size());
        dis[s]=0;vis[s]=1;
        queue<int> q;
        q.push(s);
        while(q.size()){
            int u=q.front();q.pop();
            for(auto o:G[u]){
                const auto& e = edges[o];
                if(!vis[e.v] && e.c>e.f){
                    vis[e.v]=1;
                    dis[e.v]=dis[u]+1;
                    q.push(e.v);
                }
            }
        }
        return vis[t];
    }

    Cap dfs(int u,Cap maxflow){
        if(u==t || !maxflow)return maxflow;
        Cap flow = 0;
        for(int& i=cur[u];i<G[u].size();i++){
            auto& e=edges[G[u][i]];
            if(dis[e.v] != dis[e.u]+1)continue;
            Cap f = dfs(e.v,min(maxflow,e.c-e.f));
            flow+=f;
            maxflow-=f;
            e.f+=f;
            edges[G[u][i]^1].f-=f;
            if(!maxflow)return flow;
        }
        return flow;
    }
    Cap flow(int _s,int _t){
        s=_s,t=_t;
        Cap flow = 0;
        while(bfs()){
            fill(cur.begin(), cur.end(), 0);
            flow += dfs(s,numeric_limits<Cap>::max());
        }
        return flow;
    }
};
