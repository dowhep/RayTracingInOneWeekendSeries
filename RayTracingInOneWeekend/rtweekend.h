#ifndef RTWEEKEND_H
#define RTWEEKEND_H

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// configs

const int IMAGE_WIDTH = 400;
const int IMAGE_HEIGHT = 225;
const float ASPECT_RATIO = 1.0f * IMAGE_WIDTH / IMAGE_HEIGHT;
const int DATA_SIZE = IMAGE_HEIGHT * IMAGE_WIDTH * 3;

// Constants

const float infinity = std::numeric_limits<float>::infinity();
const float pi = 3.1415926535897932385f;

// Utility Functions

inline float degrees_to_radians(float degrees) {
    return degrees * pi / 180.0f;
}

inline float random_float() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0f);
}

inline float random_float(float min, float max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_float();
}

// Common Headers

#include "ray.h"
#include "vec3.h"
#include "interval.h"

#endif