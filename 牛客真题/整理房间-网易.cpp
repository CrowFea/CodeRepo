/*
题目描述
又到了周末，小易的房间乱得一团糟。
他希望将地上的杂物稍微整理下，使每团杂物看起来都紧凑一些，没有那么乱。
地上一共有n团杂物，每团杂物都包含4个物品。第i物品的坐标用(ai,bi)表示，小易每次都可以将它绕着(xi,yi)逆时针旋转90^ \circ90 
∘
 ，这将消耗他的一次移动次数。如果一团杂物的4个点构成了一个面积不为0的正方形，我们说它是紧凑的。
因为小易很懒，所以他希望你帮助他计算一下每团杂物最少需要多少步移动能使它变得紧凑。
输入描述:
第一行一个数n(1 <= n <= 100)，表示杂物的团数。
接下来4n行，每4行表示一团杂物，每行4个数ai, bi，xi, yi, (-104 <= xi, yi, ai, bi <= 104)，表示第i个物品旋转的它本身的坐标和中心点坐标。
输出描述:
n行，每行1个数，表示最少移动次数。
示例1
输入
复制
4
1 1 0 0
-1 1 0 0
-1 1 0 0
1 -1 0 0
1 1 0 0
-2 1 0 0
-1 1 0 0
1 -1 0 0
1 1 0 0
-1 1 0 0
-1 1 0 0
-1 1 0 0
2 2 0 1
-1 0 0 -2
3 0 0 -2
-1 1 -2 0
输出
复制
1
-1
3
3
说明
对于第一团杂物，我们可以旋转第二个或者第三个物品1次。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    int a;
    int b;
    Point(int x, int y, int a, int b) {
        this->x = x;
        this->y = y;
        this->a = a;
        this->b = b;
    }
    Point() {}
};

Point rotate(Point p, int times) {
    int x = p.x;
    int y = p.y;
    int a = p.a;
    int b = p.b;
    int xx, yy;
    for (int i = 0; i < times; i++) {
        xx = a - y + b;
        yy = x - a + b;
        x = xx;
        y = yy;
    }
    return Point(x, y, a, b);
}

bool cmp(Point p1, Point p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

bool isRightAngle(Point p1, Point p2, Point p3) {
    int x = (p1.x - p2.x)*(p1.x - p3.x) + (p1.y - p2.y)*(p1.y - p3.y);
    if (x == 0) {
        return true;
    }
    return false;
}

int distance(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

bool isSquare(Point p1,Point p2,Point p3,Point p4) {
    vector<Point> points(4);
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    sort(points.begin(), points.end(), cmp);
    int s1 = distance(points[0],points[1]);
    int s2 = distance(points[0], points[2]);
    int s3 = distance(points[1], points[3]);
    int s4 = distance(points[2], points[3]);
    if (s1 == s2 && s2 == s3 && s3 == s4 && s1 != 0 && isRightAngle(points[0], points[1], points[2])) {
        return true;
    }
    else {
        return false;
    }
}
 
 
int main()
{
    int N; 
    cin >> N;
    vector<Point> nums(4);
 
    for (int index = 0; index < N; index++) {
        for (int i = 0; i < 4; i++) {
            cin >> nums[i].x >> nums[i].y >> nums[i].a >> nums[i].b;
        }
        int count = 0x3f3f3f3f;
        for (int m = 0; m < 4; m++) {
            for (int n = 0; n < 4; n++) {
                for (int p = 0; p < 4; p++) {
                    for (int q = 0; q < 4; q++) {
                        if (isSquare(rotate(nums[0], m), rotate(nums[1], n), rotate(nums[2], p), rotate(nums[3], q))) {
                            count = min(count, m + n + p + q);
                        }
                    }
                }
            }
        }
        count = count == 0x3f3f3f3f ? -1 : count;
        cout << count << endl;
    }
    return 0;
}