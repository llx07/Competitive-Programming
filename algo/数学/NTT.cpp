#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
int ksm(int a,int b){ 
    int r = 1;
    while(b){
        if(b&1)r=(ll)r*a%MOD;
        a=(ll)a*a%MOD;
        b>>=1;
    }
    return r;
}
const int G = 3, INVG = ksm(G,MOD-2); 

const int N = 4e6+5;
int rev[N];
void NTT(int* f,int n,bool flag){
    for(int i=0;i<n;i++){
        if(i<rev[i])swap(f[i],f[rev[i]]);
    }
    for(int p=2;p<=n;p<<=1){
        int g = ksm(flag?INVG:G, (MOD-1)/p); 
        for(int j=0;j<n;j+=p){
            int gnow = 1;
            for(int k=j;k<(j|p>>1);k++){
                int t = (ll)f[k|p>>1] * gnow % MOD;
                f[k|p>>1] = f[k] - t; if(f[k|p>>1]<0)f[k|p>>1]+=MOD; 
                f[k] = f[k] + t;      if(f[k]>=MOD)f[k]-=MOD;
                gnow = (ll)gnow * g % MOD;
            }
        }
    }

    int invN = ksm(n, MOD-2);
    if(flag)for(int i=0;i<n;i++)f[i]=(ll)f[i]*invN%MOD; 
}

int f[N],g[N]; 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++)cin>>f[i];
    for(int i=0;i<=m;i++)cin>>g[i];

    for(m+=n,n=1;n<=m;n<<=1);
    for(int i=0;i<n;i++){
        rev[i]=rev[i>>1]>>1;
        if(i&1)rev[i]|=n>>1;
    }

    NTT(f,n,0);NTT(g,n,0);
    for(int i=0;i<n;i++)f[i]=(ll)f[i]*g[i]%MOD;
    NTT(f,n,1);
    for(int i=0;i<=m;i++){
        cout<<f[i]<<' ';
    }
    cout<<'\n';
    return 0;
}