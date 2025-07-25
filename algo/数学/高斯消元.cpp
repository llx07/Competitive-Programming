const double EPS = 1e-8;
double mat[N][N];
int n;
double ans[N];
// 返回 0：唯一解；-1:无解；-2:无穷解
int gauss(){
    int tot = 1; // 目前消除了几列
    for(int i=1;i<=n;i++){ 
        // 尝试消除第 i 列
        int r=tot; // 这一列最大的位置
        for(int j=tot+1;j<=n;j++){
            if(fabs(mat[j][i])>fabs(mat[r][i]))r=j;
        }
        swap(mat[tot],mat[r]);
        if(fabs(mat[tot][i])<EPS)continue; // 这一列都是0，跳过
        for(int j=1;j<=n;j++){
            if(j==tot)continue;
            double f = mat[j][i]/mat[tot][i];
            // 把 mat[j][i] 消除掉
            for(int k=1;k<=n+1;k++)mat[j][k] -= f*mat[tot][k];
        }
        tot++;
    }

    if(tot!=n+1){ // 没有全部消除
        for(int i=tot;i<=n;i++){
            // 无解
            if(fabs(mat[i][n+1])>EPS)return -1;
        }
        // 无穷解
        return -2;
    }
    // 注意 ans 中可能有 -0.0
    for(int i=1;i<=n;i++)ans[i] = mat[i][n+1]/mat[i][i];
    return 0;
}
