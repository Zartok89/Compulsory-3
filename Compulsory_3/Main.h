#pragma once

// Forward Declaration
class GeneralTreeLibrary;
struct TreeNode;
class GraphLibrary;

using namespace std;

shared_ptr<GeneralTreeLibrary> GeneralTree;
shared_ptr<TreeNode> Node1;
shared_ptr<TreeNode> Node2;

shared_ptr<GraphLibrary> Graph;

//Main class Function
void PrintTrees(shared_ptr<TreeNode> TreeRoot);

