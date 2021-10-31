#include "astar.h"
#include "dijkstra.h"

SearchResult AStar::findPath(Input input)
{
    auto t = std::chrono::high_resolution_clock::now();
    SearchResult result;

    //TODO
    //переносим псевдокод в код

    result.createdNodes = closed.getSize() + open.getSize();
    result.steps = closed.getSize();
    result.runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - t).count();
    return result;
}
double AStar::getHValue(Node current, Node goal, bool dma)
{
    //TODO
    //используйте либо расстояние Манхетенна, либо диагональную метрику в зависимости от свзяности грида
    //связность грида нужно передать в метод. Этот параметр можно получить из input.map.diagonal_moves_allowed
}
std::list<Node> AStar::reconstructPath(Node current)
{
    std::list<Node> path;
    while(current.parent != nullptr)
    {
        path.push_front(current);
        current = *current.parent;
    }
    path.push_front(current);
    return path;
}

