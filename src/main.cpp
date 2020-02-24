#include <iostream>
#include <fstream>

#include "ArgumentsParser.h"
#include "Primes.h"
#include "SpecialPrimes.h"

void show_usage() {
    std::cout << "Usage:" << std::endl
              << "    -h | --help" << std::endl
              << "    -m | --mode       max <max_number> | count <numbers_count>" << std::endl
              << "    -f | --file       <output_file_name>" << std::endl
              << "    -t | --type       <prime_numbers_type>" << std::endl
              << "Available prime_numbers_types : prime, super-prime, sophie-germain-prime" << std::endl;
}

int main(int argc, char *argv[]) {
    ApplicationConfig *config = new ApplicationConfig();
    Primes *container = nullptr;
    try {
        parse_arguments(argc - 1, argv + 1, config);
    } catch (std::invalid_argument &e) {
        std::cerr << "Error while parsing arguments. Get invalid argument : " << e.what() << std::endl;
        show_usage();
        return 1;
    }
    catch (std::exception &e) {
        std::cerr << "Error while parsing arguments : " << e.what() << std::endl;
        show_usage();
        return 1;
    }

    if (config->is_help) {
        show_usage();
        return 0;
    }

    std::vector<uint32_t> result;
    if (config->mode == "max") {
        if (config->primes_type == Prime) {
            container = new Primes(config->parameter);
        } else if (config->primes_type == SuperPrime) {
            container = new SuperPrimes(config->parameter);
        } else if (config->primes_type == SophieGermainPrime) {
            container = new SophieGermainPrimes(config->parameter);
        }
        for (uint32_t &x : *container) {
            result.push_back(x);
        }
        delete container;
    } else {
        if (config->primes_type == Prime) {
            container = new Primes();
        } else if (config->primes_type == SuperPrime) {
            container = new SuperPrimes();
        } else if (config->primes_type == SophieGermainPrime) {
            container = new SophieGermainPrimes();
        }
        for (int i = 0; i < config->parameter; ++i) {
            result.push_back((*container)[i]);
        }
    }

    if (strcmp(config->file_name, "") == 0) {
        for (const uint32_t &x : result) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    } else {
        std::ofstream fout;
        fout.open(config->file_name);
        for (const uint32_t &x : result) {
            fout << x << "\n";
        }
        fout.close();
    }

    delete container;
    delete config;

    return 0;
}
