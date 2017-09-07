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

#ifdef _MSC_VER
	FILE *file = nullptr;
	fopen_s(&file, m_filename.c_str(), "rb");
#else
	FILE *file = fopen(m_filename.c_str(), "rb");
#endif
	if (file == nullptr)
		return;

	fseek(file, 0, SEEK_END);
	size_t file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char *buf = new char[file_size];

	fread(buf, 1, file_size, file);
	fclose(file);

	size_t start = 0;
	size_t curr;
	for (curr = 0; curr < file_size; curr++) {
		if (buf[curr] == '\x0d' || buf[curr] == '\x0a') {
			if (start != ~0 && curr - start > 0) {
				m_file_contents.push_back(std::string(buf + start, curr - start));
			}
			start = ~0;
		} else if (start == ~0) {
			start = curr;
		}
	}
	if (start != ~0) {
		m_file_contents.push_back(std::string(buf + start, curr - start));
	}

	delete[] buf;
}

size_t gtkread::size() {
    return m_file_contents.size();
}

void gtkread::parse_nodes() {
    size_t nodeBegin = 0;
	size_t headerIndex = ~0;
    for (size_t i=0; i < m_file_contents.size(); i++) {
        std::string line = m_file_contents[i];
        if (line.find('{') != std::string::npos) {
            nodeBegin = i+1;

            if (i > 0 && m_file_contents[i-1].substr(0, 2) == "//") {
				headerIndex = i-1;
            }
            continue;
        }

        if (line.find('}') != std::string::npos) {
            m_nodes.push_back(node(m_file_contents, headerIndex, nodeBegin, i-1));
        }
    }
}

std::vector<node>& gtkread::get_nodes() {
    return m_nodes;
}
