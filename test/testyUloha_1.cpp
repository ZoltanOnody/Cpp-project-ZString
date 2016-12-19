// Copyright 2005, Google Inc.
// All rights reserved.

// todo remove
#include <iostream>


#include "gtest/gtest.h"
#include "../src/riesenie.h"
#include <sstream>

using namespace ::testing;

//Uloha 1.
TEST_F(Test, EmptyClassDeclaration) {
    ZString s;
    ASSERT_EQ(0, s.length());
    ASSERT_STREQ("", s.value());
}

TEST_F(Test, ClassDeclaration) {
    ZString s("four");
    ASSERT_EQ(4, s.length());
    ASSERT_STREQ("four", s.value());
}

TEST_F(Test, AccessOperatorSquareBracket) {
    ZString s("ab");
    ASSERT_EQ(s[0], 'a');
    ASSERT_EQ(s[1], 'b');

    try {
        s[2];
        FAIL() << "Expected std::out_of_range";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("Index out of range!"));
    }
    catch(...) {
        FAIL() << "Expected std::out_of_range";
    }
}

TEST_F(Test, ConcatZStrings) {
    ZString s1("AB");
    ZString s2("CD");

    ZString tmp = s1 + s2;
    ASSERT_STREQ(tmp.value(), "ABCD");

    ZString s3;
    ASSERT_STREQ((tmp + s3).value(), "ABCD");
}

TEST_F(Test, AppendZStrings) {
    ZString s1("AB");
    ZString s2("CD");

    s1 += s2;
    ASSERT_STREQ(s1.value(), "ABCD");
}

TEST_F(Test, MultiplyZStrings) {
    ZString s("AB");
    ASSERT_STREQ((s * 0).value(), "");
    ASSERT_STREQ((s * 1).value(), "AB");
    ASSERT_STREQ((s * 3).value(), "ABABAB");

    try {
        s * -1;
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_EQ(err.what(), std::string("Multiplication cannot be negative!"));
    }
    catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    s *= 2;
    ASSERT_STREQ(s.value(), "ABAB");
}

// Uloha 2.
TEST_F(Test, LessZString) {
    ZString s1("AB");
    ZString s2("AC");
    ZString s3("ABC");

    ASSERT_TRUE(s1 < s2);
    ASSERT_TRUE(s1 < s3);

    ASSERT_FALSE(s1 < s1);
    ASSERT_FALSE(s2 < s3);
    ASSERT_FALSE(s3 < s1);
}

TEST_F(Test, GreaterZString) {
    ZString s1("AB");
    ZString s2("AC");
    ZString s3("ABC");

    ASSERT_TRUE(s2 > s1);
    ASSERT_TRUE(s3 > s1);

    ASSERT_FALSE(s1 > s1);
    ASSERT_FALSE(s3 > s2);
    ASSERT_FALSE(s1 > s3);
}

TEST_F(Test, EqualZString) {
    ZString s1("AB");
    ZString s2("AC");

    ASSERT_TRUE(s1 == s1);
    ASSERT_FALSE(s1 == s2);
}

TEST_F(Test, LessOrEqualZString) {
    ZString s1("AB");
    ZString s2("AC");

    ASSERT_TRUE(s1 <= s1);
    ASSERT_TRUE(s1 <= s2);

    ASSERT_FALSE(s2 <= s1);
}

TEST_F(Test, GreaterOrEqualZString) {
    ZString s1("AB");
    ZString s2("AC");

    ASSERT_TRUE(s1 >= s1);
    ASSERT_TRUE(s2 >= s1);

    ASSERT_FALSE(s1 >= s2);
}

TEST_F(Test, NotEqualZString) {
    ZString s1("AB");
    ZString s2("AC");

    ASSERT_TRUE(s1 != s2);
    ASSERT_FALSE(s1 != s1);
}

// Uloha 3.

TEST(Test, IsDigit) {
    ZString s1("01012");
    ZString s2("01012a");

    ASSERT_TRUE(s1.isdigit());
    ASSERT_FALSE(s2.isdigit());
}

TEST(Test, IsAlnum) {
    ZString s1("AZaz09");
    ZString s2("AZaz09_");

    ASSERT_TRUE(s1.isalnum());
    ASSERT_FALSE(s2.isalnum());
}

TEST(Test, IsAlpha) {
    ZString s1("AZaz");
    ZString s2("AZaz0");

    ASSERT_TRUE(s1.isalpha());
    ASSERT_FALSE(s2.isalpha());
}

TEST(Test, IsLower) {
    ZString s1("hellow world, i'm lower!");
    ZString s2("Nope,...");

    ASSERT_TRUE(s1.islower());
    ASSERT_FALSE(s2.islower());
}

TEST(Test, IsUpper) {
    ZString s1("I'M UPPER!");
    ZString s2("BUT i AM NOT");

    ASSERT_TRUE(s1.isupper());
    ASSERT_FALSE(s2.isupper());
}

TEST(Test, IsPrintable) {
    ZString s1(
            "'0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&\\'()*+,-./:;<=>?@[\\\\]^_`{|}~ \\t\\n\\r\\x0b\\x0c'");
    ZString s2("\a");

    ASSERT_TRUE(s1.isprintable());
    ASSERT_FALSE(s2.isprintable());
}

TEST(Test, IsSpace) {
    ZString s1(" \\t\\n\\r\\x0b\\x0c");
    ZString s2("    .");

    ASSERT_TRUE(s1.isspace());
    ASSERT_FALSE(s2.isspace());
}

// Uloha 4
TEST(Test, Index) {
    ZString s("Hi, how do you do Hillary?");
    ZString sub("Hi");

    ASSERT_EQ(s.index(sub), 0);
    ASSERT_EQ(s.index(sub, 0), 0);
    ASSERT_EQ(s.index(sub, 1), 18);

    try {
        s.index(sub, 20);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_EQ(err.what(), std::string("Substring not found!"));
    }
    catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    ASSERT_EQ(s.index(sub, 0, 2), 0);
    try {
        s.index(sub, 0, 1);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_EQ(err.what(), std::string("Substring not found!"));
    }
    catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(Test, RIndex) {
    ZString s("Hi, how do you do Hillary?");
    ZString sub("Hi");

    ASSERT_EQ(s.rindex(sub), 18);
    ASSERT_EQ(s.rindex(sub, 0), 18);
    ASSERT_EQ(s.rindex(sub, 1), 18);
    ASSERT_EQ(s.rindex(sub, 0, 10), 0);

    try {
        s.rindex(sub, 1, 10);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_EQ(err.what(), std::string("Substring not found!"));
    }
    catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    ASSERT_EQ(s.rindex(sub, 0, 2), 0);
    try {
        s.rindex(sub, 0, 1);
        FAIL() << "Expected std::invalid_argument";
    }
    catch (std::invalid_argument const &err) {
        EXPECT_EQ(err.what(), std::string("Substring not found!"));
    }
    catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }

    // regression test
    ZString s2("Hi, how do you do Hillary? hmmmmm....");
    ZString sub2("...");
    ASSERT_EQ(s2.rindex(sub2), 34);

}

TEST(Test, Reverse) {
    ZString s1("Howdy");
    s1.reverse();

    ASSERT_STREQ(s1.value(), "ydwoH");
}


TEST(Test, Find) {
    ZString s("Hi, how do you do Hillary?");
    ZString sub1("Hi");
    ZString sub2("Trumptadada");

    ASSERT_EQ(s.find(sub1), 0);
    ASSERT_EQ(s.find(sub1, 0), 0);
    ASSERT_EQ(s.find(sub1, 1), 18);
    ASSERT_EQ(s.find(sub2), -1);
}

TEST(Test, RFind) {
    ZString s("Hi, how do you do Hillary?");
    ZString sub1("Hi");
    ZString sub2("Trumptadada");

    ASSERT_EQ(s.rfind(sub1), 18);
    ASSERT_EQ(s.rfind(sub1, 0, 10), 0);
    ASSERT_EQ(s.rfind(sub2), -1);
}

TEST(Test, Count) {
    ZString s("Hi, how do you do Hillary? hmmmmm...");
    ZString sub1("Hi");
    ZString sub2("Trumptadada");
    ZString sub3("mm");

    ASSERT_EQ(s.count(sub1), 2);
    ASSERT_EQ(s.count(sub1, 5), 1);
    ASSERT_EQ(s.count(sub1, 0, 10), 1);
    ASSERT_EQ(s.count(sub2), 0);
    ASSERT_EQ(s.count(sub3), 2);
}

TEST(Test, StartsWith) {
    ZString s("Hi, how do you do Hillary? hmmmmm...");
    ZString sub1("Hi");
    ZString sub2("Him");
    ZString sub3("Hillary");
    ZString sub4("hmmmm");

    ASSERT_TRUE(s.startswith(sub1));
    ASSERT_FALSE(s.startswith(sub1, 1));

    ASSERT_FALSE(s.startswith(sub2));

    ASSERT_FALSE(s.startswith(sub3));
    ASSERT_TRUE(s.startswith(sub3, 18));

    ASSERT_TRUE(s.startswith(sub4, 27));
    ASSERT_FALSE(s.startswith(sub4, 27, 30));
}

TEST(Test, EndsWith) {
    ZString s("Hi, how do you do Hillary? hmmmmm...");
    ZString sub1("...");
    ZString sub2("Hillary");
    ZString sub3("hmmmm");

    ASSERT_TRUE(s.endswith(sub1));
    ASSERT_TRUE(s.endswith(sub1, 1));
    ASSERT_FALSE(s.endswith(sub1, 1, 10));

    ASSERT_TRUE(s.endswith(sub2, 0, 25));

    ASSERT_TRUE(s.endswith(sub3, 0, 32));
    ASSERT_FALSE(s.endswith(sub3, 30, 32));
}


TEST(Test, Lower) {
    ZString s("Hi, how Do you Do?!");
    ASSERT_STREQ(s.lower().value(), "hi, how do you do?!");
}

TEST(Test, Upper) {
    ZString s("Hi, how Do you Do?!");
    ASSERT_STREQ(s.upper().value(), "HI, HOW DO YOU DO?!");
}

TEST(Test, OutputReprezentation) {
    ZString s("C++14 is the best!");

    std::stringstream out;
    out << s;

    ASSERT_STREQ(out.str().c_str(), "C++14 is the best!");
}

TEST(Test, Iterable) {
    ZString s("1234");

    int index=0;
    for(char c: s){
        ASSERT_EQ(c, s[index++]);
    }
}

TEST(Test, ReplaceOne) {
    ZString s("The President of US is Obama!");
    ZString what("Obama");
    ZString by("Trump");
    s.replace(what, by);
    ASSERT_STREQ(s.value(), "The President of US is Trump!");
}

TEST(Test, ReplaceNone) {
    ZString s("Programming");
    ZString what("gaming");
    ZString by("");
    s.replace(what, by);
    ASSERT_STREQ(s.value(), "Programming");
}

TEST(Test, ReplaceMore) {
    ZString s("aabbcc");
    ZString what("ab");
    ZString by("");
    s.replace(what, by);
    ASSERT_STREQ(s.value(), "abcc");
}

TEST(Test, ReplaceShorter) {
    ZString s("A!B!C!");
    ZString what("A!");
    ZString by("a");
    s.replace(what, by);
    ASSERT_STREQ(s.value(), "aB!C!");
}

TEST(Test, ReplaceLonger) {
    ZString s("abc");
    ZString what("a");
    ZString by("A!");
    s.replace(what, by);
    ASSERT_STREQ(s.value(), "A!bc");
}

TEST(Test, ReplaceRegressionTest) {
    ZString s("a b a b a b");
    ZString what("a");
    ZString by("#");
    s.replace(what, by);
    ASSERT_STREQ(s.value(), "# b # b # b");
}

TEST(Test, ReplaceFirstTree) {
    ZString s("a b a b a b a b a");
    ZString what("a");
    ZString by("#");
    s.replace(what, by, 3);
    ASSERT_STREQ(s.value(), "# b # b # b a b a");
}


TEST(Test, Zfill) {
    ZString s("1234");
    ASSERT_STREQ(s.zfill(1).value(), "1234");
    ASSERT_STREQ(s.zfill(6).value(), "001234");
}

TEST(Test, Swapcase) {
    ZString s("Swap ... My Case!");
    ASSERT_STREQ(s.swapcase().value(), "sWAP ... mY cASE!");
}

TEST(Test, Center){
    ZString s("Hello");
    ASSERT_STREQ(s.center(2).value(), "Hello");
    ASSERT_STREQ(s.center(10).value(), "  Hello   ");
    ASSERT_STREQ(s.center(9, '#').value(), "##Hello##");
}

TEST(Test, LJust){
    ZString s("Hello");
    ASSERT_STREQ(s.ljust(2).value(), "Hello");
    ASSERT_STREQ(s.ljust(10).value(), "     Hello");
    ASSERT_STREQ(s.ljust(9, '#').value(), "####Hello");
}

TEST(Test, Title){
    ZString s("how do_you_DO?!");
    ASSERT_STREQ(s.title().value(), "How Do_You_Do?!");
}
