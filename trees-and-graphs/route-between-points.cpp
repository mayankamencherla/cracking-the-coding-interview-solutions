#include "directed-graph.cpp"
#include <queue>
#include <iostream>

using namespace std;

/**
 * This method takes in a graph and returns whether a path exists from start to end
 *
 * @param DirectedGraph& dg
 * @param int start
 * @param int end
 * @return bool
 */
bool doesPathExist(DirectedGraph& dg, int start, int end)
{
    vector<bool> visited(dg.getNumVertices(), false);

    queue<int> bfs;

    bfs.push(start);

    while (!bfs.empty())
    {
        int front = bfs.front();

        // Break early when the end we find the end vertex
        if (front == end) return true;

        bfs.pop();

        visited[front] = true;

        for (int v : dg.getAdjList(front))
        {
            if (visited[v]) continue;

            bfs.push(v);
        }
    }

    // Return whether we visited the end vertex
    return visited[end];
}

int main()
{
    DirectedGraph dg = DirectedGraph(10);

    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {0, 7},
        {1, 4},
        {1, 5},
        {2, 7},
        {2, 9},
        {3, 8},
        {4, 9},
        {5, 9},
        {6, 9},
        {7, 4},
        {7, 3},
        {7, 5},
        {8, 3},
        {8, 6},
        {8, 9},
        {9, 2},
        {9, 5},
    };

    dg.addEdges(edges);

    cout << "Does a path exist between start and end? " << doesPathExist(dg, 0, 8) << endl;

    cout << "Does a path exist between start and end? " << doesPathExist(dg, 8, 0) << endl;

    cout << "Does a path exist between start and end? " << doesPathExist(dg, 3, 9) << endl;

    cout << "Does a path exist between start and end? " << doesPathExist(dg, 7, 5) << endl;
}
