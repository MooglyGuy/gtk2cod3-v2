#include <iostream>
#include <cassert>
#include "gtkread.h"

using namespace std;

int main(int argc, char *argv[]) {
    assert(argc > 1);
    gtkread read = gtkread(&argv[1]);
    read.file_load();
    read.parse_nodes();
    cout << "Lines: " << read.size() << endl;
    cout << "Nodes: " << read.get_nodes().size() << endl;

    for (int i = 0; i <read.get_nodes().size(); i++) {
        node node = read.get_nodes()[i];
        string header = *node.get_header();
        cout << header << endl;
    }
    return 0;
}
