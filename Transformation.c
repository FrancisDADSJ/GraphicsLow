#include <math.h>
#include "shape_types.h"
/*
    Matrix Element

    float a11 = *(ta_ptr);
    float a12 = *(ta_ptr+1);
    float a13 = *(ta_ptr+2);
    float a14 = *(ta_ptr+3);

    float a21 = *(ta_ptr+4);
    float a22 = *(ta_ptr+5);
    float a23 = *(ta_ptr+6);
    float a24 = *(ta_ptr+7);

    float a31 = *(ta_ptr+8);
    float a32 = *(ta_ptr+9);
    float a33 = *(ta_ptr+10);
    float a34 = *(ta_ptr+11);

    float a41 = *(ta_ptr+12);
    float a42 = *(ta_ptr+13);
    float a43 = *(ta_ptr+14);
    float a44 = *(ta_ptr+15);
 */


void scale(float *ta_ptr, float sf_x,float sf_y, float sf_z){

    // Row 1
    *ta_ptr = sf_x * *(ta_ptr);
    *(ta_ptr+1) = sf_y * *(ta_ptr+1);
    *(ta_ptr+2) = sf_z * *(ta_ptr+2);

    // Row 2
    *(ta_ptr+4) = sf_x * *(ta_ptr+4);
    *(ta_ptr+5) = sf_y * *(ta_ptr+5);
    *(ta_ptr+6) = sf_z * *(ta_ptr+6);

    // Row 3
    *(ta_ptr+8) = sf_x * *(ta_ptr+8);
    *(ta_ptr+9) = sf_y * *(ta_ptr+9);
    *(ta_ptr+10) = sf_z * *(ta_ptr+10);

    // Row 4
    *(ta_ptr+12) = sf_x * *(ta_ptr+12);
    *(ta_ptr+13) = sf_y * *(ta_ptr+13);
    *(ta_ptr+14) = sf_z * *(ta_ptr+14);
}


void rotate_x(float *ta_ptr, float angle_rad){

    // Initial matrix working elements' copy
    float a12 = *(ta_ptr+1);
    float a13 = *(ta_ptr+2);

    float a22 = *(ta_ptr+5);
    float a23 = *(ta_ptr+6);

    float a32 = *(ta_ptr+9);
    float a33 = *(ta_ptr+10);

    float a42 = *(ta_ptr+13);
    float a43 = *(ta_ptr+14);

    // Trig values
    float cos_angle = cosf(angle_rad);
    float sin_angle = sinf(angle_rad);

    // Row 1
    *(ta_ptr+1)  = (a12 * cos_angle) - (a13 * sin_angle);
    *(ta_ptr+2)  = (a12 * sin_angle) + (a13 * cos_angle);

    // Row 2
    *(ta_ptr+5)  = (a22 * cos_angle) - (a23 * sin_angle);
    *(ta_ptr+6)  = (a22 * sin_angle) + (a23 * cos_angle);

    // Row 3
    *(ta_ptr+9)  = (a32 * cos_angle) - (a33 * sin_angle);
    *(ta_ptr+10) = (a32 * sin_angle) + (a33 * cos_angle);

    // Row 4
    *(ta_ptr+13) = (a42 * cos_angle) - (a43 * sin_angle);
    *(ta_ptr+14) = (a42 * sin_angle) + (a43 * cos_angle);
}

void rotate_y(float *ta_ptr, float angle_rad){

    // Initial matrix working elements' copy
    float a11 = *(ta_ptr);
    float a13 = *(ta_ptr+2);

    float a21 = *(ta_ptr+4);
    float a23 = *(ta_ptr+6);

    float a31 = *(ta_ptr+8);
    float a33 = *(ta_ptr+10);

    float a41 = *(ta_ptr+12);
    float a43 = *(ta_ptr+14);

    // Trig values
    float cos_angle = cosf(angle_rad);
    float sin_angle = sinf(angle_rad);

    // Row 1
    *ta_ptr     = (a11 * cos_angle) + (a13 * sin_angle);
    *(ta_ptr+2) = (a13 * cos_angle) - (a11 * cos_angle);

    // Row 2
    *(ta_ptr+4) = (a21 *cos_angle) + (a23 * sin_angle);
    *(ta_ptr+6) = (a23 *cos_angle) - (a21 *sin_angle);

    // Row 3
    *(ta_ptr+8)  = (a31 *cos_angle) + (a33 * sin_angle);
    *(ta_ptr+10) = (a33 *cos_angle) - (a31 *sin_angle);

    // Row 4
    *(ta_ptr+12) = (a41 *cos_angle) + (a43 * sin_angle);
    *(ta_ptr+14) = (a43 *cos_angle) - (a41 *sin_angle);
}

void rotate_z(float *ta_ptr, float angle_rad){

    // Initial matrix working elements' copy
    float a11 = *(ta_ptr);
    float a12 = *(ta_ptr+1);

    float a21 = *(ta_ptr+4);
    float a22 = *(ta_ptr+5);

    float a31 = *(ta_ptr+8);
    float a32 = *(ta_ptr+9);

    float a41 = *(ta_ptr+12);
    float a42 = *(ta_ptr+13);

    // Trig values
    float cos_angle = cosf(angle_rad);
    float sin_angle = sinf(angle_rad);

    // Row 1
    *ta_ptr      = (a11 * cos_angle) - (a12 * sin_angle);
    *(ta_ptr+1)  = (a11 * sin_angle) + (a12 *cos_angle);

    // Row 2
    *(ta_ptr+4)  = (a21 * cos_angle) - (a22 * sin_angle);
    *(ta_ptr+5)  = (a21 * sin_angle) + (a22 *cos_angle);

    // Row 3
    *(ta_ptr+8)  = (a31 * cos_angle) - (a32 * sin_angle);
    *(ta_ptr+9)  = (a31 * sin_angle) + (a32 *cos_angle);

    // Row 4
    *(ta_ptr+12)  = (a41 * cos_angle) - (a42 * sin_angle);
    *(ta_ptr+13)  = (a41 * sin_angle) + (a42 *cos_angle);

}

void translate(float *ta_ptr, float t_x, float t_y, float t_z){
    *(ta_ptr + 12) = *(ta_ptr+12) + t_x;
    *(ta_ptr + 13) = *(ta_ptr+13) + t_y;
    *(ta_ptr + 14) = *(ta_ptr+14) + t_z;
}

void change_perspective(float *ta_ptr,float vp_distance){
    *(ta_ptr+3) = *(ta_ptr+2) / vp_distance;
    *(ta_ptr+7) = *(ta_ptr+6) / vp_distance;
    *(ta_ptr+11) = *(ta_ptr+10) / vp_distance;
    *(ta_ptr+15) = *(ta_ptr+15) / vp_distance;
}

void change_view(float *ta_ptr,float lv_angle, float rv_angle, float origin){
    float a11 = *(ta_ptr);
    float a12 = *(ta_ptr+1);
    float a13 = *(ta_ptr+2);
    float a14 = *(ta_ptr+3);

    float a21 = *(ta_ptr+4);
    float a22 = *(ta_ptr+5);
    float a23 = *(ta_ptr+6);
    float a24 = *(ta_ptr+7);

    float a31 = *(ta_ptr+8);
    float a32 = *(ta_ptr+9);
    float a33 = *(ta_ptr+10);
    float a34 = *(ta_ptr+11);

    float a41 = *(ta_ptr+12);
    float a42 = *(ta_ptr+13);
    float a43 = *(ta_ptr+14);
    float a44 = *(ta_ptr+15);

    // Row 1
    *ta_ptr      = (a12 * cosf(lv_angle)) - (a11 * sinf(lv_angle));
    *(ta_ptr+1)  = (a13 * sinf(rv_angle)) - (a11 * cosf(lv_angle) * cosf(rv_angle)) - (a12 * sinf(lv_angle) * cosf(rv_angle));
    *(ta_ptr+2)  = (a14 * origin) - (a13 * cosf(rv_angle) - (a12 * sinf(lv_angle) * sinf(rv_angle)) - (a11 * cosf(lv_angle) * sinf(rv_angle)));

    // Row 2
    *(ta_ptr+4)  = (a22 * cosf(lv_angle)) - (a21 * sinf(lv_angle));
    *(ta_ptr+5)  = (a23 * sinf(rv_angle)) - (a21 * cosf(lv_angle) * cosf(rv_angle)) - (a22 * sinf(lv_angle) * cosf(rv_angle));
    *(ta_ptr+6)  = (a24 * origin) - (a23 * cosf(rv_angle) - (a22 * sinf(lv_angle) * sinf(rv_angle)) - (a21 * cosf(lv_angle) * sinf(rv_angle)));

    // Row 3
    *(ta_ptr+8)   = (a32 * cosf(lv_angle)) - (a31 * sinf(lv_angle));
    *(ta_ptr+9)  = (a33 * sinf(rv_angle)) - (a31 * cosf(lv_angle) * cosf(rv_angle)) - (a32 * sinf(lv_angle) * cosf(rv_angle));
    *(ta_ptr+10)  = (a34 * origin) - (a33 * cosf(rv_angle) - (a32 * sinf(lv_angle) * sinf(rv_angle)) - (a31 * cosf(lv_angle) * sinf(rv_angle)));

    // Row 4
    *(ta_ptr+12)  = (a42 * cosf(lv_angle)) - (a41 * sinf(lv_angle));
    *(ta_ptr+13)  = (a43 * sinf(rv_angle)) - (a41 * cosf(lv_angle) * cosf(rv_angle)) - (a42 * sinf(lv_angle) * cosf(rv_angle));
    *(ta_ptr+14)  = (a44 * origin) - (a43 * cosf(rv_angle) - (a42 * sinf(lv_angle) * sinf(rv_angle)) - (a41 * cosf(lv_angle) * sinf(rv_angle)));
}

void normalise(triangle *polygon, int p_size){

    for (int i = 0; i < p_size; i++){

    for(int j = 0;j < 3;j++){

        polygon[i].vertices[j][0] = polygon[i].vertices[j][0] / polygon[i].vertices[j][3];

        polygon[i].vertices[j][1]= polygon[i].vertices[j][1] / polygon[i].vertices[j][3];

        polygon[i].vertices[j][2]= polygon[i].vertices[j][2] / polygon[i].vertices[j][3];

    }
}

}

void transform(float *ta_ptr, triangle *polygon, int p_size){

for (int i = 0; i < p_size; i++){

        for(int j = 0;j < 3;j++){

        polygon[i].vertices[j][0] = polygon[i].vertices[j][0] * *(ta_ptr) +
                                    polygon[i].vertices[j][1] * *(ta_ptr+4) +
                                    polygon[i].vertices[j][2] * *(ta_ptr+8) +
                                    polygon[i].vertices[j][3] * *(ta_ptr+12);

        polygon[i].vertices[j][1]=  polygon[i].vertices[j][0] * *(ta_ptr+1) +
                                    polygon[i].vertices[j][1] * *(ta_ptr+5) +
                                    polygon[i].vertices[j][2] * *(ta_ptr+9) +
                                    polygon[i].vertices[j][3] * *(ta_ptr+13);

        polygon[i].vertices[j][2]=  polygon[i].vertices[j][0] * *(ta_ptr+2) +
                                    polygon[i].vertices[j][1] * *(ta_ptr+6) +
                                    polygon[i].vertices[j][2] * *(ta_ptr+10)+
                                    polygon[i].vertices[j][3] * *(ta_ptr+14);

        polygon[i].vertices[j][3]=  polygon[i].vertices[j][0] * *(ta_ptr+3) +
                                    polygon[i].vertices[j][1] * *(ta_ptr+7) +
                                    polygon[i].vertices[j][2] * *(ta_ptr+11)+
                                    polygon[i].vertices[j][3] * *(ta_ptr+15);
    }
}
}





