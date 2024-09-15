#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <fstream>
#include <limits>

class illegal_exception : public std::exception
{
public:
    const char *what() const noexcept override;
};

class Node // edge
{
public:
    int destination;
    double speedLimit;
    double distance;
    double adjustmentFactor;
    double time;
    Node *next;

    Node(int v, double d, double s, double a);
};
class HeapNode
{
public:
    int vertex;
    double weight;
    HeapNode(int v = 0, double d = 0.0) : vertex(v), weight(d) {}
};
class MinHeap
{
public:
    HeapNode *heapArray;
    int capacity;
    int size;

    MinHeap(int maxCapacity);
    ~MinHeap();

    bool isEmpty() const;
    void insert(int vertex, double distance);
    void customSwap(HeapNode &a, HeapNode &b);
    HeapNode extractMin();

private:
    void heapifyUp(int index);
    void heapifyDown(int index);
};

class LinkedList // vertex
{
public:
    LinkedList();
    ~LinkedList();

    void addNode(int vertex, double d, double s, double a);

    Node *getHead();
    void setHead(Node *head);
    int getVertex();
    void setVertex(int vertex);

private:
    Node *head;
    int vertex;
};

class Graph
{
public:
    Graph();
    ~Graph();

    void load(std::fstream &fin);
    void insertEdge(int a, int b, double d, double s);
    void print(int a);
    void remove(int a);
    void traffic(int a, int b, double adjustmentfactor);
    void update(std::fstream &fin);
    void path(int a, int b);
    void lowest(int a, int b);

private:
    LinkedList *adjacencyList;
    const int MAX_SIZE = 500001;
};

#endif
