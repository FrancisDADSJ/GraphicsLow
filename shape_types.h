#ifndef SHAPE_TYPES_H_
#define SHAPE_TYPES_H_

#include <stdint.h>


struct triangle{
    // Triangle vertices x, y, z axis with w scaling factor
    float vertices[3][4];
    // RGB colour array RGB from index 0 to 2
    uint8_t colour[3];
};

#endif
