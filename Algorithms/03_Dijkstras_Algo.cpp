#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Create a graphList Contain Source, Destination and Weight(Cost)
void createGraph(vector<pair<int, int>> graphList[], int edges) {
    for (int i = 0; i < edges; i++)
    {
        int source, dest, cost;
        cout <<"Enter Source and Destination: ";
        cin >>source >>dest;
        cout <<"Enter Weight: ";
        cin >>cost;

        // Make UnDirected Graph
        graphList[source].push_back(make_pair(dest, cost));
        graphList[dest].push_back(make_pair(source, cost));
    }  
}

void display(vector<pair<int, int>> graphList[], int nodes) {
    for (int i = 0; i < nodes; i++)
    {
        cout <<"Vertex " <<i <<": ";
        for (auto iter = graphList[i].begin(); iter != graphList[i].end(); iter++)
            cout <<"(" <<(*iter).first <<", " <<(*iter).second <<") ";
        cout <<endl;
    }  
}

// Print the distance of all the Nodes from the Source Node
void printDist(vector<int> dist, int source) {

    cout <<"\nSource Node: " <<source <<endl;
    cout <<"Vertex\tDist_From_Source" <<endl;
    for (int i = 0; i < dist.size(); i++)
        cout <<i <<"  <->  " <<dist[i] <<endl;   
}

// A utility function to find the vertex with 
// Minimum key value, from the set of vertices  
int findMinVertex(vector<int> distance, vector<bool> visited, int nodes) {

    int min = INT_MAX, minIndex;          // Initialize minimum value(cost) and Index
    for (int i = 0; i < nodes; i++)
    {
        if(visited[i] == false && distance[i] < min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;        // Return Vertex
}

// Dijkstra's Algorithm to find Minimum Distance  of a Node from Source Node
void dijkstraMST(vector<pair<int, int>> graphList[], int nodes, int sourceNode) {
    vector<int> distance(nodes, INT_MAX);       // Store and update distance of vertices
    vector<bool> isVisited(nodes, false);       // Check the vertex is visited or not

    // Distance of source vertex from itself is always 0
    distance[sourceNode] = 0;

    // Find shortest path for all vertices
    for (int countNode = 0; countNode < nodes - 1; countNode++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int minVertex = findMinVertex(distance, isVisited, nodes);
        // Mark the picked vertex as processed
        isVisited[minVertex] = true;

        // Update distance value of the adjacent vertices of the picked vertex.
        for (auto iter = graphList[minVertex].begin(); iter != graphList[minVertex].end(); iter++)
        {
            int vertex = (*iter).first;
            int weight = (*iter).second;

            // Update distance[vertex] only if is not in visited
            // There is a path from minVertex to vertex, total distance from sourceNode to vertex
            // Is smaller than current value of distance[vertex]
            int dist = distance[minVertex] + weight;

            if(isVisited[vertex] == false && dist < distance[vertex]) {
                distance[vertex] = dist;
            }
        }   
    }
    // print the constructed distance vector
    printDist(distance, sourceNode);
}

int main() {
    int noOfNodes = 5;              // Total number of Vertices. Here we have: 0, 1, 2, 3, 4
    int noOfEdges = 6;              // Total number of Edges
    // Edge- Cost: {{0, 1}- 2}, {{0, 3}- 6}, {{1, 2}- 3}, {{1, 3}- 8}, {{1, 4}- 5}, {{2, 4}- 7}

    vector<pair<int, int>> graph[noOfNodes];            // Create a graph of List with cost

    createGraph(graph, noOfEdges);
    display(graph, noOfNodes);

    int beginNode = 1;          // Source Node
    dijkstraMST(graph, noOfNodes, beginNode);

    return 0;
}