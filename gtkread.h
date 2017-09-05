#ifndef GTK2COD3_GTKREAD_H
#define GTK2COD3_GTKREAD_H

#include <string>
#include <vector>
#include <string>
#include <list>
#include "node.h"

using namespace std;

class gtkread {

public:
    long file_load();
    explicit gtkread(char **filename);
    unsigned long size();
    long parse_nodes();
    vector<node> get_nodes();

    ~gtkread();
};

#endif //GTK2COD3_GTKREAD_H
