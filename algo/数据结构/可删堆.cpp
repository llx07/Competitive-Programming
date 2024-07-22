#include <bits/stdc++.h>
using namespace std;

template<typename _Tp, typename _Sequence = vector<_Tp>,
	   typename _Compare  = less<typename _Sequence::value_type> >
struct Heap{
    priority_queue<_Tp,_Sequence,_Compare> q, p;
    void push(int x){q.push(x);}
    void erase(int x){p.push(x);}
    int top() {
        while (p.size()&&q.size() && p.top()==q.top())p.pop(),q.pop();
        return q.top();
    }
    void pop() {
        while (p.size()&&q.size() && p.top()==q.top())p.pop(),q.pop();
        q.pop();
    }
    int size() {
        return q.size() - p.size();
    }
    int sectop() {
        int t = top();pop();
        int r = top();push(t);
        return r;
    }
};