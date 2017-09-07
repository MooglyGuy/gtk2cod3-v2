#ifndef GTK2COD3_NODE_H
#define GTK2COD3_NODE_H

#include <string>
#include <vector>

class node {
public:
    node(std::vector<std::string> &source, size_t header_index, size_t source_start=0, size_t source_end=~0);
    std::string * get_header();
    void set_header(std::string header);
    std::vector<std::string> *get_content();
    void set_content(std::vector<std::string> content);

private:
    std::string m_head;
    std::vector<std::string> m_node_content;
};


#endif //GTK2COD3_NODE_H
