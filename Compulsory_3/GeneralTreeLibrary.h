#pragma once
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;

struct TreeNode
{
	int Data;
	vector<shared_ptr<TreeNode>> Children;
	shared_ptr<TreeNode> Parent;

	TreeNode(int InputData);
};

class GeneralTreeLibrary
{
public:
	shared_ptr<TreeNode> Root;

	/*Constructor*/
	GeneralTreeLibrary(int RootData);

	/*Member Functions*/
	void NodeInformation(shared_ptr<TreeNode> Node);
	void ListOfNodes(shared_ptr<TreeNode> Node);

	/*Tree Operations*/
	shared_ptr<TreeNode> CreateNewNode(int NodeData);
	shared_ptr<TreeNode> AddRandomNode(shared_ptr<TreeNode> Node);
	void GeneratingRandomTree();
	void GeneratingRandomTreeV2(shared_ptr<TreeNode> Root, int MaxDepth, int CurrentDepth);
	shared_ptr<TreeNode> AddSpesificNode(shared_ptr<TreeNode> Node, int NodeData);
	void DeleteNode(shared_ptr<TreeNode> RootNode, int NodeToDeleteFrom);
	shared_ptr<TreeNode> DeleteAllLeafNodes(shared_ptr<TreeNode> RootNode);

	/*Tree Traversal Functions*/
	// Pre and Post Traversal
	void PreOrderTraversal(shared_ptr<TreeNode> RootNode);
	void PostOrderTraversal(shared_ptr<TreeNode> RootNode);

	void DepthFirstSearch(shared_ptr<TreeNode> RootNode);
	void BreadthFirstSearch(shared_ptr<TreeNode> RootNode);

	/*Access Functions*/
	shared_ptr<TreeNode> GetTreeRoot();
	shared_ptr<TreeNode> GetParentNode(shared_ptr<TreeNode> Node, int NodeID);
	shared_ptr<TreeNode> GetNode(shared_ptr<TreeNode> Node, int NodeID);

	/*Query Functions*/
	int GetSize(shared_ptr<TreeNode> RootNode);
	int GetDepth(shared_ptr<TreeNode> RootNode);
	bool bIsEmpty(shared_ptr<TreeNode> RootNode);
	bool bIsRoot();
	bool bIsLeaf(shared_ptr<TreeNode> RootNode);

	/*Variables*/
	shared_ptr<TreeNode> FoundNode;

	/*Random Number Generator*/
	int RandomNumberGenerator(int MinNumber, int MaxNumber);

};
