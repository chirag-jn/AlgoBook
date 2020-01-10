/*
Minimum Edit Distance
Number of operations required to convert abcdef to azced
Options: 
1. Substitute
2. Insert
3. Delete

1 2 
3 4
if i==j -> 4 = 1
if i!=j -> 4 = min(1, 2, 3) + 1 

if(str1[i]==str2[j]) {
	T[i][j] = T[i-1][j-1]
} else {
	T[i][j] = min(T[i-1][j-1], T[i-1][j], T[i][j-1]) + 1
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
    freopen("../error.txt", "w", stderr);
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

int editDist(string s1, string s2, int m, int n) {
	if(m==0) 
		return n;
	if(n==0) 
		return m;
	if(s1[m-1]==s2[n-1]) {
		return editDist(s1, s2, m-1, n-1);
	} else {
		return 1 + min(editDist(s1, s2, m-1, n-1), min( // Substitute
					   editDist(s1, s2, m, n-1), 		// Insert
					   editDist(s1, s2, m-1, n)));		// Delete
	}
}

void solve() {
	string s1, s2;
	cin>>s1;
	cin>>s2;
	cout<<editDist(s1, s2, s1.length(), s2.length())<<endl;
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