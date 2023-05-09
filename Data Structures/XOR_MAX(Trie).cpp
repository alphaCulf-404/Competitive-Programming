//You are given q queries and a multiset A, initially containing only integer 0. There are three types of queries:

//"+ x" — add integer x to multiset A.

//"- x" — erase one occurrence of integer x from multiset A. It's guaranteed that at least one x is present in the multiset A before this query.

//"? x" — you are given integer x and need to compute the value , i.e. 
//the maximum value of bitwise exclusive OR (also know as XOR) of integer x and some integer y from the multiset A.//

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

class trieNode
{
public:
    int cnt;
    trieNode *left;
    trieNode *right;
    trieNode()
    {
        cnt = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(int n, trieNode *head)
{
    trieNode *pt = head;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 1)
        {
            if (!pt->right)
            {
                pt->right = new trieNode();
            }
            pt = pt->right;
            pt->cnt++;
        }
        else
        {
            if (!pt->left)
            {
                pt->left = new trieNode();
            }
            pt = pt->left;
            pt->cnt++;
        }
    }
}

void erase(int n, trieNode *head)
{
    trieNode *pt = head;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 1)
        {
            pt->right->cnt--;
            pt = pt->right;
        }
        else if (bit == 0)
        {
            pt->left->cnt--;
            pt = pt->left;
        }
    }
}

int findMaxXOR(int n, trieNode *head)
{
    trieNode *pt = head;
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 1)
        {
            if (pt->left && pt -> left -> cnt)
            {
                ans += (1 << i);
                pt = pt->left;
            }
            else
            {
                pt = pt->right;
            }
        }
        else
        {
            if (pt->right && pt -> right -> cnt)
            {
                ans += (1 << i);
                pt = pt->right;
            }
            else
            {
                pt = pt->left;
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    trieNode *head = new trieNode();
    insert(0, head);
    while (n--)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            insert(x, head);
        }
        else if (c == '-')
        {
            erase(x, head);
        }
        else
        {
            cout << findMaxXOR(x, head) << "\n";
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}
