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

vector<int> manacher(string s)
{
    string s1 = "@";
    for (auto c : s)
        s1 += c, s1 += "#";
    s1.back() = '&';
    vector<int> ans(s1.size() - 1);
    int lo = 0, hi = 0;
    for (int i = 1; i <= s1.size() - 2; i++)
    {
        if (i != 1)
            ans[i] = min(hi - i, ans[hi - i + lo]);
        while (s1[i - ans[i] - 1] == s1[i + ans[i] + 1])
            ans[i]++;
        if (i + ans[i] > hi)
            lo = i - ans[i], hi = i + ans[i];
    }
    ans.erase(begin(ans));
    for (int i = 0; i <= ans.size() - 1; i++)
        if ((i & 1) == (ans[i] & 1))
            ans[i]++;
    return ans;
}

string lps(string s)
{
    vector<int> arr = manacher(s);
    int ans = *max_element(arr.begin(), arr.end());
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ans)
        {
            index = i;
            break;
        }
    }
    return s.substr((index + 1) / 2 - ans / 2, ans);
}

void solve()
{
    string s;
    cin >> s;
    cout << lps(s) << "\n";
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