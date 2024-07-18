void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> ans(n); // ans[i] is the pos of the first smaller element in right
    vector<int> ans2(n); // ans[i] is the pos of the second smaller element in right
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        stack<pair<int,int>> backup;
        while(s.size() && a[s.top().first]>a[i]){
            if(s.top().second==2){              // pop for the first time
                ans[s.top().first] = i+1;
                backup.push({s.top().first,1}); 
            }
            else{
                ans2[s.top().first] = i+1;
            }
            s.pop();
        }

        s.push({i,2});
        // place it back, and the monotonicity of the stack maintains
        while(backup.size())s.push(backup.top()),backup.pop();
    }

    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
    cout<<'\n';
}
