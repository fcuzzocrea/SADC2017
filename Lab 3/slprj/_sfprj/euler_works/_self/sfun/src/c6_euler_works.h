#ifndef __c6_euler_works_h__
#define __c6_euler_works_h__

/* Type Definitions */
#ifndef typedef_SFc6_euler_worksInstanceStruct
#define typedef_SFc6_euler_worksInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_euler_works;
  void *c6_fEmlrtCtx;
  real_T (*c6_xp)[3];
  real_T (*c6_A_LN)[9];
  real_T (*c6_xp_dot)[3];
} SFc6_euler_worksInstanceStruct;

#endif                                 /*typedef_SFc6_euler_worksInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_euler_works_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_euler_works_get_check_sum(mxArray *plhs[]);
extern void c6_euler_works_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
