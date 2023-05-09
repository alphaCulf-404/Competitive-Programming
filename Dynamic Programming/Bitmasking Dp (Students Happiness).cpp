//There are N Ranks and M students in a class. Each student has a happiness value
//for the rank in the class he gets. The i th Student gets happy[i][j] on getting
//a rank j. It's ok to not keep all students in the ranks (They get 0 happiness). 
//At most one student can be assigned to a rank. The total happiness of the assignment
//can be calculated as Sum of Happiness of each of the students in the class. Find the best way to calculate.

//-------------------------- Bitmasking dp---------------------------------//



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

int happy[50][10];
int dp[50][(1 << 10)];
int n, m;

int dfs(int pos, int vis)
{
    if (pos == m)
    {
        return 0;
    }
    if (dp[pos][vis] != -1)
    {
        return dp[pos][vis];
    }
    int ans = dfs(pos + 1, vis);
    for (int i = 0; i < n; ++i)
    {
        if ((vis & (1 << i)) == 0)
        {
            int temp = happy[pos][i] + dfs(pos + 1, vis | (1 << i));
            ans = max(ans, temp);
        }
    }
    dp[pos][vis] = ans;
    return ans;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < (1 << n); ++j)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> happy[i][j];
        }
    }
    cout << dfs(0, 0) << "\n";
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
