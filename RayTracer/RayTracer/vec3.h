#include<iostream>
#include<cmath>
#include <stdlib.h>

class Vec3 {
public:
	float e[3];
	Vec3() {}
	Vec3(float a, float b, float c) { e[0] = a; e[1] = b; e[2] = c; }
	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const Vec3& operator+() const { return *this;}
	inline Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline Vec3 operator+=(const Vec3& v2) {
		e[0] += v2.e[0]; e[1] += v2.e[1]; e[2] += v2.e[2]; return *this;
	}
	inline Vec3 operator-=(const Vec3& v2) {
		e[0] -= v2.e[0]; e[1] -= v2.e[1]; e[2] -= v2.e[2]; return *this;
	}
	inline Vec3 operator*=(const Vec3& v2) {
		e[0] *= v2.e[0]; e[1] *= v2.e[1]; e[2] *= v2.e[2]; return *this;
	}
	inline Vec3 operator/=(const Vec3& v2) {
		e[0] /= v2.e[0]; e[1] /= v2.e[1]; e[2] /= v2.e[2]; return *this;
	}
	inline Vec3 operator*=(const float t) {
		e[0] *= t; e[1] *= t; e[2] *= t; return *this;
	}
	inline Vec3 operator/=(const float t) {
		float k = 1.0 / t;
		e[0] *= k; e[1] *= k; e[2] *= k; return *this;
	}

	

	inline float Length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline float Squared_Length() const { return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline void make_unit_vector();
	
};

inline std::istream& operator>>(std::istream &is, Vec3 &t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}
inline std::ostream& operator<<(std::ostream &os, Vec3 &t) {
	os << t.e[0] << t.e[1] << t.e[2];
	return os;
}
inline Vec3 operator+(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}
inline Vec3 operator-(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}
inline Vec3 operator*(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}
inline Vec3 operator/(const Vec3& v1, const Vec3& v2) {
	return Vec3(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
}
inline Vec3 operator*(const Vec3& v1, float t) {
	return Vec3(v1.e[0] * t, v1.e[1] * t, v1.e[2] * t);
}
inline Vec3 operator/(const Vec3& v1, float t) {
	return Vec3(v1.e[0] / t, v1.e[1] / t, v1.e[2] / t);
}
inline Vec3 operator*(float t, const Vec3& v1) {
	return Vec3(v1.e[0] * t, v1.e[1] * t, v1.e[2] * t);
}
inline Vec3 operator/(float t, const Vec3& v1) {
	return Vec3(t/ v1.e[0], t / v1.e[1], t / v1.e[1]);
}
inline float dot(const Vec3& v1, const Vec3& v2) {
	return (v1.e[0] * v2.e[0]+v1.e[1] * v2.e[1]+v1.e[2] * v2.e[2]);
}
inline Vec3 cross(const Vec3 &v1, const Vec3 &v2) {
	return Vec3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(-(v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0])),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}
inline void Vec3::make_unit_vector() {
	float k = 1.0 / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k; e[1] *= k; e[2] *= k;
}
inline Vec3 unit_vec(Vec3 v) { 
	return v / v.Length(); 
}