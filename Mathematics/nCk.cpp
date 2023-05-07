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

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

int qexp(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b % 2)
            res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}

vector<int> fact, invf;

void precompute(int n)
{
    fact.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], MOD - 2, MOD); // inverse modulo --> Fermat's Theorem
    for (int i = n - 1; i > 0; i--)
        invf[i] = invf[i + 1] * (i + 1) % MOD;
}

int nCk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
}

// A trick to calculate large factorial without overflowing is to take log at every step when precompute and take exponential when calculating
// Don't need invf[] now because it is the same as negative log of fact
vector<double> log_fact;
void precompute_log(int n)
{
    log_fact.assign(n + 1, 0.0);
    log_fact[0] = 0.0;
    for (int i = 1; i <= n; i++)
        log_fact[i] = log_fact[i - 1] + log(i);
}

int log_nCk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return exp(log_fact[n] - log_fact[n - k] - log_fact[k]);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    cout << nCk(n, k) << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute(1e6);
    //precompute_log(1e6);
    int t;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << t+1 << ": ";
        solve();
    }
}
