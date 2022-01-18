#include <iostream>
#include <string>
#include <vector>
using namespace std;

void createGraph(vector<int> graphList[], int edges) {
    for (int i = 0; i < edges; i++)
    {
        int node1, node2;
        cout <<"Enter edge nodes(Node1 -- Node2): ";
        cin >> node1 >> node2;

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

// Traverse the given fraph using BFS: Breadth First Search
void TraverseBFS(vector<int> graphList[], int nodes, int startNode) {
    vector<bool> visited(nodes, false);        // Create visited element vector intialized with False
    vector<int> explored;       // like Queue for expored elements

    visited[startNode] = true;
    explored.push_back(startNode);      // Enqueue starting Node for exploration

    // Run the loop untill queue became empty
    while (!explored.empty())
    {
        // Print current exploring Node
        int exploredNode = explored[0];
        explored.erase(explored.begin());
        cout <<exploredNode <<" ";

        // Traverse in exploring list
        for (auto iter = graphList[exploredNode].begin(); iter != graphList[exploredNode].end(); iter++)
        {
            if(visited[*iter] == false) {
                visited[*iter] = true;          // Mark visited Node as False
                explored.push_back(*iter);          // push adjacent node in Queue
            }
        } 
    } 
}

// Main Function
int main() {
    int noOfNodes = 7;      // Total number of Nodes, here we have:0, 1, 2, 3
    int noOfEdges = 9;      // Total number of Edges between two edges
    // Edges: {0,1}, {0,2}, {1,2}, {2,3}
    
    vector<int> graph[noOfNodes];        // Create adjacency list of graph
    createGraph(graph, noOfEdges);

    display(graph, noOfNodes);

    int beginNode = 3;              // Starting Node to traverse
    TraverseBFS(graph, noOfNodes, beginNode);

    return 0;
}