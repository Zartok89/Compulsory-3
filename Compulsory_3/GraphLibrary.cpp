#include "GraphLibrary.h"

#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <random>
#include <string>

GraphLibrary::GraphLibrary(int AmountOfVerticies)
{
	NumberOfVerticies = AmountOfVerticies;
	AdjacencyList.resize(AmountOfVerticies);
}

void GraphLibrary::InsertRandomVertex(int MaximumVertexValueToInsert)
{
	// Generate a random number between 0 and the number of verticies in the graph
	int RandomNumber = rand() % NumberOfVerticies;

	// Insert the random number into the adjacency list
	AdjacencyList[RandomNumber].push_back(RandomNumberGenerator(0, MaximumVertexValueToInsert));
	cout << "Random vertex " + to_string(RandomNumber) + " has been inserted" << endl;
}

void GraphLibrary::InsertSpesificVertex(int VertexToInsert)
{
	// Insert the vertex into the adjacency list
	AdjacencyList[VertexToInsert].push_back(VertexToInsert);
	cout << "Vertex " + to_string(VertexToInsert) + " has been inserted" << endl;
}

void GraphLibrary::DeleteVertex(int VertexToDelete)
{
	//Delete a spesific vertex from the adjacency list
	for (int i = 0; i < AdjacencyList.size(); i++)
	{
		if (VertexToDelete == i)
		{
			AdjacencyList.erase(AdjacencyList.begin() + i);
			cout << "[Vertex " + to_string(VertexToDelete) + " has been deleted]" << endl;
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

void GraphLibrary::DepthFirstSearch(int Source)
{
	// Mark the current vertex as visited
	VertexVisited[Source] = true;
	cout << Source << " ";

	vector<int>::iterator i;
	for (i = AdjacencyList[Source].begin(); i != AdjacencyList[Source].end(); ++i)
	{
		if (!VertexVisited[*i])
		{
			DepthFirstSearch(*i);
		}
	}
}

void GraphLibrary::BreadthFirstSearch(int Source)
{
	// Mark all the vertices as not visited
	vector<bool> VisitedVerticies;
	VisitedVerticies.resize(NumberOfVerticies, false);

	// Create a queue for BFS
	list<int> Queue;

	// Marking the current vertex as visited and enqueue it
	VisitedVerticies[Source] = true;
	Queue.push_back(Source);

	while (!Queue.empty())
	{
		// Dequeue a vertex from queue and print it
		Source = Queue.front();
		cout << Source << " ";
		Queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s
		// If a adjacent has not been visited, then mark it visited and enqueue it
		for (int Adjacency : AdjacencyList[Source])
		{
			if (!VisitedVerticies[Adjacency])
			{
				VisitedVerticies[Adjacency] = true;
				Queue.push_back(Adjacency);
			}
		}
	}
}

void GraphLibrary::GetVertexInformation(int Source)
{
	// Get the vertex information
	cout << "Vertex " + to_string(Source) + " information: " << GetAdjacentVerticies(Source) << endl;
}

int GraphLibrary::GetAdjacentVerticies(int Source)
{
	cout << "Adjacent vertex to " + to_string(Source) + " are: ";
	for (int AdjacentVerticies : AdjacencyList[Source])
	{
		cout << AdjacentVerticies << " ";
		return AdjacentVerticies;
	}
	cout << endl;
}

void GraphLibrary::GetVerticiesInGraph()
{
	cout << "Verticies in the graph: ";
	for (int i = 0; i < AdjacencyList.size(); i++)
	{
		cout << i << " ";
	}
	cout << endl;
}

void GraphLibrary::GetEdgesInGraph()
{
	cout << "Edges in the graph: ";
	for (int i = 0; i < AdjacencyList.size(); i++)
	{
		for (int j = 0; j < AdjacencyList[i].size(); j++)
		{
			cout << AdjacencyList[i][j] << " ";
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
