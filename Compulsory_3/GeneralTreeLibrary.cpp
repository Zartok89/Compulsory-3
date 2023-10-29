#include "GeneralTreeLibrary.h"

#include <map>
#include <queue>
#include <random>
#include <string>

TreeNode::TreeNode(int InputData)
{
	Data = InputData;
}

GeneralTreeLibrary::GeneralTreeLibrary(int RootData)
{
	Root = make_shared<TreeNode>(RootData);
}

shared_ptr<TreeNode> GeneralTreeLibrary::CreateNewNode(int NodeData)
{
	shared_ptr<TreeNode> NewNode = make_shared<TreeNode>(NodeData);
	NewNode->Data = NodeData; //De-referencing. Another way could be to do (*NodeData);
	return NewNode;
}

shared_ptr<TreeNode> GeneralTreeLibrary::AddSpesificNode(shared_ptr<TreeNode> Node, int NodeData)
{
	//Creating a new node
	shared_ptr<TreeNode> NewNode = CreateNewNode(NodeData);
	Node->Children.push_back(NewNode);
	return NewNode;
}

shared_ptr<TreeNode> GeneralTreeLibrary::AddRandomNode(shared_ptr<TreeNode> Node)
{
	shared_ptr<TreeNode> RandomNode = CreateNewNode(RandomNumberGenerator(0, 300));
	Node->Children.push_back(RandomNode);
	return RandomNode;
}

void GeneralTreeLibrary::GeneratingRandomTree()
{
	int RandomTreeSize = RandomNumberGenerator(5, 20);
	for (int i = 0; i < RandomTreeSize; i++)
	{
		AddRandomNode(Root);
	}

	for (int i = 0; i < RandomTreeSize; i++)
	{
		AddRandomNode(Root->Children[i]);
		for (int i = RandomTreeSize - (rand() % 3); i < RandomTreeSize; i++)
		{
			AddRandomNode(Root->Children[i]);
		}
	}

	cout << "Root data: " << Root->Data << endl;
	for (shared_ptr<TreeNode>& Child : Root->Children)
	{
		cout << "Child data: " << Child->Data << endl;
		for (shared_ptr<TreeNode>& GrandChild : Child->Children)
		{
			cout << "GrandChild data: " << GrandChild->Data << endl;
		}
	}
}

void GeneralTreeLibrary::DeleteNode(shared_ptr<TreeNode> RootNode, int NodeToDeleteFrom)
{
	if (RootNode->Children.empty() == false)
	{
		for (shared_ptr<TreeNode> Children : RootNode->Children)
		{
			DeleteNode(Children, NodeToDeleteFrom);

			if (Children->Data > NodeToDeleteFrom)
			{
				RootNode->Children.erase(RootNode->Children.begin());
			}
			else return;
		}
		cout << "Deleted nodes from root:" << NodeToDeleteFrom << endl;
	}
}

shared_ptr<TreeNode> GeneralTreeLibrary::DeleteAllLeafNodes(shared_ptr<TreeNode> RootNode)
{
	if (RootNode == nullptr) return nullptr; //if root is NULL return NULL
	if (RootNode->Children.empty())
	{
		//if root itself is leaf then return NULL
		return nullptr;
	}
	for (int i = 0; i < RootNode->Children.size(); i++)
	{
		//moving onto its children
		shared_ptr<TreeNode> Child = RootNode->Children[i];
		if (Child->Children.empty())
		{
			for (int j = i; j < RootNode->Children.size() - 1; j++)
			{
				// update the children vector as well
				RootNode->Children[j] = RootNode->Children[j + 1];
			}
			RootNode->Children.pop_back();
			i--;
		}
	}
	for (int i = 0; i < RootNode->Children.size(); i++)
	{
		//recursive call
		RootNode->Children[i] = DeleteAllLeafNodes(RootNode->Children[i]);
	}
	return RootNode;
}

void GeneralTreeLibrary::PreOrderTraversal(shared_ptr<TreeNode> RootNode)
{
	if (RootNode == nullptr) { return; }
	cout << RootNode->Data << " ";
	for (shared_ptr<TreeNode> Child : RootNode->Children)
	{
		PreOrderTraversal(Child);
	}
}

void GeneralTreeLibrary::PostOrderTraversal(shared_ptr<TreeNode> RootNode)
{
	if (RootNode == nullptr) { return; }
	for (shared_ptr<TreeNode> Child : RootNode->Children)
	{
		PostOrderTraversal(Child);
	}
	cout << RootNode->Data << " ";
}

void GeneralTreeLibrary::DepthFirstSearch(shared_ptr<TreeNode> RootNode)
{
	if (Root == nullptr) { return; }

	//Process the current node
	cout << RootNode->Data << " ";

	//Recursion on the children
	for (shared_ptr<TreeNode> Child : RootNode->Children)
	{
		DepthFirstSearch(Child);
	}
}

void GeneralTreeLibrary::BreadthFirstSearch(shared_ptr<TreeNode> RootNode)
{
	if (Root == nullptr) { return; }

	//Create a queue
	queue<shared_ptr<TreeNode>> Queue;

	//Enqueue the root node
	Queue.push(RootNode);

	while (!Queue.empty())
	{
		//Dequeue a node from the queue
		shared_ptr<TreeNode> Node = Queue.front();
		cout << Node->Data << " ";
		Queue.pop();

		//Enqueue the children of the dequeued node
		for (shared_ptr<TreeNode> Child : Node->Children)
		{
			Queue.push(Child);
		}
	}
}

shared_ptr<TreeNode> GeneralTreeLibrary::GetTreeRoot()
{
	return Root;
}

shared_ptr<TreeNode> GeneralTreeLibrary::GetParentNode(shared_ptr<TreeNode> Node, int NodeID)
{
	shared_ptr<TreeNode> ParentNode = Node->Parent;
	return ParentNode;
}

shared_ptr<TreeNode> GeneralTreeLibrary::GetNode(shared_ptr<TreeNode> Node, int NodeID)
{
	//Pre-order traversal
	if (Node->Data == NodeID)
	{
		FoundNode = Node;
		return FoundNode;
	}
	else
	{
		for (int i = 0; i < Node->Children.size(); i++)
		{
			GetNode(Node->Children[i], NodeID);
		}
		return FoundNode;
	}
}

int GeneralTreeLibrary::GetSize(shared_ptr<TreeNode> RootNode)
{
	int NodeSize = RootNode->Children.size();
	return NodeSize;
}

int GeneralTreeLibrary::GetDepth(shared_ptr<TreeNode> RootNode)
{
	///Deepest or Max level
	int level = 0;

	///For loop wich iterates over list of children for current root node.
	///Starts with first element in first index.
	for (shared_ptr<TreeNode> Child : RootNode->Children)
	{
		///Declaring the currentDepth as an integer
		int currentDepth = GetDepth(Child);

		level = max(level, currentDepth);
	}
	return level + 1;
}

bool GeneralTreeLibrary::bIsEmpty(shared_ptr<TreeNode> RootNode)
{
	if (RootNode == nullptr) { return true; }

	for (shared_ptr<TreeNode> Child : RootNode->Children)
	{
		if (RootNode->Children.empty() == true)
		{
			cout << "ChildNode is empty" << endl;
			cout << "RootNode: " << RootNode->Data << endl;
		}
		bIsEmpty(Child);
	}
	return true;
}

bool GeneralTreeLibrary::bIsRoot()
{
	//check if the node is root
	if (Root->Parent == nullptr)
	{
		cout << "This node is a root node" << endl;
		return true;
	}
	cout << "This node is a not a root node" << endl;
	return false;
}

bool GeneralTreeLibrary::bIsLeaf(shared_ptr<TreeNode> RootNode)
{
	//check if node is a leaf node
	if (RootNode->Children.empty())
	{
		cout << "Node " + to_string(RootNode->Data) + " is a leaf" << endl;
		return true;
	}
	cout << "Node " + to_string(RootNode->Data) + " is a not leaf" << endl;
	return false;
}

int GeneralTreeLibrary::RandomNumberGenerator(int MinNumber, int MaxNumber)
{
	random_device RandomDevice;
	map<int, int> hist;
	uniform_int_distribution<int> dist(MinNumber, MaxNumber);
	int RandomNumber = dist(RandomDevice);
	return RandomNumber;
}

void GeneralTreeLibrary::NodeInformation(shared_ptr<TreeNode> Node)
{
	cout << "Node Information" << endl;
	cout << "Root Data: " << Node->Data << endl;
	cout << "Number of Children: " << Node->Children.size() << endl;
}

void GeneralTreeLibrary::ListOfNodes(shared_ptr<TreeNode> Node)
{
	cout << "Number of Children: " << Node->Children.size() << endl;
	if (Node->Children.empty())
	{
		cout << "--End of branch--" << endl;
		return;
	}
	for (int i = 0; i < Node->Children.size(); i++)
	{
		if (Node->Children[i]->Children.empty())
		{
			cout << "--End of branch--" << endl;
			return;
		}
		cout << "Number of Grand Children in branch [" + to_string(i) + "]: " << Node->Children[i]->Children.size() <<
			endl;
		for (int j = 0; j < Node->Children.size(); j++)
		{
			if (Node->Children[i]->Children[j]->Children.empty())
			{
				cout << "--End of branch--" << endl;
				return;
			}
			cout << "Number of Great Grand Children in branch [" + to_string(j) + "]: " << Node->Children[i]->Children[
				j]->Children.size() << endl;
		}
	}
}
