#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a graph using edges
vector<vector<int>> createGraph(vector<vector<int>> graphMatrix, int edges) {
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout <<"Enter Nodes(connected to edge): ";
        cin >> node1 >> node2;

        // Create Undirected Graph
        graphMatrix[node1][node2] = 1;
        graphMatrix[node2][node1] = 1;
    }
    return graphMatrix;
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

// Traverse the given graph using BFS: Breadth First Search
void traverseBFS(vector<vector<int>> graphMatrix, int nodes, int startNode) {
    vector<bool> visited(graphMatrix.size(), false);        // Create visited element vector intialized with False
    vector<int> explored;       // like Queue for expored elements

    visited[startNode] = true;
    explored.push_back(startNode);      // Enqueue starting Node for exploration

    // Run the loop untill queue became empty
    while (!explored.empty())
    {
        // Print current exploring Node
        int exploredElement = explored[0];
        explored.erase(explored.begin());
        cout <<exploredElement <<" ";

        // Traverse in exploring array
        for (int i = 0; i < nodes; i++)
        {
            if (graphMatrix[exploredElement][i] == 1 && visited[i] == false)
            {
                visited[i] = true;          // Mark visited Node as False
                explored.push_back(i);          // push adjacent node in Queue
            } 
        } 
    }
    cout <<endl;
}

// Main Function
int main() {
    int noOfNodes = 7;      // Total number of Nodes, here we have:0, 1, 2, 3, 4, 5, 6
    int noOfEdges = 9;      // Total number of Edges between two edges
    // Edges: {0,1}, {0,2}, {0,3}, {1,2}, {2,3}, {2,4}, {3,4}, {4,5}, {4,6}
    
    vector<vector<int>> graph(noOfNodes, vector<int> (noOfNodes, 0));      // Create 2D matrix of value 0
    
    graph = createGraph(graph, noOfEdges);

    int beginNode = 1;              // Starting Node to traverse
    traverseBFS(graph, noOfNodes, beginNode);

    display(graph);

    return 0;
}