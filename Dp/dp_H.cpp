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


const int mod = 1e9 + 7;

int n, m;
int solve(int i, int j, vector<vector<char>> &v, vector<vector<int>> &dp)
{

    if (i == 1 && j == 1)
    {
        return 1;
    }

    if (i < 1 || j < 1)
    {
        return 0;
    }

    if (v[i][j] == '#')
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = solve(i - 1, j, v, dp);
    int left = solve(i, j - 1, v, dp);

    return dp[i][j] = (up + left) % mod;
}

int32_t main()
{

    cin >> n >> m;

    vector<vector<char>> v(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << solve(n, m, v, dp) << endl;
}