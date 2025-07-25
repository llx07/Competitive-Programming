// 求 det(A) mod p
int det(vector<vector<int>> A,int p){
    int n = A.size();
    int res = 1; // 答案
    for(int i=0;i<n;i++){
        // 把第 i 列第 (i+1~n) 行全部消成 0
        for(int j=i+1;j<n;j++){
            // 把 a[i][i] 消掉
            while(A[i][i]){
                int div = A[j][i]/A[i][i]; // 辗转相除
                for(int k=i;k<n;k++) // 只会进行 O(n^2 + n log p) 次
                    A[j][k] = ((A[j][k] - (ll)div*A[i][k])%p+p)%p; 
                swap(A[i],A[j]); res=-res;
            }
            swap(A[i],A[j]); res=-res;
        }
    }
    for(int i=0;i<n;i++)res=(ll)res*A[i][i]%p;
    res=(res+p)%p;
    return res;
}