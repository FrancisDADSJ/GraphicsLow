#include <stdio.h>
#include <math.h>
void scale(float *ta_ptr, float sf_x,float sf_y, float sf_z);


int main(){

float  transform_array[4][4] =
{
                                {1.0,0.0,0.0,0.0},
                                {0.0,1.0,0.0,0.0},
                                {0.0,0.0,1.0,0.0},
                                {0.0,0.0,0.0,1.0}

};
float *ta_ptr = &transform_array[0][0];

scale(ta_ptr, 5.0, 3.0, 4.0);

for(int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
        printf(" %f\t",transform_array[i][j]);
    }
    printf("\n");
}

return 0;
}


// Scale: general function for indenpendent axis scaling of a 3D homogeneous coordinate system.
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
    // Row 1
    *(ta_ptr+1) = (*(ta_ptr+1) * cosf(angle_rad)) - (*(ta_ptr+2) * sinf(angle_rad));
    *(ta_ptr+2) = (*(ta_ptr+1) * sinf(angle_rad)) + (*(ta_ptr+2) * cosf(angle_rad));

    // Row 2
    *(ta_ptr+5) = (*(ta_ptr+5) * cosf(angle_rad)) - (*(ta_ptr+6) * sinf(angle_rad));
    *(ta_ptr+6) = (*(ta_ptr+5) * sinf(angle_rad)) + (*(ta_ptr+6) * cosf(angle_rad));

    // Row 3
    *(ta_ptr+9) = (*(ta_ptr+9) * cosf(angle_rad)) - (*(ta_ptr+10) * sinf(angle_rad));
    *(ta_ptr+10) = (*(ta_ptr+9) * sinf(angle_rad)) + (*(ta_ptr+10) * cosf(angle_rad));

    // Row 4
    *(ta_ptr+13) = (*(ta_ptr+1) * cosf(angle_rad)) - (*(ta_ptr+2) * sinf(angle_rad));
    *(ta_ptr+14) = (*(ta_ptr+1) * sinf(angle_rad)) + (*(ta_ptr+2) * cosf(angle_rad));
}

void rotate_y(float *ta_ptr, float angle_rad){

}

void rotate_z(float *ta_ptr, float angle_rad){

}

void translate(){

}
