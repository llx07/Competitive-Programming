struct TwoSAT{
private:
    int n;
    vector<vector<int>> G;
    vector<int> low,dfn;
    stack<int> s;
    int d,scc;vector<int> belong;
    void tarjan(int u){
        low[u]=dfn[u]=++d;
        s.push(u);
        for(int v:G[u]){
            if(!dfn[v])tarjan(v),low[u] = min(low[u], low[v]);
            else if(!belong[v])low[u] = min(low[u],dfn[v]);
        }
        if(low[u]==dfn[u]){
            ++scc;
            while(s.top()!=u)belong[s.top()]=scc,s.pop();
            belong[u]=scc,s.pop();
        }
    }
public:
    vector<int> sol; // must call satisfiable() before accessing the solution
    TwoSAT(int _n):G(_n*2+1),low(_n*2+1),dfn(_n*2+1),belong(_n*2+1)
                    ,sol(_n+1){
        n = _n;
        d = scc = 0;
    }
    void add_edge(int u,int v){G[u].push_back(v);}
    void implies(int i,bool a,int j,bool b){ // x_i = a -> x_j = b   
        add_edge(i + (a?0:n), j + (b?0:n));
        add_edge(j + (b?n:0), i + (a?n:0));
    }
    void at_least_one(int i,bool a,int j,bool b){ // (x_i=a) ∨ (x_j=b) = True
        add_edge(i + (a?n:0), j + (b?0:n));
        add_edge(j + (b?n:0), i + (a?0:n));
    }
    void equal(int i,bool a){ // x_i = a
        add_edge(i + (a?n:0), i+(a?0:n));
    }
    void or_clause(int i,int j,bool c){ // x_i | x_j = c
        if(c) at_least_one(i,1,j,1);
        else equal(i,0),equal(j,0);
    }
    void and_clause(int i,int j,bool c){ // x_i & x_j = c
        if(c) equal(i,1),equal(j,1);
        else at_least_one(i,0,j,0);
    }
    void xor_clause(int i,int j,bool c){ // x_i ⊕ x_j = c
        if(c) or_clause(i,j,1),or_clause(i+n,j+n,1);
        else  or_clause(i+n,j,1),or_clause(i,j+n,1);
    }
    bool satisfiable(){
        for(int i=1;i<=n*2;i++)if(!dfn[i])tarjan(i);
        for(int i=1;i<=n;i++){
            if(belong[i] == belong[i+n])return 0;
            sol[i] = (belong[i]<belong[i+n])?1:0;
        }
        return 1;
    }
};