#include <iostream>
#include <memory_resource>
#include <vector>
#include <map>

int main()
{
    std::cout << "Cup Cake" << std::endl;
    int buffer[64] = {};
    std::pmr::monotonic_buffer_resource pool{std::data(buffer), std::size(buffer)};
    std::pmr::map<int, int> squares{ &pool };
    std::map<int, int> squaresm;

    for(int idx = 1; idx <= 164; ++idx)
    {
        squares[idx] = idx*idx;
        squaresm[idx] = idx*idx;
    }


    for(auto& v : squares)
    {
        std::cout << v.first << "->" << v.second << std::endl;
    }

    std::cout << "*************************************************************************" << std::endl;
    return 0;
}

