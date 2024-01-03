#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

const int IMAGE_WIDTH = 256;
const int IMAGE_HEIGHT = 256;
const int DATA_SIZE = IMAGE_HEIGHT * IMAGE_WIDTH * 3;
using color = vec3;

void write_color(std::ostream& out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

void write_color_to_array(char (&data)[DATA_SIZE], int dataInd, color pixel_color) {
    data[dataInd + 0] = static_cast<int>(255.999 * pixel_color.x());
    data[dataInd + 1] = static_cast<int>(255.999 * pixel_color.y());
    data[dataInd + 2] = static_cast<int>(255.999 * pixel_color.z());
}

#endif