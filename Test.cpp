#include "doctest.h"
#include "snowman.hpp"

using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}


TEST_CASE("Good snowman code") {
CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
/* Add more checks here */
}

TEST_CASE("Bad snowman code - number out of bounds") {
CHECK_THROWS(snowman(555));
CHECK_THROWS(snowman(81111111));
CHECK_THROWS(snowman(17111111));
CHECK_THROWS(snowman(11811111));
CHECK_THROWS(snowman(11171111));
CHECK_THROWS(snowman(11115111));
CHECK_THROWS(snowman(11111911));
CHECK_THROWS(snowman(11111101));
CHECK_THROWS(snowman(11111117));
/* Add more checks here */
}

TEST_CASE("Bad snowman code - not 8 digits"){
CHECK_THROWS(snowman(1));
CHECK_THROWS(snowman(12));
CHECK_THROWS(snowman(123));
CHECK_THROWS(snowman(1234));
CHECK_THROWS(snowman(12341));
CHECK_THROWS(snowman(123412));
CHECK_THROWS(snowman(1234123));
CHECK_THROWS(snowman(123412341));
CHECK_THROWS(snowman(1234123412));
CHECK_THROWS(snowman(4123));
}

TEST_CASE("Bad snowman code - not 8 digits + out of bounds"){
CHECK_THROWS(snowman(7));
CHECK_THROWS(snowman(15));
CHECK_THROWS(snowman(125));
CHECK_THROWS(snowman(1235));
CHECK_THROWS(snowman(12345));
CHECK_THROWS(snowman(123415));
CHECK_THROWS(snowman(1234125));
CHECK_THROWS(snowman(123412345));
CHECK_THROWS(snowman(1234123415));
CHECK_THROWS(snowman(192));
}

TEST_CASE("Good Snowman - head change") {
CHECK(nospaces(snowman(11111111)) == nospaces("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(21111111)) == nospaces("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(31111111)) == nospaces("   _   \n  /_\\  \n (.,.) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(41111111)) == nospaces("  ___  \n (_*_) \n (.,.) \n<( : )>\n ( : ) "));
}

TEST_CASE("Good Snowman - nose change") {
CHECK(nospaces(snowman(11111111)) == nospaces("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(12111111)) == nospaces("       \n _===_ \n (...) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(13111111)) == nospaces("       \n _===_ \n (._.) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(14111111)) == nospaces("       \n _===_ \n (. .) \n<( : )>\n ( : ) "));
}

TEST_CASE("Good Snowman - full") {

CHECK(nospaces(snowman(12122212)) == nospaces("       \n _===_ \n\\(..o)/\n ( : ) \n (\" \") "));
CHECK(nospaces(snowman(33132124)) == nospaces("   _   \n  /_\\  \n\\(._O) \n (] [)>\n (   ) "));
CHECK(nospaces(snowman(32143333)) == nospaces("   _   \n  /_\\  \n (..-) \n/(> <)\\\n (___) "));
CHECK(nospaces(snowman(44144432)) == nospaces("  ___  \n (_*_) \n (. -) \n (> <) \n (\" \") "));
CHECK(nospaces(snowman(44142123)) == nospaces("  ___  \n (_*_) \n\\(. -) \n (] [)>\n (___) "));
CHECK(nospaces(snowman(11114411)) == nospaces("       \n _===_ \n (.,.) \n ( : ) \n ( : ) "));
CHECK(nospaces(snowman(41141144)) == nospaces("  ___  \n (_*_) \n (.,-) \n<(   )>\n (   ) "));
CHECK(nospaces(snowman(11111111)) == nospaces("       \n _===_ \n (.,.) \n<( : )>\n ( : ) "));
CHECK(nospaces(snowman(33133333)) == nospaces("   _   \n  /_\\  \n (._O) \n/(> <)\\\n (___) "));
CHECK(nospaces(snowman(22122222)) == nospaces("  ___  \n ..... \n\\(..o)/\n (] [) \n (\" \") "));
CHECK(nospaces(snowman(44144444)) == nospaces("  ___  \n (_*_) \n (. -) \n (   ) \n (   ) "));
}