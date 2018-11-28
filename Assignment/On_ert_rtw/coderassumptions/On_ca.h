/*
 * File: On_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef ON_CA_H
#define ON_CA_H

/* preprocessor validation checks */
#include "On_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_On_HWRes;
extern CA_PWS_TestResults CA_On_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_On_ExpHW;
extern CA_HWImpl CA_On_ActHW;

/* entry point function to run tests */
void On_caRunTests(void);

#endif                                 /* ON_CA_H */
