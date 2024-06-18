#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dfs(int i, vector<ll> &a, vector<ll> &b, ll m, ll n, vector<ll> &dp) {
    if(i > m)return 0;
    if(dp[i] != -1)return dp[i];
    ll ans = 1e17, run = 0;
    for(int j=i+1;j<a.size();j++){
        ans = min(ans, dfs(j, a, b, m ,n, dp) + run + a[j]);
        run += b[j];
    }
    return dp[i] = ans;
} 

void L() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n+1), b(n+1), dp(n+1, -1);
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    cout << dfs(0, a, b, n - m, n, dp) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    L();
    return 0;
}