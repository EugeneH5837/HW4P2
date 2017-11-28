#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "ArgumentManager.h"
#include "LinkedList.h"
#include <list>
using namespace std;

void exploregraph(string filename);
void openfiletest(string filename);
// A C Program to demonstrate adjacency list representation of graphs
LinkedList<string> vertcount;
// Driver program to test above functions
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

	ifstream input("input.txt");
	//ifstream input(script);
	string line;
	while (getline(input,line) ){
		//cout << line << endl;
		//if (line.substr(0, 7) == "<a href") {
		//	int file = line.find_first_of("\"");
		//	string c = line.substr(file + 1);
		//	int file2 = c.find_last_of("\"");
		//	c.erase(file2, c.length());
		//	//cout << c<<endl;
		//}
		if (line.substr(0, 7) == "explore") {
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '(' || line[i] == ')' || line[i] == '\'') {
					line[i] = ' ';
				 }
				
			}
			stringstream test(line);
			string func, file;
			test >> func >> file;
			exploregraph(file);
		}
	}	
	int vertices = vertcount.count;
	cout << "VERTICES" << vertices << endl;
	/*LinkedList<string> b;
	b.insertion("p");
	b.display();
	list<int> *test;
	test[0].push_back(2);*/
	vertcount.display();
	LinkedList<string> b;
	b.insertion("1.txt");
	if (!b.find("2.txt")) {
		//cout << "not found";
	}
	else {
		//cout << "found";
	}
	system("pause");
	return 0;
}

void exploregraph(string filename) {
	string line;
	ifstream input(filename);
	while (getline(input, line)) {
		openfiletest(line);
	}
}

void openfiletest(string filename) {
	ifstream input(filename);
	if (!vertcount.find(filename)) {
		vertcount.insertion(filename);
	}
	string line;
	//cout << "FILE "<<filename << endl;
	while (getline(input, line)) {
		if (line.substr(0, 7) == "<a href") {
			int file = line.find_first_of("\"");
			string c = line.substr(file + 1);
			int file2 = c.find_last_of("\"");
			c.erase(file2, c.length());
			if (!vertcount.find(c)) {
				vertcount.insertion(c);
			}
			//cout << c<<endl;
		}
	}
}
//implement function for exploregraph
//class edge {
//
//};
//class node {
//	LinkedList<edge> adjlist;
//};
//
//class graph {
//	int vertices;
//	LinkedList<string> *adj;
//	AdjList* array;
//	graph();
//	void addEdge(int v, int w);
//};
//
//void graph::addEdge(int v, int w) {
//
//}
//
//graph::graph() {
//
//	adj = new LinkedList<string>;
//}
//
//struct AdjacentListNode {
//	int destination;
//	AdjacentListNode *next;
//};
//struct AdjList {
//	AdjacentListNode *nodelist;
//};
//
