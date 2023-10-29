#include "GraphLibrary.h"

#include <iostream>
#include <map>
#include <ostream>
#include <random>
#include <string>

GraphLibrary::GraphLibrary(int AmountOfVerticies)
{
	NumberOfVerticies = AmountOfVerticies;
	AdjacencyList.resize(AmountOfVerticies);
}

void GraphLibrary::InsertRandomNode(int MaximumVertexValueToInsert)
{
	// Generate a random number between 0 and the number of verticies in the graph
	int RandomNumber = rand() % NumberOfVerticies;

	// Insert the random number into the adjacency list
	AdjacencyList[RandomNumber].push_back(RandomNumberGenerator(0, MaximumVertexValueToInsert));
	cout << "Random node " + to_string(RandomNumber) + " has been inserted" << endl;
}

void GraphLibrary::InsertSpesificNode(int VertexToInsert)
{
	// Insert the node into the adjacency list
	AdjacencyList[VertexToInsert].push_back(VertexToInsert);
	cout << "Node " + to_string(VertexToInsert) + " has been inserted" << endl;
}

void GraphLibrary::DeleteVertex(int VertexNodeToDelete)
{
	//Delete a spesific vertex from the adjacency list
	for (int i = 0; i < AdjacencyList.size(); i++)
	{
		if (VertexNodeToDelete == i)
		{
			AdjacencyList.erase(AdjacencyList.begin() + i);
			cout << "[Vertex " + to_string(VertexNodeToDelete) + " has been deleted]" << endl;
		}
	}
}

void GraphLibrary::InsertEdge(int Source, int Destination)
{
	AdjacencyList[Source].push_back(Destination);
	AdjacencyList[Destination].push_back(Source);
	cout << "Edge between " + to_string(Source) + " and " + to_string(Destination) + " has been inserted" << endl;
}

void GraphLibrary::DeleteEdge(int Source, int Destination)
{
	// Find the index of the destination vertex in the source vertex's adjacency list
	int DestinationIndex = -1;
	for (int i = 0; i < AdjacencyList[Source].size(); i++)
	{
		if (AdjacencyList[Source][i] == Destination)
		{
			DestinationIndex = i;
			break;
		}
	}

	// Remove the destination vertex from the source vertex's adjacency list
	if (DestinationIndex != -1)
	{
		AdjacencyList[Source].erase(AdjacencyList[Source].begin() + DestinationIndex);
	}

	// Find the index of the source vertex in the destination vertex's adjacency list
	int SourceIndex = -1;
	for (int i = 0; i < AdjacencyList[Destination].size(); i++)
	{
		if (AdjacencyList[Destination][i] == Source)
		{
			SourceIndex = i;
			break;
		}
	}

	// Remove the source vertex from the destination vertex's adjacency list
	if (SourceIndex != -1)
	{
		AdjacencyList[Destination].erase(AdjacencyList[Destination].begin() + SourceIndex);
	}
	cout << "Edge between " + to_string(Source) + " and " + to_string(Destination) + " has been deleted" << endl;
}

void GraphLibrary::DepthFirstSearch()
{
	// Create a vector to keep track of visited verticies
	vector<bool> VisitedVerticies(NumberOfVerticies, false);

	// Create a stack to keep track of verticies to visit
	vector<int> Stack;

	// Push the first vertex onto the stack
	Stack.push_back(0);

	// While the stack is not empty
	while (!Stack.empty())
	{
		// Pop the top vertex from the stack
		int CurrentVertex = Stack.back();
		Stack.pop_back();

		// If the vertex has not been visited
		if (!VisitedVerticies[CurrentVertex])
		{
			// Mark the vertex as visited
			VisitedVerticies[CurrentVertex] = true;

			// Print the vertex
			cout << CurrentVertex << " ";

			// Push all adjacent verticies onto the stack
			for (int i = 0; i < AdjacencyList[CurrentVertex].size(); i++)
			{
				Stack.push_back(AdjacencyList[CurrentVertex][i]);
			}
		}
	}
	cout << endl;
}

int GraphLibrary::GetSize()
{
	cout << NumberOfVerticies << endl;
	return NumberOfVerticies;
}

bool GraphLibrary::bIsEmpty()
{
	// Check if the adjacency list is empty
	if (AdjacencyList.empty())
	{
		cout << "Graph is empty" << endl;
		return true;
	}
	else
	{
		cout << "Graph is not empty" << endl;
		return false;
	}
}

bool GraphLibrary::bIsConnected(int Source, int Destination)
{
	for (int i = 0; i < AdjacencyList[Source].size(); i++)
	{
		if (AdjacencyList[Source][i] == Destination)
		{
			cout << "Vertex " + to_string(Source) + " is connected to " + to_string(Destination) << endl;
			return true;
		}
	}
	cout << "Vertex " + to_string(Source) + " is not connected to " + to_string(Destination) << endl;

	return false;
}

void GraphLibrary::PrintGraph()
{
	for (int i = 0; i < AdjacencyList.size(); i++)
	{
		cout << "Vertex " << i << " is connected to: ";
		for (int j = 0; j < AdjacencyList[i].size(); j++)
		{
			cout << AdjacencyList[i][j] << " ";
		}
		cout << endl;
	}
}

int GraphLibrary::RandomNumberGenerator(int MinNumber, int MaxNumber)
{
	random_device RandomDevice;
	map<int, int> hist;
	uniform_int_distribution<int> dist(MinNumber, MaxNumber);
	int RandomNumber = dist(RandomDevice);
	return RandomNumber;
}
