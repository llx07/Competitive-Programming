struct Euler{
    vector<int> G[N];
    int cur[N];
    stack<int> ans;
    void add_edge(int u,int v){
        G[u].push_back(v);
    }
    void clear(int n){
        for(int i=0;i<=n;i++)G[i].clear();
        while(ans.size())ans.pop();
    }
    void dfs(int u){
        for(int& i=cur[u];i<G[u].size();){ 
            i++; 
            dfs(G[u][i-1]); 
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