#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <intrin.h>

#define M3D_IMPLEMENTATION
#include "m3d.h"

void m3d_print_test(char const* name, bool pass)
{
    static char   const *DOTS     = "............................................................";
    static size_t const  DOTS_LEN = strlen(DOTS);

    size_t len = strlen(name) + 1; // add one for a space

    if (len < DOTS_LEN)
        printf("%s %s %s\n", name, DOTS + len, pass ? "pass" : "FAIL");
    else
        printf("%s %s\n", name, pass ? "pass" : "FAIL");
}

void m3d_test_suite()
{
    printf("\n=== Running m3d Test Suite ===\n\n");

    float const EPSILON = 1e-7f;

    size_t test_count   = 0;
    size_t tests_passed = 0;
    size_t tests_failed = 0;

#define COUNT_TEST(name, pass) do {             \
        m3d_print_test((name), (pass));         \
        test_count++;                           \
        if ((pass)) tests_passed++;             \
        else tests_failed++;                    \
    } while (0)

    {
        Vec2 v = vec2(2.0f, 3.5f);
        bool pass = v.x == 2.0f && v.y == 3.5f;
        COUNT_TEST("vec2(x, y) construction", pass);
    }

    {
        Vec2 v = -vec2(1.0f, 2.0f);
        bool pass = v.x == -1.0f && v.y == -2.0f;
        COUNT_TEST("Vec2 negation", pass);
    }

    {
        Vec2 a = vec2(1.0f, 2.0f);
        Vec2 b = vec2(3.0f, 4.0f);
        Vec2 c = b - a;
        bool pass = c.x == 2.0f && c.y == 2.0f;
        COUNT_TEST("Vec2 subtraction", pass);
    }

    {
        Vec2 a = vec2(1.0f, 2.0f);
        Vec2 b = vec2(3.0f, 4.0f);
        Vec2 c = a + b;
        bool pass = c.x == 4.0f && c.y == 6.0f;
        COUNT_TEST("Vec2 addition", pass);
    }

    {
        Vec2 a = 5.0f * vec2(1.0f, 2.0f);
        bool pass = a.x == 5.0f && a.y == 10.0f;
        COUNT_TEST("scalar to Vec2 multiplication", pass);
    }

    {
        Vec2 a = vec2(1.0f, 2.0f) * 5.0f;
        bool pass = a.x == 5.0f && a.y == 10.0f;
        COUNT_TEST("Vec2 to scalar multiplication", pass);
    }

    {
        Vec2 a = vec2(1.0f, 2.0f);
        Vec2 b = vec2(7.0f, 3.0f);
        a += b;
        bool pass = a.x == 8.0f && a.y == 5.0f;
        COUNT_TEST("Vec2 self addition", pass);
    }

    {
        Vec2 a = vec2(1.0f, 2.0f);
        a *= 3.0f;
        bool pass = a.x == 3.0f && a.y == 6.0f;
        COUNT_TEST("Vec2 self scalar multiplication", pass);
    }

    {
        Vec2 a = vec2(1.0f, 2.0f);
        Vec2 b = a / 2.0f;
        bool pass = fabsf(b.x - 0.5f) < EPSILON && b.y == 1.0f;
        COUNT_TEST("Vec2 scalar division", pass);
    }

    {
        Vec2 a = vec2(3.0f, 6.0f);
        Vec2 b = vec2(2.0f, 7.0f);
        Vec2 c = hadamard(a, b);
        bool pass = c.x == 6.0f && c.y == 42.0f;
        COUNT_TEST("Vec2 hadamard product", pass);
    }

    {
        Vec2  a = vec2(3.0f, 4.0f);
        Vec2  b = vec2(10.0f, 5.0f);
        float c = dot(a, b);
        bool pass = c == 50.0f;
        COUNT_TEST("Vec2 dot product", pass);
    }

    {
        Vec2  a = vec2(6.0f, 2.0f);
        float b = len_sq(a);
        bool pass = b == 40.0f;
        COUNT_TEST("Vec2 len_sq", pass);
    }

    {
        Vec2  a = vec2(3.0f, 2.0f);
        float b = length(a);
        bool pass = fabsf(b - 3.60555127546f) < EPSILON;
        COUNT_TEST("Vec2 length", pass);
    }
    
    {
        Vec2  a = vec2(5.0f, 4.0f);
        Vec2  b = normalize(a);
        float c = length(b);
        bool pass = (fabsf(b.x - 0.780868809f) < EPSILON &&
                     fabsf(b.y - 0.624695047f) < EPSILON &&
                     fabsf(c - 1.0f) < EPSILON);
        COUNT_TEST("Vec2 normalize", pass);
    }

    {
        Vec3 v    = vec3(2.0f, 3.5f, 1.0f);
        bool pass = v.x == 2.0f && v.y == 3.5f && v.z == 1.0f;
        COUNT_TEST("vec3(x, y, z) construction", pass);
    }

    {
        Vec3 v    = vec3(vec2(4.0f, 3.6f));
        bool pass = v.x == 4.0f && v.y == 3.6f && v.z == 0.0f;
        COUNT_TEST("vec3(Vec2) construction", pass);
    }

    {
        Vec3 v    = vec3(vec2(7.0f, 1.0f), 8.2f);
        bool pass = v.x == 7.0f && v.y == 1.0f && v.z == 8.2f;
        COUNT_TEST("vec3(Vec2, z) construction", pass);
    }

    {
        Vec3 v    = -vec3(1.0f, 2.0f, 3.0f);
        bool pass = v.x == -1.0f && v.y == -2.0f && v.z == -3.0f;
        COUNT_TEST("Vec3 negation", pass);
    }

    {
        Vec3 a = vec3(1.0f, 2.0f, 2.0f);
        Vec3 b = vec3(3.0f, 4.0f, 8.0f);
        Vec3 c = b - a;
        bool pass = c.x == 2.0f && c.y == 2.0f && c.z == 6.0f;
        COUNT_TEST("Vec3 subtraction", pass);
    }

    {
        Vec3 a = vec3(1.0f, 2.0f, 3.0f);
        Vec3 b = vec3(3.0f, 4.0f, 11.0f);
        Vec3 c = a + b;
        bool pass = c.x == 4.0f && c.y == 6.0f && c.z == 14.0f;
        COUNT_TEST("Vec3 addition", pass);
    }

    {
        Vec3 a = 5.0f * vec3(1.0f, 2.0f, 6.0f);
        bool pass = a.x == 5.0f && a.y == 10.0f && a.z == 30.0f;
        COUNT_TEST("scalar to Vec3 multiplication", pass);
    }

    {
        Vec3 a = vec3(1.0f, 2.0f, 4.0f) * 5.0f;
        bool pass = a.x == 5.0f && a.y == 10.0f && a.z == 20.0f;
        COUNT_TEST("Vec3 to scalar multiplication", pass);
    }

    {
        Vec3 a = vec3(1.0f, 2.0f, 1.0f);
        Vec3 b = vec3(7.0f, 3.0f, 12.0f);
        a += b;
        bool pass = a.x == 8.0f && a.y == 5.0f && a.z == 13.0f;
        COUNT_TEST("Vec3 self addition", pass);
    }

    {
        Vec3 a = vec3(1.0f, 2.0f, 12.0f);
        a *= 3.0f;
        bool pass = a.x == 3.0f && a.y == 6.0f && a.z == 36.0f;
        COUNT_TEST("Vec3 self scalar multiplication", pass);
    }

    {
        Vec3 a = vec3(1.0f, 2.0f, 12.0f);
        Vec3 b = a / 2.0f;
        bool pass = fabsf(b.x - 0.5f) < EPSILON && b.y == 1.0f && b.z == 6.0f;
        COUNT_TEST("Vec3 scalar division", pass);
    }

    {
        Vec3 a = vec3(3.0f, 6.0f, 2.0f);
        Vec3 b = vec3(2.0f, 7.0f, 5.0f);
        Vec3 c = hadamard(a, b);
        bool pass = c.x == 6.0f && c.y == 42.0f && c.z == 10.0f;
        COUNT_TEST("Vec3 hadamard product", pass);
    }

    {
        Vec3  a = vec3(3.0f, 4.0f, 2.0f);
        Vec3  b = vec3(10.0f, 5.0f, 3.0f);
        float c = dot(a, b);
        bool pass = c == 56.0f;
        COUNT_TEST("Vec3 dot product", pass);
    }

    {
        Vec3 a = vec3(1.0f, 0.0f, 0.0f);
        Vec3 b = vec3(0.0f, 1.0f, 0.0f);
        Vec3 c = cross(a, b);
        bool pass = c.x == 0.0f && c.y == 0.0f && c.z == 1.0f;
        COUNT_TEST("Vec3 cross product", pass);
    }

    {
        Vec3  a = vec3(6.0f, 2.0f, 4.0f);
        float b = len_sq(a);
        bool pass = b == 56.0f;
        COUNT_TEST("Vec3 len_sq", pass);
    }

    {
        Vec3  a = vec3(3.0f, 2.0f, 6.0f);
        float b = length(a);
        bool pass = fabsf(b - 7.0f) < EPSILON;
        COUNT_TEST("Vec3 length", pass);
    }
    
    {
        Vec3  a = vec3(5.0f, 4.0f, 2.0f);
        Vec3  b = normalize(a);
        float c = length(b);
        bool pass = (fabsf(b.x - 0.7453559925f) < EPSILON &&
                     fabsf(b.y - 0.596284794f)  < EPSILON &&
                     fabsf(b.z - 0.298142397f)  < EPSILON &&
                     fabsf(c - 1.0f) < EPSILON);
        COUNT_TEST("Vec3 normalize", pass);
    }

    {
        Vec4 v    = vec4(2.0f, 3.5f, 1.0f, 7.0f);
        bool pass = v.x == 2.0f && v.y == 3.5f && v.z == 1.0f && v.w == 7.0f;
        COUNT_TEST("vec4(x, y, z, w) construction", pass);
    }

    {
        Vec4 v    = vec4(vec2(4.0f, 3.6f));
        bool pass = v.x == 4.0f && v.y == 3.6f && v.z == 0.0f && v.w == 0.0f;
        COUNT_TEST("vec4(Vec2) construction", pass);
    }

    {
        Vec4 v    = vec4(vec2(7.0f, 1.0f), 8.2f, 9.0f);
        bool pass = v.x == 7.0f && v.y == 1.0f && v.z == 8.2f && v.w == 9.0f;
        COUNT_TEST("vec4(Vec2, z) construction", pass);
    }

    {
        Vec4 v    = vec4(vec3(4.0f, 3.6f, 7.5f));
        bool pass = v.x == 4.0f && v.y == 3.6f && v.z == 7.5f && v.w == 0.0f;
        COUNT_TEST("vec4(Vec2) construction", pass);
    }

    {
        Vec4 v    = vec4(vec3(4.0f, 3.6f, 7.5f), 2.3f);
        bool pass = v.x == 4.0f && v.y == 3.6f && v.z == 7.5f && v.w == 2.3f;
        COUNT_TEST("vec4(Vec2) construction", pass);
    }

    {
        Vec4 v = vec4(1, 2, 3, 4);
        Vec3 a = v.xyz;
        Vec3 b = v.yzw;
        Vec2 c = v.xy;
        Vec2 d = v.yz;
        Vec2 e = v.zw;
        bool pass = (a.x == 1.0f && a.y == 2.0f && a.z == 3.0f &&
                     b.x == 2.0f && b.y == 3.0f && b.z == 4.0f &&
                     c.x == 1.0f && c.y == 2.0f &&
                     d.x == 2.0f && d.y == 3.0f &&
                     e.x == 3.0f && e.y == 4.0f);
        COUNT_TEST("vec4 xyzw swizzling", pass);
    }

    {
        Vec4 v = vec4(1, 2, 3, 4);
        Vec3 a = v.stu;
        Vec3 b = v.tuv;
        Vec2 c = v.st;
        Vec2 d = v.tu;
        Vec2 e = v.uv;
        bool pass = (a.s == 1.0f && a.t == 2.0f && a.u == 3.0f &&
                     b.s == 2.0f && b.t == 3.0f && b.u == 4.0f &&
                     c.s == 1.0f && c.t == 2.0f &&
                     d.s == 2.0f && d.t == 3.0f &&
                     e.s == 3.0f && e.t == 4.0f);
        COUNT_TEST("vec4 stuv swizzling", pass);
    }

    {
        Vec4 v = vec4(1, 2, 3, 4);
        Vec3 a = v.rgb;
        Vec3 b = v.gba;
        bool pass = (a.r == 1.0f && a.g == 2.0f && a.b == 3.0f &&
                     b.r == 2.0f && b.g == 3.0f && b.b == 4.0f);
        COUNT_TEST("vec4 rgba swizzling", pass);
    }

    {
        Vec4 v    = -vec4(1.0f, 2.0f, 3.0f, 4.0f);
        bool pass = v.x == -1.0f && v.y == -2.0f && v.z == -3.0f && v.w == -4.0f;
        COUNT_TEST("Vec4 negation", pass);
    }

    {
        Vec4 a = vec4(1.0f, 2.0f, 2.0f, 4.0f);
        Vec4 b = vec4(3.0f, 4.0f, 8.0f, 12.0f);
        Vec4 c = b - a;
        bool pass = c.x == 2.0f && c.y == 2.0f && c.z == 6.0f && c.w == 8.0f;
        COUNT_TEST("Vec4 subtraction", pass);
    }

    {
        Vec4 a = vec4(1.0f, 2.0f, 3.0f, 4.0f);
        Vec4 b = vec4(3.0f, 4.0f, 11.0f, 3.0f);
        Vec4 c = a + b;
        bool pass = c.x == 4.0f && c.y == 6.0f && c.z == 14.0f && c.w == 7.0f;
        COUNT_TEST("Vec4 addition", pass);
    }

    {
        Vec4 a = 5.0f * vec4(1.0f, 2.0f, 6.0f, 4.0f);
        bool pass = a.x == 5.0f && a.y == 10.0f && a.z == 30.0f && a.w == 20.0f;
        COUNT_TEST("scalar to Vec4 multiplication", pass);
    }

    {
        Vec4 a = vec4(1.0f, 2.0f, 4.0f, 6.0f) * 5.0f;
        bool pass = a.x == 5.0f && a.y == 10.0f && a.z == 20.0f && a.w == 30.0f;
        COUNT_TEST("Vec4 to scalar multiplication", pass);
    }

    {
        Vec4 a = vec4(1.0f, 2.0f, 12.0f, 10.0f);
        Vec4 b = a / 2.0f;
        bool pass = (fabsf(b.x - 0.5f) < EPSILON &&
                     b.y == 1.0f &&
                     b.z == 6.0f &&
                     b.w == 5.0f);
        COUNT_TEST("Vec4 scalar division", pass);
    }

    {
        Vec4 a = vec4(1.0f, 2.0f, 1.0f, 3.0f);
        Vec4 b = vec4(7.0f, 3.0f, 12.0f, 4.0f);
        a += b;
        bool pass = a.x == 8.0f && a.y == 5.0f && a.z == 13.0f && a.w == 7.0f;
        COUNT_TEST("Vec4 self addition", pass);
    }

    {
        Vec4 a = vec4(1.0f, 2.0f, 12.0f, 8.0f);
        a *= 3.0f;
        bool pass = a.x == 3.0f && a.y == 6.0f && a.z == 36.0f && a.w == 24.0f;
        COUNT_TEST("Vec4 self scalar multiplication", pass);
    }

    {
        Vec4 a = vec4(3.0f, 6.0f, 2.0f, 4.0f);
        Vec4 b = vec4(2.0f, 7.0f, 5.0f, 5.0f);
        Vec4 c = hadamard(a, b);
        bool pass = c.x == 6.0f && c.y == 42.0f && c.z == 10.0f && c.w == 20.0f;
        COUNT_TEST("Vec4 hadamard product", pass);
    }

    {
        Vec4  a = vec4(3.0f, 4.0f, 2.0f, 5.0f);
        Vec4  b = vec4(10.0f, 5.0f, 3.0f, 4.0f);
        float c = dot(a, b);
        bool pass = c == 76.0f;
        COUNT_TEST("Vec4 dot product", pass);
    }

    {
        Vec4  a = vec4(6.0f, 2.0f, 4.0f, 7.0f);
        float b = len_sq(a);
        bool pass = b == 105.0f;
        COUNT_TEST("Vec4 len_sq", pass);
    }

    {
        Vec4  a = vec4(3.0f, 2.0f, 6.0f, 4.0f);
        float b = length(a);
        bool pass = fabsf(b - 8.0622577483f) < EPSILON;
        COUNT_TEST("Vec4 length", pass);
    }
    
    {
        Vec4  a = vec4(5.0f, 4.0f, 2.0f, 6.0f);
        Vec4  b = normalize(a);
        float c = length(b);
        bool pass = (fabsf(b.x - 0.555555555556f) < EPSILON &&
                     fabsf(b.y - 0.444444444444f) < EPSILON &&
                     fabsf(b.z - 0.222222222222f) < EPSILON &&
                     fabsf(b.w - 0.666666666667f) < EPSILON &&
                     fabsf(c - 1.0f) < EPSILON);
        COUNT_TEST("Vec4 normalize", pass);
    }

    {
        Mat4 A = identity();
        bool pass = (A.at(0, 0) == 1.0f &&
                     A.at(1, 0) == 0.0f &&
                     A.at(2, 0) == 0.0f &&
                     A.at(3, 0) == 0.0f &&
                     A.at(0, 1) == 0.0f &&
                     A.at(1, 1) == 1.0f &&
                     A.at(2, 1) == 0.0f &&
                     A.at(3, 1) == 0.0f &&
                     A.at(0, 2) == 0.0f &&
                     A.at(1, 2) == 0.0f &&
                     A.at(2, 2) == 1.0f &&
                     A.at(3, 2) == 0.0f &&
                     A.at(0, 3) == 0.0f &&
                     A.at(1, 3) == 0.0f &&
                     A.at(2, 3) == 0.0f &&
                     A.at(3, 3) == 1.0f);
        COUNT_TEST("Mat4 identity", pass);
    }

    {
        Mat4 A = orthoGL(-5, 8, 12, -7, 2, 25);
        bool pass = (fabsf(A.at(0, 0) - 0.153846153846f)   < EPSILON &&
                     fabsf(A.at(1, 0) - 0.0f)              < EPSILON &&
                     fabsf(A.at(2, 0) - 0.0f)              < EPSILON &&
                     fabsf(A.at(3, 0) - 0.0f)              < EPSILON &&
                     fabsf(A.at(0, 1) - 0.0f)              < EPSILON &&
                     fabsf(A.at(1, 1) - 0.105263157895f)   < EPSILON &&
                     fabsf(A.at(2, 1) - 0.0f)              < EPSILON &&
                     fabsf(A.at(3, 1) - 0.0f)              < EPSILON &&
                     fabsf(A.at(0, 2) - 0.0f)              < EPSILON &&
                     fabsf(A.at(1, 2) - 0.0f)              < EPSILON &&
                     fabsf(A.at(2, 2) - -0.0869565217391f) < EPSILON &&
                     fabsf(A.at(3, 2) - 0.0f)              < EPSILON &&
                     fabsf(A.at(0, 3) - -0.230769230769f)  < EPSILON &&
                     fabsf(A.at(1, 3) - -0.263157894737f)  < EPSILON &&
                     fabsf(A.at(2, 3) - -1.17391304348f)   < EPSILON &&
                     fabsf(A.at(3, 3) - 1.0f)              < EPSILON);
        COUNT_TEST("Mat4 orthoGL", pass);
    }

    {
        Mat4 A = perspectiveGL(-5, 8, 12, -7, 2, 25);
        bool pass = (fabsf(A.at(0, 0) - 0.307692307692f) < EPSILON &&
                     fabsf(A.at(1, 0) - 0.0f)            < EPSILON &&
                     fabsf(A.at(2, 0) - 0.0f)            < EPSILON &&
                     fabsf(A.at(3, 0) - 0.0f)            < EPSILON &&
                     fabsf(A.at(0, 1) - 0.0f)            < EPSILON &&
                     fabsf(A.at(1, 1) - 0.210526315789f) < EPSILON &&
                     fabsf(A.at(2, 1) - 0.0f)            < EPSILON &&
                     fabsf(A.at(3, 1) - 0.0f)            < EPSILON &&
                     fabsf(A.at(0, 2) - 0.230769230769f) < EPSILON &&
                     fabsf(A.at(1, 2) - 0.263157894737f) < EPSILON &&
                     fabsf(A.at(2, 2) - -1.17391304348f) < EPSILON &&
                     fabsf(A.at(3, 2) - -1.0f)           < EPSILON &&
                     fabsf(A.at(0, 3) - 0.0f)            < EPSILON &&
                     fabsf(A.at(1, 3) - 0.0f)            < EPSILON &&
                     fabsf(A.at(2, 3) - -4.34782608696f) < EPSILON &&
                     fabsf(A.at(3, 3) - 0.0f)            < EPSILON);
        COUNT_TEST("Mat4 perspectiveGL", pass);
    }

    {
        Mat4 A = perspectiveGL(-1, 1, 1, -1, 1, 10);
        Mat4 B = perspectiveGL(90, 1, 1, 10);
        bool pass = (fabsf(A.at(0, 0) - B.at(0, 0)) < EPSILON &&
                     fabsf(A.at(1, 0) - B.at(1, 0)) < EPSILON &&
                     fabsf(A.at(2, 0) - B.at(2, 0)) < EPSILON &&
                     fabsf(A.at(3, 0) - B.at(3, 0)) < EPSILON &&
                     fabsf(A.at(0, 1) - B.at(0, 1)) < EPSILON &&
                     fabsf(A.at(1, 1) - B.at(1, 1)) < EPSILON &&
                     fabsf(A.at(2, 1) - B.at(2, 1)) < EPSILON &&
                     fabsf(A.at(3, 1) - B.at(3, 1)) < EPSILON &&
                     fabsf(A.at(0, 2) - B.at(0, 2)) < EPSILON &&
                     fabsf(A.at(1, 2) - B.at(1, 2)) < EPSILON &&
                     fabsf(A.at(2, 2) - B.at(2, 2)) < EPSILON &&
                     fabsf(A.at(3, 2) - B.at(3, 2)) < EPSILON &&
                     fabsf(A.at(0, 3) - B.at(0, 3)) < EPSILON &&
                     fabsf(A.at(1, 3) - B.at(1, 3)) < EPSILON &&
                     fabsf(A.at(2, 3) - B.at(2, 3)) < EPSILON &&
                     fabsf(A.at(3, 3) - B.at(3, 3)) < EPSILON);
        COUNT_TEST("Mat4 horizontal fov perspectiveGL", pass);
    }

    {
        Mat4 A = translate(2.0f, 3.0f, 4.0f);
        bool pass = (A.at(0, 3) == 2.0f &&
                     A.at(1, 3) == 3.0f &&
                     A.at(2, 3) == 4.0f &&
                     A.at(3, 3) == 1.0f);
        COUNT_TEST("Mat4 translate", pass);
    }

    // test rotations on separate x, y, and z axes
    {
        float angle = 45.0f;
        float cos0  = M3D_COSF(to_radians(angle));
        float sin0  = M3D_SINF(to_radians(angle));

        {
            Mat4 A = rotation(angle, vec3(1,0,0));
            bool pass = (A.at(0, 0) == 1.0f  &&
                         A.at(1, 1) == cos0  &&
                         A.at(2, 1) == sin0  &&
                         A.at(1, 2) == -sin0 &&
                         A.at(2, 2) == cos0  &&
                         A.at(3, 3) == 1.0f);
            COUNT_TEST("Mat4 rotation x-axis", pass);
        }

        {
            Mat4 A = rotation(angle, vec3(0,1,0));
            bool pass = (A.at(0, 0) == cos0  &&
                         A.at(1, 1) == 1.0f  &&
                         A.at(2, 2) == cos0  &&
                         A.at(0, 2) == sin0  &&
                         A.at(2, 0) == -sin0 &&                         
                         A.at(3, 3) == 1.0f);
            COUNT_TEST("Mat4 rotation y-axis", pass);
        }

        {
            Mat4 A = rotation(angle, vec3(0,0,1));
            bool pass = (A.at(0, 0) == cos0  &&
                         A.at(1, 1) == cos0  &&
                         A.at(2, 2) == 1.0f  &&
                         A.at(0, 1) == -sin0 &&
                         A.at(1, 0) == sin0  &&
                         A.at(3, 3) == 1.0f);
            COUNT_TEST("Mat4 rotation z-axis", pass);
        }
    }

    {
        Mat4 A = scale(2.0f, 3.0f, 4.0f);
        bool pass = (A.at(0, 0) == 2.0f &&
                     A.at(1, 1) == 3.0f &&
                     A.at(2, 2) == 4.0f &&
                     A.at(3, 3) == 1.0f);
        COUNT_TEST("Mat4 scale", pass);
    }

    {
        bool isInvertible = false;
        Mat4 A = scale(3.0f, 4.0f, 8.0f);
        Mat4 B = translate(2.0f, 5.0f, 3.0f);
        Mat4 C = inverse(B * A, &isInvertible);
        bool pass = (fabsf(C.at(0, 0) - 0.33333333f) < EPSILON &&
                     fabsf(C.at(1, 1) - 0.25f)       < EPSILON &&
                     fabsf(C.at(2, 2) - 0.125f)      < EPSILON &&
                     fabsf(C.at(0, 3) - -0.6666666f) < EPSILON &&
                     fabsf(C.at(1, 3) - -1.25f)      < EPSILON &&
                     fabsf(C.at(2, 3) - -0.375f)     < EPSILON &&
                     C.at(3, 3) == 1.0f &&
                     isInvertible == true);
        COUNT_TEST("Mat4 inverse", pass);
    }

    {
        bool isInvertible = true;
        Mat4 A = scale(0.0f, 0.0f, 0.0f);
        Mat4 B = translate(2.0f, 5.0f, 3.0f);
        Mat4 C = inverse(B * A, &isInvertible);
        bool pass = isInvertible == false;
        COUNT_TEST("Mat4 non-invertible inverse", pass);
    }
    
    {
        Mat4 A = translate(2, 3, 4) * scale(2, 3, 4);
        Mat4 B = translate(5, 6, 7) * scale(5, 6, 7);
        Mat4 C = A + B;
        bool pass = (C.at(0, 0) == 7.0f  &&
                     C.at(1, 0) == 0.0f  &&
                     C.at(2, 0) == 0.0f  &&
                     C.at(3, 0) == 0.0f  &&
                     C.at(0, 1) == 0.0f  &&
                     C.at(1, 1) == 9.0f  &&
                     C.at(2, 1) == 0.0f  &&
                     C.at(3, 1) == 0.0f  &&
                     C.at(0, 2) == 0.0f  &&
                     C.at(1, 2) == 0.0f  &&
                     C.at(2, 2) == 11.0f &&
                     C.at(3, 2) == 0.0f  &&
                     C.at(0, 3) == 7.0f  &&
                     C.at(1, 3) == 9.0f  &&
                     C.at(2, 3) == 11.0f &&
                     C.at(3, 3) == 2.0f);
        COUNT_TEST("Mat4 addition", pass);
    }

    {
        Mat4 A = scale(3.0f, 4.0f, 8.0f);
        Mat4 B = identity();
        Mat4 C = B * A;
        bool pass = (C.at(0, 0) == 3.0f &&
                     C.at(1, 1) == 4.0f &&
                     C.at(2, 2) == 8.0f &&
                     C.at(3, 3) == 1.0f &&
                     C.at(3, 0) == 0.0f &&
                     C.at(2, 3) == 0.0f);
        COUNT_TEST("Mat4 mult with identity", pass);
    }

    {
        Mat4 A = scale(3.0f, 4.0f, 8.0f);
        Mat4 B = translate(2.0f, 5.0f, 3.0f);
        Mat4 C = B * A;
        bool pass = (C.at(0, 0) == 3.0f &&
                     C.at(1, 1) == 4.0f &&
                     C.at(2, 2) == 8.0f &&
                     C.at(3, 3) == 1.0f &&
                     C.at(0, 3) == 2.0f &&
                     C.at(1, 3) == 5.0f &&
                     C.at(2, 3) == 3.0f);
        COUNT_TEST("Mat4 translate * scale", pass);
    }

    {
        Mat4 A = scale(6.0f, 2.0f, 9.0f);
        Vec4 b = vec4(12.0f, 3.0f, 4.0f, 1.0f);
        Vec4 c = A * b;
        bool pass = (c.x == 72.0f &&
                     c.y == 6.0f  &&
                     c.z == 36.0f &&
                     c.w == 1.0f);
        COUNT_TEST("Mat4 scale * Vec4", pass);
    }

#undef COUNT_TEST

    printf("\n%zd tests run -- %zd passed -- %zd failed\n\n",
           test_count,
           tests_passed,
           tests_failed);
}

typedef unsigned __int64 u64;

/*
 * The get_start_cycles and get_end_cycles functions are based off
 * the recommendations from this Intel white paper (section 3.2.1):
 *
 * http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf
 *
 * N.B. This should only be used on processors that have an invariant
 * TSC.  More of which can be read about here (MSDN -- Acquiring
 * High-Resolution Time Stamps):
 *
 * https://msdn.microsoft.com/en-us/library/windows/desktop/dn553408(v=vs.85).aspx
 */
__forceinline
u64 get_start_cycles()
{
    unsigned int aux;
    return __rdtscp(&aux);
}

__forceinline
u64 get_end_cycles()
{
    unsigned int aux;
    u64 result = __rdtscp(&aux);
    int cpuInfo[4];
    __cpuid(cpuInfo, 0);
    return result;
}

__forceinline u64 bm_min_of(u64 a, u64 b) { return a < b ? a : b; }
__forceinline u64 bm_max_of(u64 a, u64 b) { return a > b ? a : b; }

void m3d_print_benchmark(char const* name, u64 min, u64 max, double avg)
{
    static char   const *DOTS     = "...................................";
    static size_t const  DOTS_LEN = strlen(DOTS);

    size_t len = strlen(name) + 1; // add one for a space

    if (len < DOTS_LEN)
        printf("%s %s Cycles min: %3llu, max: %3llu, average: %5.1f\n",
               name, DOTS + len, min, max, avg);
    else
        printf("%s Cycles min: %3llu, max: %3llu, average: %5.1f\n",
               name, min, max, avg);
}

#define COUNT_OF(arr) (sizeof(arr) / sizeof((arr)[0]))

struct Rng {
    float data[16];
    float   operator [] (size_t i) const { return data[i]; }
    float & operator [] (size_t i)       { return data[i]; }
};

Rng create_rng()
{
    Rng rng;

    for (int i = 0; i < COUNT_OF(rng.data); ++i) {
        float next = float(rand());
        rng[i] = (next / float(RAND_MAX)) * 5.0f;
    }

    return rng;
}

float sum_mat(Mat4 const &A)
{
    float sum = 0.0f;
    for (int i = 0; i < COUNT_OF(A.data); ++i)
        sum += A.data[i];

    return sum;
}

void m3d_benchmark_suite()
{
    printf("\n=== Running m3d Benchmark Suite ===\n\n");
    srand(static_cast<unsigned int>(time(0)));

    /*
     * This micro benchmark code requires an x86 processor with
     * the rdtscp instruction support and an invariant TSC.  You can
     * determine the latter with the cpuid instruction; however,
     * literally all modern processors have support for these
     * features.
     *
     * For benchmarking we add all the individual elements of
     * computations into the garbage variable which will get
     * get sent to stdout at the end.  This prevents the compiler
     * from optimizing away the computation that is being bechmarked.
     *
     * Additionally, we use RNG values for the setup parameters to
     * prevent the compiler from constant folding any of the computations.
     * Furthermore, this construction of RNG values is done each time
     * in the benchmark loop to keep the compiler from hoisting out
     * setup and benchmark code out of the loop and use one single
     * computation to be added to the garbage out for each loop iteration.
     *
     * The use of volatile to prevent compiler optimizations is avoided as
     * it just generated unnecessary code inside the bechmarked region
     * of the computation.  Also, any benchmark run that exceeds a thousand
     * cycles is thrown out as it is most likely an outlier due to some
     * external factor (e.g. OS context switch).
     */

    float garbage  = 0.0f;
    u64   overhead = _UI64_MAX;

    for (int i = 0; i < 1000; ++i) {
        u64 start   = get_start_cycles();
        u64 end     = get_end_cycles();
        u64 elapsed = end - start;
        overhead = bm_min_of(overhead, elapsed);
    }

#define RUN_BENCHMARK(benchmark, first, second, bench, write_garbage)   \
    {                                                                   \
        int const bm_count = 1000;                                      \
        double bm_sum = 0.0;                                            \
        u64    bm_min = _UI64_MAX;                                      \
        u64    bm_max = 0;                                              \
        for (int bm_i = 0; bm_i < bm_count;) {                          \
            Rng rng = create_rng();                                     \
            first;                                                      \
            second;                                                     \
            u64 bm_start = get_start_cycles();                          \
            bench;                                                      \
            u64 bm_end = get_end_cycles();                              \
            u64 bm_delta = bm_end - bm_start;                           \
            bm_delta = bm_delta > overhead ? bm_delta - overhead : 0;   \
            if (bm_delta > 999)                                         \
                continue;                                               \
            bm_sum += static_cast<double>(bm_delta);                    \
            bm_min = bm_min_of(bm_min, bm_delta);                       \
            bm_max = bm_max_of(bm_max, bm_delta);                       \
            write_garbage;                                              \
            ++bm_i;                                                     \
        }                                                               \
        double bm_avg = bm_sum / static_cast<double>(bm_count);         \
        m3d_print_benchmark(benchmark, bm_min, bm_max, bm_avg);         \
    }

    RUN_BENCHMARK("Vec2 negation",
                  Vec2 a = vec2(rng[0], rng[1]),
                  Vec2 b = vec2(rng[2], rng[3]),
                  Vec2 c = -a,
                  garbage += c.x + c.y);

    RUN_BENCHMARK("Vec2 subtraction",
                  Vec2 a = vec2(rng[0], rng[1]),
                  Vec2 b = vec2(rng[2], rng[3]),
                  Vec2 c = b - a,
                  garbage += c.x + c.y);

    RUN_BENCHMARK("Vec2 addition",
                  Vec2 a = vec2(rng[0], rng[1]),
                  Vec2 b = vec2(rng[2], rng[3]),
                  Vec2 c = b + a,
                  garbage += c.x + c.y);

    RUN_BENCHMARK("Vec2 scalar multiplication",
                  Vec2  a = vec2(rng[0], rng[1]),
                  float s = rng[2],
                  Vec2  b = s * a,
                  garbage += b.x + b.y);

    RUN_BENCHMARK("Vec2 scalar division",
                  Vec2  a = vec2(rng[0], rng[1]),
                  float s = 7.5f,
                  Vec2  b = a / s,
                  garbage += b.x + b.y);

    RUN_BENCHMARK("Vec2 hadamard product",
                  Vec2 a = vec2(rng[0], rng[1]),
                  Vec2 b = vec2(rng[2], rng[3]),
                  Vec2 c = hadamard(a, b),
                  garbage += c.x + c.y);

    RUN_BENCHMARK("Vec2 dot product",
                  Vec2  a = vec2(rng[0], rng[1]),
                  Vec2  b = vec2(rng[2], rng[3]),
                  float c = dot(a, b),
                  garbage += c);

    RUN_BENCHMARK("Vec2 length squared",
                  Vec2 a = vec2(rng[0], rng[1]),
                  {},
                  float b = len_sq(a),
                  garbage += b);

    RUN_BENCHMARK("Vec2 length",
                  Vec2 a = vec2(rng[0], rng[1]),
                  {},
                  float b = length(a),
                  garbage += b);

    RUN_BENCHMARK("Vec2 normalize",
                  Vec2 a = vec2(rng[0], rng[1]),
                  {},
                  Vec2 b = normalize(a),
                  garbage += b.x + b.y);

    RUN_BENCHMARK("Vec3 negation",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  Vec3 b = vec3(rng[3], rng[4], rng[5]),
                  Vec3 c = -a,
                  garbage += c.x + c.y + c.z);

    RUN_BENCHMARK("Vec3 subtraction",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  Vec3 b = vec3(rng[3], rng[4], rng[5]),
                  Vec3 c = b - a,
                  garbage += c.x + c.y + c.z);

    RUN_BENCHMARK("Vec3 addition",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  Vec3 b = vec3(rng[3], rng[4], rng[5]),
                  Vec3 c = b + a,
                  garbage += c.x + c.y + c.z);

    RUN_BENCHMARK("Vec3 scalar multiplication",
                  Vec3  a = vec3(rng[0], rng[1], rng[2]),
                  float s = rng[2],
                  Vec3  b = s * a,
                  garbage += b.x + b.y + b.z);

    RUN_BENCHMARK("Vec3 scalar division",
                  Vec3  a = vec3(rng[0], rng[1], rng[2]),
                  float s = 7.5f,
                  Vec3  b = a / s,
                  garbage += b.x + b.y + b.z);

    RUN_BENCHMARK("Vec3 hadamard product",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  Vec3 b = vec3(rng[3], rng[4], rng[5]),
                  Vec3 c = hadamard(a, b),
                  garbage += c.x + c.y);

    RUN_BENCHMARK("Vec3 dot product",
                  Vec3  a  = vec3(rng[0], rng[1], rng[2]),
                  Vec3  b  = vec3(rng[3], rng[4], rng[5]),
                  float c  = dot(a, b),
                  garbage += c);

    RUN_BENCHMARK("Vec3 cross product",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  Vec3 b = vec3(rng[3], rng[4], rng[5]),
                  Vec3 c = cross(a, b),
                  garbage += c.x + c.y + c.z);

    RUN_BENCHMARK("Vec3 length squared",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  {},
                  float b = len_sq(a),
                  garbage += b);

    RUN_BENCHMARK("Vec3 length",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  {},
                  float b = length(a),
                  garbage += b);

    RUN_BENCHMARK("Vec3 normalize",
                  Vec3 a = vec3(rng[0], rng[1], rng[2]),
                  {},
                  Vec3 b = normalize(a),
                  garbage += b.x + b.y + b.z);

    RUN_BENCHMARK("Vec4 negation",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  Vec4 b = vec4(rng[4], rng[5], rng[6], rng[7]),
                  Vec4 c = -a,
                  garbage += c.x + c.y + c.z + c.w);

    RUN_BENCHMARK("Vec4 subtraction",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  Vec4 b = vec4(rng[4], rng[5], rng[6], rng[7]),
                  Vec4 c = b - a,
                  garbage += c.x + c.y + c.z + c.w);

    RUN_BENCHMARK("Vec4 addition",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  Vec4 b = vec4(rng[4], rng[5], rng[6], rng[7]),
                  Vec4 c = b + a,
                  garbage += c.x + c.y + c.z + c.w);

    RUN_BENCHMARK("Vec4 scalar multiplication",
                  Vec4  a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  float s = rng[2],
                  Vec4  b = s * a,
                  garbage += b.x + b.y + b.z + b.w);

    RUN_BENCHMARK("Vec4 scalar division",
                  Vec4  a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  float s = 7.5f,
                  Vec4  b = a / s,
                  garbage += b.x + b.y + b.z + b.w);

    RUN_BENCHMARK("Vec4 hadamard product",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  Vec4 b = vec4(rng[4], rng[5], rng[6], rng[7]),
                  Vec4 c = hadamard(a, b),
                  garbage += c.x + c.y + c.z + c.w);

    RUN_BENCHMARK("Vec4 dot product",
                  Vec4  a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  Vec4  b = vec4(rng[4], rng[5], rng[6], rng[7]),
                  float c = dot(a, b),
                  garbage += c);

    RUN_BENCHMARK("Vec4 length squared",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  {},
                  float b = len_sq(a),
                  garbage += b);

    RUN_BENCHMARK("Vec4 length",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  {},
                  float b = length(a),
                  garbage += b);

    RUN_BENCHMARK("Vec4 normalize",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  {},
                  Vec4 b = normalize(a),
                  garbage += b.x + b.y + b.z + b.w);

    RUN_BENCHMARK("Mat4 orthoGL", {}, {},
                  Mat4 A = orthoGL(rng[0], rng[1], rng[2], rng[3], rng[4], rng[5]),
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 perspectiveGL", {}, {},
                  Mat4 A = perspectiveGL(rng[0], rng[1], rng[2], rng[3], rng[4], rng[5]),
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 perspectiveGL HOV", {}, {},
                  Mat4 A = perspectiveGL(rng[0], rng[1], rng[2], rng[3]),
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 translate", {}, {},
                  Mat4 A = translate(rng[0], rng[1], rng[2]),
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 rotation", {}, {},
                  Mat4 A = rotation(rng[0], vec3(0,0,1)),
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 scale", {}, {},
                  Mat4 A = scale(rng[0], rng[1], rng[2]),
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 inverse",
                  bool isInvertible = false,
                  Mat4 A = translate(rng[0], rng[1], rng[2]),
                  Mat4 B = inverse(A, &isInvertible),
                  garbage += sum_mat(A));
    
    RUN_BENCHMARK("Mat4 addition",
                  Mat4 A = scale(rng[0], rng[1], rng[2]),
                  Mat4 B = translate(rng[3], rng[4], rng[5]),
                  Mat4 C = B + A,
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 multiplication",
                  Mat4 A = scale(rng[0], rng[1], rng[2]),
                  Mat4 B = translate(rng[3], rng[4], rng[5]),
                  Mat4 C = B * A,
                  garbage += sum_mat(A));

    RUN_BENCHMARK("Mat4 Vec4 multiplication",
                  Vec4 a = vec4(rng[0], rng[1], rng[2], rng[3]),
                  Mat4 B = translate(rng[4], rng[5], rng[6]),
                  Vec4 c = B * a,
                  garbage += c.x + c.y + c.z + c.w);

    puts("\n");
    printf("Garbage out: %f\n\n", garbage);
    
#undef RUN_BENCHMARK
}

int main(int, char *[])
{
    m3d_test_suite();
    m3d_benchmark_suite();
    return 0;
}
