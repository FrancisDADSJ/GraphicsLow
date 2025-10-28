#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_
#include "shape_types.h"

/*
 * scale: function scales a 3D vector in its homogeneous coordinates form
 * enabling independent axis [x,y,z] scaling.
 * In case no scaling is needed for a particular axis, parametise it as 1.0.
 */
void scale(float *ta_ptr, float sf_x,float sf_y, float sf_z);

/*
 * rotate_x: function rotates a 3D vector in its homogeneous coordinates form
 * about the x axis.
 */
void rotate_x(float *ta_ptr, float angle_rad);

/*
 * rotate_y: function rotates a 3D vector in its homogeneous coordinates form
 * about the y axis.
 */
void rotate_y(float *ta_ptr, float angle_rad);

/*
 * rotate_z: function rotates a 3D vector in its homogeneous coordinates form
 * about the z axis.
 */
void rotate_z(float *ta_ptr, float angle_rad);

/*
 * translate: function translates 3D vector in its homogeneous coordinate form
 * from the x, y, and z axis.
 * In case no translation is needed for a particular axis, parametise it as 0.0.
 */
void translate(float *ta_ptr, float t_x, float t_y, float t_z);

/*
 * change_perspective: transforms model into perspective projection with distance from view plane.
 */
void change_perspective(float *ta_ptr,float vp_distance);

/*
 * change_view: transforms model so to fit a viewing model so that is normal to z vertex.
 * origin is the vector from the world coordinate origin to the view point.
 * rv_angle is the angle between the z axis and the origin vector.
 * lv_angle is the angle between the x axis and the horizontal component (relative to world central coordinate) of origin vector.
 */
void change_view(float *ta_ptr,float lv_angle, float rv_angle, float origin);

/*
 * Normalise the model to fit Normalised device coordinates.
 */
void normalise(triangle *polygon, int p_size);

/*
 * transform: applies combined transformation to polygons.
 */
void transform(float *ta_ptr, triangle *polygon, int p_size);

#endif
