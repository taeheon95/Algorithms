#pragma once
#include<list>
#include<iostream>

class graph
{
private:
	int v;
	std::list<int>* adj;
public:
	graph(int vertax) : v(vertax)
	{adj = new std::list<int>[vertax];}
	void addedge(int src, int dest);
	void printgraph();
	void bfs(int s);
};