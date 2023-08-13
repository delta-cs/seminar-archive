#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <limits>

struct Vertex {
    int id;
    int height;
    int x, y;

    explicit Vertex(int id, int height, int x, int y) : id(id), height(height), x(x), y(y) {}
};

struct Edge {
    int weight;
    std::shared_ptr<Vertex> to;

    Edge(int weight, std::shared_ptr<Vertex> to) : weight(weight), to(std::move(to)) {}
};

struct Graph {
    std::vector<std::shared_ptr<Vertex>> vertices;
    std::vector<std::vector<std::shared_ptr<Edge>>> neighbours; // max 4 items, no linked list needed

    explicit Graph(std::vector<std::shared_ptr<Vertex>> vertices,
                   std::vector<std::vector<std::shared_ptr<Edge>>> neighbours
    ) : vertices(std::move(vertices)),
        neighbours(std::move(neighbours)) {}

    friend std::ostream &operator<<(std::ostream &os, Graph &g) {
        for (const std::shared_ptr<Vertex> &vertex: g.vertices) {
            os << '[' << vertex->x << ',' << vertex->y << "] ->";
            for (const std::shared_ptr<Edge> &neighbour: g.neighbours[vertex->id]) {
                os << ' ' << neighbour->to->id << '(' << neighbour->weight << ')';
            }
            os << std::endl;
        }

        return os;
    }
};

std::vector<int> BFS(const Graph &g, int start, int end, int mnd) {
    struct MemoItem {
        int predecessorId = -1;
        int predecessorForwardMnd = std::numeric_limits<int>::max();
        int predecessorBackwardMnd = std::numeric_limits<int>::max();
    };

    struct BFSItem {
        int vertexId;
        int forwardMnd;
        int backwardMnd;

        int predecessorId;
        int predecessorForwardMnd;
        int predecessorBackwardMnd;

        BFSItem(int vertexId, int forwardMnd, int backwardMnd,
                int predecessorId, int predecessorForwardMnd, int predecessorBackwardMnd)
                : vertexId(vertexId),
                  forwardMnd(forwardMnd), backwardMnd(backwardMnd),
                  predecessorId(predecessorId),
                  predecessorForwardMnd(predecessorForwardMnd), predecessorBackwardMnd(predecessorBackwardMnd) {}

        bool operator<(const BFSItem &rhs) const {
            return std::abs(forwardMnd - backwardMnd) < std::abs(rhs.forwardMnd - rhs.backwardMnd);
        }
    };

    // vertices x positiveMnd x negativeMnd
    auto memo = std::vector<std::vector<std::vector<std::shared_ptr<MemoItem>>>>(
            g.vertices.size(), std::vector<std::vector<std::shared_ptr<MemoItem>>>(
                    mnd + 1, std::vector<std::shared_ptr<MemoItem>>(mnd + 1)
            )
    );

    std::queue<BFSItem> queue;
    queue.push(BFSItem(start, 0, 0, -1, 0, 0));

    while (!queue.empty()) {
        BFSItem item = queue.front();
        queue.pop();

        if (memo[item.vertexId][item.forwardMnd][item.backwardMnd]) {
            continue;
        }

        auto itemMemo = std::make_shared<MemoItem>();
        itemMemo->predecessorId = item.predecessorId;
        itemMemo->predecessorForwardMnd = item.predecessorForwardMnd;
        itemMemo->predecessorBackwardMnd = item.predecessorBackwardMnd;

        memo[item.vertexId][item.forwardMnd][item.backwardMnd] = itemMemo;

        if (item.vertexId == end) {
//            std::cout << "E: " << item.vertexId << "(" << item.forwardMnd << ", " << item.backwardMnd << ")" << std::endl;

            std::vector<int> path;
            path.push_back(item.vertexId);

            while (itemMemo) {
                if (itemMemo->predecessorId < 0) {
                    break;
                }

                path.push_back(itemMemo->predecessorId);
                itemMemo = memo[itemMemo->predecessorId][itemMemo->predecessorForwardMnd][itemMemo->predecessorBackwardMnd];
            }

            return path;
        }

//        std::cout << item.vertexId << "(" << item.forwardMnd << ", " << item.backwardMnd << ")" << std::endl;

        std::shared_ptr<Vertex> vertex = g.vertices[item.vertexId];
        for (const std::shared_ptr<Edge> &edge: g.neighbours[item.vertexId]) {
            int neighbourId = edge->to->id;
            int edgeWeight = edge->weight;

            // Nemohu jezdit tam a zpet mezi dvema body
            if (neighbourId == item.predecessorId) {
                continue;
            }

            // Musim jet rovne nebo dolu, ale cesta je do kopce
            if (item.forwardMnd > 0 && edgeWeight > 0) {
                continue;
            }

            // V opacnem smeru musim jet rovne nebo nahoru, ale cesta je do dolu
            if (item.backwardMnd > 0 && edgeWeight < 0) {
                continue;
            }

            int neighbourForwardMnd = item.forwardMnd ? item.forwardMnd - 1 : (edgeWeight > 0 ? mnd : 0);
            int neighbourBackwardMnd = item.backwardMnd ? item.backwardMnd - 1 : (edgeWeight < 0 ? mnd : 0);

            if (!memo[neighbourId][neighbourForwardMnd][neighbourBackwardMnd]) {
                queue.push(
                        BFSItem(neighbourId, neighbourForwardMnd, neighbourBackwardMnd,
                                item.vertexId, item.forwardMnd, item.backwardMnd));
            }
        }
    }

    return {};
}

int main() {
    int mnd;
    std::cin >> mnd;

    int startX, startY;
    std::cin >> startX >> startY;

    int endX, endY;
    std::cin >> endX >> endY;

    int mapWidth, mapHeight;
    std::cin >> mapWidth >> mapHeight;

    std::vector<std::shared_ptr<Vertex>> vertices(mapHeight * mapWidth);

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            int id = (i * mapWidth) + j;
            int height;

            std::cin >> height;

            vertices[id] = std::make_unique<Vertex>(id, height, i, j);
        }
    }

    std::vector<std::vector<std::shared_ptr<Edge>>> neighbours(mapHeight * mapWidth);

    for (int i = 0; i < mapHeight; i++) {
        for (int j = 0; j < mapWidth; j++) {
            int id = (i * mapWidth) + j;
            std::shared_ptr<Vertex> vertex = vertices[id];

            if (j > 0) {
                // compare left node (symmetric)
                int neighbourId = (i * mapWidth) + (j - 1);
                std::shared_ptr<Vertex> neighbour = vertices[neighbourId];

                int heightDifference = vertex->height - neighbour->height;
                if (std::abs(heightDifference) <= 1) {
                    neighbours[id].push_back(std::make_unique<Edge>(-heightDifference, neighbour));
                    neighbours[neighbourId].push_back(std::make_unique<Edge>(heightDifference, vertex));
                }
            }

            if (i > 0) {
                // compare top node (symmetric)
                int neighbourId = ((i - 1) * mapWidth) + j;
                std::shared_ptr<Vertex> neighbour = vertices[neighbourId];

                int heightDifference = vertex->height - neighbour->height;
                if (std::abs(heightDifference) <= 1) {
                    neighbours[id].push_back(std::make_unique<Edge>(-heightDifference, neighbour));
                    neighbours[neighbourId].push_back(std::make_unique<Edge>(heightDifference, vertex));
                }
            }
        }
    }

    int start = (startY * mapWidth) + startX;
    int end = (endY * mapWidth) + endX;

    auto g = Graph(vertices, neighbours);

    auto path = BFS(g, start, end, mnd);

//    std::cout << ((int) path.size() > 0 ? 1 : 0) << std::endl;

    for (int i =  (int) path.size() - 1; i >= 0; i--) {
        int vertex = path[i];
        std::cout << (vertex % mapWidth) << " " << (vertex / mapWidth) << std::endl;
    }

    return 0;
}
