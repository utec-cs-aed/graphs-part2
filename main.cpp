#include <iostream>
#include <vector>
#include "Graph/UndirectedGraph.h"
#include "Graph/Algorithms/astar.h"
#include "Graph/Algorithms/dfs.h"
#include "Graph/Algorithms/dijkstra.h"
#include "Graph/Algorithms/floyd.h"
#include "Graph/Algorithms/greedybfs.h"
#include "Graph/Algorithms/kruskal.h"
#include "Graph/Algorithms/prim.h"
#include "tester.h"

Graph<string, int>* GraphTester() {
    vector<string> vertices = { "1", "2", "3", "4", "5" };
    vector<tuple<string, string, int>> edges = 
    {
        {"1", "2", 3}, 
        {"1", "3", 3}, 
        {"2", "3", 1}, 
        {"1", "4", 2}, 
        {"2", "5", 6},
        {"5", "4", 7}, 
        {"4", "3", 2}, 
        {"2", "4", 0}
    }; 

    Graph<string, int>* graph = new UnDirectedGraph<string, int>;
    for (auto vertex : vertices) {
        graph->insertVertex(vertex, vertex);
    }
    for (auto edge : edges) {
        auto [v1, v2, w] = edge;
        graph->createEdge(v1, v2, w);
    }
    return graph;
}

bool checkVertexesTest(vector<pair<string, string>>& expected, vector<Edge<string, int>*>& given) {
    if (expected.size() != given.size()) return false;
    for (auto edge : given) {
        string v1 = edge->vertexes[0]->data;
        string v2 = edge->vertexes[1]->data;
        auto it = find_if(expected.begin(), expected.end(), 
                        [v1, v2](pair<string, string> element) { 
            return (element.first == v1 && element.second == v2)
                    || (element.first == v2 && element.second == v1);} );
        if (it == expected.end()) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;

    Graph<string, int>* graph = GraphTester();
    bool pass;

    vector<pair<string, string>> KruskalExpected = {{"1", "4"}, {"2", "3"}, {"2", "4"}, {"2", "5"}};
    vector<Edge<string, int>*> KruskalGiven = kruskal<string, int>(graph);
    pass = checkVertexesTest(KruskalExpected, KruskalGiven);
    ASSERT(pass == true, "Kruskal is OK", 1);

    vector<pair<string, string>> PrimExpected = {{"1", "4"}, {"2", "3"}, {"2", "4"}, {"2", "5"}};
    vector<Edge<string, int>*> PrimGiven = prim<string, int>(graph);
    pass = checkVertexesTest(PrimExpected, PrimGiven);
    ASSERT(pass == true, "Prim is OK", 1);

    vector<pair<string, string>> DFSExpected = {{"4", "2"}, {"2", "3"}, {"3", "1"}, {"2", "5"}};
    vector<Edge<string, int>*> DFSGiven = dfs<string, int>(graph, "4");
    pass = checkVertexesTest(DFSExpected, DFSGiven);
    ASSERT(pass == true, "DFS is OK", 1);

    vector<pair<string, int>> DijkstraExpected = {{"1", 3}, {"2", 1}, {"4", 1}, {"5", 7}};
    unordered_map<Vertex<string, int>*, int> DijkstraGiven = dijkstra<string, int>(graph, "3");
    pass = true;
    if (DijkstraExpected.size() != DijkstraGiven.size()) pass = false;
    else for (auto weightVertex : DijkstraGiven) {
        string vertex = weightVertex.first->data;
        int w = weightVertex.second;
        auto it = find_if(DijkstraExpected.begin(), DijkstraExpected.end(), 
                        [vertex, w](pair<string, int> element) { 
            return (element.first == vertex && element.second == w);} );
        if (it == DijkstraExpected.end()) { pass = false; break; }
    }
    ASSERT(pass == true, "Dijkstra is OK", 1);

    vector<string> AstarExpected = {"1", "2", "5"};
    unordered_map<string, int> heuristics = {{"1", 30}, {"2", 8}, {"3", 10}, {"4", 15}, {"5", 2}};
    vector<Vertex<string, int>*> AstarGiven = astar<string, int>(graph, "1", "5", heuristics);
    pass = true;
    if (AstarExpected.size() != AstarGiven.size()) pass = false;
    else for (int i = 0; i < AstarExpected.size(); i++) {
        if (AstarExpected[i] != AstarGiven[i]->data) { pass = false; break; }
    }
    ASSERT(pass == true, "A* is OK", 1);
    
    return EXIT_SUCCESS;
}