#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a graph using edges
vector<vector<int>> createGraph(vector<vector<int>> graphMatrix, int edges) {
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout <<"Enter edge of two Node(Node1 --- Node2): ";
        cin >> node1 >> node2;

        // Create Undirected Graph
        graphMatrix[node1][node2] = 1;
        graphMatrix[node2][node1] = 1;
    }
    return graphMatrix;
}

// Traverse a given graph using DFS: Depth First Search
void traverseDFS(vector<vector<int>> graphMatrix, vector<bool> &visited, int startNode) {
    cout <<startNode <<" ";         // Print explored Node
    visited[startNode] = true;          // Mark visited Nodes as true

    for (int i = 0; i < graphMatrix.size(); i++)
    {
        if(graphMatrix[startNode][i] == 1 && visited[i] == false)
            traverseDFS(graphMatrix, visited, i);
    }
}

void display(vector<vector<int>> graphMatrix) {
    for (int i = 0; i < graphMatrix.size(); i++)
    {
        for (int j = 0; j < graphMatrix[i].size(); j++)
        {
            cout <<graphMatrix[i][j] <<" ";
        }
        cout <<endl;
    }
}

// Main Function
int main() {
    int noOfNodes = 4;      // Total number of Nodes, here we have:0, 1, 2, 3
    int noOfEdges = 4;      // Total number of Edges between two edges
    // Edges: {0,1}, {0,2}, {1,2}, {2,3}

    vector<vector<int>> graph(noOfNodes, vector<int> (noOfNodes, 0));      // Create 2D matrix of value 0

    graph = createGraph(graph, noOfEdges);
    display(graph);

    int beginNode = 1;              // Starting Node to traverse
    vector<bool> visited(noOfNodes, false);        // Create visited element vector intialized with False         

    traverseDFS(graph, visited, beginNode);

    return 0;
}