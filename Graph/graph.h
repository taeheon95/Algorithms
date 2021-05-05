#ifndef __graph_h__
#define __graph_h__

#include<list>
#include<iostream>

class graph
{
private:
	int v;
	std::list<int>* adj;
public:
	graph(int vertax) : v(vertax)
	{adj = new std::list<int>[v];}
	void addedge(int src, int dest);
	void printgraph();
	void bfs(int s);
};

#endif