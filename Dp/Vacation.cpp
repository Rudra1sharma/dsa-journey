#include <bits/stdc++.h>
using namespace std;
#define ln endl
#define ll long long
#define int long long
#define pii pair<ll,ll>
#define ff first
#define ss second
#define pb push_back

int n;
vector<vector<int>> v;
vector<vector<int>> dp;


int solve(int day, int prev){

    if(day == n){
        return 0;
    }


    if(dp[day][prev + 1] != -1){
        return dp[day][prev + 1];
    }

    int happy = 0;

    for(int i = 0; i < 3; i++){
        if(prev != i){
            happy = max(happy, v[day][i] + solve(day + 1, i));
        }
    }

    return dp[day][prev + 1] = happy;

}

int32_t main() {
    
    cin >> n;

    v = vector<vector<int>>(n, vector<int>(3));
    dp = vector<vector<int>>(n, vector<int>(4, -1));

    for(int i = 0; i < n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    cout << solve(0, -1) << "\n";

}