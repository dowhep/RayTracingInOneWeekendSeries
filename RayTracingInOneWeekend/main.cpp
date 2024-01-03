#include "color.h"
#include "vec3.h"

#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS 
#include "stb_image_write.h"

// Image
char data[DATA_SIZE];

int main() {



    // Render

    //std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < IMAGE_HEIGHT; ++j) {
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            int dataInd = j * IMAGE_WIDTH * 3 + i * 3;

            auto pixel_color = color(double(i) / (IMAGE_WIDTH - 1), double(j) / (IMAGE_HEIGHT - 1), 0);
            write_color_to_array(data, dataInd, pixel_color);
            //std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    stbi_write_png("result.png", IMAGE_WIDTH, IMAGE_HEIGHT, 3, data, IMAGE_WIDTH * 3);
}