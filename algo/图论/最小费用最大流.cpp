template<int _N,typename Cap=int,typename Cost=int>
struct MCMF{
    struct Edge{
        int u,v;
        Cost w;
        Cap c,f; 
    };

    int maxnode;

    vector<Edge> edges; 
    vector<int> G[_N];
    void add_edge(int u,int v,Cap cap,Cost cst){
        debug(u,v,cap,cst);
        edges.push_back({u,v,cst,cap,0}); 
        edges.push_back({v,u,-cst,0,0});
        auto cnt = edges.size();
        G[u].push_back(cnt-2);
        G[v].push_back(cnt-1);
        maxnode = max(maxnode,max(u,v));
    }

    Cap INFFLOW = numeric_limits<Cap>::max();
    Cost INFDIS = numeric_limits<Cost>::max()/2;

    int _s,_t;
    int fa[_N];
    bool inq[_N]; 
    Cost d[_N],cost=0;
    Cap a[_N],flow=0;

    bool _SPFA(){
        fill(d,d+_N,INFDIS);
        d[_s]=0;a[_s]=INFFLOW;
        queue<int> q;
        q.push(_s);inq[_s]=1;
        while(q.size()){
            int u=q.front();
            q.pop();inq[u]=0;
            for(int ind:G[u]){
                auto& edge = edges[ind];
                if(edge.c > edge.f && d[edge.v] > d[u] + edge.w){
                    d[edge.v]=d[u]+edge.w;
                    a[edge.v]=min(a[u],edge.c-edge.f);
                    fa[edge.v] = ind;
                
                    if(!inq[edge.v]){
                        q.push(edge.v);inq[edge.v]=1;
                    }
                }
            }
        }
        if(d[_t]==INFDIS)return 0;
        flow += a[_t],cost += a[_t]*d[_t]; 
        int now = _t;
        while(now!=_s){
            int ind = fa[now];
            edges[ind].f += a[_t]; 
            edges[ind^1].f -= a[_t]; 
            now = edges[ind].u;
        }
        return 1;
    }
    pair<Cap,Cost> flow(int s,int t){
        flow=0,cost=0;
        _s=s,_t=t;
        while(_SPFA());
        return {flow,cost};
    }
    void clear(){
        for(int i=0;i<=maxnode;i++)G[i].clear();
        edges.clear();
        maxnode=0;
    }
};
