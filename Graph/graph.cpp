#include "graph.h"
#include<iostream>
#include<list>

using namespace std;

void graph::addedge(int src, int dest)
{
	src--;
	dest--;
	adj[src].push_back(dest);
}

void graph::printgraph()
{
	for (int i=0; i< this->v; i++)
	{
		cout << endl << "Adjacency list of vertex " << i + 1 << " is \n";
		for (auto& it : adj[i])
			cout << it + 1 << " ";
	}
	cout << endl;
}

void graph::bfs(int s)
{
	bool* visited = new bool[this->v + 1];
	memset(visited, false, sizeof(bool) * (this->v + 1));
	visited[s] = true;
	list<int> q;
	q.push_back(s);
	while (!q.empty())
	{
		int u = q.front();
		cout << u << " ";
		q.pop_front();
		for (auto& it : adj[u])
		{
			if (visited[it] == false)
			{
				visited[it] == true;
				q.push_back(it);
			}
		}
	}
}