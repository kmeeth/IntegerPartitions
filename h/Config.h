#ifndef PARTITIONSGENERATION_CONFIG_H
#define PARTITIONSGENERATION_CONFIG_H
#include <atomic>

class Config
{
public:
    static std::atomic<int> threads;
    static bool cache;
};

#endif //PARTITIONSGENERATION_CONFIG_H
