#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename type> inline bool IsInBetween(const type& num, const type& start, const type& end) {
    return start < num&& num < end;
}

