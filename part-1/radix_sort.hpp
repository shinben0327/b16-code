#ifndef __radix_sort__
#define __radix_sort__

#include <algorithm>
#include <limits>
#include <queue>

template <typename I>
static constexpr int num_digits_v =
    std::numeric_limits<typename I::value_type>::digits;

// ! Not working.

template <typename I>
void radix_sort(const I &begin, const I &end, int digit = num_digits_v<I>)
{
    if (digit < 0) return;

    std::queue<int> q0;
    std::queue<int> q1;

    for (auto it = begin; it != end; ++it) {
        if ((*it >> digit) & 1)
            q1.push(*it);
        else
            q0.push(*it);
    }

    auto it = begin;
    while (!q0.empty()) {
        *it++ = q0.front();
        q0.pop();
    }
    while (!q1.empty()) {
        *it++ = q1.front();
        q1.pop();
    }

    radix_sort(begin, end, digit - 1);
}

#endif // __radix_sort__