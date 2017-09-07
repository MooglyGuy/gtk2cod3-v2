#include "gtkread.h"
#include <fstream>
#include <cassert>
#include <iostream>

gtkread::gtkread(char *filename) {
    m_filename = filename;
}

gtkread::~gtkread() {
}

void gtkread::file_load() {
    assert(m_filename.length() > 0);
    std::ifstream file(m_filename.c_str());
    std::string line;
    m_file_contents.clear();

    while (getline(file, line)) {
        m_file_contents.push_back(line);
    }
    file.close();
}

size_t gtkread::size() {
    return m_file_contents.size();
}

std::vector<std::string> slice(const std::vector<std::string>& v, size_t start=0, size_t end=~0) {
	if (end == ~0)
		end = v.size();
	
	std::vector<std::string> sliced;
	sliced.insert(sliced.begin(), v.begin() + start, v.begin() + end);
    return sliced;
}

void gtkread::parse_nodes() {
    size_t nodeBegin = 0;
    node currentNode;
    for (size_t i=0; i < m_file_contents.size(); i++) {
        std::string line = m_file_contents[i];
        if (line.find('{') != std::string::npos) {
            currentNode = node();
            nodeBegin = i+1;

            if (i > 0 && m_file_contents[i-1].substr(0, 2) == "//") {
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
}

std::vector<node>& gtkread::get_nodes() {
    return m_nodes;
}
