template<typename T=int >
struct Trie{
    const int MAXBIT = numeric_limits<T>::digits;

    vector<array<int,2>> ch;
    vector<int> cnt;
    int tot=1;
    Trie(int sz):ch(sz*(MAXBIT+1)+10),cnt(sz*(MAXBIT+1)+10){}
    void insert(T x){
        int u = 1;
        for(int i=MAXBIT;i>=0;i--){
            int c = (x>>i)&1;
            if(!ch[u][c])ch[u][c]=++tot;
            u = ch[u][c];
            cnt[u]++;
        }
    }
    void erase(T x){
        int u = 1;
        for(int i=MAXBIT;i>=0;i--){
            int c = (x>>i)&1;
            if(!ch[u][c])ch[u][c]=++tot;
            u = ch[u][c];
            cnt[u]--;
        }
    }
    T max_xor(T x){
        int u = 1;
        T res = 0; 
        for(int i=MAXBIT;i>=0;i--){
            int c = ((x>>i)&1)^1;
            if(ch[u][c] && cnt[ch[u][c]])res |= (1<<i),u = ch[u][c];
            else u = ch[u][c^1];
        }
        return res;
    }
    T min_xor(T x){
        int u = 1;
        T res = 0; 
        for(int i=MAXBIT;i>=0;i--){
            int c = ((x>>i)&1);
            if(ch[u][c] && cnt[ch[u][c]])res |= (1<<i),u = ch[u][c];
            else u = ch[u][c^1];
        }
        return res;
    }
};