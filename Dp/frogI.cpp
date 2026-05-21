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

int n;
int dp[100001];

int solve(int i, vector<int> &h)
{

    // base case
    if (i == n - 1)
    {
        return 0;
    }

    if (dp[i] != -1)
    {
        return dp[i];
    }

    int jump1 = 1e9;

    if (i + 1 < n)
    {
        jump1 = solve(i + 1, h) + abs(h[i + 1] - h[i]);
    }

    int jump2 = 1e9;
    if (i + 2 < n)
    {
        jump2 = solve(i + 2, h) + abs(h[i + 2] - h[i]);
    }
    // ans = min({ans, abs(h[i+1] - h[i]) + solve(i+1, h), abs(h[i+2] - h[i]) + solve(i+2, h)});

    return dp[i] = min(jump1, jump2);
}

int32_t main()
{

    cin >> n;

    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, h) << endl;
}

// int n;
// int dp[100001];

// int solve(int i, vector<int> &h)
// {

//     // base case
//     if (i >= n)
//     {
//         return 1e9;
//     }

//     if (i == n - 1)
//     {
//         return 0;
//     }

//     if (dp[i] != -1)
//     {
//         return dp[i];
//     }

//     int ans = 1e9;
//     ans = min({ans, abs(h[i + 1] - h[i]) + solve(i + 1, h), abs(h[i + 2] - h[i]) + solve(i + 2, h)});

//     return dp[i] = ans;
// }

// int32_t main()
// {

//     cin >> n;

//     vector<int> h(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> h[i];
//     }

//     memset(dp, -1, sizeof(dp));
//     cout << solve(0, h) << endl;
// }

