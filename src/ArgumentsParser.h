#pragma once

#include <cstring>
#include <unordered_map>

enum PrimesTypes {
    Prime,
    SuperPrime,
    SophieGermainPrime
};

struct ApplicationConfig {
    bool is_help = false;
    std::string mode = "max";
    uint32_t parameter = 100;
    const char *file_name = "";
    PrimesTypes primes_type = Prime;

    bool operator==(const ApplicationConfig &other) const {
        return is_help == other.is_help
               && mode == other.mode
               && parameter == other.parameter
               && strcmp(file_name, other.file_name) == 0
               && primes_type == other.primes_type;
    }
};

const std::unordered_map<std::string, PrimesTypes> available_primes_types =
        {{"prime",                Prime},
         {"super-prime",          SuperPrime},
         {"sophie-germain-prime", SophieGermainPrime}};

void check_argc(int argc, int min, const std::string& flag) {
    if (argc < min) {
        throw std::runtime_error("Not enough arguments for " + flag + " parameter");
    }
}

int find_next_parameter(int argc, char *argv[], ApplicationConfig *config) {
    if (strcmp(argv[0], "--help") == 0 || strcmp(argv[0], "-h") == 0) {
        config->is_help = true;
        return 1;
    }
    if (strcmp(argv[0], "--mode") == 0 || strcmp(argv[0], "-m") == 0) {
        check_argc(argc, 3, argv[0]);
        config->mode = argv[1];
        if (config->mode == "max" || config->mode == "count") {
            try {
                config->parameter = std::stoul(argv[2]);
            } catch (const std::invalid_argument &e) {
                throw std::invalid_argument(argv[1]);
            }
        } else {
            throw std::invalid_argument(argv[1]);
        }
        return 3;
    }
    if (strcmp(argv[0], "--file") == 0 || strcmp(argv[0], "-f") == 0) {
        check_argc(argc, 2, argv[0]);
        config->file_name = argv[1];
        return 2;
    }
    if (strcmp(argv[0], "--type") == 0 || strcmp(argv[0], "-t") == 0) {
        check_argc(argc, 2, argv[0]);
        if (available_primes_types.count(argv[1]) == 0) {
            throw std::invalid_argument(argv[1]);
        }
        config->primes_type = available_primes_types.at(argv[1]);
        return 2;
    }
    throw std::invalid_argument(argv[0]);
}

void parse_arguments(int argc, char *argv[], ApplicationConfig *config) {
    while (argc > 0 && !config->is_help) {
        int arguments_parsed = find_next_parameter(argc, argv, config);
        argc -= arguments_parsed;
        argv += arguments_parsed;
    }
}
