/*===========================================================================*/
/**
 * @file mpu_fake.cc
 *
 * FFF fake definitions for mpu.c unit tests.
 */
/*==========================================================================*/
#include "mpu_fake.h"

DEFINE_FAKE_VALUE_FUNC(int32_t, xthal_read_map, struct xthal_MPU_entry *);
DEFINE_FAKE_VOID_FUNC(xthal_write_map, const struct xthal_MPU_entry *, uint32_t);
DEFINE_FAKE_VALUE_FUNC(int32_t, xthal_check_map, const struct xthal_MPU_entry *, uint32_t);
