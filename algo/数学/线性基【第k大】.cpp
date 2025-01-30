template<typename T> struct Basis{
    T b[numeric_limits<T>::digits];
    int pos[numeric_limits<T>::digits];
    int tot;
    Basis(){memset(b,0,sizeof b);tot=0;}
    void ins(T x){
        for(int i=numeric_limits<T>::digits-1;i>=0;i--){
            if((x>>i)&1){ 
                if(!b[i]){b[i]=x;++tot;break;}
                x^=b[i];
            }
        }
    }
    void prework(){
        int now = 0;
        for(int i=0;i<=numeric_limits<T>::digits-1;i++){
            if(!b[i])continue;
            for(int j=i-1;j>=0;j--){
                if((b[i]>>j)&1)b[i]^=b[j];
            }
            pos[now++]=i;
        }
    }
    T kth(int _k){
        ll ans = 0;
        for(int i=0;i<tot;i++){
            if((_k>>i)&1)ans^=b[pos[i]];
        }
        return ans;
    }
    friend Basis operator+(const Basis& lhs,const Basis& rhs){
        Basis ret = lhs;
        for(int i=0;i<numeric_limits<T>::digits;i++){
            if(rhs.b[i])ret.ins(rhs.b[i]);
        }
        return ret;
    }
};