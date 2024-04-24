#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>

template <typename T>
inline T random_value()
{
    if constexpr (std::is_same<T, int32_t>::value)
    {
        return std::rand();
    }
    else
    {
        return static_cast<T>(std::rand()) / RAND_MAX;
    }
}

// Generate a randomly sorted array of values 0-(n-1).
inline std::vector<perfSpB_index> generate_a_random_index(
    perfSpB_index n)
{
    std::vector<perfSpB_index> a;
    std::random_device rd;
    std::mt19937 g(rd());

    for (perfSpB_index i = 0; i < n; ++i)
    {
        a.push_back((perfSpB_index)i);
    }
    std::shuffle(a.begin(), a.end(), g);
    return a;
}

inline std::vector<perfSpB_index> generate_index(
    perfSpB_index n)
{
    std::vector<perfSpB_index> a;

    for (perfSpB_index i = 0; i < n; ++i)
    {
        a.push_back((perfSpB_index)i);
    }

    return a;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
generate_random_number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dist(0.0, 1.0);
    return dist(gen);
}

// 生成整数类型随机数
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
generate_random_number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> dist(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    return dist(gen);
}
