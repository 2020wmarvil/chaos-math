#pragma once

#include <vec.hpp>

namespace cm {

// https://newbedev.com/how-to-achieve-vector-swizzling-in-c
template<typename T, unsigned int I>
struct scalar_swizzle {
    T v[1];
    T &operator=(const T x) {
        v[I] = x;
        return v[I];
    }

    operator T() const {
        return v[I];
    }

    T operator++(int) {
        return v[I]++;
    }

    T operator++() {
        return ++v[I];
    }

    T operator--(int) {
        return v[I]--;
    }

    T operator--() {
        return --v[I];
    }

    scalar_swizzle& operator+=(const scalar_swizzle& right) {
      v[I] += right;
      return *this;
    }

    friend scalar_swizzle operator+(scalar_swizzle left, const scalar_swizzle& right) {
      left += right;
      return left;
    }
};

// We use a vec_type in a template instead of forward declartions to prevent erros in some compilers.
template<typename vec_type, typename T, unsigned int A, unsigned int B>
struct vec2_swizzle {
    T d[2];
    vec_type operator=(const vec_type& vec) {
        return vec_type(d[A] = vec.x, d[B] = vec.y);
    }

    operator vec_type() {
        return vec_type(d[A], d[B]);
    }
};

template<typename T>
struct vec2 {
    float k;
    union {
        T d[2];
        scalar_swizzle<T, 0> x, i;
        scalar_swizzle<T, 1> y, j;

        vec2_swizzle<vec2, T, 0, 0> xx;
        vec2_swizzle<vec2, T, 0, 1> xy;
        vec2_swizzle<vec2, T, 1, 0> yx;
        vec2_swizzle<vec2, T, 1, 1> yy;
    };

    class : public ReadOnlyProperty<float> { 
    public:
        vec2<T>* _vec;

        void SetVec(vec2<T>* vec) { _vec = vec; }

        virtual operator float const & () const {
            return std::sqrt(_vec->x* _vec->x + _vec->y* _vec->y); 
        }
    } magnitude;

    vec2() : vec2(0, 0) { }
    vec2(T all) : vec2(all, all) { }
    vec2(T a, T b) {
        x = a; y = b;
        magnitude.SetVec(this);
    }

    vec2& operator+=(const vec2& right) {
      x += right.x;
      y += right.y;
      return *this;
    }

    friend vec2 operator+(vec2 left, const vec2& right) {
      left += right;
      return left;
    }

    vec2& operator-=(const vec2& right) {
      x += right.x;
      y += right.y;
      return *this;
    }

    friend vec2 operator-(vec2 left, const vec2& right) {
      left += right;
      return left;
    }
};

inline std::ostream& operator<<(std::ostream &os, vec2<float> vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

inline std::ostream& operator<<(std::ostream &os, vec2<int> vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

}
