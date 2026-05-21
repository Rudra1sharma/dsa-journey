#include <bits/stdc++.h>
using namespace std;
#define ln endl
#define ll long long
#define int long long
#define pii pair<ll, ll>
#define ff first
#define ss second
#define pb push_back

int n;
vector<vector<int>> v;
vector<vector<int>> dp;

int solve(int day, int activity)
{

    if (day == 0)
    {
        return 0;
    }

    if (dp[day][activity] != -1)
    {
        return dp[day][activity];
    }

    int best = 0;
    for (int prev = 0; prev < 3; prev++)
    {
        if (prev != activity)
        {
            best = max(best, solve(day - 1, prev));
        }
    }
    return dp[day][activity] = v[day][activity] + best;
}

int32_t main()
{

    cin >> n;

    v = vector<vector<int>>(n + 1, vector<int>(3));
    dp = vector<vector<int>>(n + 1, vector<int>(3, -1));

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    int ans = max({solve(n, 0), solve(n, 1), solve(n, 2)});

    cout << ans << endl;
}