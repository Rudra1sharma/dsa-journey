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


double solve(int i, int head, vector<double> &p, vector<vector<double>> &dp)
{

    if (i == 0)
    {
        if (head == 0)
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    }

    if (dp[i][head] != -1)
    {
        return dp[i][head];
    }
    double res = 0;

    // case1 : tail
    res += solve(i - 1, head, p, dp) * (1.0 - p[i - 1]);

    if (head > 0)
    {
        res += solve(i - 1, head - 1, p, dp) * p[i - 1];
    }

    return dp[i][head] = res;
}

int32_t main()
{

    int n;
    cin >> n;

    vector<double> p(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, -1));

    double ans = 0.0;

    int need = n / 2 + 1;

    for (int he = need; he <= n; he++)
    {
        ans += solve(n, he, p, dp);
    }
    cout << fixed << setprecision(10) << "jeje ->" << ans << "\n";
}