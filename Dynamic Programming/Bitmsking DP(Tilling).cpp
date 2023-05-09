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

int n, m;
int dp[13][13][1 << 13];

int rec(int i, int j, int mask)
{
    if (i == n - 1 && j == m)
    {
        if (mask == ((1 << m) - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (j == m)
    {
        return rec(i + 1, 0, mask);
    }
    if (dp[i][j][mask] != -1)
    {
        return dp[i][j][mask];
    }
    int ans = 0;

    if ((mask & (1 << 0)) == 0)
    {
        ans += rec(i, j + 1, (mask >> 1) | (1 << (m - 1)));
    }
    else
    {
        ans += rec(i, j + 1, mask >> 1);
        if (j != 0 && (mask & (1 << (m - 1))) == 0)
        {
            ans += rec(i, j + 1, (mask >> 1) | (1 << (m - 1)) | (1 << (m - 2)));
        }
    }
    return dp[i][j][mask] = ans;
}

void solve()
{
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, (1 << m) - 1) << "\n";
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
