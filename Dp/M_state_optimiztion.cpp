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
        vector<int> pref_dp(k + 1, 0);
        // prefix sum array
        pref_dp[0] = dp[i + 1][0];
        for (int j = 1; j <= k; j++)
        {
            pref_dp[j] = (pref_dp[j - 1] + dp[i + 1][j]) % mod;
        }

        for (int j = 0; j <= k; j++)
        {

            int ans = 0;
            // for(int c = 0; c <= a[i]; c++){
            //     if(c + j <= k){
            //         ans += (dp[i+1][j + c]) % mod;
            //     }
            // }
            // dp[i][j] = ans;

            if (a[i] < k - j)
            {
                ans = pref_dp[j + a[i]] % mod;
                else
                {
                }
                ans = pref_dp[k] % mod;
            }

            if (j != 0)
            {
                ans = (ans - pref_dp[j - 1] + mod) % mod;
            }

            dp[i][j] = ans;
        }
    }

    cout << dp[0][0] << endl;
}