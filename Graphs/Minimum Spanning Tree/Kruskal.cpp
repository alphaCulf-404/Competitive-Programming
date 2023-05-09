// Need to use edge list for Kruskal
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

int n, m, par[MAX_N];
vector<array<int,3>> edges;
 
int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}
 
void unite(int u, int v) {
    par[find(u)] = find(v);
}

void kruskal() {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) par[i] = i;

    ll cnt = 0, cost = 0;
    for (auto [w, u, v] : edges) {
        u = find(u), v = find(v);
        if (u != v) {
            par[u] = v;
            cost += w;
            cnt++;
        }
    }
    if (cnt == n - 1) cout << cost << "\n";
    else cout << "IMPOSSIBLE\n";
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    kruskal();
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
