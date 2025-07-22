
int ch[N][26],fail[N],cnt[N],tot=1;
bool vis[N];
void ins(const string& s){
    int u=1;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        if(!ch[u][c])ch[u][c]=++tot;
        u=ch[u][c];
    }
    cnt[u]++;
}
void getFail(){
    for(int i=0;i<26;i++)ch[0][i]=1;
    fail[1]=0;
    queue<int> q;q.push(1);
    while(q.size()){
        int u=q.front();q.pop();
        for(int i=0;i<26;i++){
            int v=ch[u][i];
            if(!v)ch[u][i]=ch[fail[u]][i];
            else{
                fail[v]=ch[fail[u]][i];
                q.push(v);
            }
        }
    }
}
int query(const string& s){
    int u=1,ans=0;
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        int now=ch[u][c];
        while(now>1 && !vis[now]){
            ans += cnt[now];
            vis[now] = 1;
            now = fail[now];
        }
        u=ch[u][c];
    }
    return ans;
}