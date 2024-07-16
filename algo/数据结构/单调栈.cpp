void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> ans(n); // ans[i] 是 a[i] 右边第一个比 a[i] 大的数（ans[i]=0）代表不存在
    vector<int> ans2(n); // ans[i] 是 a[i] 右边第二个比 a[i] 大的数
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        stack<pair<int,int>> backup;
        while(s.size() && a[s.top().first]<a[i]){
            if(s.top().second==2){              // 是第一次出栈
                ans[s.top().first] = i+1;
                backup.push({s.top().first,1}); // 等一下统一放回去
            }
            else{
                ans2[s.top().first] = i+1;
            }
            s.pop();
        }

        s.push({i,2});
        while(backup.size())s.push(backup.top()),backup.pop();
    }

    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
    cout<<'\n';
}
