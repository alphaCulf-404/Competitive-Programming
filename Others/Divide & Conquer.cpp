//Count the number of Inversion of a Array with the complexity of O(n*log(n))
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

int Merge(vector<int> arr, vector<int> aux, int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
 
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }
 
    while (i <= mid) {
        aux[k++] = arr[i++];
    }
    for (int i = low; i <= high; i++) {
        arr[i] = aux[i];
    }
 
    return inversionCount;
}
int MergeSort(vector<int> arr, vector<int> aux, int low, int high)
{
    if (high <= low) 
    {
        return 0;
    }
 
    int mid = (low + ((high - low) >> 1));

    int inversionCount = 0;
    inversionCount += MergeSort(arr, aux, low, mid);
    inversionCount += MergeSort(arr, aux, mid + 1, high);
    inversionCount += Merge(arr, aux, low, mid, high);
 
    return inversionCount;
}

void solve()
{
    int n; cin >> n; 
    vector<int>arr, aux;

    for(int i = 0; i < n; i++)
    {
        int x; cin >> x; arr.pb(x); aux.pb(x);
    }
    sort(aux.begin(), aux.end());
    cout << MergeSort(arr, aux, 0, n - 1) << "\n";
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
