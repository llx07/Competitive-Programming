// 空间记得开两倍大！
int dep[N];
int e[N*2],pos[N],tot,st[N*2][20];
vector<int> G[N];

void dfs(int u,int fa){
    e[++tot]=u; // 递归开始记录 
    pos[u]=tot; // 记录第一次访问的时间
    dep[u]=dep[fa]+1;
    for(int v:G[u]){
        if(v==fa)continue;
        dfs(v,u);
        e[++tot]=u; // 递归回溯记录
    }
}

int n;
void init(){ // 初始化 ST 表
    for(int i=1;i<=2*n-1;i++)st[i][0]=e[i];
    for(int j=1;j<20;j++){
        for(int i=1;(i+(1<<j))-1<=2*n-1;i++){
            st[i][j] = (dep[st[i][j-1]] < dep[st[i+(1<<(j-1))][j-1]])
                ? st[i][j-1]
                : st[i+(1<<(j-1))][j-1];
        }
    }
}
int lca(int u,int v){
    int l=pos[u],r=pos[v];
    if(l>r)swap(l,r);
    int o = __lg(r-l+1);
    if(dep[st[l][o]]<dep[st[r-(1<<o)+1][o]])return st[l][o];
    return st[r-(1<<o)+1][o];
}