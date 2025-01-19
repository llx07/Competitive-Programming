void init(){
    vis[1]=1;d[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]){
            p[++cnt]=i,f[i]=1;
            d[i]=2;
        }
        for(int j=1;j<=cnt&&i*p[j]<N;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0){
                f[i*p[j]]=f[i]+1;
                d[i*p[j]]=d[i]/(f[i]+1)*(f[i]+2);
                break;
            }
            f[i*p[j]]=1;
            d[i*p[j]]=d[i]*2;
        }
    }
}