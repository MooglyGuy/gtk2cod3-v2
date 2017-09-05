#include "gtkread.h"
#include <fstream>
#include <cassert>
#include <list>
#include <iostream>

char **file_name;
vector<string> file_contents;
vector<node> nodes;

long gtkread::file_load() {
    assert(file_name != nullptr);
    ifstream file(*file_name);
    string line;
    file_contents.clear();

    while (getline(file, line)) {
        file_contents.push_back(line);
    }
    file.close();
}

gtkread::gtkread(char **filename) {
    file_name = filename;
    file_contents = vector<string>();
    nodes = vector<node>();
}

gtkread::~gtkread() {
    file_name = nullptr;
}

unsigned long gtkread::size() {
    return file_contents.size();
}

vector<string> slice(const vector<string>& v, int start=0, int end=-1) {
    unsigned long oldlen = v.size();
    unsigned long newlen;

    if (end == -1 or end >= oldlen){
        newlen = oldlen-start;
    } else {
        newlen = static_cast<unsigned long>(end - start);
    }

    vector<string> nv(newlen);

    for (int i=0; i<newlen; i++) {
        nv[i] = v[start+i];
    }
    return nv;
}

long gtkread::parse_nodes() {
    int nodeBegin;
    node currentNode;
    for (int i=0; i<file_contents.size(); i++) {
        string line = file_contents[i];
        if (line.find('{') != string::npos) {
            currentNode = node();
            nodeBegin = i+1;

            if (file_contents.size() > i-1 && file_contents[i-1].substr(0, 2) == "//") {
                currentNode.set_header(file_contents[i-1]);
            }
            continue;
        }

        if (line.find('}') != string::npos) {
            currentNode.set_content(slice(file_contents, nodeBegin, i-1));
            nodes.push_back(currentNode);
            continue;
        }
    }
    return 0;
}

vector<node> gtkread::get_nodes() {
    return nodes;
}
