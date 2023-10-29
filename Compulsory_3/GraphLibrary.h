#pragma once
#include <list>
#include <map>
#include <memory>
#include <vector>

using namespace std;

class GraphLibrary
{
private:
	int NumberOfVerticies;
	vector<vector<int>> AdjacencyList;

public:
	/*Constructor*/
	GraphLibrary(int AmountOfVerticies);

	/*Graph Operations*/
	void InsertRandomVertex(int MaximumVertexValueToInsert); //
	void InsertSpesificVertex(int VertexToInsert); //
	void DeleteVertex(int VertexToDelete);
	void InsertEdge(int Source, int Destination); //
	void DeleteEdge(int Source, int Destination); //

	/*Graph Traversal Functions*/
	void DepthFirstSearch(int Source); //
	void BreadthFirstSearch(int Source); //

	/*Access Functions*/
	void GetVertexInformation(int Source);
	int  GetAdjacentVerticies(int Source); //
	void GetVerticiesInGraph(); //
	void GetEdgesInGraph(); //

	/*Query Functions*/
	int GetSize(); //
	bool bIsEmpty(); // 
	bool bIsConnected(int Source, int Destination); //

	/*Print Function*/
	void PrintGraph(); //
	int RandomNumberGenerator(int MinNumber, int MaxNumber); //

	/*Maps*/
	map<int, bool> VertexVisited;
};
