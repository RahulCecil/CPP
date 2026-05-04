#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    int n = 10;
    std::vector<uint64_t> fib(n);
    
    if (n > 0) fib[0] = 0;
    if (n > 1) fib[1] = 1;

    // Use an algorithm to fill the rest
    for (int i = 2; i < n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Modern functional-style printing
    std::ranges::copy(fib, std::ostream_iterator<uint64_t>(std::cout, " "));

    return 0;
}
