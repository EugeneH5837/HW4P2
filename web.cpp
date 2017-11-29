#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "ArgumentManager.h"
#include "LinkedList.h"
#include "Vertex.h"
#include <list>
using namespace std;

void exploregraph(string filename);
void openfiletest(string filename);
int globalEdgecount(LinkedList<Vertex*> VertexList);
bool ExistsinLL(string VertexName, LinkedList<Vertex*> VertexList);
void PrintLLGraph(LinkedList<Vertex*> VertexList);
LinkedList<string> vertcount;
//maybe make global graph 
//add isreachable algorithm to check for any isolated nodes
int main(int argc, char* argv[])
{
	 //create the graph given in above fugure
	

	// print the adjacency list representation of the above graph
	
	/*if (argc < 2) {
		std::cerr << "Usage: spellchecker inputfile=input.txt" << std::endl;
		return -1;
	}
	ArgumentManager am(argc, argv);
	const std::string script = am.get("script");
	std::cout << "input script file name is " << script << std::endl;*/

	LinkedList<Vertex*> Graph;
	Vertex *temp = new Vertex();
	Vertex *temp2 = new Vertex();
	ifstream input("input.txt");
	//ifstream input(script);
	string line;
	while (getline(input,line) ){
		cout << line << endl;
		if (line.substr(0, 7) == "explore") {
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '(' || line[i] == ')' || line[i] == '\'') {
					line[i] = ' ';
				 }
				
			}
			stringstream test(line);
			string func, file;
			test >> func >> file;
			ifstream newinput(file);
			string newline;
			while (getline(newinput, newline)) {
				ifstream fileinput(newline);
				string theline;
				cout << "FILE " << newline << endl;
				while (getline(fileinput, theline)) {
					if (theline.substr(0, 7) == "<a href") {
						int file = theline.find_first_of("\"");
						string c = theline.substr(file + 1);
						int file2 = c.find_last_of("\"");
						c.erase(file2, c.length());
						if (!ExistsinLL(c, Graph)) {
							temp = new Vertex(c);
							Graph.insertion(temp);
						}
						else {
							Node<Vertex*> *current = Graph.head;
							while (current != NULL) {
								if (c == current->info->GetName()) {
									temp = current->info;
								}

								current = current->next;
							}
						}
						if (!ExistsinLL(newline, Graph)) {
							temp2 = new Vertex(newline);
							temp2->outdegree++;
							Graph.insertion(temp2);
							Node<Vertex*> *current = Graph.head;
							while (current != NULL) {
								if (current->info->GetName() == newline) {
									temp->indegree++;
									current->info->adjlist.insertion(temp);
								}
								current = current->next;
							}
						}
						else {
							Node<Vertex*> *current = Graph.head;
							while (current != NULL) {
								if (newline == current->info->GetName()) {
									current->info->outdegree++;
									//current->info->AddNewVertexLL(temp);
									temp->indegree++;
									current->info->adjlist.insertion(temp);
								}
								current = current->next;
							}
						}
						cout << c << endl;
					}
				}
			}
			
		}
	}	
	PrintLLGraph(Graph);
	cout << endl;
	cout << "n " << Graph.count << endl;
	cout << "m " << globalEdgecount(Graph) << endl;
	system("pause");
	return 0;
}



bool ExistsinLL(string VertexName, LinkedList<Vertex*> VertexList) {
	Node<Vertex*> *temp = VertexList.head;
	while (temp != NULL) {
		if (VertexName == temp->info->GetName()) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}
void PrintLLGraph(LinkedList<Vertex*> VertexList) {
	Node<Vertex*> *current = VertexList.head;
	while (current != NULL) {
		current->info->PrintVertexsLL();
		current = current->next;
	}
	cout << endl;
}
void findisolated(LinkedList<Vertex*> graph) {

}

void findtopthree(LinkedList<Vertex*> graph) {
	Node<Vertex*> *current = graph.head;
	string top, top2, top3;
	while (current != NULL) {
		current->info->indegree;
		current = current->next;
	}
}
void exploregraph(string filename) {
	string line;
	ifstream input(filename);
	while (getline(input, line)) {
		openfiletest(line);
	}
}
int globalEdgecount(LinkedList<Vertex*> VertexList) {
	int count = 0;
	int thecount;
	Node<Vertex*> *current = VertexList.head;
	while (current != NULL) {
		thecount = current->info->adjlist.count;
		current = current->next;
		count += thecount;
	}
	return count;
}

void openfiletest(string filename) {
	ifstream input(filename);
	if (!vertcount.find(filename)) {
		vertcount.insertion(filename);
	}
	string line;
	cout << "FILE "<<filename << endl;
	while (getline(input, line)) {
		if (line.substr(0, 7) == "<a href") {
			int file = line.find_first_of("\"");
			string c = line.substr(file + 1);
			int file2 = c.find_last_of("\"");
			c.erase(file2, c.length());
			cout << c<<endl;
		}
	}
}



Vertex::Vertex(string newName)
{
	IsUsable = true;
	IsActive = true;
	Name = newName;
	indegree = 0;
}

Vertex::Vertex() {

}

bool Vertex::GetActive()
{
	return IsActive;
}

string Vertex::GetName()
{
	return Name;
}

void Vertex::AddNewVertex(Vertex *newVertex)
{

	adjList.push_back(newVertex);
}

void Vertex::AddNewVertexLL(Vertex *newVertex) {
	adjlist.insertion(newVertex);
}

bool Vertex::IsVertexPresent(string VertexName)
{

	for (int i = 0; i<adjList.size(); i++)
	{
		if (adjList[i]->GetName() == VertexName) return true;
	}
	return false;
}

void Vertex::PrintVertexs()
{
	cout << "Vertex\tLinks to\n-----\t--------\n";
	cout << GetName();
	for (int i = 0; i<adjList.size(); i++)
	{
		if (adjList[i]->GetActive())
		{
			cout << "\t" << adjList[i]->GetName() << endl;
		}
	}
	cout << endl;

}
void Vertex::PrintVertexsLL() {
	cout << "Vertex\tLinks to\n-----\t--------\n";
	cout << GetName();  //vertex
	cout << " indegree " << indegree;
	cout << " outdegree " << outdegree << endl;
	Node<Vertex*> *current = adjlist.head;
	while (current != NULL) {
		cout << "\t" << current->info->GetName() << " ";
		current = current->next;
	}
	cout << endl;
	cout << endl;
}



int Vertex::getCount() {
	return adjlist.count;
}

void Vertex::Activate()
{
	IsActive = true;
}

void Vertex::Deactivate()
{
	IsActive = false;
}

bool Vertex::GetUsable()
{
	return IsUsable;
}

void Vertex::SetUsable(bool usable)
{
	IsUsable = usable;
}

vector<Vertex*> Vertex::GetAdjacencyList()
{
	return adjList;
}

LinkedList<Vertex*> Vertex::GetLL() {
	return adjlist;
}