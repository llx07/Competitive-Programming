template<typename T>
struct ST{
    vector<vector<T>> tmin,tmax;
    ST(const vector<T>& a):
        tmin(a.size(),vector<T>(__lg(a.size())+1)),
        tmax(a.size(),vector<T>(__lg(a.size())+1))
    {
        for(int i=0;i<a.size();i++)tmin[i][0]=tmax[i][0]=a[i];
        for(int j=1;j<=__lg(a.size());j++)for(int i=0;i+(1<<j)-1<a.size();i++)
            tmin[i][j] = min(tmin[i][j-1],tmin[i+(1<<(j-1))][j-1]),
            tmax[i][j] = max(tmax[i][j-1],tmax[i+(1<<(j-1))][j-1]);
    } 
    ST(const T* a,int n):tmin(n,__lg(n)+1),tmax(n,__lg(n)+1){
        for(int i=0;i<n;i++)tmin[i][0]=tmax[i][0]=a[i];
        for(int j=1;j<=__lg(n);j++)for(int i=0;i+(1<<j)-1<n;i++)
            tmin[i][j] = min(tmin[i][j-1],tmin[i+(1<<(j-1))][j-1]),
            tmax[i][j] = min(tmax[i][j-1],tmax[i+(1<<(j-1))][j-1]);
    } 
    T min(int l,int r){int o = __lg(r-l+1);return min(tmin[l][o],tmin[r-(1<<o)+1][o]);}
    T max(int l,int r){int o = __lg(r-l+1);return max(tmax[l][o],tmax[r-(1<<o)+1][o]);}
};


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