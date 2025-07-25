#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
// parametrized constructor e.g (1.0, 2.0, 3.0)
public:
    double e[3];
    vec3() : e{0, 0, 0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // getter to access coords.
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // minus operator to negate the vector => neg = vec3(-1.0, 2.0, -3.0)
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    // read vector as array
    double operator[](int i) const { return e[i]; }
    // read-write vector as array
    double& operator[](int i) { return e[i]; }

    // in-place vector addition
    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // multiply vector by a scalar
    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // scalar division
    vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    // euclidian length
    double length() const {
        return std::sqrt(length_squared());
    }

    // squared length
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// just alias for vec3 for clarity
using point3 = vec3;

// output vector to stream e.g. std::cout << v => "1 2 3"
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// vector addition
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// vector subtraction
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// component-wise vector multiplication
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// scalar * vector (left-side)
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

// vector * scalar (right-side)
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

// vector / scalar
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

// dot product of two vectors
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

// cross product of two vectors
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

// return unit vector (normalized)
inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif //VEC3_H
