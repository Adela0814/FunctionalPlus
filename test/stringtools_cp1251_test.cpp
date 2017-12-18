// Copyright 2015, Tobias Hermann and the FunctionalPlus contributors.
// https://github.com/Dobiasd/FunctionalPlus
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fplus/fplus.hpp>


TEST_CASE("stringtools_test, to_lower/upper_case, cp1251")
{
    using namespace fplus;
    const std::locale loc_cp1251 {
#ifdef WIN32
        "ru-RU"
#else
        "ru_RU.cp1251"
#endif
    };
    REQUIRE_EQ(to_lower_case(std::string("cYrIlLiC 123&? ���������"), loc_cp1251), std::string("cyrillic 123&? ���������"));
    REQUIRE_EQ(to_lower_case(std::string("�����Ũ��������������������������"), loc_cp1251), std::string("��������������������������������"));

    REQUIRE_EQ(to_upper_case(std::string("cYrIlLiC 123&? ���������"), loc_cp1251), std::string("CYRILLIC 123&? ���������"));
    REQUIRE_EQ(to_upper_case(std::string("��������������������������������"), loc_cp1251), std::string("�����Ũ��������������������������"));
}