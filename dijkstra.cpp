#include "dijkstra.h"
#include <list>
#include <vector>
#include <algorithm>
using std::vector;
SearchResult Dijkstra::findPath(Input input)
{
    auto t = std::chrono::high_resolution_clock::now();
    SearchResult result;

    //переносим псевдокод в код
    input.start.g = 0;
    Node goal = input.goal;
    open.addNode(input.start);

    while (open.getSize() != 0){

        Node temp = open.getMin();
        Node* current = new Node(temp.x, temp.y, temp.g, temp.parent);
        closed.addClose(*current);
        open.popMin();
        if (current->x == goal.x and current->y == goal.y){
            result.path = reconstructPath(*current);
            result.pathfound = true;
            result.cost = current->g;
            break;
        }
        std::list<Node> neighbors;
        neighbors = input.map.getValidMoves(*current);
        for (Node neighbor: neighbors) {
            if (closed.inClose(neighbor.x, neighbor.y))
                continue;
            neighbor.g = current->g + input.map.getCost(*current, neighbor);
            neighbor.parent = current;
            open.ifFoundReplaceElseInsert(neighbor);
        }
    }

    result.createdNodes = closed.getSize() + open.getSize();
    result.steps = closed.getSize();
    result.runtime = std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - t).count();
    return result;
}

std::list<Node> Dijkstra::reconstructPath(Node current)
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
