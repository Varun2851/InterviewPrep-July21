// NStairs.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <deque>
#include <bitset>
#include <climits>
#include <cstdio>
#include <list>
#include <iomanip>
using namespace std;

#define ll long long int
#define new(a,n) ll*a = new ll[n]
#define new1(a,n,m) ll**a = new ll*[n]; for(ll i = 0 ; i < n ; i++) a[i] = new ll[m];
#define mp make_pair
#define pb push_back
#define fi first
#define pii pair<ll,ll>
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define init(a,n,v) for(int i = 0 ; i <n ; i++) a[i]=v;
#define init2(a,n,m,v) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){a[i][j]=v;}}
#define AS 200001
#define mod 1000000007

ll dp[10000];

ll NStairs(ll n, ll k) {
	// base case
	if (n == 0) {
		return dp[n] = 1;
	}
	if (n < 0) {
		return 0;
	}
	if (dp[n] != -1) {
		return dp[n];
	}
	// Recursive case
	ll ans = 0;
	for (ll i = 1 ; i <= k ; i++) {
		ans += NStairs(n - i, k);
	}
	return dp[n] = ans;
}

ll NStairsFast(ll n, ll k) {
	ll dp[10000];
	dp[0] = dp[1] = 1;

	for (ll i = 2 ; i <= n ; i++) {
		dp[i] = 2 * dp[i - 1] - ((i - 1 - k >= 0) ? dp[i - 1 - k] : 0);
	}

	return dp[n];
}

void solve() {
	ll n, k;
	cin >> n >> k;

	memset(dp, -1, sizeof dp);
	cout << NStairs(n, k) << endl;
	cout << NStairsFast(n, k) << endl;
}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}










