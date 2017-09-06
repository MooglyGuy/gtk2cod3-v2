#ifndef GTK2COD3_GTKREAD_H
#define GTK2COD3_GTKREAD_H

#include <string>
#include <vector>
#include <string>
#include <list>
#include "node.h"

class gtkread {

public:
    gtkread(char **filename);
    ~gtkread();

    long file_load();
    unsigned long size();
    long parse_nodes();
    std::vector<node> get_nodes();

private:
    char **m_filename;
    std::vector<std::string> m_file_contents;
    std::vector<node> m_nodes;
};

#endif //GTK2COD3_GTKREAD_H
