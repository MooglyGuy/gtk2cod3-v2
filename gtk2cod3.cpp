#include <iostream>
#include <cassert>
#include <ctime>
#include "gtkread.h"
#include "stringutil.h"

int main(int argc, char *argv[]) {
    assert(argc > 1);

	clock_t start = clock();
	gtkread read = gtkread(argv[1]);
    read.file_load();

	clock_t parse_start = clock();
    read.parse_nodes();

	std::cout << "Lines: " << read.size() << std::endl;
    std::cout << "Nodes: " << read.get_nodes().size() << std::endl;

	clock_t print_start = clock();
    for (size_t i = 0; i <read.get_nodes().size(); i++) {
        std::string header = *read.get_nodes()[i].get_header();
        std::cout << header << std::endl;
    }

	clock_t end = clock();

	double total_time = double(end - start) / CLOCKS_PER_SEC;
	double load_time  = double(parse_start - start) / CLOCKS_PER_SEC;
	double parse_time = double(print_start - parse_start) / CLOCKS_PER_SEC;
	double print_time = double(end - print_start) / CLOCKS_PER_SEC;

	std::cout << string_util::format("       Total time: %.3fs", total_time) << std::endl;
	std::cout << string_util::format("        Load time: %.3fs (%3.2f%% of total)",      load_time, (     load_time / total_time) * 100) << std::endl;
	std::cout << string_util::format("       Parse time: %.3fs (%3.2f%% of total)",     parse_time, (    parse_time / total_time) * 100) << std::endl;
	std::cout << string_util::format("       Print time: %.3fs (%3.2f%% of total)",     print_time, (    print_time / total_time) * 100) << std::endl;
	return 0;
}
