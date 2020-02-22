#pragma once

#include <cstring>
#include <unordered_set>

struct ApplicationConfig {
    bool is_help = false;
    std::string mode = "max";
    uint32_t parameter = 100;
    const char *file_name = "";
    std::string primes_type = "prime";

    bool operator==(const ApplicationConfig &other) const {
        return is_help == other.is_help
               && mode == other.mode
               && parameter == other.parameter
               && strcmp(file_name, other.file_name) == 0
               && primes_type == other.primes_type;
    }
};

const std::unordered_set<std::string> available_primes_types = {"primes"};

int find_next_parameter(int argc, char *argv[], ApplicationConfig *config) {
    if (strcmp(argv[0], "--help") == 0 || strcmp(argv[0], "-h") == 0) {
        config->is_help = true;
        return 1;
    }
    if (strcmp(argv[0], "--mode") == 0 || strcmp(argv[0], "-m") == 0) {
        if (argc < 3) {
            throw std::runtime_error("Not enough arguments for : " + std::string(argv[0]) + "parameter");
        }
        config->mode = argv[1];
        if (config->mode == "max" || config->mode == "count") {
            config->parameter = std::stoul(argv[2]);
        } else {
            throw std::runtime_error("Invalid argument : " + std::string(argv[1]));
        }
        return 3;
    }
    if (strcmp(argv[0], "--file") == 0 || strcmp(argv[0], "-f") == 0) {
        if (argc < 2) {
            throw std::runtime_error("Not enough arguments for : " + std::string(argv[0]) + "parameter");
        }
        config->file_name = argv[1];
        return 2;
    }
    if (strcmp(argv[0], "--type") == 0 || strcmp(argv[0], "-t") == 0) {
        if (argc < 2) {
            throw std::runtime_error("Not enough arguments for : " + std::string(argv[0]) + "parameter");
        }
        if (available_primes_types.count(argv[1]) == 0) {
            throw std::runtime_error("Invalid argument : " + std::string(argv[1]));
        }
        config->primes_type = argv[1];
        return 2;
    }
    throw std::runtime_error("Invalid argument : " + std::string(argv[0]));
}

void parse_arguments(int argc, char *argv[], ApplicationConfig *config) {
    while (argc > 0 && !config->is_help) {
        int arguments_parsed = find_next_parameter(argc, argv, config);
        argc -= arguments_parsed;
        argv += arguments_parsed;
    }
}
