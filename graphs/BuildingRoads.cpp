 /*
 https://cses.fi/problemset/task/1666/
 */
 #include <bits/stdc++.h>
 #define all(v) v.begin(), v.end()
 #define rall(v) v.rbegin(), v.rend()
 #define rev reverse
 #define endl '\n'
 #define flp(x,y) for(int i = x ; i < y ; ++i)
 #define fln(x,y) for(int i = y ; i > x ; --i)
 #define c(v,x) count(v.begin(),v.end(),x)
 #define a(v,x) accumulate(v.begin(),v.end(),x)
 #define Motto_Hayakku ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 #define vec(x) vector<x>
 #define pb push_back
 #define rs(v,x) sort(v.begin(),v.end(),greater<x>())
 #define MT make_tuple
 #define MP make_pair
 #define gv(i,n) get<n>(v[i])
 #define fv(i) v[i].first
 #define sv(i) v[i].second
 #define p(x) cout << x << endl
 #define lp(x) cout << x << " " 
 #define cout(v) for(auto &i : v) cout<<i<<" "; cout<<"\n"
 using namespace std;
 typedef long long ll;
 typedef long double ld;
 const int N = 1e5 + 1;
 const int mod = 1e9 + 7;
 
 class Disjointset {
     vector<ll> size,parent;
 public:
     Disjointset(int n){
         size.resize((n+1),1);
         parent.resize(n+1);
         iota(parent.begin(),parent.end(),0);
     }
 
     int findUpar(int node){
         if(node == parent[node]){
             return node;
         }
         return findUpar(parent[node]);
     }
 
     void unionBySize(int u , int v){
         int ulp_u = findUpar(u);
         int ulp_v = findUpar(v);
         if(ulp_v == ulp_u){
             return;
         }
         if(size[ulp_u]<size[ulp_v]){
             parent[ulp_u] = ulp_v;
             size[ulp_v] += size[ulp_u];
         }
         else{
             parent[ulp_v] = ulp_u;
             size[ulp_u] += size[ulp_v];
         }
     }
 };
 
 void solve(){
    int n,m;
    cin >> n >> m;
    Disjointset Ds(n);
    int x,y;
    for(int i = 0 ; i < m ; i++){
        cin >> x >> y;
        Ds.unionBySize(x,y);
    }
    vector<int> nodes;
    for(int i = 1 ; i <= n ; i++){
        if(Ds.findUpar(i)==i){
            nodes.pb(i);
        }
    }
    cout << (nodes.size()-1) << endl;
    for(int i = 0 ; i < (nodes.size()-1) ; i++){
        cout << nodes[i] << " " << nodes[i+1] << endl;
    }
 }
 
 int main(){
  Motto_Hayakku;
  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
  #endif
  ll test=1;
  // cin >> test;
  while(test--){
     solve();
  }
  return 0;
 }
