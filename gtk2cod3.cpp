#include <iostream>
#include <cassert>
#include "gtkread.h"

int main(int argc, char *argv[]) {
    assert(argc > 1);
    gtkread read = gtkread(argv[1]);
    read.file_load();
    read.parse_nodes();
    std::cout << "Lines: " << read.size() << std::endl;
    std::cout << "Nodes: " << read.get_nodes().size() << std::endl;

    node node;
    for (size_t i = 0; i <read.get_nodes().size(); i++) {
        node = read.get_nodes()[i];
        std::string header = *node.get_header();
        std::cout << header << std::endl;
    }
    return 0;
}
