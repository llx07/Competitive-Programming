template<typename T>
struct STmax{
    vector<vector<T>> t;
    STmax(const vector<T>& a):t(a.size(),vector<T>(__lg(a.size())+1)){
        for(int i=0;i<a.size();i++)t[i][0]=a[i];
        for(int j=1;j<=__lg(a.size());j++)for(int i=0;i+(1<<j)-1<a.size();i++)
            t[i][j] = max(t[i][j-1],t[i+(1<<(j-1))][j-1]);
    } 
    STmax(const T* a,int n):t(n,__lg(n)+1){
        for(int i=0;i<n;i++)t[i][0]=a[i];
        for(int j=1;j<=__lg(n);j++)for(int i=0;i+(1<<j)-1<n;i++)
            t[i][j] = max(t[i][j-1],t[i+(1<<(j-1))][j-1]);
    } 
    T query(int l,int r){
        int o = __lg(r-l+1);return max(t[l][o],t[r-(1<<o)+1][o]);
    }
};

template<typename T>
struct STmin{
    vector<vector<T>> t;
    STmin(const vector<T>& a):t(a.size(),vector<T>(__lg(a.size())+1)){
        for(int i=0;i<a.size();i++)t[i][0]=a[i];
        for(int j=1;j<=__lg(a.size());j++)for(int i=0;i+(1<<j)-1<a.size();i++)
            t[i][j] = min(t[i][j-1],t[i+(1<<(j-1))][j-1]);
    } 
    STmin(const T* a,int n):t(n,__lg(n)+1){
        for(int i=0;i<n;i++)t[i][0]=a[i];
        for(int j=1;j<=__lg(n);j++)for(int i=0;i+(1<<j)-1<n;i++)
            t[i][j] = min(t[i][j-1],t[i+(1<<(j-1))][j-1]);
    } 
    T query(int l,int r){
        int o = __lg(r-l+1);return min(t[l][o],t[r-(1<<o)+1][o]);
    }
};