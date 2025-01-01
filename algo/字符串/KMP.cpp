#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+6;
char s[N],t[N];
int nxt[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    cin>>(s+1)>>(t+1);
    int n=strlen(s+1),m=strlen(t+1);
    
    for(int i=2,j=0;i<=m;i++){
        while(j && t[j+1]!=t[i])j=nxt[j];
        if(t[j+1]==t[i])j++;
        nxt[i]=j;
    }

    for(int i=1,j=0;i<=n;i++){
        while(j && t[j+1]!=s[i])j=nxt[j];
        if(t[j+1] == s[i])j++;
        if(j==m)cout<<i-m+1<<'\n';
    }

    return 0;
}