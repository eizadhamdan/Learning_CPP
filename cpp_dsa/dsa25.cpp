/*
Code with a different printgraph function


WORKING PRINT GRAPH FUNCTION
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Graph
{
private:
    unordered_map< string, unordered_set<string> > adjList;
public:
    void printGraph()
    {
        unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
        while(kvPair != adjList.end())
        {
            cout << kvPair->first << ": [";
            unordered_set<string>::iterator edge = kvPair->second.begin();
            bool first = true;
            while(edge != kvPair->second.end())
            {
                if(!first)
                {
                    cout << ", ";
                }
                cout << *edge;
                edge++;
                first = false;
            }
            cout << "]" << endl;
            kvPair++;
        }
    }

    bool addVertex(string vertex)
    {
        if(adjList.count(vertex) == 0)
        {
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }

    bool removeEdge(string vertex1, string vertex2)
    {
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
        {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;

    }

    bool removeVertex(string vertex)
    {
        if(adjList.count(vertex) == 0) return false;

        for(auto otherVertex : adjList.at(vertex))
        {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }
};

int main()
{
    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");

    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("A", "D");
    myGraph->addEdge("B", "D");
    myGraph->addEdge("C", "D");

    myGraph->removeVertex("D");

    myGraph->printGraph();


    return 0;
}