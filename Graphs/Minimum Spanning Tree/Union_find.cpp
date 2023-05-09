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

int n, m;
int parent[MAX_N];
int rank_array[MAX_N];

void makeSet()
{
    for(int i = 1; i <=n; i++)
    {
        parent[i] = i; rank_array[i] = 0;
    }
}

int findPar(int node)
{
    if(node == parent[node])
    {
        return node;
    }
    return parent[node] = findPar(parent[node]);
}

void Union(int u, int v)
{
    u = findPar(u);
    v = findPar(v);
    
    if(rank_array[u] < rank_array[v])
    {
        parent[u] = v;
    }
    else if(rank_array[v] == rank_array[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank_array[u]++;
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i; rank_array[i] = 0;
    }
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a == 0)
        {
            Union(b, c);
        }
        else
        {
            if(findPar(b) == findPar(c))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }
    
}
    

signed main()
{
// #ifndef ONLINE_JUDGE
//     //for getting input from input.txt

//     freopen("input.txt","r",stdin);
//     //for writing output to output.txt
//     freopen("output.txt","w",stdout);
// #endif
    
    ios::sync_with_stdio(0);cin.tie(0); 
    makeSet();
    solve();
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0; 
}
