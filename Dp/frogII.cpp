#include <bits/stdc++.h>
using namespace std;
#define ln endl
#define ll long long
#define int long long
#define pii pair<ll, ll>
#define ff first
#define ss second
#define pb push_back
#define vi vector<ll>
#define vii vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vp vector<pii>
#define vs vector<string>
#define mii unordered_map<ll, ll>
#define mib unordered_map<ll, bool>

class comp
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return max(a.ff, a.ss) < max(b.ff, b.ss);
    }
};

template <typename T>
istream &operator>>(istream &os, vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
        os >> v[i];
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
        os << v[i] << ' ';
    return os;
}

template <typename T, typename U>
istream &operator>>(istream &os, pair<T, U> &v)
{
    os >> v.ff >> v.ss;
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &v)
{
    os << v.ff << ' ' << v.ss << ' ';
    return os;
}

int n;
int k;

int solve(int idx, vector<int> &h, vector<int> &dp)
{

    if (idx == n - 1)
    {
        return 0;
    }

    if (idx >= n)
    {
        return INT_MAX;
    }

    if (dp[idx] != -1)
    {
        return dp[idx];
    }

    int ans = 1e9;
    for (int jump = 1; jump <= k; jump++)
    {

        if (idx + jump < n)
        {
            ans = min(ans, abs(h[idx] - h[idx + jump]) + solve(idx + jump, h, dp));
        }
    }
    return dp[idx] = ans;
}

int32_t main()
{

    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    vector<int> dp(n, -1);

    cout << solve(0, h, dp) << endl;
}