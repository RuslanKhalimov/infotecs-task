enable_testing()

include_directories(../src)

add_executable(primes_tests Primes_test.cpp ../src/Primes.cpp)
add_executable(arguments_parser_test ArgumentsParserTest.cpp ../src/ArgumentsParser.h)
add_executable(special_primes_test SpecialPrimesTest.cpp ../src/SpecialPrimes.cpp ../src/Primes.cpp)

target_link_libraries(primes_tests PUBLIC gtest_main)
target_link_libraries(arguments_parser_test PUBLIC gtest_main)
target_link_libraries(special_primes_test PUBLIC gtest_main)

add_test(
        NAME primes_tests
        COMMAND primes_tests
)
add_test(
        NAME arguments_parser_test
        COMMAND arguments_parser_test
)
add_test(
        NAME special_primes_test
        COMMAND special_primes_test
)