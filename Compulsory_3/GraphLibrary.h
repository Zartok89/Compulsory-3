#pragma once
class GraphLibrary
{
	/*Constructor*/
	GraphLibrary();

	/*Member Functions*/
	void NodeInformation();
	void AdjacencyList();
	
	/*Tree Operations*/
	void InsertRandomNode();
	void InsertSpesificNode();
	void DeleteNode();
	void InsertEdge();
	void DeleteEdge();

	/*Tree Traversal Functions*/
	void DepthFirstSearch();
	void BreadthFirstSearch();

	/*Access Functions*/
	void GetNodeInformation();
	void GetAdjacentNodes();
	void GetVerticiesInGraph();
	void GetEdgesInGraph();

	/*Query Functions*/
	int GetSize();
	bool bIsEmpty();
};
