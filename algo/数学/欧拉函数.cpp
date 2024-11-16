template<typename T>
T phi(T x){
    T ans = x;
    for(T i=2;i*i<=x;i++){
        if(x%i==0){
            ans = ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    }
    if (x > 1) ans = ans / x * (x - 1);
    return ans;
}