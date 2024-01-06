#include "rtweekend.h"

#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS 
#include "stb_image_write.h"

// Image
char data[DATA_SIZE];

int main() {
    // World
    hittable_list world;

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    camera cam;

    cam.samples_per_pixel = 100;
    cam.max_depth = 50;

    cam.render(world, data);

    stbi_write_png("result.png", IMAGE_WIDTH, IMAGE_HEIGHT, 3, data, IMAGE_WIDTH * 3);
}