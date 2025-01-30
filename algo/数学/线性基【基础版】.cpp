template<typename T> struct Basis{
    T b[numeric_limits<T>::digits];
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
    friend Basis operator+(const Basis& lhs,const Basis& rhs){
        Basis ret = lhs;
        for(int i=0;i<numeric_limits<T>::digits;i++){
            if(rhs.b[i])ret.ins(rhs.b[i]);
        }
        return ret;
    }
};