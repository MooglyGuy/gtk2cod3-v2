#ifndef GTK2COD3_NODE_H
#define GTK2COD3_NODE_H

#include <string>
#include <vector>

using namespace std;

class node {
public:
    node();
    string * get_header();
    long set_header(string header);
    vector<string> *get_content();
    long set_content(vector<string> content);
};


#endif //GTK2COD3_NODE_H
