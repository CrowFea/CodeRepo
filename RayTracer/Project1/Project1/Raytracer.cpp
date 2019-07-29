#include<iostream>
#include<fstream>
#include"ray.h"

using namespace std;

Vec3 color(const ray& r) {
	Vec3 unit_direction = unit_vec(r.direction());
	float t = 0.5*unit_direction.y() + 1.0;
	return (1.0 - t)*Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0); //Lerp
}

int main()
{
	ofstream outfile;
	outfile.open("img.ppm");

	int nx = 200, ny = 100;
	outfile << "P3" << endl << nx << " " << ny << endl << "255" << endl;

	Vec3 lower_left_corner(-2.0, -1.0, -1.0);
	Vec3 horizontal(4.0, 0.0, 0.0);
	Vec3 vertical(0.0, 2.0, 0.0);
	Vec3 origin(0.0, 0.0, 0.0);
	for (int j = ny - 1; j >= 0; --j) {
		for (int i = 0; i < nx; ++i) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u * horizontal + v * vertical);
			Vec3 col = color(r);
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			outfile << ir << " " << ig << " " << ib << endl;
		}
	}
}