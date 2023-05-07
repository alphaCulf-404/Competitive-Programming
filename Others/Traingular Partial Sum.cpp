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

void solve()
{
    int n,m,q; cin>>n>>m>>q;
    vector<vector<int> > grid(n+1, vector<int>(m+1));
    vector<vector<int> > sqs(n+1, vector<int>(m+1));
    vector<vector<int> > tqs(n+1, vector<int>(m+1)); 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) cin>>grid[i][j];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            sqs[i][j] = (sqs[i-1][j] + sqs[i][j-1] + grid[i][j] - sqs[i-1][j-1])%MOD;
            tqs[i][j] = (tqs[i-1][j-1] + (sqs[i][j] - sqs[i][j-1]))%MOD;
        }
    }

    while(q--){
        int x,y,l; cin>>x>>y>>l;
        int m = ((tqs[x][y] - tqs[max(0ll, x-l)][max(0ll, y-l)] - (sqs[max(0ll, x-l)][y] - sqs[max(0ll, x-l)][max(0ll, y-l)]))%MOD+MOD)%MOD;
        cout<<m<<endl;
    }
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
