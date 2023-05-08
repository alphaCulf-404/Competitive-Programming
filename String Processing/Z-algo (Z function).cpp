// Given a string s (with length n) and a pattern t (with length m), find all the occurrence of p in s
// Time complexity: O(n + m)
// Problem link: https://cses.fi/problemset/task/1753/

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
 
// f[i] = length of the longest common prefix between s and the substring s[i...n-1]
vector<int> z_func(string s) {
    int n = s.size();
    vector<int> f(n); // f[0] = 0 by default
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) f[i] = min(r - i + 1, f[i - l]);
        while (i + f[i] < n && s[f[i]] == s[i + f[i]]) f[i]++;
        if (i + f[i] - 1 > r) l = i, r = i + f[i] - 1;
    }
    return f;
}
 
int cnt_occ(string s, string t) 
{
    string ts = t + "#" + s;
    int n = t.size(), m = s.size(), nm = ts.size();
    auto f = z_func(ts);
    int res = 0;
    for (int i = n + 1; i < nm; i++) res += (f[i] == n);
    return res;
}
 
void solve() 
{
    string s, t; cin >> s >> t;
    cout << cnt_occ(s, t) << "\n";
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
