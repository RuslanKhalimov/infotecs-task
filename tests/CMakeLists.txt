enable_testing()

include_directories(../src)

add_executable(tests Primes_test.cpp ../src/Primes.cpp)

target_link_libraries(tests PUBLIC
        gtest_main)

add_test(
        NAME tests
        COMMAND tests
)