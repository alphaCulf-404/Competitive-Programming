// Find the number between L and R whose sum of the digits of that numnber % D = K (0 <= a <= b <= 1e9)
//Atcoder Education Dp contest

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

int len;
int D;
string L, R;

int dp[10010][2][2][100];

int rec(int level, int tlo, int thi, int sumD)
{
    if (level == len)
    {
        if (sumD == 0)
            return 1;
        else
            return 0;
    }
    if (dp[level][tlo][thi][sumD] != -1)
    {
        return dp[level][tlo][thi][sumD];
    }
    int ans = 0;
    int lo = 0;
    if (tlo == 1)
    {
        lo = L[level] - '0';
    }
    int hi = 9;
    if (thi == 1)
    {
        hi = R[level] - '0';
    }
    for (int i = lo; i <= hi; i++)
    {
        int ntlo = tlo;
        if (i != L[level] - '0')
            ntlo = 0;

        int nthi = thi;
        if (i != R[level] - '0')
            nthi = 0;

        ans += rec(level + 1, ntlo, nthi, (sumD + i) % D);
        ans %= MOD;
    }
    return dp[level][tlo][thi][sumD] = ans;
}

void solve()
{
    cin>>L>>R;
    cin>>D;
    int cnt = R.length()-L.length();
    string temp = "";
    while(cnt--){
        temp+='0';
    }
    L = temp+L;
    len = R.length();

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0)<<endl;
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
