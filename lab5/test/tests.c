#include "ctest.h"

#include <libstring/fromWindowsToLinuxPath.h>
#include <libstring/libstring.h>

CTEST(INPUT_CHECK, CHECK_SYMBOLS)
{
    char* firstString
            = "C:\\Windows\\system32+E:\\Distrib\\msoffice.exe+/home/alex/prog/"
              "lab4.c";
    ASSERT_EQUAL(0, checkSymbols(firstString, '+'));
    char* secondString
            = "C:\\Windows\\system32+E:\\Dis?trib\\msoffice.exe+/home/alex/"
              "prog/lab4.c";
    ASSERT_EQUAL(1, checkSymbols(secondString, '+'));
}
CTEST(INPUT_CHECK, CHECK_PATHS)
{
    char* firstString = "/home/alex/prog/lab4.c";
    ASSERT_EQUAL(0, checkPaths(firstString, '+'));
    char* secondString = "C:\\Windows\\system32+E:\\Distrib\\msoffice.exe";
    ASSERT_EQUAL(0, checkPaths(secondString, '+'));
    char* thirdString = "sdfgsfgh";
    ASSERT_EQUAL(1, checkPaths(thirdString, '+'));
}
CTEST(INPUT_CHECK, CHECK_NAME_FILE)
{
    char* firstString
            = "abc/"
              "test.c+C:"
              "\\abcdefghijklmnopqrstuvwxyz\\abcdefghijklmnopqrstuvwxyz\\hello."
              "c";
    ASSERT_EQUAL(0, checkNameFile(firstString, '+'));
    char* secondString
            = "abc/"
              "test.c+C:"
              "\\abcdefghijklmnopqrstuvwxyz\\abcdefghijklmnopqrstuvwxyz\\"
              "abcdefghijklmnopqrstuvwxyz\\abcdefghijklmnopqrstuvwxyz\\"
              "abcdefghijklmnopqrstuvwxyz\\abcdefghijklmnopqrstuvwxyz\\"
              "abcdefghijklmnopqrstuvwxyz\\abcdefghijklmnopqrstuvwxyz\\"
              "abcdefghijklmnopqrstuvwxyz\\abcdefghijklmnopqrstuvwxyz\\hello.c";
    ASSERT_EQUAL(1, checkNameFile(secondString, '+'));
}
