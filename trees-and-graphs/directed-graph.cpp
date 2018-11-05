#include "directed-graph.h"

using namespace std;

/**
 * This is an implementation of a directed graph
 */

/**
 * Creates a digraph with V edges with no edges
 *
 * @param int v
 */
DirectedGraph::DirectedGraph(int v)
{
    this->V = v;

    this->adj.resize(v, vector<int>());
}

/**
 * Returns whether the given vertex is valid
 *
 * @param int v
 * @return bool
 */
bool DirectedGraph::isVertexValid(int v)
{
    return ((v >= 0) && (v <= this->V-1));
}

/**
 * Adds directed edges from input 2D array
 *
 * @param vector<vector<int>>& edges
 * @return void
 */
void DirectedGraph::addEdges(vector<vector<int>>& edges)
{
    for (vector<int> edge : edges)
    {
        this->addEdge(edge[0], edge[1]);
    }
}

/**
 * Adds a directed edge from vertex u to vertex v
 *
 * @param int u
 * @param int v
 * @return void
 */
void DirectedGraph::addEdge(int u, int v)
{
    // Disallow self loops by default
    if (!isVertexValid(u) || !isVertexValid(v) || u == v) return;

    this->adj[u].push_back(v);
}

/**
 * Returns the adj list of vertex u
 *
 * @param int u
 * @return vector<int>
 */
vector<int> DirectedGraph::getAdjList(int u)
{
    if (!isVertexValid(u)) return {};

    return this->adj[u];
}


/**
 * Returns the number of vertices in the graph
 *
 * @return int
 */
int DirectedGraph::getNumVertices()
{
    return this->V;
}
