template<typename T=int>
struct BIT2D{
    int n,m;
    vector<vector<T>> t;
    BIT2D(int _n,int _m):n(_n),m(_m),t(_n+1,vector<T>(_m+1)){}
    void add(int x,int y,int k){
        for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=m;j+=j&-j)t[i][j]+=k;
    }
    void add(int x1,int y1,int x2,int y2,int k){
        add(x1, y1, k);
        add(x1, y2+1, -k);
        add(x2+1, y1, -k);
        add(x2+1, y2+1, k);
    }
    T query(int x,int y){
        T res = 0;
        for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)res+=t[i][j];
        return res;
    };
    T query(int x1,int y1,int x2,int y2){return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);}
};