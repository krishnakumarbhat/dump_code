/**
 * @file xtensa/tie/xt_ioports.h
 *
 * Empty stub that shadows the real Xtensa header for x86 unit testing.
 * The real header provides XT_RER / XT_WER / XT_ISYNC intrinsics which are
 * replaced by FFF mocks via dss_ecc_parity_mock.h when UNIT_TEST is defined.
 */
#ifndef XT_IOPORTS_STUB_H
#define XT_IOPORTS_STUB_H
#endif
