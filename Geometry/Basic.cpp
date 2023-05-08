// Basic geometry template for 2D Point (modified from kactl)
// All other extended functions from kactl should still work normally
// Problem link: https://cses.fi/problemset/task/2191/ (finding the area of a polygon)

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

double polygonArea(vector<double>X, vector<double>Y, int n)
{
    double area = 0.0;
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (X[j] + X[i]) * (Y[j] - Y[i]);
        j = i;
    }
    return abs(area / 2.0);
}

void solve() {
    int n; cin >> n;
    vector<double>X;
    vector<double>Y;
    
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x; X.pb(x);
    }

    for(int i = 0; i < n; i++)
    {
        int y; cin >> y; Y.pb(y);
    }
    cout << polygonArea(X, Y, n) << "\n";
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
