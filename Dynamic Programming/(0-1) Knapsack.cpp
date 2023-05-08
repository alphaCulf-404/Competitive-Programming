// Given a list of items with their weights and values
// Find the maximum value one can obtain with a total weight limit
// Time complexity: O(nw)
// Problem link: https://cses.fi/problemset/task/1158

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

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_W];

//----------Recursive code-----------//
int knapSack(int i, int j) 
{
    if (i == n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int res = knapSack(i+1, j);
    if (j >= w[i]) res = max(res, knapSack(i+1, j-w[i]) + v[i]);
    return dp[i][j] = res;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << knapSack(0, W) << endl;
}
//------Iterative code------// 
// void solve() 
// {
//     int n, w; cin >> n >> w;
//     int weight[n], val[n];
//     for (int i = 0; i < n; i++) cin >> weight[i];
//     for (int i = 0; i < n; i++) cin >> val[i];

//     int dp[w + 1] = {};
//     for (int i = 0; i < n; i++)
//         for (int j = w; j >= weight[i]; j--)
//             dp[j] = max(dp[j], dp[j - weight[i]] + val[i]);
//     cout << dp[w] << "\n";
// }

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
