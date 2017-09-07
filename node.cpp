#include "node.h"

node::node(std::vector<std::string> &source, size_t header_index, size_t source_start, size_t source_end)
	: m_head(header_index != ~0 ? source[header_index] : "//") {
	if (source_end == ~0)
		source_end = source.size();

	m_node_content.insert(m_node_content.begin(), source.begin() + source_start, source.begin() + source_end);
}

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
