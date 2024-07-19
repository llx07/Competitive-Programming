struct Euler{
    struct Edge{
        int to,rev;
        bool exist;
    };
    vector<Edge> G[N];
    int cur[N];
    stack<int> ans;
    void add_edge(int u,int v){
        G[u].push_back(Edge{v,(int)G[v].size(),true});
        if(u!=v)G[v].push_back(Edge{u,(int)G[u].size()-1,true});
    }
    void clear(int n){
        for(int i=0;i<=n;i++)G[i].clear();
        while(ans.size())ans.pop();
    }
    void dfs(int u){
        for(int& i=cur[u];i<G[u].size();){
            i++;
            if(!G[u][i-1].exist)continue;
            G[u][i-1].exist = 0;
            G[G[u][i-1].to][G[u][i-1].rev].exist=0;
            dfs(G[u][i-1].to);
        }
        ans.push(u);
    }
    void output(){
        while(ans.size()){
            cout << ans.top() <<' ';
            ans.pop();
        }
        cout << '\n';
    }
}e;