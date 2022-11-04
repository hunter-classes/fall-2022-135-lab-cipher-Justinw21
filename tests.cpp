#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
// add your tests here

TEST_CASE("TASK A")
{
    std::string example1 = "He was the type of guy who liked Christmas lights on his house in the middle of July.";
    std::string example2 = "Douglas figured the best way to succeed was to do the opposite of what he'd been doing all his life.";
    std::string example3 = "He fumbled in the darkness looking for the light switch, but when he finally found it there was someone already there.";
    std::string encrypted1 = encryptCaesar(example1, 20);
    std::string encrypted2 = encryptCaesar(example2, 15);
    std::string encrypted3 = encryptCaesar(example3, 25);

    CHECK(solve(encrypted1) == example1);
    CHECK(solve(encrypted2) == example2);
    CHECK(solve(encrypted3) == example3);

}