string s;
struct PAM{
    int ch[N][26],len[N],fail[N],tot=1,now=1;
    int dif[N],slink[N];
    void init(){
        fail[0]=1, len[1]=-1;
    }
    void ins(int i){
        int j,v=(s[i]-'a');
        while(s[i-len[now]-1]!=s[i])now=fail[now];
        if(!ch[now][v]){
            len[++tot]=len[now]+2;
            j=fail[now];
            while(s[i-len[j]-1] != s[i])j=fail[j];
            fail[tot]=ch[j][v];
            ch[now][v]=tot;
            dif[tot] = len[tot] - len[fail[tot]];
            if(dif[tot]==dif[fail[tot]])slink[tot]=slink[fail[tot]];
            else slink[tot]=fail[tot];
        }
        now = ch[now][v];
    }

    int dp[N],g[N];
    int solve(){
        // g[x] 表示一整个等差数列的 dp
        // dp 按照具体题目实现
        memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;
        for(int i=1;i<s.size();i++){
            ins(i);
            for(int u=now;u>1;u=slink[u]){
                g[u] = dp[i-len[slink[u]]-dif[u]];
                if(dif[u]==dif[fail[u]])g[u]=min(g[u],g[fail[u]]);
                dp[i] = min(dp[i], g[u]+1);
            }
        }
        return dp[s.size()-1];
    }
}pam;