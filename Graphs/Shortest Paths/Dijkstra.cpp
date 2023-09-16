#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
// using namespace __gnu_pbds;
 
typedef long long int ll;
typedef long double   ld;
typedef unsigned long long ull;
#define endl '\n'
#define int         ll
#define double      ld
#define ff          first
#define ss          second
#define sz(x)       (int)x.size()
#define pb          push_back
#define ppb         pop_back
#define mp          make_pair
#define all(x)      x.begin(), x.end()
#define ret(x)      {cout<<x; return;}
#define vi          vector<int>
#define vpii        vector<pair<int,int>>
#define pii         pair<int,int>
#define mi          map<int,int>
#define rep(i,j,n)  for(int i=j;i<n;i++)
#define inf         9223372036854775807
#define cinv(v,n)   rep(i,0,n)cin>>v[i];
#define pr(x)       cout<<x<<endl;
#define PI          3.14159265358979323846264338327950288419716939937510
#define dbg(x)      cout<<#x<<": "<<x<<endl;
#define dbgg(x,y)   cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl;
#define fl(x)        cerr<<"Flag :"<<x<<endl;
#define MOD         1000000007
#define MAXN        200001
#define no cout << "NO\n"
#define yes cout << "YES\n"
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Susnata cout.tie(NULL);
 
//template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ; // h_by_order(iterator), order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<< #x <<": "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif
 
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(bool t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
//template <class T> void _print(ordered_set <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//template <class T> void _print(ordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
 
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}

vector<vector<pair<int, int> > > graph;
// vector<int> dist;
int E, V;

void dijkstra(int source, vector<int>&dist) 
{
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        for (const pair<int, int>& neighbor : graph[u]) 
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void solve()
{
    cin >> V >> E;
    graph.assign(V, vector<pair<int, int> >());
    
    for (int i = 0; i < E; ++i) 
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back(make_pair(v, weight));
        graph[v].push_back(make_pair(u, weight));
    }
    vector<int>dist(V, INT_MAX);
    dijkstra(0, dist);
    
    for (int i = 0; i < V; ++i) cout << dist[i] << "\n";
}
 

signed main()
{
    Code By Susnata
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);
#endif
    int t; cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
