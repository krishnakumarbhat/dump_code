/* Tiny assert harness for A-PRISM host tests (clang, deterministic). */
#ifndef APRISM_TEST_H
#define APRISM_TEST_H

#include <math.h>
#include <stdio.h>

static int aprism_fail = 0;

#define APRISM_CHECK(cond) do { \
    if (!(cond)) { \
        printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
        aprism_fail++; \
    } } while (0)

#define APRISM_CHECK_CLOSE(a, b, tol) do { \
    double _da = (double)(a), _db = (double)(b); \
    double _dd = _da - _db; if (_dd < 0) _dd = -_dd; \
    if (!(_dd <= (tol))) { \
        printf("FAIL %s:%d: |%g - %g| = %g > %g\n", \
               __FILE__, __LINE__, _da, _db, _dd, (double)(tol)); \
        aprism_fail++; \
    } } while (0)

/* Deterministic xorshift64 RNG + Box-Muller normal. */
static unsigned long long aprism_rng = 0x123456789ABCULL;

__attribute__((unused)) static double aprism_uni(void)
{
    aprism_rng ^= aprism_rng << 13;
    aprism_rng ^= aprism_rng >> 7;
    aprism_rng ^= aprism_rng << 17;
    return (double)(aprism_rng >> 11) * (1.0 / 9007199254740992.0);
}

__attribute__((unused)) static double aprism_gauss(void)
{
    double u1 = aprism_uni() + 1e-12, u2 = aprism_uni();
    return sqrt(-2.0 * log(u1)) * cos(6.283185307179586 * u2);
}

#define APRISM_REPORT(name) do { \
    if (aprism_fail == 0) { printf("%s PASS\n", name); } \
    else { printf("%s FAIL (%d)\n", name, aprism_fail); } \
    return aprism_fail; } while (0)

#endif /* APRISM_TEST_H */
