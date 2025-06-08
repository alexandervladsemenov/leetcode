#include "common.h"

int strStr(string haystack, string needle)
{
    if(haystack.length() < needle.length())
        return -1;
    uint32_t base = 31;
    uint32_t module = 1e9 + 9;
    RollingHash haystack_(base, module, haystack, 0);
    RollingHash needle_(base, module, needle, -1);
    for (size_t i{0}; i < haystack.length() - needle.length() + 1; i++)
    {
        size_t end = i + needle.length() - 1;
        long long hash_substr_haystack;
        if (i > 0)
            hash_substr_haystack = (haystack_(end) + module - haystack_(i - 1)) % module;
        else
            hash_substr_haystack = haystack_(end);
        long long hash_needle = needle_(i);
        if(hash_needle == hash_substr_haystack)
            return i;
        // std::cout << i << " " << end << " " << hash_needle << " " << hash_substr_haystack << "\n";
    }
    return -1;
}

int main()
{
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    std::cout << strStr(haystack, needle);
    return 0;
}