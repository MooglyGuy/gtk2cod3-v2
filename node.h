#ifndef GTK2COD3_NODE_H
#define GTK2COD3_NODE_H

#include <string>
#include <vector>

class node {
public:
    node();
    std::string * get_header();
    long set_header(std::string header);
    std::vector<std::string> *get_content();
    long set_content(std::vector<std::string> content);

private:
    std::string m_head;
    std::vector<std::string> m_node_content;
};


#endif //GTK2COD3_NODE_H
