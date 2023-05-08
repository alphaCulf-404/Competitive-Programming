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
typedef vector<vector<int>> vvi;
#define int long long int
#define pb push_back
#define no cout << "NO" \
                << "\n"
#define yes cout << "YES" \
                 << "\n"
#define sp(a) setprecision(a)
#define ar array

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;
const int MAX_N = 1000;
const int MAX_W = 1000;

int dp[MAX_N][MAX_N];

string X, Y;
int n = X.length();
int m = Y.length();

int lcs(int i, int j)
{
    if (i == n || j == m)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    if (X[i] == Y[j])
    {
        ans = 1 + lcs(i - 1, j - 1);
    }
    else
    {
        ans = max(lcs(i, j - 1), lcs(i - 1, j));
    }
    return dp[i][j] = ans;
}

//----------------------Iterative code-----------------------//

// void solve() {
//     string x, y; cin >> x >> y;
//     int n = x.size(), m = y.size();
//     int dp[n + 1][m + 1] = {};
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (x[i - 1] == y[j - 1]) 
//                 dp[i][j] = max dp[i][j], dp[i - 1][j - 1] + 1);
//             else
//                 dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
//         }
//     }
//     cout << dp[n][m];
// }


void solve()
{
    string X, Y;
    cin >> X >> Y;
    memset(dp, -1, sizeof(dp));
    int n = X.length();
    int m = Y.length();
    cout << lcs(n, m) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << t+1 << ": ";
        solve();
    }
}
