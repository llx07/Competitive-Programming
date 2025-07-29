
int rt,tot;
int ch[N][2];
int val[N],sz[N],pri[N];
void maintain(int x){
    sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
void split(int now,int k,int& x,int &y){
    if(!now){x=0,y=0;return;}
    // 如果按下标分裂，改成左儿子的大小<k
    if(val[now]<=k) x=now, split(ch[now][1], k, ch[now][1], y);
    else y=now,split(ch[now][0],k, x, ch[now][0]);
    maintain(now);
}
int merge(int x,int y){
    if(!x||!y)return x+y;
    if(pri[x]<pri[y])return ch[x][1]=merge(ch[x][1],y),maintain(x), x;
    else return ch[y][0]=merge(x,ch[y][0]),maintain(y), y;
}
int kth(int now,int k){
    while(1){
        if(k<=sz[ch[now][0]])now=ch[now][0];
        else if(k==sz[ch[now][0]]+1)return now;
        else k-=sz[ch[now][0]]+1,now=ch[now][1];
    }
}
int newnode(int v){
    val[++tot]=v;
    pri[tot]=rand();
    sz[tot]=1;
    ch[tot][0]=ch[tot][1]=0;
    return tot;
}
void ins(int v){
    int x  ,y;
    split(rt, v, x,y);
    rt = merge(merge(x,newnode(v)), y);
}
void del(int v){
    int x, y, z;
    split(rt, v, x, z);
    split(x, v-1, x, y);
    y = merge(ch[y][0], ch[y][1]);
    rt = merge(merge(x,y),z);
}