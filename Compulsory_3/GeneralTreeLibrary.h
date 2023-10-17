#pragma once
class GeneralTreeLibrary
{
	/*Constructor*/
	GeneralTreeLibrary();

	/*Member Functions*/
	void NodeInformation();
	void ListOfChildren();

	/*Tree Operations*/
	void InsertRandomChild();
	void InsertSpesificChild();
	void DeleteChild();

	/*Tree Traversal Functions*/
	void DepthFirstSearch();
	void BreadthFirstSearch();

	/*Access Functions*/
	void GetTreeRoot();
	void GetParentNode();
	void GetChildrenNode();

	/*Query Functions*/
	int GetSize();
	int GetDepth();
	bool bIsEmpty();
	bool bIsRoot();
	bool bIsLeaf();
};
