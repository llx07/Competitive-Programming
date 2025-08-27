struct PAM{ // sum[i] 以 i 结尾的回文串个数
    int ch[N][26],len[N],fail[N],tot=1,now=1,sum[N];
    void build(){
        fail[0]=1, len[1]=-1;
        s = "#" + s;
        for(int i=1;i<s.size();i++){
            int j,v=(s[i]-'a');
            while(s[i-len[now]-1]!=s[i])now=fail[now];
            if(!ch[now][v]){
                len[++tot]=len[now]+2;
                j=fail[now];
                while(s[i-len[j]-1] != s[i])j=fail[j];
                fail[tot]=ch[j][v];
                ch[now][v]=tot;
                sum[tot]=sum[fail[tot]]+1;
            }
            now = ch[now][v];
        }
    }
}pam;