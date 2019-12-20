#include<bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define endl '\n'

void setEnv() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    // for writing error to error.txt
    freopen("error.txt", "w", stderr);
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

void solve() {

}

signed main() {
	setEnv();

	int t = 1;
	cin>>t;
	while(t--) {
		solve();
	}

	return 0;
}