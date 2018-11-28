/*
 * File: On_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "On_ca.h"

CA_HWImpl_TestResults CA_On_HWRes;
CA_PWS_TestResults CA_On_PWSRes;
const CA_HWImpl CA_On_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "ARM Compatible->ARM Cortex",        /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_On_ActHW;
void On_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_On_ActHW, &CA_On_ExpHW, &CA_On_PWSRes);
  caVerifyHWImpl(&CA_On_ActHW, &CA_On_ExpHW, &CA_On_HWRes);
}
