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

template<typename T>
class Graph {
public:
	unordered_map<T, list<T> > adj;
	void addEdge(T u, T v, bool bidir = false) {
		adj[u].pb(v);
		if (bidir) adj[v].pb(u);
	}

	void print() {
		for (auto node : adj) {
			cout << node.first << "-->";
			for (auto c : node.second) cout << c << " ";
			cout << endl;
		}
	}


	void BFS(T src, T des) {
		queue<T> q;
		unordered_map<T, bool> visited;
		unordered_map<T, int> dist;
		unordered_map<T, T> parent;
		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		parent[src] = src;

		while (!q.empty()) {
			auto node = q.front();
			cout << node << " ";
			q.pop();
			int node_dist = dist[node];

			for (auto children : adj[node]) {
				if (!visited[children]) {
					q.push(children);
					visited[children] = true;
					dist[children] = node_dist + 1;
					parent[children] = node;
				}
			}
		}
		cout << endl;
		for (auto node : dist) {
			cout << "Distance of " << node.first << " from " << src << ": " << node.second << endl;
		}

		while (des != src) {
			cout << des << "<--";
			des = parent[des];
		}
		cout << des << endl;
	}

	void dfs_helper(T src, unordered_map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		for (auto children : adj[src]) {
			if (!visited[children]) {
				dfs_helper(children, visited);
			}
		}
	}

	void dfs(T src) {
		unordered_map<T, bool> visited;
		dfs_helper(src, visited);

		int components = 1;

		for (auto node : adj) {
			if (!visited[node.first]) {
				dfs_helper(node.first, visited);
				components++;
			}
		}
		cout << "Total Components: " << components << endl;
	}

};

void solve() {
	Graph<int> g;

	g.addEdge(0, 1, true);
	g.addEdge(0, 2, true);
	g.addEdge(3, 1, true);
	g.addEdge(3, 2, true);
	g.addEdge(3, 4, true);
	g.addEdge(4, 2, true);
	g.addEdge(4, 5, true);
	g.addEdge(40, 50, true);
	g.addEdge(40, 51, true);

	// g.addEdge("Putin", "Trump", false);
	// g.addEdge("Putin", "Modi", false);
	// g.addEdge("Trump", "Modi", true);
	// g.addEdge("Yogi", "Modi", true);
	// g.addEdge("Yogi", "Prabhu", false);
	// g.addEdge("Prabhu", "Modi", false);
	// g.addEdge("Putin", "Pope", false);

	// g.BFS(1, 5);
	// unordered_map<int, bool> visited;
	g.dfs(1);

	// g.addEdge(0, 1);
	// g.addEdge(2, 1);
	// g.addEdge(0, 4);
	// g.addEdge(1, 4);
	// g.addEdge(3, 4);
	// g.addEdge(3, 2);
	// g.addEdge(3, 1);

	// g.print();

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











