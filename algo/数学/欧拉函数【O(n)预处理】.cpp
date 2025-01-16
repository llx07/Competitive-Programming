int p[N/2],cnt,phi[N];
bool vis[N];

void init(){
    vis[1]=1;phi[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            p[++cnt]=i;
            phi[i]=i-1; // 质数
        }
        for(int j=1;j<=cnt&&i*p[j]<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0){
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            else phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
}