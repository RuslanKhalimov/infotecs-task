#include <gtest/gtest.h>
#include "ArgumentsParser.h"

class ArgumentsParserTest : public ::testing::Test {
protected:
    ApplicationConfig *parsed_config, *expected_config;


    void SetUp() {
        parsed_config = new ApplicationConfig();
        expected_config = new ApplicationConfig();
    }

    void TearDown() {
        delete parsed_config;
        delete expected_config;
    }
};

TEST_F(ArgumentsParserTest, empty_parameters) {
    parse_arguments(0, {}, parsed_config);
    EXPECT_EQ(*parsed_config, *expected_config);
}

TEST_F(ArgumentsParserTest, help_message) {
    char *args[] = {"--help"};
    parse_arguments(1, args, parsed_config);

    expected_config->is_help = true;
    EXPECT_EQ(*parsed_config, *expected_config);
}

TEST_F(ArgumentsParserTest, set_mode) {
    char *args[] = {"--mode", "count", "50"};
    parse_arguments(3, args, parsed_config);

    expected_config->mode = "count";
    expected_config->parameter = 50;
    EXPECT_EQ(*parsed_config, *expected_config);
}

TEST_F(ArgumentsParserTest, set_file_name) {
    char *args[] = {"--file", "output.txt"};
    parse_arguments(2, args, parsed_config);

    expected_config->file_name = "output.txt";
    EXPECT_EQ(*parsed_config, *expected_config);
}

TEST_F(ArgumentsParserTest, set_all) {
    char *args[] = {"-f", "out", "-m", "max", "123"};
    parse_arguments(5, args, parsed_config);

    expected_config->mode = "max";
    expected_config->parameter = 123;
    expected_config->file_name = "out";
    EXPECT_EQ(*parsed_config, *expected_config);
}

TEST_F(ArgumentsParserTest, invalid_flag) {
    char *args[] = {"--fie"};
    EXPECT_THROW(parse_arguments(1, args, parsed_config), std::runtime_error);
}

TEST_F(ArgumentsParserTest, invalid_argument) {
    char *args[] = {"--mode", "qwe", "123"};
    EXPECT_THROW(parse_arguments(3, args, parsed_config), std::runtime_error);
}

TEST_F(ArgumentsParserTest, not_enough_parameters) {
    char *args[] = {"--file"};
    EXPECT_THROW(parse_arguments(1, args, parsed_config), std::runtime_error);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
