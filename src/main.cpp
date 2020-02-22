#include <iostream>

#include "ArgumentsParser.h"
#include "Primes.h"

void print(const std::vector<uint32_t> &result, std::string delimiter) {
    for (const uint32_t &x : result) {
        std::cout << x << delimiter;
    }
}

void show_usage() {
    std::cout << "Usage:" << std::endl
                 << "    -h | --help\n"
                 << "    -m | --mode       max <max_number> | count <numbers_count>" << std::endl
                 << "    -f | --file       <output_file_name>" << std::endl
                 << "    -t | --type       <prime_numbers_type>" << std::endl
                 << "Available prime_numbers_types : prime" << std::endl;
}

int main(int argc, char *argv[]) {
    ApplicationConfig *config = new ApplicationConfig();
    try {
        parse_arguments(argc - 1, argv + 1, config);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        show_usage();
        return 1;
    }

    if (config->is_help) {
        show_usage();
        return 0;
    }

    std::vector<uint32_t> result;
    if (config->mode == "max") {
        Primes container(config->parameter);
        for (uint32_t &x : container) {
            result.push_back(x);
        }
    } else {
        Primes container;
        for (int i = 0; i < config->parameter; ++i) {
            result.push_back(container[i]);
        }
    }

    if (strcmp(config->file_name, "") == 0) {
        print(result, " ");
    } else {
        freopen(config->file_name, "w", stdout);
        print(result, "\n");
    }

    delete config;

    return 0;
}
