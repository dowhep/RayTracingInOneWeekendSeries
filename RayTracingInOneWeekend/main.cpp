#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS 
#include "stb_image_write.h"

// Image
const int image_width = 256;
const int image_height = 256;
char data[image_height * image_width * 3];

int main() {



    // Render

    //std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            int dataInd = j * image_width * 3 + i * 3;

            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            data[dataInd + 0] = ir;
            data[dataInd + 1] = ig;
            data[dataInd + 2] = ib;

            //std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    stbi_write_png("result.png", image_width, image_height, 3, data, image_width * 3);
}