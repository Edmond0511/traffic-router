#include "graph.h"
#include <iostream>
#include <limits>

const char *illegal_exception::what() const noexcept
{
    return "illegal argument\n";
}

Node::Node(int v, double d, double s, double a)
{
    destination = v;
    distance = d;
    speedLimit = s;
    adjustmentFactor = a;
    time = d / (s * a);
    next = nullptr;
}

LinkedList::LinkedList()
{
    head = nullptr;
    vertex = 0;
}

LinkedList::~LinkedList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }
}

int LinkedList::getVertex()
{
    return vertex;
}

void LinkedList::setVertex(int v)
{
    vertex = v;
}

void LinkedList::addNode(int v, double d, double s, double a)
{
    Node *node = new Node(v, d, s, a);
    if (head == nullptr)
    {
        head = node;
        vertex  = v;
    }
    else
    {
        node->next = head;
        head = node;       
         vertex  = v;
    }
}

Node *LinkedList::getHead()
{
    return head;
}

void LinkedList::setHead(Node *head)
{
    this->head = head;
}

Graph::Graph()
{
    adjacencyList = new LinkedList[MAX_SIZE];
}

Graph::~Graph()
{
    delete[] adjacencyList;
}

void Graph::load(std::fstream &fin)
{
    int a, b;
    double d, s;
    while (fin >> a >> b >> d >> s)
    {
        adjacencyList[a].addNode(b, d, s, 1);
        adjacencyList[b].addNode(a, d, s, 1);
    }
}

void Graph::insertEdge(int a, int b, double d, double s)
{
    if (a <= 0 || b <= 0 || a >= MAX_SIZE || b >= MAX_SIZE)
    {
        throw illegal_exception();
    }
    else
    {
        adjacencyList[a].addNode(b, d, s, 1);
        adjacencyList[b].addNode(a, d, s, 1);
    }
}

void Graph::print(int a)
{
    if (a <= 0 || a >= MAX_SIZE)
    {
        throw illegal_exception();
    }
    else
    {
        // print all the vertices adjacent to "a" from the adjacency list
        if (adjacencyList[a].getVertex() == 0)
        {
            std::cout << "failure\n";
            return;
        }
        Node *temp = adjacencyList[a].getHead();
        if (temp == nullptr)
        {
            std::cout << std::endl; 
            return;
        }
        while (temp != nullptr)
        {
            std::cout << temp->destination << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

void Graph::remove(int a)
{
    if (a <= 0 || a >= MAX_SIZE)
    {
        throw illegal_exception();
    }
    else
    {
        // remove all the edges containing vertex "a"
        if (adjacencyList[a].getVertex() == 0)
        {
            std::cout << "failure\n";
            return;
        }
        Node *current = adjacencyList[a].getHead();
        while(current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
            adjacencyList[a].setHead(nullptr);
        }
    
        for (int i = 1; i < MAX_SIZE; ++i)
        {
            Node *temp = adjacencyList[i].getHead();
            Node *prev = nullptr;

            while (temp != nullptr)
            {
                if (temp->destination == a)
                {
                    // Remove the edge containing vertex 'a'
                    if (prev == nullptr)
                    {
                        adjacencyList[i].setHead(temp->next);
                    }
                    else
                    {
                        prev->next = temp->next;
                    }

                    delete temp;
                    if (prev == nullptr)
                    {
                        temp = adjacencyList[i].getHead();
                    }
                    else
                    {
                        temp = prev->next;
                    }
                }
                else
                {
                    prev = temp;
                    temp = temp->next;
                }
            }
        }

        // Remove the linked list for vertex 'a'
        //delete[] adjacencyList[a].getHead();
        adjacencyList[a].setHead(nullptr);
        adjacencyList[a].setVertex(0);

        std::cout << "success\n";
    }
}

void Graph::traffic(int a, int b, double adjustmentFactor)
{

    if (a <= 0 || b <= 0 || a >= MAX_SIZE || b >= MAX_SIZE)
    {
        throw illegal_exception();
    }
    else if(adjustmentFactor < 0 || adjustmentFactor > 1)
    {
        std::cout << "failure\n";
        return;
    }
    else
    {
        int validEdge = 0;
        Node *temp = adjacencyList[a].getHead();

        while (temp != nullptr)
        {
            if (temp->destination == b)
            {
                temp->adjustmentFactor = adjustmentFactor;
                if (adjustmentFactor == 0)
                {
                    temp->time = std::numeric_limits<double>::infinity();
                }
                else
                {
                    temp->time = temp->distance / (temp->speedLimit * adjustmentFactor);
                }
                validEdge++;
                break;
            }
            temp = temp->next;
        }
        temp = adjacencyList[b].getHead();
        while (temp != nullptr)
        {
            if (temp->destination == a)
            {
                temp->adjustmentFactor = adjustmentFactor;
                if (adjustmentFactor == 0)
                {
                    temp->time = std::numeric_limits<double>::infinity();
                }
                else
                {
                    temp->time = temp->distance / (temp->speedLimit * adjustmentFactor);
                }
                validEdge++;
                break;
            }
            temp = temp->next;
        }
        if (validEdge == 0)
        {
            std::cout << "failure\n";
        }
        else
        {
            std::cout << "success\n";
        }
    }
}

void Graph::update(std::fstream &fin)
{
    int validEdge = 0;
    int a, b;
    double adjustmentFactor;
    while (fin >> a >> b >> adjustmentFactor)
    {
        Node *temp = adjacencyList[a].getHead();
        while (temp != nullptr)
        {
            if (temp->destination == b)
            {
                temp->adjustmentFactor = adjustmentFactor;
                if (adjustmentFactor == 0)
                {
                    temp->time = std::numeric_limits<double>::infinity();
                }
                else
                {
                    temp->time = temp->distance / (temp->speedLimit * adjustmentFactor);
                }

                validEdge++;
                break;
            }
            temp = temp->next;
        }
        temp = adjacencyList[b].getHead();
        while (temp != nullptr)
        {
            if (temp->destination == a)
            {
                temp->adjustmentFactor = adjustmentFactor;
                if (adjustmentFactor == 0)
                {
                    temp->time = std::numeric_limits<double>::infinity();
                }
                else
                {
                    temp->time = temp->distance / (temp->speedLimit * adjustmentFactor);
                }
                validEdge++;
                break;
            }
            temp = temp->next;
        }
    }
    if (validEdge == 0)
    {
        std::cout << "failure\n";
    }
    else
    {
        std::cout << "success\n";
    }
}

// Dijkstra's algorithm TTEEESSTTTTING
MinHeap::MinHeap(int maxCapacity) : capacity(maxCapacity), size(0)
{
    heapArray = new HeapNode[capacity]; // +1 because we start indexing from 1
}

MinHeap::~MinHeap()
{
    delete[] heapArray;
}

void MinHeap::customSwap(HeapNode &a, HeapNode &b) {
    HeapNode temp = a;
    a = b;
    b = temp;
}

bool MinHeap::isEmpty() const
{
    return size == 0;
}

void MinHeap::insert(int vertex, double distance)
{
    if (size >= capacity)
    {
        // Handle overflow if necessary (resize the array, for example)
        return;
    }

    size++;
    heapArray[size] = HeapNode(vertex, distance);
    heapifyUp(size);
}

HeapNode MinHeap::extractMin()
{
    if (isEmpty())
    {
        // Handle underflow if necessary
        return HeapNode(-1, std::numeric_limits<double>::infinity());
    }

    HeapNode minNode = heapArray[1];
    heapArray[1] = heapArray[size];
    size--;
    heapifyDown(1);

    return minNode;
}

void MinHeap::heapifyUp(int index)
{
    while (index > 1 && heapArray[index].weight < heapArray[index / 2].weight)
    {
        customSwap(heapArray[index], heapArray[index / 2]);
        index /= 2;
    }
}

void MinHeap::heapifyDown(int index)
{
    int smallest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;

    if (leftChild <= size && heapArray[leftChild].weight < heapArray[smallest].weight)
    {
        smallest = leftChild;
    }

    if (rightChild <= size && heapArray[rightChild].weight < heapArray[smallest].weight)
    {
        smallest = rightChild;
    }

    if (smallest != index)
    {
        customSwap(heapArray[index], heapArray[smallest]);
        heapifyDown(smallest);
    }
}
void Graph::path(int a, int b)
{
    if (a <= 0 || b <= 0 || a >= MAX_SIZE || b >= MAX_SIZE)
    {
        throw illegal_exception();
    }
    if (adjacencyList[a].getVertex() == 0  || adjacencyList[b].getVertex() == 0)
    {
        std::cout << "failure\n";
        return;
    }
    MinHeap minHeap(MAX_SIZE);
    double *distances = new double[MAX_SIZE];
    int *parents = new int[MAX_SIZE];

    for (int i = 1; i < MAX_SIZE; ++i)
    {
        distances[i] = std::numeric_limits<double>::infinity();
        parents[i] = -1;
    }

    distances[a] = 0;

    minHeap.insert(a, 0);

    while (!minHeap.isEmpty())
    {
        HeapNode current = minHeap.extractMin();

        Node *temp = adjacencyList[current.vertex].getHead();
        while (temp != nullptr)
        {
            double newDistance = distances[current.vertex] + temp->time;

            if (newDistance < distances[temp->destination])
            {
                distances[temp->destination] = newDistance;
                parents[temp->destination] = current.vertex;
                minHeap.insert(temp->destination, newDistance);
            }

            temp = temp->next;
        }
    }

   if (distances[b] == std::numeric_limits<double>::infinity())
    {
        std::cout << "failure\n";
        delete[] distances;
        delete[] parents;
        return;
    }
    int current = b;
    while (current != -1)
    {
        std::cout << current << " ";
        current = parents[current];
    }
    std::cout << std::endl;

    delete[] distances;
    delete[] parents;
}




void Graph::lowest(int a, int b)
{
    if (a <= 0 || b <= 0 || a >= MAX_SIZE || b >= MAX_SIZE)
    {
        throw illegal_exception();
    }

    if (adjacencyList[a].getVertex() == 0 || adjacencyList[b].getVertex() == 0)
    {
        std::cout << "failure\n";
        return;
    }

    MinHeap minHeap(MAX_SIZE);
    double *distances = new double[MAX_SIZE];
    int *parents = new int[MAX_SIZE];

    // Initialize distances and parents
    for (int i = 1; i < MAX_SIZE; ++i)
    {
        distances[i] = std::numeric_limits<double>::infinity();
        parents[i] = -1;
    }

    // Distance from source to itself is 0
    distances[a] = 0;

    minHeap.insert(a, 0);

    while (!minHeap.isEmpty())
    {
        HeapNode current = minHeap.extractMin();

        // Iterate through neighbors of current vertex
        Node *temp = adjacencyList[current.vertex].getHead();
        while (temp != nullptr)
        {
            double newDistance = distances[current.vertex] + temp->time;

            if (newDistance < distances[temp->destination])
            {
                distances[temp->destination] = newDistance;
                parents[temp->destination] = current.vertex;
                minHeap.insert(temp->destination, newDistance);
            }

            temp = temp->next;
        }
    }
   if (distances[b] == std::numeric_limits<double>::infinity())
    {
        std::cout << "failure\n";
        delete[] distances;
        delete[] parents;
        return;
    }
    // Calculate the weight of the lowest-weight path considering the time value

    double temp = distances[b];
    std::cout << "lowest is " << temp << std::endl;

    delete[] distances;
    delete[] parents;
}