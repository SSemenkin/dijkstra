#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>



struct Edge {
    int m_distance;
    int m_toEdge;
};

struct Vertex {
    int m_id;
    std::vector<Edge> m_edges;
};

class Graph {
public:
    Graph(const std::vector<Vertex> &vertexes) : m_vertexes(vertexes) {

    }
    Graph() = default;

    void setVertexes(const std::vector<Vertex> &vertexes) {
        m_vertexes = vertexes;
    }

    friend std::ostream& operator<< (std::ostream& stream, const Graph &graph) {
        stream << "Graph {";

        for (int i = 0; i < graph.m_vertexes.size(); ++i) {
            stream << graph.m_vertexes[i].m_id;
            if (i < graph.m_vertexes.size() - 1)  {
                stream << ',';
            }
        }

        stream << "}\n";

        for (int i = 0; i < graph.m_vertexes.size(); ++i) {
            stream << "Node " << graph.m_vertexes[i].m_id << "{\n";
            for (const Edge &edge : graph.m_vertexes[i].m_edges) {
                stream << "Edge {" << edge.m_toEdge << "," << edge.m_distance << "}\n";
            }
            stream << "}\n";
        }
        return stream;
    }

private:
    std::vector<Vertex> m_vertexes;
};

Graph readGraphFromFile(const std::string &path)
{
    Graph graph;
    std::ifstream inputFile(path);

    if (inputFile.is_open()) {

        int vertexCount, vertexId;
        inputFile >> vertexCount;

        std::vector<Vertex> vertexes(vertexCount);
        for (int i = 0; i < vertexCount; ++i) {
            inputFile >> vertexId;
            vertexes[i].m_id = vertexId;
        }

        int edgesCount;
        inputFile >> edgesCount;

        int toEdge, distance;

        for (int i = 0; i < edgesCount; ++i) {
            inputFile  >> vertexId >> toEdge >> distance;
            Edge edge {distance, toEdge};

            auto pos = std::find_if(vertexes.begin(), vertexes.end(), [vertexId](const Vertex& vertex) {
                return vertexId == vertex.m_id;
            });

            if (pos == vertexes.end()) {
                std::cout << "Not find vertex with id " << vertexId;
            }


            (*pos).m_edges.push_back(edge);
        }
        graph.setVertexes(vertexes);

    } else {
        std::cerr << "File " << path << " not open\n";
    }
    return graph;
}

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;

    Graph graph = readGraphFromFile("input.txt");

    std::cout << graph;



    return 0;
}

