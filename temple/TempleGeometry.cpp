#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-9;
const double Pi = acos(-1.0);

// 比较函数
inline int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

// 点/向量结构体
struct Point {
    double x, y;
    
    Point() : x(0), y(0) {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    
    // 输入输出
    friend istream& operator>>(istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    
    // 比较运算
    bool operator==(const Point& p) const {
        return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
    }
    bool operator!=(const Point& p) const {
        return !(*this == p);
    }
    bool operator<(const Point& p) const {
        return dcmp(x - p.x) < 0 || (dcmp(x - p.x) == 0 && dcmp(y - p.y) < 0);
    }
    
    // 向量运算
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    Point operator*(double k) const {
        return Point(x * k, y * k);
    }
    Point operator/(double k) const {
        return Point(x / k, y / k);
    }
    
    // 向量点积
    double dot(const Point& p) const {
        return x * p.x + y * p.y;
    }
    
    // 向量叉积
    double cross(const Point& p) const {
        return x * p.y - y * p.x;
    }
    
    // 向量长度
    double length() const {
        return sqrt(x * x + y * y);
    }
    
    // 向量长度的平方
    double length2() const {
        return x * x + y * y;
    }
    
    // 向量旋转（逆时针旋转rad弧度）
    Point rotate(double rad) const {
        return Point(x * cos(rad) - y * sin(rad), 
                     x * sin(rad) + y * cos(rad));
    }
    
    // 向量旋转90度（逆时针）
    Point rotate90() const {
        return Point(-y, x);
    }
    
    // 单位向量
    Point unit() const {
        double len = length();
        return Point(x / len, y / len);
    }
    
    // 规范化向量（保持方向不变，长度为1）
    void normalize() {
        double len = length();
        x /= len;
        y /= len;
    }
    
    // 向量夹角（弧度）
    double angle() const {
        return atan2(y, x);
    }
    
    // 与另一向量的夹角（弧度）
    double angle(const Point& p) const {
        return acos(dot(p) / (length() * p.length()));
    }
    
    // 判断向量是否为零向量
    bool isZero() const {
        return dcmp(x) == 0 && dcmp(y) == 0;
    }
};

// 直线/线段结构体
struct Line {
    Point s, e;  // 起点和终点
    
    Line() {}
    Line(Point _s, Point _e) : s(_s), e(_e) {}
    
    // 方向向量
    Point direction() const {
        return e - s;
    }
    
    // 直线长度
    double length() const {
        return (e - s).length();
    }
    
    // 点到直线的距离
    double distanceToPoint(const Point& p) const {
        return fabs((p - s).cross(direction())) / direction().length();
    }
    
    // 点到直线的垂足
    Point projection(const Point& p) const {
        Point v = direction();
        return s + v * ((p - s).dot(v) / v.length2());
    }
    
    // 点关于直线的对称点
    Point reflection(const Point& p) const {
        Point proj = projection(p);
        return proj * 2 - p;
    }
    
    // 判断点是否在线段上
    bool onSegment(const Point& p) const {
        // 先判断点是否在直线端点的包围盒内
        if (dcmp((p - s).cross(e - s)) != 0) return false;
        
        // 再判断点是否在线段上
        return dcmp((p - s).dot(p - e)) <= 0;
    }
    
    // 判断点是否在射线上
    bool onRay(const Point& p) const {
        if (dcmp((p - s).cross(e - s)) != 0) return false;
        return dcmp((p - s).dot(e - s)) >= 0;
    }
};

// 多边形结构体
struct Polygon {
    vector<Point> points;
    
    Polygon() {}
    Polygon(const vector<Point>& pts) : points(pts) {}
    
    // 计算多边形面积（带方向）
    double area() const {
        double res = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            res += points[i].cross(points[j]);
        }
        return res / 2.0;
    }
    
    // 计算多边形面积（绝对值）
    double absArea() const {
        return fabs(area());
    }
    
    // 计算多边形周长
    double perimeter() const {
        double res = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            res += (points[j] - points[i]).length();
        }
        return res;
    }
    
    // 判断点是否在多边形内（射线法）
    bool contains(const Point& p) const {
        int n = points.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            Point a = points[i], b = points[j];
            
            // 如果点在顶点上
            if (p == a || p == b) return true;
            
            // 如果点在边上
            if (Line(a, b).onSegment(p)) return true;
            
            // 射线与边相交判断
            if (dcmp(a.y - b.y) > 0) swap(a, b);
            if (dcmp(p.y - a.y) > 0 && dcmp(p.y - b.y) <= 0 &&
                dcmp((b - a).cross(p - a)) > 0) {
                cnt++;
            }
        }
        
        return cnt % 2 == 1;
    }
};

// 几何工具函数
struct Geometry {
    // 判断三点共线
    static bool collinear(const Point& a, const Point& b, const Point& c) {
        return dcmp((b - a).cross(c - a)) == 0;
    }
    
    // 判断点是否在线段上
    static bool pointOnSegment(const Point& p, const Point& a, const Point& b) {
        if (collinear(p, a, b)) {
            return dcmp((p - a).dot(p - b)) <= 0;
        }
        return false;
    }
    
    // 判断两线段是否相交（包括端点）
    static bool segmentIntersect(const Point& a, const Point& b, 
                                 const Point& c, const Point& d) {
        if (max(a.x, b.x) < min(c.x, d.x) ||
            max(a.y, b.y) < min(c.y, d.y) ||
            min(a.x, b.x) > max(c.x, d.x) ||
            min(a.y, b.y) > max(c.y, d.y)) {
            return false;
        }
        
        double cross1 = (b - a).cross(c - a);
        double cross2 = (b - a).cross(d - a);
        double cross3 = (d - c).cross(a - c);
        double cross4 = (d - c).cross(b - c);
        
        return dcmp(cross1) * dcmp(cross2) <= 0 && 
               dcmp(cross3) * dcmp(cross4) <= 0;
    }
    
    // 判断两直线是否平行
    static bool parallel(const Point& a, const Point& b, 
                         const Point& c, const Point& d) {
        return dcmp((b - a).cross(d - c)) == 0;
    }
    
    // 判断两直线是否垂直
    static bool perpendicular(const Point& a, const Point& b, 
                              const Point& c, const Point& d) {
        return dcmp((b - a).dot(d - c)) == 0;
    }
    
    // 计算两直线交点（确保不平行）
    static Point lineIntersection(const Point& a, const Point& b, 
                                  const Point& c, const Point& d) {
        Point v1 = b - a, v2 = d - c;
        double cross = v1.cross(v2);
        if (dcmp(cross) == 0) return Point(NAN, NAN);  // 平行
        
        Point u = c - a;
        double t = v2.cross(u) / cross;
        return a + v1 * t;
    }
    
    // 计算点到线段的最短距离
    static double pointToSegmentDistance(const Point& p, 
                                         const Point& a, const Point& b) {
        if (a == b) return (p - a).length();
        
        Point v = b - a, w = p - a;
        double proj = w.dot(v);
        
        if (proj <= 0) return (p - a).length();
        if (proj >= v.length2()) return (p - b).length();
        
        return fabs(v.cross(w)) / v.length();
    }
    
    // 计算两线段的最短距离
    static double segmentToSegmentDistance(const Point& a, const Point& b,
                                           const Point& c, const Point& d) {
        if (segmentIntersect(a, b, c, d)) return 0.0;
        
        double d1 = min(pointToSegmentDistance(a, c, d), 
                       pointToSegmentDistance(b, c, d));
        double d2 = min(pointToSegmentDistance(c, a, b), 
                       pointToSegmentDistance(d, a, b));
        
        return min(d1, d2);
    }
    
    // 计算三角形的面积
    static double triangleArea(const Point& a, const Point& b, const Point& c) {
        return fabs((b - a).cross(c - a)) / 2.0;
    }
    
    // 判断点是否在三角形内（包括边界）
    static bool pointInTriangle(const Point& p, const Point& a, 
                                const Point& b, const Point& c) {
        double s1 = triangleArea(p, a, b);
        double s2 = triangleArea(p, b, c);
        double s3 = triangleArea(p, c, a);
        double s = triangleArea(a, b, c);
        
        return dcmp(s1 + s2 + s3 - s) == 0;
    }
    
    // 计算多边形的重心
    static Point polygonCentroid(const vector<Point>& points) {
        double area = 0;
        Point centroid(0, 0);
        int n = points.size();
        
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            double cross = points[i].cross(points[j]);
            area += cross;
            centroid.x += (points[i].x + points[j].x) * cross;
            centroid.y += (points[i].y + points[j].y) * cross;
        }
        
        area /= 2.0;
        centroid.x /= (6.0 * area);
        centroid.y /= (6.0 * area);
        
        return centroid;
    }
    
    // 计算两点间的距离
    static double distance(const Point& a, const Point& b) {
        return (b - a).length();
    }
    
    // 计算两点间距离的平方
    static double distance2(const Point& a, const Point& b) {
        return (b - a).length2();
    }
    
    // 计算向量的极角（角度制）
    static double angleDegree(const Point& p) {
        double angle = atan2(p.y, p.x) * 180.0 / Pi;
        if (angle < 0) angle += 360.0;
        return angle;
    }
    
    // 判断点是否在凸多边形内（二分法，O(log n)）
    static bool pointInConvexPolygon(const Point& p, const vector<Point>& poly) {
        int n = poly.size();
        
        // 判断点在第一条边和最后一条边的位置
        if (dcmp((poly[1] - poly[0]).cross(p - poly[0])) < 0 ||
            dcmp((poly[n-1] - poly[0]).cross(p - poly[0])) > 0) {
            return false;
        }
        
        // 二分查找
        int l = 1, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (dcmp((poly[mid] - poly[0]).cross(p - poly[0])) > 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        
        // 判断点是否在三角形内
        return pointInTriangle(p, poly[0], poly[l], poly[r]);
    }

    // 获取凸包（Graham扫描算法）
    static Polygon convexHull(vector<Point> points) {
        int n = points.size();
        if (n <= 3) return Polygon(points);
        
        // 寻找最下最左的点
        int base = 0;
        for (int i = 1; i < n; i++) {
            if (dcmp(points[i].y - points[base].y) < 0 ||
                (dcmp(points[i].y - points[base].y) == 0 &&
                 dcmp(points[i].x - points[base].x) < 0)) {
                base = i;
            }
        }
        swap(points[0], points[base]);
        
        // 按极角排序
        sort(points.begin() + 1, points.end(), [&](const Point& a, const Point& b) {
            double cross = (a - points[0]).cross(b - points[0]);
            if (dcmp(cross) != 0) return cross > 0;
            return (a - points[0]).length2() < (b - points[0]).length2();
        });
        
        // Graham扫描
        vector<Point> hull;
        
        for (int i = 0; i < n; i++) {
            while (hull.size() >= 2) {
                Point a = hull[hull.size() - 2];
                Point b = hull.back();
                Point c = points[i];
                
                if (dcmp((b - a).cross(c - a)) <= 0) {
                    hull.pop_back();
                } else {
                    break;
                }
            }
            hull.push_back(points[i]);
        }
        
        return Polygon(hull);
    }
};

// 圆结构体
struct Circle {
    Point center;
    double radius;
    
    Circle() : radius(0) {}
    Circle(Point c, double r) : center(c), radius(r) {}
    
    // 判断点是否在圆内（包括边界）
    bool contains(const Point& p) const {
        return dcmp((p - center).length() - radius) <= 0;
    }
    
    // 计算圆的面积
    double area() const {
        return Pi * radius * radius;
    }
    
    // 计算圆的周长
    double perimeter() const {
        return 2 * Pi * radius;
    }
    
    // 获取圆与直线的交点
    vector<Point> intersectLine(const Line& line) const {
        vector<Point> res;
        Point proj = line.projection(center);
        double dist = (proj - center).length();
        
        if (dcmp(dist - radius) > 0) {
            return res;  // 无交点
        }
        
        if (dcmp(dist - radius) == 0) {
            res.push_back(proj);  // 相切
            return res;
        }
        
        // 两个交点
        double d = sqrt(radius * radius - dist * dist);
        Point dir = line.direction().unit();
        res.push_back(proj + dir * d);
        res.push_back(proj - dir * d);
        
        return res;
    }
    
    // 获取两圆的交点
    vector<Point> intersectCircle(const Circle& other) const {
        vector<Point> res;
        
        Point c1 = center, c2 = other.center;
        double r1 = radius, r2 = other.radius;
        
        double d = (c2 - c1).length();
        if (dcmp(d) == 0) {
            return res;  // 同心圆
        }
        
        if (dcmp(d - r1 - r2) > 0 || dcmp(fabs(r1 - r2) - d) > 0) {
            return res;  // 无交点
        }
        
        double a = (r1 * r1 - r2 * r2 + d * d) / (2 * d);
        double h = sqrt(r1 * r1 - a * a);
        
        Point p = c1 + (c2 - c1) * (a / d);
        
        if (dcmp(h) == 0) {
            res.push_back(p);  // 相切
            return res;
        }
        
        Point offset = (c2 - c1).rotate90().unit() * h;
        res.push_back(p + offset);
        res.push_back(p - offset);
        
        return res;
    }
    
    // 获取过圆外一点的切线
    vector<Line> tangentsFromPoint(const Point& p) const {
        vector<Line> res;
        
        double d = (p - center).length();
        if (dcmp(d - radius) < 0) {
            return res;  // 点在圆内
        }
        
        if (dcmp(d - radius) == 0) {
            // 点在圆上，只有一条切线
            Point dir = (p - center).rotate90();
            res.push_back(Line(p, p + dir));
            return res;
        }
        
        // 两条切线
        double angle = asin(radius / d);
        Point dir = (center - p).unit();
        
        Point p1 = p + dir.rotate(angle) * d;
        Point p2 = p + dir.rotate(-angle) * d;
        
        res.push_back(Line(p, p1));
        res.push_back(Line(p, p2));
        
        return res;
    }
};

// 测试用例
void testGeometry() {
    cout << "===== 计算几何向量板子测试 =====\n" << endl;
    
    // 点/向量测试
    cout << "1. 点/向量操作测试：" << endl;
    Point a(1, 2), b(3, 4);
    cout << "点a: " << a << endl;
    cout << "点b: " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * 2 = " << a * 2 << endl;
    cout << "a点积b = " << a.dot(b) << endl;
    cout << "a叉积b = " << a.cross(b) << endl;
    cout << "a的长度 = " << a.length() << endl;
    cout << "a旋转90度 = " << a.rotate90() << endl;
    cout << endl;
    
    // 几何工具测试
    cout << "2. 几何工具测试：" << endl;
    Point p1(0, 0), p2(3, 0), p3(0, 4);
    cout << "三角形面积(" << p1 << ", " << p2 << ", " << p3 << ") = " 
         << Geometry::triangleArea(p1, p2, p3) << endl;
    
    Point p4(1, 1);
    cout << "点" << p4 << "是否在三角形内: " 
         << (Geometry::pointInTriangle(p4, p1, p2, p3) ? "是" : "否") << endl;
    
    cout << "点" << p4 << "到线段" << p1 << "-" << p2 << "的距离 = "
         << Geometry::pointToSegmentDistance(p4, p1, p2) << endl;
    cout << endl;
    
    // 多边形测试
    cout << "3. 多边形测试：" << endl;
    vector<Point> polyPoints = {{0, 0}, {3, 0}, {3, 3}, {0, 3}};
    Polygon poly(polyPoints);
    cout << "多边形面积 = " << poly.absArea() << endl;
    cout << "多边形周长 = " << poly.perimeter() << endl;
    cout << "点" << p4 << "是否在多边形内: " 
         << (poly.contains(p4) ? "是" : "否") << endl;
    cout << endl;
    
    // 凸包测试
    cout << "4. 凸包测试：" << endl;
    vector<Point> points = {{0, 0}, {1, 2}, {2, 1}, {3, 3}, 
                           {1, 1}, {2, 2}, {3, 1}, {1, 3}};
    Polygon hull = Geometry::convexHull(points);
    cout << "凸包顶点:" << endl;
    for (const auto& p : hull.points) {
        cout << "  " << p << endl;
    }
    cout << "凸包面积 = " << hull.absArea() << endl;
    cout << endl;
    
    // 圆测试
    cout << "5. 圆测试：" << endl;
    Circle c(Point(0, 0), 5);
    Point testPoint(3, 4);
    cout << "点" << testPoint << "是否在圆内: " 
         << (c.contains(testPoint) ? "是" : "否") << endl;
    cout << "圆的面积 = " << c.area() << endl;
    cout << "圆的周长 = " << c.perimeter() << endl;
}

int main() {
    testGeometry();
    return 0;
}