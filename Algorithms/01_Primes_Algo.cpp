#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a graph including cost value
void createGraph(vector<pair<int, int>> graphList[], int edges) {
    for (int i = 0; i < edges; i++)
    {
        int node1, node2, cost;
        cout <<"Enter edge between two Nodes(Node1 -- Node2): ";
        cin >> node1 >>node2;
        cout <<"Enter Cost: ";
        cin >> cost;

        graphList[node1].push_back(make_pair(node2, cost));
        graphList[node2].push_back(make_pair(node1, cost));
    }       
}

// Print graph
void display(vector<pair<int, int>> graphList[], int nodes) {
    for (int i = 0; i < nodes; i++)
    {
        cout <<"Vertex(Node): " <<i <<": ";
        for (auto iter = graphList[i].begin(); iter != graphList[i].end(); iter++)
        {
            cout <<"(" <<(*iter).first <<", " <<(*iter).second <<") ";
        }
        cout <<endl;
    }
}

// Print Minimum Spanning Tree
void printMST(vector<int> parent,vector<int> key, int nodes) {
    cout <<"Edge\tCost" <<endl;
    for (int i = 1; i < nodes; i++)
        cout <<parent[i] <<" - " <<i <<"\t" <<key[i] <<endl;
}

// A utility function to find the vertex with 
// Minimum key value, from the set of vertices  
int minKey(vector<int> key, vector<bool> mstSet, int nodes) {
    
    int min = INT_MAX;          // Initialize minimum value(cost)
    int minKey_Index;           // Vertex which has minimum cost

    for (int i = 0; i < nodes; i++)
    {
        if(mstSet[i] == false && key[i] < min) {
            min = key[i];
            minKey_Index = i;
        }
    }
    return minKey_Index;        // Return Vertex
}

// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primeMST(vector<pair<int, int>> graphList[], int nodes) {
    vector<int> key(nodes, INT_MAX);          // Key values used to pick minimum weight edge in cut 
    vector<int> parent(nodes, -1);            // Vector to store constructed MST
    vector<bool> mstSet(nodes, false);        // To represent set of vertices included in MST 

    key[0] = 0;             // Start with 1st vertex in MST
    parent[0] = -1;         // 1st vertex has no any parent(Root Node)

    for (int count = 0; count < nodes - 1; count++)
    {
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST 
        int minKeyValue = minKey(key, mstSet, nodes);

        mstSet[minKeyValue] = true;             // Add the picked vertex to the MST Set 

        // Update key value and parent index of the adjacent vertices of the picked vertex. 
        // Consider only those vertices which are not yet included in MST 
        for (auto iter = graphList[minKeyValue].begin(); iter != graphList[minKeyValue].end(); iter++)
        {
            int vertex = (*iter).first;         // Vertex
            int cost = (*iter).second;          // Cost of Vertex

            if(mstSet[vertex] == false && cost < key[vertex]) {
                key[vertex] = cost;
                parent[vertex] = minKeyValue;
            }
        }
    }
    // print the constructed MST 
    printMST(parent,key, nodes);
}

// Main Function
int main() {
    int noOfNodes = 4;      // Total number of Nodes, here we have:0, 1, 2, 3
    int noOfEdges = 4;      // Total number of Edges between two edges
    // Edges- Cost: {{0,1}- 8}, {{0,2}- 5}, {{1,2}- 3}, {{2,3}- 2}

    vector<pair<int ,int>> graph[noOfNodes];      // Create a list of size 4(number of nodes)

    createGraph(graph, noOfEdges);  
    display(graph, noOfNodes);  
    primeMST(graph, noOfNodes);

    return 0;
}