int f[N],inv[N];
void init(){
    inv[0]=f[0]=inv[1]=f[1]=1;
    for(int i=2;i<N;i++)inv[i]=((ll)MOD-MOD/i)*inv[MOD%i]%MOD;
    for(int i=2;i<N;i++)inv[i]=(ll)inv[i-1]*inv[i]%MOD;
    for(int i=2;i<N;i++)f[i]=(ll)f[i-1]*i%MOD;
}
inline int C(int n,int r){return (r<0)?0:((ll)f[n]*inv[r]%MOD*inv[n-r]%MOD);}
