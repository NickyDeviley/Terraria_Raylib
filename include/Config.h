#include <chrono>
#include <stdint.h>

#ifndef CONFIG_H
#define CONFIG_H

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define FPS 60
#define UPS 120
#define ONE_NANOSECOND 1000000000

#define nanoSec std::chrono::nanoseconds

#define internalMethod static

using timePoint = std::chrono::high_resolution_clock::time_point;
using duration = std::chrono::high_resolution_clock::duration;

constexpr nanoSec DELTA_FPS {ONE_NANOSECOND / FPS};
constexpr nanoSec DELTA_UPS {ONE_NANOSECOND / UPS};

#endif