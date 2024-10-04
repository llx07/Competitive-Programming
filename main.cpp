#include<bits/stdc++.h>
using namespace std;

using ll=long long;using ull=unsigned long long;using pii=pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unq(x) (x).erase(unique(all((x))),(x).end())
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define mem0(x) memset((x),0,sizeof(x))

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& data){
    for(int i=0;i<data.size();i++)os<<data[i]<<' ';
	return os;
}

#ifndef ONLINE_JUDGE
#include "template/cpp-dump/cpp-dump.hpp"
#define debug(...) cpp_dump(__VA_ARGS__)
namespace cp = cpp_dump;
CPP_DUMP_SET_OPTION_GLOBAL(max_line_width, 80);
CPP_DUMP_SET_OPTION_GLOBAL(log_label_func, cp::log_label::filename());
CPP_DUMP_SET_OPTION_GLOBAL(enable_asterisk, true);
#ifdef NO_COLOR
CPP_DUMP_SET_OPTION_GLOBAL(es_style, cp::types::es_style_t::no_es);
#endif // NO_COLOR
#else
#define debug(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
#endif // ONLINE_JUDGE

void solve(){


}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int T; cin>>T;
    while(T--)solve();
    return 0;
}

/*
1. 除非你明确需要元素去重，不要使用set，使用multiset。
*/