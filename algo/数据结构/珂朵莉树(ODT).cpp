using ValueT=int;
struct Node{
    int l,r;
    mutable ValueT v;
 
    bool operator<(const Node& rhs)const{return l<rhs.l;}
};
int n;
set<Node> odt;
auto split(int x){
    if(x>n)return odt.end();
    auto it=--odt.upper_bound({x,0,0});
    if(it->l==x)return it;
    int l=it->l,r=it->r; ValueT v=it->v;
    odt.erase(it);
    odt.insert({l,x-1,v});
    return odt.insert({x,r,v}).first;
}
void assign(int l,int r,ValueT v){
    auto itr=split(r+1),itl=split(l);
    odt.erase(itl,itr);
    odt.insert({l,r,v});
}

/*
    auto itr=split(r+1),itl=split(l);
    for(;itl!=itr;++itl){
        // do something ..
    }
*/