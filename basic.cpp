#include <bits/stdc++.h>
using namespace std;

#define endl "\n";
int n,m,x;
vector<pair<int,char>> v;
set<int> s;
int modX(int x,int n){
    return (x>n)?(x%(n+1)+1):x;
}

void f(int x,int i){
    if(i==m){
        s.insert(x);
    }
    else{
        if(v[i].second=='0'){
            f(modX(x+v[i].first,n),i+1);
        }
        else if(v[i].second=='1'){
            f(modX(x+n-v[i].first,n),i+1);
        }
        else{
            f(modX(x+v[i].first,n),i+1);
            f(modX(x+n-v[i].first,n),i+1);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m>>x;
        v.resize(m);
        for(int i=0;i<m;i++){
            cin>>v[i].first>>v[i].second;
        }
        f(x,0);
        cout<<s.size()<<endl;
        for(auto num:s){
            cout<<num<<" ";
        }
        cout<<endl;
        s.clear();
        v.clear();
    }
    return 0;
}

