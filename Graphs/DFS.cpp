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

class Graph {
	int V;
	list<int> *adj;

public:
	Graph(int v) {
		this->V = v;
		adj = new list<int>[V];
	}

	void addEdge(int u, int v) {
		if(u>V-1 || v>V-1) {
			cerr<<"Error"<<endl;
			exit(0);
		}
		adj[u].push_back(v);
	}

	void DFSUtil(int s, bool *visited) {
		visited[s] = true;
		cout<<s<<" ";

		for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i)
		{	
			if(!visited[*i]) {
				DFSUtil(*i, visited);
			}
		}
	}

	void DFS(int s) {
		bool *visited = new bool[V];
		for (int i = 0; i < V; ++i)
		{
			visited[i] = false;
		}

		DFSUtil(s, visited);
		cout<<endl;
	}
};

void solve() {
	int num_nodes;
	cin>>num_nodes;

	Graph g(num_nodes);

	int num_edges;
	cin>>num_edges;

	for (int i = 0; i < num_edges; ++i)
	{
		int u, v;
		cin>>u>>v;
		g.addEdge(u, v);
	}

	int src;
	cin>>src;

	g.DFS(src);
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