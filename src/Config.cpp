#include "h/Config.h"

bool Config::cache = false;
std::atomic<int> Config::threads = 1;