// 数组要开两倍大！
char stmp[N],s[N<<1];
// 在原字符串上，d[i] 表示以此为中心的回文串最长长度+1
int d[N<<1];

int main(){
    scanf("%s",stmp);int l=strlen(stmp);
    s[0]='^';s[1]='#';
    int n=2;
    for(int i=0;i<l;i++)s[n++]=stmp[i],s[n++]='#';
    // 预处理成 ^#a#b#c#d#
    int mid=0,r=-1; // 最靠右的回文部分
    for(int i=1;i<n;i++){ // i=1 开始
        if(i<=r)d[i]=min(d[mid*2-i],r-i+1); // 利用之前信息
        while(s[i-d[i]]==s[i+d[i]])d[i]++; // 暴力更新
        if(i+d[i]-1>r)r=i+d[i]-1,mid=i; // 更新最靠右的
    }
    printf("%d\n",(*max_element(d,d+n))-1);
    return 0;
}