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

const int mod = 1e9 + 7;

int n, k;
// int solve(int i, int j, vector<int>& a, vector<vector<int>>& dp){

//     // base case
//     if(i == n){
//         if(j == k){
//             return 1;
//         }
//         return 0;
//     }

//     // cache check

//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }

//     // computation

//     int ans = 0;
//     for(int c = 0; c <= a[i]; c++){

//         if(c + j <= k){
//             ans += (solve(i+1, c+j, a, dp)) % mod;
//         }
//     }

//     // return
//     return dp[i][j] = ans;

// }

int32_t main()
{

    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    dp[n][k] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= k; j++)
        {

            int ans = 0;
            for (int c = 0; c <= a[i]; c++)
            {
                if (c + j <= k)
                {
                    ans += (dp[i + 1][j + c]) % mod;
                }
            }
            dp[i][j] = ans;
        }
    }
    // cout << solve(0, 0, a, dp) << endl;
    cout << dp[0][0] << endl;
}