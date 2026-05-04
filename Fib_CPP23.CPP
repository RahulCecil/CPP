#include <iostream>
#include <generator> // C++23
#include <ranges>

// A coroutine that yields Fibonacci numbers indefinitely
std::generator<uint64_t> fibonacci() {
    uint64_t a = 0;
    uint64_t b = 1;
    while (true) {
        co_yield a;
        auto next = a + b;
        a = b;
        b = next;
    }
}

int main() {
    // We take only the first 10 numbers from the infinite sequence
    for (auto val : fibonacci() | std::views::take(10)) {
        std::cout << val << " ";
    }
    
    return 0;
}
