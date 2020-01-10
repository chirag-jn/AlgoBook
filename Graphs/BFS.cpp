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

	void addEdge(int u, int w) {
		if (u>V-1 || w>V-1) {
			cerr<<"Error"<<endl;
		}
		adj[u].push_back(w);
	}

	void BFS(int s) {
		bool visited[V];
		for (int i = 0; i < V; ++i)
		{
			visited[i] = false;
		}

		list<int> queue;
		visited[s] = true;

		queue.push_back(s);

		while(!queue.empty()) {
			s = queue.front();
			queue.pop_front();

			cout<<s<<" ";

			for (list<int>::iterator i = adj[s].begin(); i != adj[s].end(); ++i)
			{
				if(!visited[*i]) {
					visited[*i] = true;
					queue.push_back(*i);
				}
			}
		}
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

	g.BFS(src);

	
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