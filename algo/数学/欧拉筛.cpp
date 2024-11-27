int p[N/2],cnt;
bool vis[N];

void init(){
    vis[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            p[++cnt]=i;
        }
        for(int j=1;j<=cnt&&i*p[j]<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}