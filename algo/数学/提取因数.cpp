template<typename T>
vector<T> getfactors(T x){
    vector<T> ret;
    for(T i=1;i*i<=x;i++){
        if(x%i==0){
            ret.push_back(i);
            if(i*i != x)ret.push_back(x/i);
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}