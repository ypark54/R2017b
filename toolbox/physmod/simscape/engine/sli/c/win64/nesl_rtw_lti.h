#ifndef __nesl_rtw_lti_h__
#define __nesl_rtw_lti_h__
#include "pm_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
PmAllocator *pm_default_allocator(void);int_T pm_create_sparsity_pattern_fields
(PmSparsityPattern *patternPtr,size_t nNzMax,size_t nRow,size_t nCol,
PmAllocator *allocator);PmSparsityPattern *pm_create_sparsity_pattern(size_t
nNzMax,size_t nRow,size_t nCol,PmAllocator *allocatorPtr);void pm_sp_equals_sp
(PmSparsityPattern *Ap,const PmSparsityPattern *Bp);boolean_T
pm_sp_equalequals_sp(const PmSparsityPattern *Ap,const PmSparsityPattern *Bp);
PmSparsityPattern *pm_copy_sparsity_pattern(const PmSparsityPattern *
input_pattern,PmAllocator *allocatorPtr);void
pm_destroy_sparsity_pattern_fields(PmSparsityPattern *patternPtr,PmAllocator *
allocator);void pm_destroy_sparsity_pattern(PmSparsityPattern *patternPtr,
PmAllocator *allocatorPtr);PmSparsityPattern *pm_create_full_sparsity_pattern(
size_t nrows,size_t ncols,PmAllocator *allocatorPtr);PmSparsityPattern *
pm_create_empty_sparsity_pattern(size_t nrows,size_t ncols,PmAllocator *
allocatorPtr);PmSparsityPattern *pm_create_partial_identity_sparsity_pattern(
size_t p,size_t n,PmAllocator *allocatorPtr);PmSparsityPattern *
pm_create_identity_sparsity_pattern(size_t n,PmAllocator *allocatorPtr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "mc_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
const McLinearAlgebra *mc_get_csparse_rect_la(void);real_T
mc_csparse_rect_la_cond(const McLinearAlgebraData *mcLaData);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "mc_std.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
const McLinearAlgebra *mc_get_csparse_linear_algebra(void);real_T
mc_csparse_cond(const void *mcLaData);PMF_DEPLOY_STATIC boolean_T cgSolve(
const int32_T m,const int32_T n,int32_T *matIr,int32_T *matJc,const real_T *
matPr,real_T *xPr,real_T *rhsPr,boolean_T doDCOpt){const McLinearAlgebra *la=
doDCOpt?mc_get_csparse_linear_algebra():mc_get_csparse_rect_la();PmAllocator *
allocator= pm_default_allocator();PmSparsityPattern pattern;
McLinearAlgebraData *data= NULL;McLinearAlgebraStatus status= MC_LA_OK;pattern
.mJc= matJc;pattern.mIr= matIr;pattern.mNumRow= m;pattern.mNumCol= n;data= la
->mConstructor(allocator,&pattern);status= la->mSymbolic(data);if(status!=
MC_LA_OK){return false;}status= la->mNumeric(data,matPr);if(status!=MC_LA_OK){
la->mSymbolicDestroy(data);return false;}status= la->mSolve(data,matPr,xPr,
rhsPr);la->mNumericDestroy(data);la->mSymbolicDestroy(data);la->mDestructor(
allocator,data);return status==MC_LA_OK;}
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* __nesl_rtw_lti_h__ */
