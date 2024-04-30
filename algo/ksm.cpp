constexpr inline int ksm(int a,int b){
    int r=1;
    while(b){
        if(b&1)r=(ll)r*a%MOD;
        a=(ll)a*a%MOD;
        b>>=1;
    }
    return r;
}