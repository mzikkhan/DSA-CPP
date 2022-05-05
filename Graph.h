#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "QueType.h"
#include "Stack.h"

class Graph{
public:
    Graph();
    Graph(int);
    ~Graph();
    void AddVertex(int);
    void AddEdge(int, int);
    void AddEdge(int, int, int);
    int WeightIs(int, int);
    void GetToVertices(int, QueType&);
    void ClearMarks();
    void MarkVertex(int);
    bool IsMarked(int);
    void DepthFirstSearch(Graph, int, int);
    void BreadthFirstSearch(Graph, int, int);
private:
    int numVertices;
    int maxVertices;
    int* vertices;
    int **edges;
    bool* marks;
};

/*void DepthFirstSearch(Graph g, int fromVertex, int toVertex){
    Stack s;
    QueType vertexQ;
    bool found = false;
    int vertex;
    int item;
    g.ClearMarks();
    s.push(fromVertex);
    do{
        s.pop(vertex);
        if(vertex == toVertex){
            cout << vertex << endl;
            found = true;
        }else{
            if(!g.IsMarked(vertex)){
                g.MarkVertex(vertex);
                cout << vertex << endl;
                g.GetToVertices(vertex, vertexQ);
                while(!vertexQ.isEmpty()){
                    vertexQ.Dequeue(item);
                    if(!g.IsMarked(item)){
                        s.push(item);
                    }
                }
            }
        }
    }while(!s.isEmpty() && !found);
    if(!found){
        cout << "Path not found" << endl;
    }
}

void BreadthFirstSearch(Graph g, int fromVertex, int toVertex){
    QueType queue;
    QueType vertexQ;
    bool found = false;
    int vertex;
    int item;
    g.ClearMarks();
    queue.Enqueue(fromVertex);
    do{
        queue.Dequeue(vertex);
        if(vertex == toVertex){
            cout << vertex << endl;
            found = true;
        }else{
            if(!g.IsMarked(vertex)){
                g.MarkVertex(vertex);
                cout << vertex << endl;
                g.GetToVertices(vertex, vertexQ);
                while(!vertexQ.isEmpty()){
                    vertexQ.Dequeue(item);
                    if(!g.IsMarked(item)){
                        queue.Enqueue(item);
                    }
                }
            }
        }
    }while(!queue.isEmpty() && !found);
    if(!found){
        cout << "Path not found" << endl;
    }
}*/

#endif // GRAPH_H_INCLUDED
