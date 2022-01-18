#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Every Edge is created between source and destination and contain some cost
class Edge {
    public:
    int source;
    int destination;
    int weight;
};

void display(Edge* e_ptr, int edges) {

    cout <<"Source - Dest\tWeight" <<endl;
    for (int i = 0; i < edges; i++)
    {
        cout <<e_ptr[i].source <<"  -  " <<e_ptr[i].destination <<"\t\t" <<e_ptr[i].weight <<endl;
    } 
    cout <<endl;
}

// To sort accnding order
int compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;   
}

// If the index of parent and its value 
// found same then return 
int findParent(int vertex, vector<int> parent) {
    if(parent[vertex] == vertex) 
        return vertex;
    else   
        return findParent(parent[vertex], parent);
}

// kruskal's Algorithem function
void kruskalMST(Edge* e_ptr, int nodes, int edges) {

    // Sort Edges according to the weight
    sort(e_ptr+0, e_ptr+edges, compare);

    // Initialize all vertices parents itself
    vector<int> parent;         
    for (int i = 0; i <= nodes; i++)
        parent.push_back(i);
    
    // Resultant MST contain final MST
    Edge* finalMST = new Edge[edges - 1];

    // Traverse through all the given edges
    for (int count = 0,MSTCount = 0; count < edges; count++)
    {
        int sourceParent = findParent(e_ptr[count].source, parent);
        int destParent = findParent(e_ptr[count].destination, parent);

        // If source and destination's parents are same 
        // then loop will be created 
        // So take out only those Edges whose 
        // source and destination's parents are different
        if(sourceParent != destParent) {
            finalMST[MSTCount] = e_ptr[count];
            MSTCount ++;
            parent[sourceParent] = destParent;
        }
    }
    // Print Minimum Spanning Tree 
    display(finalMST, nodes-1);
}

// Main Function
int main() {
    int noOfNodes = 5;              // Total number of Vertices: Here we have 1, 2, 3, 4, 5 
    int noOfEdges = 7;              // Total number of edges
    // Edges-Weght: {{1, 2}- 1}, {{1, 3}- 5}, {{1, 4}- 9}, {{2, 3}- 4}, {{2, 4}- 2}, {{3, 5}- 7}, {{4, 5}- 3}

    Edge *edge_ptr = new Edge[noOfEdges];           // Create all the edges

    for (int edge_counter = 0; edge_counter < noOfEdges; edge_counter++)
    {
        // s: Source
        // d: Destination
        // w: Weight
        int s, d, w;
        cout <<"Enter Source and Destination: ";
        cin >> s >> d;
        cout <<"Weight: ";
        cin >> w;

        edge_ptr[edge_counter].source = s; 
        edge_ptr[edge_counter].destination = d; 
        edge_ptr[edge_counter].weight = w; 
    }
    display(edge_ptr, noOfEdges);

    kruskalMST(edge_ptr, noOfNodes, noOfEdges);

    return 0;
}