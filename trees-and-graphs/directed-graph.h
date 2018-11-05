#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH

#include <vector>

using namespace std;

class DirectedGraph
{
    private:
        /**
         * Number of vertices in the graph
         *
         * @param int V
         */
        int V;

        /**
         * Adjacency list containing all edges for each vertex
         *
         * @param vector<vector<int>> adj
         */
        vector<vector<int>> adj;

    public:
        /**
         * Creates a digraph with V edges with no edges
         *
         * @param int v
         */
        DirectedGraph(int v);

        /**
         * Adds directed edges from input 2D array
         *
         * @param vector<vector<int>>& edges
         * @return void
         */
        void addEdges(vector<vector<int>>& edges);

        /**
         * Adds a directed edge from vertex u to vertex v
         *
         * @param int u
         * @param int v
         * @return void
         */
        void addEdge(int u, int v);

        /**
         * Returns the adj list of vertex u
         *
         * @param int u
         * @return vector<int>
         */
        vector<int> getAdjList(int u);

        /**
         * Returns the given vertex is valid
         *
         * @param int v
         * @return bool
         */
        bool isVertexValid(int v);

        /**
         * Returns the number of vertices in the graph
         *
         * @return int
         */
        int getNumVertices();
};

#endif
