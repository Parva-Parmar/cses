/*
https://cses.fi/problemset/task/1192/
*/
/*
.______      ___      .______     ____    ____  ___      
|   _  \    /   \     |   _  \    \   \  /   / /   \     
|  |_)  |  /  ^  \    |  |_)  |    \   \/   / /  ^  \    
|   ___/  /  /_\  \   |      /      \      / /  /_\  \   
|  |     /  _____  \  |  |\  \----.  \    / /  _____  \  
| _|    /__/     \__\ | _| `._____|   \__/ /__/     \__\ 
 
.______      ___      .______      .___  ___.      ___      .______      
|   _  \    /   \     |   _  \     |   \/   |     /   \     |   _  \     
|  |_)  |  /  ^  \    |  |_)  |    |  \  /  |    /  ^  \    |  |_)  |    
|   ___/  /  /_\  \   |      /     |  |\/|  |   /  /_\  \   |      /     
|  |     /  _____  \  |  |\  \----.|  |  |  |  /  _____  \  |  |\  \----.
| _|    /__/     \__\ | _| `._____||__|  |__| /__/     \__\ | _| `._____|
*/
 
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rev reverse
#define endl '\n'
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e5 + 1;
const int mod = 1e9 + 7;
 
/*
vector<int> ord(n);
iota(ord.begin(), ord.end(), 0);
sort(ord.begin(), ord.end(), [&](auto x, auto y) { return p[x] < p[y]; });
*/
int powr(int a, int b){
    int ans =1;
    while (b>0){
        if ((b&1)==1){
            ans=(ans*1LL*a)%(998244353);
 
        }
        a=(a*1LL*a)%(998244353);
        b=b>>1;
    }
    return ans;
}
 
ll GCD(ll x , ll y){
    if(y==0){
        return x;
    }
    return gcd(y,y%x);
}
 
bool isVowel(char a)
{
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){
        return true;
    }
    else{
        return false;
    }
    
}
ll fact(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return (n*fact(n-1))%((int)mod);
    }
}
 
void dfs(vector<vector<char>>& G,ll row,ll col){
    int n = G.size(), m = G[0].size();
    if(row<0 || col < 0 || row>=n || col >= m){
        return;
    }
    if(G[row][col]=='#'){
        return;
    }
    G[row][col] = '#';
    dfs(G, row,col+1);
    dfs(G, row+1,col);
    dfs(G, row,col-1);
    dfs(G, row-1,col);
}
 
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> G(n,vector<char>(m));
    for (int i = 0; i < n; i++) {
        /* code */
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            /* code */
            G[i][j] = s[j];
        }
    }
     
    ll count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(G[i][j]=='.'){
                count++;
                dfs(G,i,j);
            }
        }
    }
    cout << count << endl;
}
 
int main(){
 FIO;
 ll test = 1;
//  cin >> test;
 for(int t = 0 ; t < test ; t++){
    solve();
 }
 return 0;
}
