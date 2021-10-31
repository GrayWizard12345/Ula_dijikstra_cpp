#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "input.h"
#include <chrono>

class Dijkstra
{
    ClosedList closed;
    OpenList open;
public:
    Dijkstra() {}
    SearchResult findPath(Input input);
    std::list<Node> reconstructPath(Node current);

    void get_neighbors_of_current(const Node &current, std::list<Node> &neighbors, const Input &input) const;
};

#endif // DIJKSTRA_H
