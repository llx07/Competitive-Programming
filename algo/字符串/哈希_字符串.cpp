const int B = 1145141;
const int M1 = (int)1e9+9, M2 = (int)1e9+7;
struct Hash{
    int x,y;
    Hash():x(0),y(0){}
    Hash(int v):x(v),y(v){}
    Hash(char v):x(v),y(v){}
    Hash(int a,int b):x(a),y(b){}
    Hash operator+(int k){return {(x+k)%M1,(y+k)%M2};}
    Hash operator+(const Hash& a){return {(x+a.x)%M1,(y+a.y)%M2};}
    Hash& operator+=(const Hash& a){x=(x+a.x)%M1,y=(y+a.y)%M2;return *this;}
    Hash operator-(int k){return {(x-k+M1)%M1,(y-k+M2)%M2};}
    Hash operator-(const Hash& a){return {(x-a.x+M1)%M1,(y-a.y+M2)%M2};}
    Hash& operator-=(const Hash& a){x=(x-a.x+M1)%M1,y=(y-a.y+M2)%M2;return *this;}
    Hash operator*(int k){return {(int)((ll)x*k%M1),(int)((ll)y*k%M2)};}
    Hash operator*(const Hash a){return {(int)((ll)x*a.x%M1),(int)((ll)y*a.y%M2)};}
    bool operator==(const Hash& a){return x==a.x&&y==a.y;}
    // bool operator!=(const Hash& a){return x!=a.x||y!=a.y;}
    operator ll(){return (((ll)x)<<32)|y;}
};
struct SH{
    vector<Hash> bp,h;
    SH(const string& s):bp(s.size()),h(s.size()){bp[0]=1;h[0]=s[0];for(int i=1;i<s.size();i++)bp[i]=bp[i-1]*B,h[i]=h[i-1]*B+s[i];}
    Hash get(int l,int r){return (l==0)?h[r]:(h[r]-h[l-1]*bp[r-l+1]);}
};