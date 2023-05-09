//On cutting cost = length of the current rod. Break into small parts with n-1 cuts and find the minimum cuts
// LR Dp 

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

int n;
int x[1001];
int dp[1001][1001];

int rec(int l, int r)
{
    //pruning

    //basecase
    if(l+1 == r)
    {
        return 0;
    }
    //cache check
    if(dp[l][r] != -1) return dp[l][r];

    //compute
    int ans = 1e9;
    for(int i = l+1; i <= r-1; i++)
    {
        ans = min(ans, x[r]- x[l] + rec(l,i)+ rec(i,r));
    }
    return dp[l][r] = ans;
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    x[0] = 0;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, n) << "\n";
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
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
