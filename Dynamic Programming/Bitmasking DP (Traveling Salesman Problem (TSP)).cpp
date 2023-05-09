// Given n cities/nodes, find a minimum weight Hamiltonian Cycle/Tour
// Time complexity: O(2^n * n^2)
// Problem link: https://vjudge.net/problem/UVA-10496

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


int d[15][15];
int dp[(1 << 15)][15];

int dfs(int vis, int pos, int n)
{
    if (vis == (1 << n) - 1)
    {
        return d[pos][0];
    }
    if (dp[vis][pos])
    {
        return dp[vis][pos];
    }
    int ans = 2e18;
    for (int i = 0; i < n; ++i)
    {
        if ((vis & (1 << i)) == 0)
        {
            int temp = d[pos][i] + dfs(vis | (1 << i), i, n);
            ans = min(ans, temp);
        }
    }
    dp[vis][pos] = ans;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> d[i][j];
        }
    }
    cout << dfs(1, 0, n) << "\n";
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
