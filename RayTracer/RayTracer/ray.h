#include<iostream>
#include"vec3.h"

class ray {
public:
	Vec3 a, b;

	ray(){}
	ray(const Vec3& v1, const Vec3& v2) { a = v1; b = v2; }
	Vec3 origin() const { return a; }
	Vec3 direction() const { return b; }
	Vec3 point_at_parameter(float t) const { return a + t * b; }
};
