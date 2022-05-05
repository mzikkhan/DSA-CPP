#include "Graph.h"
#include <iostream>

using namespace std;

Graph :: Graph(){
    numVertices = 0;
    maxVertices = 50;
    vertices = new int[maxVertices];
    edges = new int*[maxVertices];
    for(int i = 0; i<maxVertices; i++){
        edges[i] = new int[maxVertices];
    }
    marks = new bool[maxVertices];
}
Graph :: Graph(int maxV){
    numVertices = 0;
    maxVertices = maxV;
    vertices = new int[maxVertices];
    edges = new int*[maxVertices];
    for(int i = 0; i<maxVertices; i++){
        edges[i] = new int[maxVertices];
    }
    marks = new bool[maxVertices];
}
Graph :: ~Graph(){
    delete [] vertices;
    for(int i = 0; i<maxVertices; i++){
        delete [] edges[i];
    }
    delete [] edges;
    delete marks;
}
int IndexIs(int* vertices, int vertex){
    int i=0;
    while(!(vertex == vertices[i])){
        i++;
    }
    return i;
}
const int NULL_EDGE = 0;
void Graph :: AddVertex(int vertex){
    vertices[numVertices] = vertex;
    for(int i=0; i<numVertices; i++){
        edges[i][numVertices] = NULL_EDGE;
        edges[numVertices][i] = NULL_EDGE;
    }
    numVertices++;
}
void Graph :: AddEdge(int fromVertex, int toVertex){
    int row = IndexIs(vertices, fromVertex);
    int col = IndexIs(vertices, toVertex);
    edges[row][col] = 1;
    edges[col][row] = 1;
}
void Graph :: AddEdge(int fromVertex, int toVertex, int weight){
    int row = IndexIs(vertices, fromVertex);
    int col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}
int Graph :: WeightIs(int fromVertex, int toVertex){
    int row = IndexIs(vertices, fromVertex);
    int col = IndexIs(vertices, toVertex);
    return edges[row][col];
}
void Graph :: GetToVertices(int vertex, QueType& vertexQ){
    int fromVertex = IndexIs(vertices, vertex);
    int toVertex;
    for(toVertex = 0; toVertex<numVertices; toVertex++){
        if(edges[fromVertex][toVertex] != NULL_EDGE){
            vertexQ.Enqueue(vertices[toVertex]);
        }
    }
}
void Graph :: ClearMarks(){
    for(int i=0; i<numVertices; i++){
        marks[i] = false;
    }
}
void Graph :: MarkVertex(int vertex){
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
}
bool Graph :: IsMarked(int vertex){
    int index = IndexIs(vertices, vertex);
    return (marks[index] == true) ;
}
