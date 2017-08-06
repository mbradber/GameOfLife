#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

typedef int64_t life_t;

struct Node {
    Node(life_t _x, life_t _y) : x(_x), y(_y) {}
    life_t x;
    life_t y;
};

template <>
struct std::hash<Node> {
    std::size_t operator()(const Node& n) const {
        life_t hash = 23;
        hash *= 31 + n.x;
        hash *= 31 + n.y;
        return hash;
    }
};

class Graph {
    std::unordered_map< Node, std::vector<Node*> > mAdjMap;
};

int main(int argc, const char * argv[]) {
    std::ifstream inf("state.in");
    if (!inf) {
        std::cerr << "Could not open state.in for reading" << std::endl;
    }
    while (inf) {
        std::string s;
        if (!getline(inf, s)) break;
        
        life_t x = 0, y = 0;
        sscanf(s.c_str(), "%lld,%lld", &x, &y);
        
        std::cout << x << "," << y << std::endl;
    }
    
    return 0;
}
