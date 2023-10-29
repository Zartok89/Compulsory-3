#pragma once
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

	/*Member Functions*/
	void NodeInformation();

	/*Graph Operations*/
	void InsertRandomNode(int MaximumVertexValueToInsert); //
	void InsertSpesificNode(int VertexToInsert); //
	void DeleteVertex(int VertexNodeToDelete);
	void InsertEdge(int Source, int Destination); //
	void DeleteEdge(int Source, int Destination); //

	/*Graph Traversal Functions*/
	void DepthFirstSearch();
	void BreadthFirstSearch();

	/*Access Functions*/
	void GetNodeInformation();
	void GetAdjacentNodes();
	void GetVerticiesInGraph();
	void GetEdgesInGraph();

	/*Query Functions*/
	int GetSize(); //
	bool bIsEmpty(); // 
	bool bIsConnected(int Source, int Destination); //

	/*Print Function*/
	void PrintGraph(); //
	int RandomNumberGenerator(int MinNumber, int MaxNumber); //
};
