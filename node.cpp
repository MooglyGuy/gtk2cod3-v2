#include "node.h"

std::string* node::get_header() {
    return &m_head;
}

void node::set_header(std::string header) {
    m_head = std::move(header);
}

std::vector<std::string>* node::get_content() {
    return &m_node_content;
}

void node::set_content(std::vector<std::string> content) {
    m_node_content = std::move(content);
}

node::node() {
    m_head = "//";
    m_node_content = std::vector<std::string>();
}
