#pragma once

#ifdef TOWER_EXPORTS
#define TOWER_API __declspec(dllexport)
#else
#define TOWER_API __declspec(dllimport)
#endif

extern "C" {
#include <GLFW/glfw3.h>
#include <glad/glad.h>
}


// stl global includes
// stl library with signed integer types with exact widths
#include <cstdint>
// stl library with memory utils. Tower uses shared_ptr and unique_ptr
#include <memory>
#include <string>
#include <cassert>


#define REAL_MAX FLT_MAX
#define real_sqrt sqrtf
#define real_abs fabsf
#define real_sin sinf
#define real_cos cosf
#define real_tan tanf
#define real_atan atanf
#define real_atan2 atan2f
#define real_exp expf
#define real_pow powf
#define real_fmod fmod4
#define real_epsilon DBL_EPSILON

using std::shared_ptr;
using std::unique_ptr;
using std::string;

// Custom typedefs
typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;
typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef float F32;
typedef double F64;
// Separate because sometimes we want to be able to change just what a real number is.
// Also use this wherever you are talking about a real number. Only use F32 when you
// need a 32 bit floating point number SPECIFICALLY.
typedef float real;

const real R_PI = static_cast<real>(3.14159265358979);

//==========================================================================================================================
// Global Helper functions
//==========================================================================================================================
inline real REAL_SQR(real x)
{
    return x * x;
}

inline real RADIAN(real angle)
{
    return static_cast<real>(angle * R_PI / 180.0f);
}

inline real DEGREE(real radian)
{
    return static_cast<real>(radian * 180.0f / R_PI);
}

inline real REAL_CLAMP(real val, real min, real max)
{
    if (val < min)
    {
        return min;
    }
    else if (val > max)
    {
        return max;
    }
    else
    {
        return val;
    }
}