#ifndef PARTITIONSGENERATION_CONFIG_H
#define PARTITIONSGENERATION_CONFIG_H
#include <atomic>

class Config
{
public:
    static constexpr int maxBatch = 128;
    static std::atomic<int> threads;
    static bool cache;
};

#endif //PARTITIONSGENERATION_CONFIG_H
