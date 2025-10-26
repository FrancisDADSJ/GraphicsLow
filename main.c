#include <stdio.h>
#include "Transformation.h"
#include "shape_types.h"

triangle prism [8] =
{
     // Front face
     { {{0.0,0.0,0.0,1.0}, {0.8,0.0,0.0,1.0}, {0.4,0.8,0.0,1.0}}, {255, 255, 255} },

     // Back face
     { {{0.0,0.0,0.6,1.0}, {0.8,0.0,0.6,1.0}, {0.4,0.8,0.6,1.0}}, {255, 255, 255} },

     // LSide face 1
     { {{0.0,0.0,0.0,1.0}, {0.0,0.0,0.6,1.0}, {0.4,0.8,0.0,1.0}}, {255, 255, 255} },

     // LSide face 2
     { {{0.4,0.8,0.0,1.0}, {0.4,0.8,0.6,1.0}, {0.0,0.0,0.6,1.0}}, {255, 255, 255} },

     // RSide face 1
     { {{0.8,0.0,0.0,1.0}, {0.8,0.0,0.6,1.0}, {0.4,0.8,0.0,1.0}}, {255, 255, 255} },

     // RSide face 2
     { {{0.4,0.8,0.0,1.0}, {0.4,0.8,0.6,1.0}, {0.8,0.0,0.6,1.0}}, {255, 255, 255} },

     // BSide face 1
     { {{0.0,0.0,0.0,1.0}, {0.8,0.0,0.0,1.0}, {0.0,0.0,0.6,1.0}}, {255, 255, 255} },

     // BSide face 2
     { {{0.0,0.0,0.6,1.0}, {0.8,0.0,0.6,1.0}, {0.8,0.0,0.0,1.0}}, {255, 255, 255} }
};

int main(){
// Identity Matrix as base
float  transform_array[4][4] =
{
                                {1.0f,0.0,0.0,0.0},
                                {0.0,1.0f,0.0,0.0},
                                {0.0,0.0,1.0f,0.0},
                                {0.0,0.0,0.0,1.0f}
};

// Points to the first element
float *ta_ptr              = &transform_array[0][0];
triangle *prism_ptr = &prism[0];

int prism_size = sizeof(prism)/(sizeof(prism[0]));

scale(ta_ptr, 5.0f, 3.0f, 4.0f);
rotate_x(ta_ptr,0.5f);
rotate_y(ta_ptr,0.2f);
rotate_z(ta_ptr,0.1f);
translate(ta_ptr,2.0 ,2.0 ,2.0);

transform(ta_ptr, prism_ptr, prism_size);

for (int i = 0; i < (sizeof(prism)/sizeof(prism[0])); i++){

    for(int j = 0;j < 3;j++){
        printf("%f %f %f %f\n", prism[i].vertices[j][0], prism[i].vertices[j][1], prism[i].vertices[j][2], prism[i].vertices[j][3]);
    }
    printf("\n\n");
}

return 0;
}
