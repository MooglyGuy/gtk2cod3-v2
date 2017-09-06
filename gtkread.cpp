#include "gtkread.h"
#include <fstream>
#include <cassert>
#include <iostream>

gtkread::gtkread(char **filename) {
    this->m_filename = filename;
}

gtkread::~gtkread() {
    m_filename = nullptr;
}

long gtkread::file_load() {
    assert(m_filename != nullptr);
    std::ifstream file(*m_filename);
    std::string line;
    m_file_contents.clear();

    while (getline(file, line)) {
        m_file_contents.push_back(line);
    }
    file.close();
}

unsigned long gtkread::size() {
    return m_file_contents.size();
}

std::vector<std::string> slice(const std::vector<std::string>& v, int start=0, int end=-1) {
    unsigned long oldlen = v.size();
    unsigned long newlen;

    if (end == -1 or end >= oldlen){
        newlen = oldlen-start;
    } else {
        newlen = static_cast<unsigned long>(end - start);
    }

    std::vector<std::string> nv(newlen);

    for (int i=0; i<newlen; i++) {
        nv[i] = v[start+i];
    }
    return nv;
}

long gtkread::parse_nodes() {
    int nodeBegin;
    node currentNode;
    for (int i=0; i<m_file_contents.size(); i++) {
        std::string line = m_file_contents[i];
        if (line.find('{') != std::string::npos) {
            currentNode = node();
            nodeBegin = i+1;

            if (m_file_contents.size() > i-1 && m_file_contents[i-1].substr(0, 2) == "//") {
                currentNode.set_header(m_file_contents[i-1]);
            }
            continue;
        }

        if (line.find('}') != std::string::npos) {
            currentNode.set_content(slice(m_file_contents, nodeBegin, i-1));
            m_nodes.push_back(currentNode);
            continue;
        }
    }
    return 0;
}

std::vector<node> gtkread::get_nodes() {
    return m_nodes;
}
