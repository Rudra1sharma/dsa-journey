#include <bits/stdc++.h>
using namespace std;
#define ln endl
#define ll long long
#define int long long
#define pii pair<ll, ll>
#define ff first
#define ss second

int N, W;
vector<int> w, v;

vector<vector<ll>> dp;

int solve(int i, int cap)
{

    if (i < 0)
    {
        return 0;
    }

    if (dp[i][cap] != -1)
    {
        return dp[i][cap];
    }

    int not_take = solve(i - 1, cap);

    int take = 0;

    if (w[i] <= cap)
    {
        take = v[i] + solve(i - 1, cap - w[i]);
    }

    return dp[i][cap] = max(take, not_take);
}

int32_t main()
{

    cin >> N >> W;

    v.resize(N);
    w.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    dp.assign(N, vector<ll>(W + 1, -1));

    cout << solve(N - 1, W) << "\n";

    return 0;
}