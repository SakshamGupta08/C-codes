#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <unordered_map>
using namespace std;

class Graph
{
    vector<Vertex*> vertices;

    bool hasPath(unordered_map<Vertex*,bool> &visited,Vertex* v1,Vertex* v2)
    {

        /*visited[v1]=true;
        vector<Vertex*> adjacent = v1 -> getAllAdjacentVertices();
        for(int i = 0; i < adjacent.size(); i++)
        {
            if(adjacent[i]->name==v2->name) return true;
            else
            {
                visited[adjacent[i]]=true;
                vector<Vertex*> adjacent1 = adjacent[i] -> getAllAdjacentVertices();
                for(int i = 0; i < adjacent1.size(); i++)
                {
                    if(visited.count(adjacent1[i]->name)==1) continue;
                    else
                    {
                        hasPath(visited,adjacent[i],v2);
                        if(hasPath(visited,adjacent[i],v2)==1) return true;
                    }
                }

            }
        }
        return false;
        }*/

        if(v1 -> isAdjacent(v2))
        {
            return true;
        }

        visited[v1]=true;

        vector<Vertex*> adj= v1 -> getAllAdjacentVertices();
        for(int i=0; i<adj.size(); i++)
        {
            if(visited.count(adj[i])==0)
            {
                bool ans=hasPath(visited,adj[i],v2);
                if(ans)
                {
                    return true;
                }
            }
        }
        return false;

    }

    vector<Vertex*> getPath(unordered_map<Vertex*,bool>&visited,Vertex* v1,Vertex* v2)
    {

        if(v1 -> isAdjacent(v2))
        {
            vector<Vertex*> path;
            path.push_back(v1);
            path.push_back(v2);
            return path;
        }

        visited[v1]=true;

        vector<Vertex*> adj= v1 -> getAllAdjacentVertices();
        for(int i=0; i<adj.size(); i++)
        {
            if(visited.count(adj[i])==0)
            {
                vector<Vertex*> ans=getPath(visited,adj[i],v2);
                if(ans.size()>0)
                {
                    ans.push_back(v1);
                    return ans;
                }
            }
        }
        vector<Vertex*> out;
        return out;

    }


public:

    bool hasPath_BFS(char* vname1,char* vname2)
    {
        if((isVertexPresent(vname1) == -1)||isVertexPresent(vname2) == -1)
        {
            return false;
        }

        int index1 = isVertexPresent(vname1);
        Vertex *v1 = vertices[index1];
        int index2 = isVertexPresent(vname2);
        Vertex *v2 = vertices[index2];

        queue<Vertex*> pendingvertices;
        pendingvertices.enqueue(v1);
        unordered_map<Vertex*,bool> visited;

        while(!pendingvertices.isEmpty())
        {
            Vertex *current=pendingvertices.dequeue();
            if(visited.count(current)==0)
            {
                visited[current]=true;
                if(current -> isAdjacent(v2))
                {
                    return true;
                }

                vector<Vertex*> adjacent=current -> getAllAdjacentVertices();

                for(int i=0; i<adjacent.size(); i++)
                {
                    pendingvertices.enqueue(adjacent[i]);
                }
            }

        }
        return false;

    }


    vector<vector<Vertex*>>* connectedcomponents(){

    unordered_map<Vertex*,bool> visited;
    vector<vector<Vertex*>>* output;

    for(int i=0;i<vertices.size();i++)
        {
            Vertex* currentvertex=vertices[i];

        if(visited.count(currentvertex)==0){

            queue<Vertex*> pendingvertices;
            vector<Vertex*> v;
           // v.push_back(currentvertex);
            pendingvertices.enqueue(currentvertex);

            while(!pendingvertices.isEmpty())
        {
            Vertex *current=pendingvertices.dequeue();

            if(visited.count(current)==0)
            {
                visited[current]=true;
                v.push_back(current);
                vector<Vertex*> adjacent=current -> getAllAdjacent();

                for(int i=0; i<adjacent.size(); i++)
                {
                    pendingvertices.enqueue(adjacent[i]);
                    v.push_back(adjacent[i]);
                    visited[adjacent[i]]=true;

                }

        }
    }
    output.push_back(v);
        }

    return output;
    }

    //DFS
    bool isPath(char* vname1,char* vname2)
    {
        if(isVertexPresent(vname1) == -1)||isVertexPresent(vname2) == -1)
        {
            return false;
        }

        int index1 = isVertexPresent(vname1);
        Vertex *v1 = vertices[index1];
        int index2 = isVertexPresent(vname2);
        Vertex *v2 = vertices[index2];
        unordered_map<Vertex*,bool> visited;
        return hasPath(visited,v1,v2);


    }



    int numVertices()
    {
        return vertices.size();
    }

    int numEdges()
    {
        int num = 0;
        for(int i = 0; i < vertices.size(); i++)
        {
            num += vertices[i] -> countEdges();
        }
        return num / 2;
    }

    void addVertex(char *vName)
    {
        // check if this vertex already exists
        for(int i = 0; i < vertices.size(); i++)
        {
            if(strcmp(vertices[i] -> name, vName) == 0)
            {
                cout << "Vertex already exists !" << endl;
                return;
            }
        }

        Vertex *newVertex = new Vertex(vName);
        vertices.push_back(newVertex);
    }

    int isVertexPresent(char *vName)
    {
        for(int i = 0; i < vertices.size(); i++)
        {
            if(strcmp(vertices[i] -> name, vName) == 0)
            {
                //cout << "Vertex already exists !" << endl;
                return i;
            }
        }
        return -1;
    }

    void addEdge(char *vName1, char *vName2)
    {
        // check if both vertex exists
        if((isVertexPresent(vName1) == -1) || (isVertexPresent(vName2) == -1))
        {
            return;
        }

        int v1Index = isVertexPresent(vName1);
        int v2Index = isVertexPresent(vName2);
        Vertex *v1 = vertices[v1Index];
        Vertex *v2 = vertices[v2Index];

        // check if edge already exists
        if(v1 -> isAdjacent(v2))
        {
            return;
        }

        // add edge
        Edge *newEdge = new Edge(v1, v2);
        v1 -> addNewEdge(newEdge);
        v2 -> addNewEdge(newEdge);
    }

    void removeEdge(char *vName1, char *vName2)
    {
        // check if both vertex exists
        if((isVertexPresent(vName1) == -1) || (isVertexPresent(vName2) == -1))
        {
            return;
        }

        int v1Index = isVertexPresent(vName1);
        int v2Index = isVertexPresent(vName2);
        Vertex *v1 = vertices[v1Index];
        Vertex *v2 = vertices[v2Index];

        // check if edge already exists
        if(!(v1 -> isAdjacent(v2)))
        {
            return;
        }

        v1 -> removeEdgeWith(v2);
        v2 -> removeEdgeWith(v1);
    }

    void removeVertex(char *vName)
    {
        if(isVertexPresent(vName) == -1)
        {
            return;
        }

        int index = isVertexPresent(vName);
        Vertex *toBeRemoved = vertices[index];

        vector<Vertex*> adjacent = toBeRemoved -> getAllAdjacentVertices();

        for(int i = 0; i < adjacent.size(); i++)
        {
            adjacent[i] -> removeEdgeWith(toBeRemoved);
        }

        delete toBeRemoved;

        vertices.erase(vertices.begin() + index);
    }

    void print()
    {
        for(int i = 0; i < vertices.size(); i++)
        {
            vertices[i] -> print();
        }
    }









};

#endif
