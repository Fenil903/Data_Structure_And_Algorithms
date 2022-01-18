#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a graph using List
void createGraph(vector<int> graphList[], int edges) {
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout <<"Enter edge Nodes(Node1 -- Node2): ";
        cin >>node1 >>node2;

        // Create Undirected Graph
        graphList[node1].push_back(node2);
        graphList[node2].push_back(node1);
    }
}

void display(vector<int> graphList[], int nodes) {
    for (int i = 0; i < nodes; i++)
    {
        cout <<"Index " <<i <<": ";
        for (auto iter = graphList[i].begin(); iter != graphList[i].end(); iter++)
        {
            cout <<*iter <<" ";
        }
        cout <<endl;
    }
}

// Main Function
int main() {
    int noOfNodes = 4;      // Total number of Nodes, here we have:0, 1, 2, 3
    int noOfEdges = 4;      // Total number of Edges between two edges
    // Edges: {0,1}, {0,2}, {1,2}, {2,3}

    vector<int> graph[noOfNodes];      // Create a list of size 4(number of nodes)

    createGraph(graph, noOfEdges);
    display(graph, noOfNodes);

    return 0;
}