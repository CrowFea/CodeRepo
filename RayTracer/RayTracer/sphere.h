#include"hitable.h"

class Sphere :public hitable {
public:
	float radius;
	Vec3 center;
	Sphere() {}
	Sphere(Vec3 cen, float r) :center(cen), radius(r) {}
	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec)	const;

};
//判断是否可以打击到圆
//判断条件为解析几何里的直线与圆相交，如果相交，返回的true
bool Sphere::hit(const ray& r, float tmin, float tmax, hit_record& rec)	const {
	Vec3 oc = r.origin() - center;
	float a = dot(r.direction(), r.direction());
	float b = 2 * dot(oc, r.direction());
	float c = dot(oc, oc) - radius * radius;
	float d = (b * b - a*c > 0);//求根公式
	if (d > 0) {
		float root= (-b - sqrt(d) / a);
		if (root<tmax&&root>tmin) {
			rec.t = root;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		root = (-b + sqrt(d) / a);
		if (root<tmax&&root>tmin) {
			rec.t = root;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}