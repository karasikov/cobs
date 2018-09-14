#pragma once

#include <cstdlib>
#include <fstream>
#include <ctime>

namespace cobs {
    uint64_t get_page_size();

    template<class T>
    auto operator<<(std::ostream& os, const T& t) -> decltype(t.print(os), os);
    std::string random_sequence(size_t len, size_t seed = std::time(0));
    void initialize_map();
    void initialize_map_server();

    template<typename T>
    T* allocate_aligned(uint64_t size, size_t alignment);
    void deallocate_aligned(void* ptr);
}


namespace cobs {
    template<class T>
    auto operator<<(std::ostream& os, const T& t) -> decltype(t.print(os), os) {
        t.print(os);
        return os;
    }

    template<typename T>
    T* allocate_aligned(uint64_t size, size_t alignment) {
        T* ptr;
        int r = posix_memalign(reinterpret_cast<void**>(&ptr), alignment, sizeof(T) * size);
        if (r != 0)
            throw std::runtime_error("Out of memory");
        std::fill(ptr, ptr + size, 0);
        return ptr;
    }
}
