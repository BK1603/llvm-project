//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// REQUIRES: locale.en_US.UTF-8
// REQUIRES: locale.fr_FR.UTF-8

// <locale>

// template <class charT> class numpunct_byname;

// char_type decimal_point() const;

#include <locale>
#include <cassert>

#include "platform_support.h" // locale name macros

int main()
{
    {
        std::locale l("C");
        {
            typedef char C;
            const std::numpunct<C>& np = std::use_facet<std::numpunct<C> >(l);
            assert(np.decimal_point() == '.');
        }
        {
            typedef wchar_t C;
            const std::numpunct<C>& np = std::use_facet<std::numpunct<C> >(l);
            assert(np.decimal_point() == L'.');
        }
    }
    {
        std::locale l(LOCALE_en_US_UTF_8);
        {
            typedef char C;
            const std::numpunct<C>& np = std::use_facet<std::numpunct<C> >(l);
            assert(np.decimal_point() == '.');
        }
        {
            typedef wchar_t C;
            const std::numpunct<C>& np = std::use_facet<std::numpunct<C> >(l);
            assert(np.decimal_point() == L'.');
        }
    }
    {
        std::locale l(LOCALE_fr_FR_UTF_8);
        {
            typedef char C;
            const std::numpunct<C>& np = std::use_facet<std::numpunct<C> >(l);
            assert(np.decimal_point() == ',');
        }
        {
            typedef wchar_t C;
            const std::numpunct<C>& np = std::use_facet<std::numpunct<C> >(l);
            assert(np.decimal_point() == L',');
        }
    }
}
