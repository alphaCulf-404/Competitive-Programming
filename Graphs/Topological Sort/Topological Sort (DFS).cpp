// Traversal path of a typical DFS is a reverse topological order
// Problem link: https://cses.fi/problemset/task/1679

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

vector<vector<int> >g;
vector<int> vis;
vector<int> topo;

void dfs(int node)
{
    vis[node] = 1;
    for(auto v:g[node])
    {
        if(!vis[v]) dfs(v);
    }
    topo.pb(node);
}
void solve()
{
    int n, m; cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1, 0);

    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());

    for(int i = 0; i < topo.size(); i++)
    {
        cout << topo[i] << " ";
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        // cout << "Case #" << t  << ": ";
        solve();
    }
    return 0;
}
