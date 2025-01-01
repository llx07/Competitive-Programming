inline mint C(int n,int r){
    static vector<mint> f{1, 1}, finv{1, 1};
    while(n >= f.size()){
        int m = f.size();
        f.resize(m << 1), finv.resize(m << 1);
        for (int i = m; i < m << 1; i++)f[i]=f[i-1]*i,finv[i]=finv[i-1]/i;
    }
    return (r<0)?0:(f[n]*finv[r]*finv[n-r]);
}
