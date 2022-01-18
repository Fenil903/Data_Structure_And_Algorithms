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

int main() {
    int noOfNodes = 4;      // Total number of Nodes, here we have:0, 1, 2, 3
    int noOfEdges = 4;      // Total number of Edges between two edges
    // Edges: {0,1}, {0,2}, {1,2}, {2,3}

    vector<vector<int>> graph(noOfNodes, vector<int> (noOfNodes, 0));      // Create 2D matrix of value 0

    graph = createGraph(graph, noOfEdges);
    display(graph);

    return 0;
}