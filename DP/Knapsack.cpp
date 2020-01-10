/*
You have the maximum weight possible and then you have certain items with their weights and values
maximise value, total weight is less than or equal to maximum weight
You can either pick the item or not pick at all
Greedy: Sort the items by val/weight in non-increasing order. And split the item at the last to maximise value.
But we can't split here.
So we use DP
Hint:
row i
col j
if (j < wt[i]) {
	T[i][j] = T[i-1][j]
} else {
	T[i][j] = max(T[i-1][j], val[i] + T[i-1][j-wt[i]])
}
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n'

void setEnv() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
    // for writing error to error.txt
    // freopen("../error.txt", "w", stderr);
	#endif

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
}

void debug(string s) { // Doesn't run in case of an online judge
	#ifndef ONLINE_JUDGE
	cout<<s<<endl;
	#endif
}

void debug(int s) { // Doesn't run in case of an online judge
	#ifndef ONLINE_JUDGE
	cout<<s<<endl;
	#endif
}

int max(int a, int b) {
	return (a>b) ? a:b;
}

int knapsack(int max_wt, int* val, int* wt, int n) {
	if(n==0 || max_wt==0) {
		return 0;
	} 
	if(wt[n-1] > max_wt) {
		return knapsack(max_wt, val, wt, n-1);
	} else {
		return max(knapsack(max_wt, val, wt, n-1), val[n-1] + knapsack(max_wt-wt[n-1], val, wt, n-1));
	}

	return 0;
}

void solve() {
	int num_items = 0;
	cin>>num_items;
	
	int max_wt = 0;
	cin>>max_wt;

	int values[num_items];
	int weights[num_items];
	
	for(int i=0; i<num_items; i++) {
		cin>>values[i];
		cin>>weights[i];
	}

	cout<<knapsack(max_wt, values, weights, num_items)<<endl;


}

signed main() {
	setEnv();

	int t = 1;
	// cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}