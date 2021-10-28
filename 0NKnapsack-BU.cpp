#include "bits/stdc++.h"
 
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define filewr() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
int main(){
	fastio();
	int n,w;
	cin >> n >> w;
	vector<int> val(n,0), weights(n, 0);
	// dp = vector<vector<int>>(w+1, vector<int>(n+1, -1));
	for(int i=0;i<n;i++)
		cin >> weights[i];
	for(int i=0;i<n;i++)
		cin >> val[i];

	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(i==0 || j==0) continue;
			if(weights[i-1]<=j)
				dp[i][j] = max(max(dp[i-1][j], val[i-1] + dp[i][j-weights[i-1]]), val[i-1] + dp[i-1][j-weights[i-1]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	// for(int i=0;i<n+1;i++){
	// 	for(int j=0;j<w+1;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[n][w];

	return 0;
}