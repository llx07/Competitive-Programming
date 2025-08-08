inline mint C(int n,int r){
    if(r<0 || r>n)return 0;
    static vector<mint> f{1, 1}, finv{1, 1};
    while(n >= (int)f.size()){
        int m = f.size();
        f.resize(m << 1), finv.resize(m << 1);
        for (int i = m; i < m << 1; i++)f[i]=f[i-1]*i,finv[i]=finv[i-1]/i;
    }
    return f[n]*finv[r]*finv[n-r];
}