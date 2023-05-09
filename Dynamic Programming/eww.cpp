//Given a simple graph, output the number of simple cycles in it. 
//A simple cycle is a cycle with no repeated vertices or edges.

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

const int MOD = 1e9 + 7;

int dp[20][(1 << 20)];
bool isEdge[20][20];
int n, m;
int cur;

int dfs(int pos, int vis, int sz)
{
    if (dp[pos][vis] != -1)
    {
        return dp[pos][vis];
    }
    int ans = 0;
    if (sz > 2 && isEdge[pos][cur])
    {
        ans++;
    }
    for (int i = cur; i < n; ++i)
    {
        if ((vis & (1 << i)))
            continue;
        if (isEdge[pos][i])
        {
            ans += dfs(i, (vis | (1 << i)), sz + 1);
        }
    }
    return dp[pos][vis] = ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        isEdge[a][b] = isEdge[b][a] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cur = i;
        memset(dp, -1, sizeof(dp));
        ans += dfs(i, (1 << i), 1);
    }
    cout << ans / 2;
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
