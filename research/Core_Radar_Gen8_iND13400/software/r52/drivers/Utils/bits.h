#ifndef _BITS_H
#define _BITS_H

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-empty-struct"

#define __WORDSIZE    (__SIZEOF_LONG__ * 8)
#define BITS_PER_LONG __WORDSIZE

#define BIT(bi)     (1UL << (bi))
#define BIT_ULL(bi) (1ULL << (bi))

#define __is_constexpr(x) (sizeof(int) == sizeof(*(8 ? ((void *)((long)(x)*0l)) : (int *)8)))

#define BUILD_BUG_ON_ZERO(e) ((int)(sizeof(struct { int : (-!!(e)); })))

#define GENMASK_INPUT_CHECK(h, l) (BUILD_BUG_ON_ZERO(__builtin_choose_expr(__is_constexpr((l) > (h)), (l) > (h), 0)))

#define __GENMASK(h, l) (((~(0UL)) - ((1UL) << (l)) + 1) & (~(0UL) >> (BITS_PER_LONG - 1 - (h))))

#define GENMASK(h, l) (GENMASK_INPUT_CHECK(h, l) + __GENMASK(h, l))

#pragma clang diagnostic pop

#endif
