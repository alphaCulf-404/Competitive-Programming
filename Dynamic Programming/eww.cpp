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
typedef vector<vector<int> > vvi;
#define int long long int
#define pb push_back
#define no cout << "NO" << "\n"
#define yes cout << "YES" << "\n"
#define sp(a) setprecision(a)

const int MOD = 1e9 + 7;
int dp[100100];

int rec(int x)
{
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];

    int ans = 0;

    for(int i = 0; (1<<i)<= x; i++)
    {
        if(!rec(x-(1<<i)))
        {
            ans = 1;
            break;
        }
    }
    return dp[x] = ans;
}

void solve()
{
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << rec(n) << "\n";
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
