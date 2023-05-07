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
typedef vector<vector<int> > vvi;
// #define int long long int
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

int phi(int n)
{
    int ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            ans/= i; ans*=(i-1);
        }
        while(n%i == 0)
        {
            n/=i;
        }
    }
    if(n > 1)
    {
        ans/= n; ans*=(n-1);
    }
    return ans;
}

int getcount(int d, int n)
{
    return phi(n/d);
}

void solve()
{
    int n; cin >> n;
    int res = 0;

    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            int d1 = i;
            int d2 = n/i;
            res += d1* getcount(d1, n);

            if(d1 != d2) res += d2* getcount(d2, n);
        }
    }
    cout << res << "\n";
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
