#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<vector<int>>> dp;

int dfs(vector<vector<int>> &city, int r1, int c1, int r2, int c2)
{

    // int c2 = r1 + c1 - r2; // since same steps

    if (r1 >= n || r2 >= n || c1 >= n || c2 >= n)
    {
        return -1e9;
    }

    if (city[r1][c1] == -1 || city[r2][c2] == -1)
        return -1e9;

    if (r1 == n - 1 && c1 == n - 1)
    {
        return city[r1][c1];
    }

    if (dp[r1][c1][r2] != INT_MIN)
    {
        return dp[r1][c1][r2];
    }

    int rider = 0;
    if (r1 == r2 && c1 == c2)
        rider += city[r1][c1];

    else
        rider += city[r1][c1] + city[r2][c2];

    // explore all possibilitiies

    int best = max({
        dfs(city, r1 + 1, c1, r2 + 1, c2), // r r
        dfs(city, r1, c1 + 1, r2, c2 + 1), // d d
        dfs(city, r1 + 1, c1, r2, c2 + 1), // d r
        dfs(city, r1, c1 + 1, r2 + 1, c2), // r d
    });

    return dp[r1][c1][r2] = rider + best;
}

int maxRiders(vector<vector<int>> &city)
{
    n = city.size();

    dp.assign(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));

    return max(0, dfs(city, 0, 0, 0, 0));
}

int main()
{
    vector<vector<int>> city = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1, 1}};
    cout << maxRiders(city) << endl; // Output: 5
}
