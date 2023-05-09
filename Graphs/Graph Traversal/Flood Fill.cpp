// Problem link: https://cses.fi/problemset/task/1192

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

const int MAX_N = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
 
int n, m, visited[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
 
const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
 
bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.';
}
 
void dfs(int i, int j) 
{
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++) 
    {
        int ni = i + di[k], nj = j + dj[k];
        if (valid(ni, nj) && !visited[ni][nj]) 
        {
            dfs(ni, nj);
        }
    }
}
 
void solve() 
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (valid(i, j) && !visited[i][j]) 
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << "\n";
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
