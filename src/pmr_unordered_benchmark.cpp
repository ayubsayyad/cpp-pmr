#include <vector>
#include <unordered_map>
#include <array>
#include <chrono>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <memory_resource>


int main()
{

    std::array<std::byte, 50000 * 32> buffer; // enough to fit in all nodes
    std::pmr::monotonic_buffer_resource mbr{buffer.data(), buffer.size()};
    std::pmr::polymorphic_allocator<int> pa{&mbr};
    std::pmr::unordered_map<int, int> map{pa};
    unsigned elementCount = 5;

    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    while (elementCount <= 80)
    {
        elementCount *= 2;
        std::vector<unsigned int> tmp;
        auto val = std::rand()%50000;
        map.insert(std::make_pair(val, 1));
    }

    auto tp0 = std::chrono::high_resolution_clock::now() - start;
    double vTime = double(std::chrono::duration_cast<std::chrono::nanoseconds>(tp0).count());

    std::cout << vTime << std::endl;

    return 0;
}
