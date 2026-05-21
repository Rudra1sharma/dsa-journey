#include <bits/stdc++.h>
using namespace std;
#define ln endl
#define ll long long
#define int long long
#define pii pair<ll, ll>
#define ff first
#define ss second

int32_t main()
{

    int n, w;
    cin >> n >> w;

    vector<int> W(n + 1);
    vector<int> V(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> W[i] >> V[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j]; // skip

            if (j >= W[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]); // take item
            }
        }
    }

    cout << dp[n][w] << endl;

    return 0;
}