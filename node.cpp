#include "node.h"

string head;
vector<string> node_content;

string* node::get_header() {
    return &head;
}

long node::set_header(string header) {
    head = std::move(header);
}

vector<string>* node::get_content() {
    return &node_content;
}

long node::set_content(vector<string> content) {
    node_content = std::move(content);
}

node::node() {
    head = "//";
    node_content = vector<string>();
}
