#ifdef WITH_CATCH

#define CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER
#include "contrib/catch.hpp"
#define SKIPTEST  , "[!hide]"

#elif defined(WITH_DOCTEST)

#include "contrib/doctest.h"
#define SECTION(...) SUBCASE(__VA_ARGS__)
#define SKIPTEST  * doctest::skip(true)
#define CHECK_THAT(a, b) 
#else
#error define either WITH_CATCH or WITH_DOCTEST
#endif



// this second unit exists mostly  to guard against duplicate symbol linker errors
#include "stringconvert.h"
#include "formatter.h"
#include "hexdumper.h"
#include "stringlibrary.h"
#include "argparse.h"
TEST_CASE("second linker object") {
    CHECK( string::convert<char>(std::string("abcd")) == std::string("abcd") );
    CHECK( stringformat("%i", 123) == "123" );
    std::stringstream buf;
    buf << Hex::hexstring << std::setfill(' ') << Hex::dumper("abcde", 5);
    CHECK( buf.str() == "61 62 63 64 65" );
    CHECK( stringcompare("abcd", "abcd") == 0 );
}

