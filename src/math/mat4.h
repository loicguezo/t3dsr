#ifndef MATRIX4_H
#define MATRIX4_H

#define MAT_SIZE 16
#define MAT_DIM 4

#ifndef SIMD
#if defined(__x86_64__) || defined(__amd64__) || defined(_M_X64)
#define SIMD_X86

#elif defined(__aarch64__) || defined(__arm64__) || defined(_M_ARM64)
#define SIMD_ARCH

#else
#endif
#define SIMD
#endif

#ifdef _MSC_VER
#define ALIGN16_MAT __declspec(align(MAT_SIZE))
#else
#define ALIGN16_MAT __attribute__((aligned(MAT_SIZE)))
#endif

typedef struct
{
    float m[MAT_SIZE];
} ALIGN16_MAT Mat4f_t;

Mat4f_t* mat4f_from_array_ip(Mat4f_t* __restrict m, const float arr[MAT_SIZE]);

static inline Mat4f_t mat4f_from_array(const float arr[MAT_SIZE])
{
    Mat4f_t mat;
    mat4f_from_array_ip(&mat, arr);
    return mat;
}

Mat4f_t* mat4f_scalar_ip(Mat4f_t* __restrict m, float f);

static inline Mat4f_t mat4f_scalar(float f)
{
    Mat4f_t mat;
    mat4f_scalar_ip(&mat, f);
    return mat;
}

Mat4f_t* mat4f_zero_ip(Mat4f_t* __restrict m);

static inline Mat4f_t mat4f_zero(void)
{
    Mat4f_t mat;
    mat4f_zero_ip(&mat);
    return mat;
}

Mat4f_t* mat4f_identity_ip(Mat4f_t* __restrict m);

static inline Mat4f_t mat4f_identity(void)
{
    Mat4f_t mat;
    mat4f_identity_ip(&mat);
    return mat;
}

inline static Mat4f_t mat4f_clone(const Mat4f_t* __restrict out)
{
    return *out;
}

Mat4f_t* mat4f_add_ip(Mat4f_t* out, const Mat4f_t* m2);

static inline Mat4f_t mat4f_add(const Mat4f_t* m1, const Mat4f_t* m2)
{
    Mat4f_t mout = mat4f_clone(m1);
    mat4f_add_ip(&mout, m2);
    return mout;
}

Mat4f_t* mat4f_sub_ip(Mat4f_t* out, const Mat4f_t* m2);

static inline Mat4f_t mat4f_sub(const Mat4f_t* m1, const Mat4f_t* m2)
{
    Mat4f_t mout = mat4f_clone(m1);
    mat4f_sub_ip(&mout, m2);
    return mout;
}

Mat4f_t* mat4f_scale_ip(Mat4f_t* out, float scalar);
static inline Mat4f_t mat4f_scale(const Mat4f_t* __restrict m, float scalar)
{
    Mat4f_t mout = mat4f_clone(m);
    mat4f_scale_ip(&mout, scalar);
    return mout;
}

// row * col
Mat4f_t* mat4f_mul_ip(Mat4f_t* out, const Mat4f_t* m2);
static inline Mat4f_t mat4f_mul(const Mat4f_t* m1, const Mat4f_t* m2)
{
    Mat4f_t mout = mat4f_clone(m1);
    mat4f_mul_ip(&mout, m2);
    return mout;
}

Mat4f_t* mat4f_tpo_ip(Mat4f_t* __restrict m);
static inline Mat4f_t mat4f_tpo(const Mat4f_t* __restrict m)
{
    Mat4f_t res = mat4f_clone(m);
    mat4f_tpo_ip(&res);
    return res;
}

float mat4f_det(const Mat4f_t* m);

Mat4f_t* mat4f_inv_ip(Mat4f_t* __restrict m);

static inline Mat4f_t mat4f_inv(const Mat4f_t* m)
{
    Mat4f_t mout = mat4f_clone(m);
    mat4f_inv_ip(&mout);
    return mout;
}

#endif  // MATRIX4_H
