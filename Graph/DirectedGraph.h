#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    public: 

    bool insertVertex(string id, TV data) {
        // TODO
        return true;
    }
    bool createEdge(string id1, string id2, TE w = 0) {
        // TODO
        return true;
    }
    bool deleteVertex(string id) {
        // TODO
        return true;
    }
    bool deleteEdge(string id1, string id2) {
        // TODO
        return true;
    }
    TE &operator()(string id1, string id2) {
        // TODO
        TE ans = TE{};
        return ans;
    }
    float density() {
        // TODO
        return 0;
    }
    bool isDense(float threshold = 0.5) {
        // TODO
        return true;
    }
    bool isConnected() {
        // TODO
        return true;
    }
    bool isStronglyConnected() {
        // TODO
        return true;
    }
    bool empty() {
        // TODO
        return true;
    }
    void clear() {
        // TODO
    }
      
    void displayVertex(string id) {
        // TODO
    }
    bool findById(string id) {
        // TODO
        return true;
    }
    void display() {
        // TODO
    }
};

#endif