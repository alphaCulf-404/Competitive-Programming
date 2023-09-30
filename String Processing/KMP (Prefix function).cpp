// Given a string s (with length n) and a pattern t (with length m), find all occurrence of p in s
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

vector<int> KMP(string &str)
{
    int n = str.length();
    vector<int> lps(n, 0);
    int i = 0;
    int j = 1;
    lps[0] = 0;
    cout << n << "\n";
    while (i < n && j < n)
    {
        if (str[j] != str[i])
        {
            if (i != 0)
                i = lps[i - 1];
            else
            {
                lps[j] = 0;
                j++;
            }
        }
        else
        {
            lps[j] = 1 + i;
            i++;
            j++;
        }
    }
}

int cnt_occ(string s, string t) 
{
    string ts = t + "#" + s;
    int n = t.size(), m = s.size(), nm = ts.size();
    vector<int>f = KMP(ts);
    int res = 0;
    for (int i = n + 1; i < nm; i++) res += (f[i] == n);
    return res;
}

void solve()
{
    string s, t; cin >> s >> t;
    cout << cnt_occ(s,t) << "\n";
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
