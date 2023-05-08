// String Hashing 
// Consider carefully the choice of 'base' and 'mod'
// 'base' should be greater than the number of characters in the input alphabet 
// 'mod' should be a large prime like 1e9 + 7

// should always convert 'a' into 1 instead 0
// should randomise the value of 'base' to avoid hacking
// should use > 1 'base' to reduce collision rate

// Example of using Hashing for String Matching (Rabin-Karp)
// Problem link: https://cses.fi/problemset/task/1753

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {return uniform_int_distribution(l, r)(rng);}
const int BASE = rand(300, 1e9);
const int NUM_MOD = 2;
const int MODS[] = {(int)1e9 + 2277, (int)1e9 + 5277};
struct Hash {
    vector<int> H[NUM_MOD], P[NUM_MOD];
    Hash(string s) {
        for (int i = 0; i < NUM_MOD; i++) {
            P[i].push_back(1);
            H[i].push_back(0);
        }
        for (char c : s) {
            for (int i = 0; i < NUM_MOD; i++) {
                P[i].push_back(P[i].back() * BASE % MODS[i]);
                H[i].push_back((H[i].back() * BASE + c) % MODS[i]);
            }
        }
    } 
    ar<int,NUM_MOD> operator()(int l, int r) {
        ar<int,NUM_MOD> res;
        for (int i = 0; i < NUM_MOD; i++) {
            res[i] = (H[i][r + 1] - H[i][l] * P[i][r + 1 - l]) % MODS[i];
            if (res[i] < 0) res[i] += MODS[i];
        }
        return res;
    }
};

int cnt_occ(string s, string t) 
{
    int n = s.size(), m = t.size();
    Hash hs(s), ht(t);
    int res = 0;
    for (int i = 0, j = m - 1; j < n; i++, j++) {
        res += (hs(i, j) == ht(0, m - 1));
    }
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
