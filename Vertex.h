#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "LinkedList.h"

using namespace std;

class Vertex
{
public:
	//Constructor for the class
	Vertex(string newName);

	Vertex();
	//Will return the active status of the Vertex
	bool GetActive();

	//Adds a new Vertex to the list of Vertexs
	void AddNewVertex(Vertex *newVertex);

	//Checks if tempVertex is present in the list of Vertexs, will return true or false
	bool IsVertexPresent(string VertexName);

	//Prints all the Vertexs in the list and also the Vertex that owns the list
	void PrintVertexs();

	//Gets the name of the Vertex
	string GetName();

	//Activates Vertex (sets boolean flag to true)
	void Activate();

	//Deactivates Vertex (sets boolean flag to false)
	void Deactivate();

	//Checks if Vertex is usable
	bool GetUsable();
	void Vertex::AddNewVertexLL(Vertex *newVertex);
	//Sets "usable" property
	void SetUsable(bool usable);
	LinkedList<Vertex*> Vertex::GetLL();
	vector<Vertex*> GetAdjacencyList();
	void Vertex::PrintVertexsLL();
	LinkedList<Vertex*> adjlist;
	int getCount();
	int indegree;
	int outdegree;
private:
	bool IsActive;
	bool IsUsable;

	vector<Vertex*> adjList;
	string Name;

};
