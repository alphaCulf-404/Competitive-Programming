// Prim Agorithm is similar to Dijkstra
// Time Complexity: O(mlogn)
// Problem link: https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
typedef vector<int> vi;
#include <unordered_set>
typedef vector<vector<int>> vvi;
#define int long long int
#define pb push_back
#define no cout << "NO" \
                << "\n"
#define yes cout << "YES" \
                 << "\n"
#define sp(a) setprecision(a)

const int MAX_N = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, m, visited[MAX_N];
vector<ar<int,2>> adj[MAX_N];

void prim(int s = 1) {
    ll cost = 0;
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    visited[s] = 1; 
    for (auto [u, d] : adj[s]) 
        if (!visited[u]) 
            pq.push({d, u});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (!visited[u]) {
            cost += d;
            visited[u] = 1;
            for (auto [v, w] : adj[u]) 
                if (!visited[v]) 
                    pq.push({w, v});
        }
    } 
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
    cout << cost << "\n";
}

void solve() {
    cin >> n >> m;    
    for(int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
        adj[v].push_back({u, w});
    }
    prim();
}


signed main()
{
// #ifndef ONLINE_JUDGE
//     //for getting input from input.txt

//     freopen("input.txt","r",stdin);
//     //for writing output to output.txt
//     freopen("output.txt","w",stdout);
// #endif
    
    ios::sync_with_stdio(0);cin.tie(0); 
    makeSet();
    solve();
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0; 
}
