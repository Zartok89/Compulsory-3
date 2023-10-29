#include <iostream>
#include "Main.h"
#include <string>
#include "GeneralTreeLibrary.h"
#include "GraphLibrary.h"

#define COUTSPACE cout << endl;

int main()
{
	//Creating constructor for the root
	GeneralTree = make_shared<GeneralTreeLibrary>(10);
	shared_ptr<TreeNode> Root = GeneralTree->GetTreeRoot();

	//Creating constructor for the graph
	Graph = make_shared<GraphLibrary>(10);

	////Adding children to the root
	GeneralTree->AddSpesificNode(Root, 2); //i=0
	GeneralTree->AddSpesificNode(Root, 3); //i=1

	////Adding children 4, 5 and 6 to the root of 2 and 3
	GeneralTree->AddSpesificNode(Root->Children[0], 4);
	GeneralTree->AddSpesificNode(Root->Children[0], 5);
	GeneralTree->AddSpesificNode(Root->Children[0], 6);
	GeneralTree->AddSpesificNode(Root->Children[1], 7);
	GeneralTree->AddSpesificNode(Root->Children[1], 8);
	GeneralTree->AddSpesificNode(Root->Children[1], 9);

	//Adding children 13 and 14 to the root of 4
	GeneralTree->AddSpesificNode(Root->Children[1]->Children[0], 10);
	GeneralTree->AddSpesificNode(Root->Children[1]->Children[0], 11);

	cout << "Depth First Search Traversal of the N-ary tree: ";
	GeneralTree->DepthFirstSearch(Root);
	COUTSPACE
	cout << "Breadth First Search Traversal of the N-ary tree: ";
	GeneralTree->BreadthFirstSearch(Root);
	COUTSPACE
	cout << "List of nodes in Root: " << endl;
	GeneralTree->ListOfNodes(Root);
	//cout << "List of nodes in Root->Children[0]: " << endl;
	//GeneralTree->ListOfNodes(Root->Children[0]);
	GeneralTree->GetSize(Root);
	COUTSPACE
	GeneralTree->bIsLeaf(Root);
	GeneralTree->bIsLeaf(Root->Children[0]);
	GeneralTree->bIsLeaf(Root->Children[0]->Children[0]);
	COUTSPACE
	cout << "--BEFORE DELETION OF LEAFS-- " << endl;
	cout << "Pre-Order Traversal: ";
	GeneralTree->PreOrderTraversal(Root);
	COUTSPACE
	cout << "Post-Order Traversal: ";
	GeneralTree->PostOrderTraversal(Root);
	COUTSPACE
	GeneralTree->DeleteAllLeafNodes(Root);
	COUTSPACE
	cout << "--AFTER DELETION OF LEAFS-- " << endl;
	cout << "Pre-Order Traversal: ";
	GeneralTree->PreOrderTraversal(Root);
	COUTSPACE
	cout << "Post-Order Traversal: ";
	GeneralTree->PostOrderTraversal(Root);
	COUTSPACE
	COUTSPACE
	cout << "****Random Tree****" << endl;
	GeneralTree->GeneratingRandomTree();
	COUTSPACE
	Graph->InsertEdge(0, 1);
	Graph->InsertEdge(0, 4);
	Graph->InsertEdge(1, 2);
	Graph->InsertEdge(1, 3);
	Graph->InsertEdge(1, 4);
	Graph->InsertEdge(2, 3);
	Graph->InsertEdge(3, 4);
	COUTSPACE
	cout << "--BEFORE DELETION OF EDGE-- " << endl;
	Graph->PrintGraph();
	COUTSPACE
	Graph->DeleteEdge(1, 4);
	COUTSPACE
	cout << "--AFTER DELETION OF EDGE-- " << endl;
	Graph->PrintGraph();
	COUTSPACE
	Graph->DeleteVertex(2);
	COUTSPACE
	cout << "--AFTER DELETION OF VERTEX-- " << endl;
	Graph->PrintGraph();
	COUTSPACE
	//Graph->InsertRandomVertex(50);
	//Graph->InsertRandomVertex(10);
	//Graph->InsertRandomVertex(20);
	//Graph->InsertRandomVertex(200);
	//Graph->InsertRandomVertex(65);
	COUTSPACE
	Graph->InsertSpesificVertex(3);
	COUTSPACE
	cout << "--AFTER DELETION OF EDGE-- " << endl;
	Graph->PrintGraph();
	COUTSPACE
	cout << "--Check Connected--" << endl;
	Graph->bIsConnected(0, 1);
	Graph->bIsConnected(0, 2);
	Graph->bIsConnected(0, 4);
	COUTSPACE
	cout << "--Check if Graph is empty--" << endl;
	Graph->bIsEmpty();
	COUTSPACE
	cout << "--Check size of the Graph--" << endl;
	Graph->GetSize();
	COUTSPACE
	Graph->GetAdjacentVerticies(1);
	COUTSPACE
	cout << "Depth First Traversal: " << " ";
	Graph->DepthFirstSearch(3);
	COUTSPACE
	cout << "Bredth First Traversal: " << " ";
	Graph->BreadthFirstSearch(3);
	COUTSPACE
	Graph->GetVertexInformation(3);
	COUTSPACE
	Graph->GetVerticiesInGraph();
	COUTSPACE
	Graph->GetEdgesInGraph();
	COUTSPACE
}

//Printing out the tree
void PrintTrees(shared_ptr<TreeNode> TreeRoot)
{
	cout << "Root data: " << TreeRoot->Data << endl;
	if (TreeRoot->Children.size() == TreeRoot->Children.empty()) { return; }
	for (shared_ptr<TreeNode>& Child : TreeRoot->Children)
	{
		cout << "Child data: " << Child->Data << endl;
		if (Child->Children.size() == Child->Children.empty()) { return; }
		for (shared_ptr<TreeNode>& GrandChild : Child->Children)
		{
			cout << "GrandChild data: " << GrandChild->Data << endl;
			if (GrandChild->Children.size() == GrandChild->Children.empty()) { return; }
			for (shared_ptr<TreeNode>& GreatGrandChild : GrandChild->Children)
			{
				cout << "GreatGrandChild data: " << GreatGrandChild->Data << endl;
			}
		}
	}
}
