#include <ParTI.h>

#ifndef unlikely
#define unlikely(x) __builtin_expect(!!(x), 0)
#endif unlikely

#ifndef spt_CheckError
#define spt_CheckError(errcode, module, reason) \
    if(unlikely((errcode) != 0)) { \
        spt_ComplainError(module, (errcode), __FILE__, __LINE__, (reason)); \
        return (errcode); \
    }
#endif

void spt_ComplainError(const char *module, int errcode, const char *file, unsigned line, const char *reason);

int ccsd_task_0(
    /* output */ sptSparseTensor *i0_aaaa,
    /* output */ sptSparseTensor *i0_abab,
    /* output */ sptSparseTensor *i0_bbbb,
    /* input  */ sptSparseTensor *_a004_aaaa,
    /* input  */ sptSparseTensor *_a004_abab,
    /* input  */ sptSparseTensor *_a004_bbbb,
    /* input  */ sptSparseTensor *chol3d_aa_oo,
    /* input  */ sptSparseTensor *chol3d_aa_ov,
    /* input  */ sptSparseTensor *chol3d_aa_vo,
    /* input  */ sptSparseTensor *chol3d_aa_vv,
    /* input  */ sptSparseTensor *chol3d_bb_oo,
    /* input  */ sptSparseTensor *chol3d_bb_ov,
    /* input  */ sptSparseTensor *chol3d_bb_vo,
    /* input  */ sptSparseTensor *chol3d_bb_vv,
    /* input  */ sptSparseTensor *f1_aa_oo,
    /* input  */ sptSparseTensor *f1_aa_ov,
    /* input  */ sptSparseTensor *f1_aa_vv,
    /* input  */ sptSparseTensor *f1_bb_oo,
    /* input  */ sptSparseTensor *f1_bb_ov,
    /* input  */ sptSparseTensor *f1_bb_vv,
    /* input  */ sptSparseTensor *t1_aa,
    /* input  */ sptSparseTensor *t1_bb,
    /* input  */ sptSparseTensor *t2_aaaa,
    /* input  */ sptSparseTensor *t2_abab,
    /* input  */ sptSparseTensor *t2_bbbb,
) {
    // _a017_aa(p3_va, h2_oa, cind)            = -1.0   * t2_aaaa(p1_va, p3_va, h3_oa, h2_oa) * chol3d_aa_ov(h3_oa, p1_va, cind)
    // _a017_bb(p3_vb, h2_ob, cind)            = -1.0   * t2_bbbb(p1_vb, p3_vb, h3_ob, h2_ob) * chol3d_bb_ov(h3_ob, p1_vb, cind)
    sptSparseTensor _a017_aa;
    sptSparseTensor _a017_bb;
    {
        static const sptIndex cmodes_X[] = [0, 2];
        static const sptIndex cmodes_Y[] = [1, 0];
        static const sptIndex cmodes_X2[] = [0, 2];
        static const sptIndex cmodes_Y2[] = [1, 0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a017_aa,
            /* X */ &t2_aaaa,
            /* Y */ &chol3d_aa_ov,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a017_bb,
            /* X2 */ &t2_bbbb,
            /* Y2 */ &chol3d_bb_ov,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a017_bb(p3_vb, h2_ob, cind)           += -1.0   * t2_abab(p1_va, p3_vb, h3_oa, h2_ob) * chol3d_aa_ov(h3_oa, p1_va, cind)
    // _a017_aa(p3_va, h2_oa, cind)           += -1.0   * t2_abab(p3_va, p1_vb, h2_oa, h3_ob) * chol3d_bb_ov(h3_ob, p1_vb, cind)
    sptFreeSparseTensor(&_a017_bb);
    sptFreeSparseTensor(&_a017_aa);
    {
        static const sptIndex cmodes_X[] = [0, 2];
        static const sptIndex cmodes_Y[] = [1, 0];
        static const sptIndex cmodes_X2[] = [1, 3];
        static const sptIndex cmodes_Y2[] = [1, 0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a017_bb,
            /* X */ &t2_abab,
            /* Y */ &chol3d_aa_ov,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a017_aa,
            /* X2 */ &t2_abab,
            /* Y2 */ &chol3d_bb_ov,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a006_aa(h4_oa, h1_oa)                  = -1.0   * chol3d_aa_ov(h4_oa, p2_va, cind) * _a017_aa(p2_va, h1_oa, cind)
    // _a006_bb(h4_ob, h1_ob)                  = -1.0   * chol3d_bb_ov(h4_ob, p2_vb, cind) * _a017_bb(p2_vb, h1_ob, cind)
    sptSparseTensor _a006_aa;
    sptSparseTensor _a006_bb;
    {
        static const sptIndex cmodes_X[] = [1, 2];
        static const sptIndex cmodes_Y[] = [0, 2];
        static const sptIndex cmodes_X2[] = [1, 2];
        static const sptIndex cmodes_Y2[] = [0, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a006_aa,
            /* X */ &chol3d_aa_ov,
            /* Y */ &_a017_aa,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a006_bb,
            /* X2 */ &chol3d_bb_ov,
            /* Y2 */ &_a017_bb,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a007(cind)                             =  1.0   * chol3d_aa_ov(h4_oa, p1_va, cind) * t1_aa(p1_va, h4_oa)
    // _a009_aa(h3_oa, h2_oa, cind)            =  1.0   * chol3d_aa_ov(h3_oa, p1_va, cind) * t1_aa(p1_va, h2_oa)
    sptSparseTensor _a007;
    sptSparseTensor _a009_aa;
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [1, 0];
        static const sptIndex cmodes_X2[] = [1];
        static const sptIndex cmodes_Y2[] = [0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a007,
            /* X */ &chol3d_aa_ov,
            /* Y */ &t1_aa,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a009_aa,
            /* X2 */ &chol3d_aa_ov,
            /* Y2 */ &t1_aa,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a007(cind)                            +=  1.0   * chol3d_bb_ov(h4_ob, p1_vb, cind) * t1_bb(p1_vb, h4_ob)
    // _a009_bb(h3_ob, h2_ob, cind)            =  1.0   * chol3d_bb_ov(h3_ob, p1_vb, cind) * t1_bb(p1_vb, h2_ob)
    sptFreeSparseTensor(&_a007);
    sptSparseTensor _a009_bb;
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [1, 0];
        static const sptIndex cmodes_X2[] = [1];
        static const sptIndex cmodes_Y2[] = [0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a007,
            /* X */ &chol3d_bb_ov,
            /* Y */ &t1_bb,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a009_bb,
            /* X2 */ &chol3d_bb_ov,
            /* Y2 */ &t1_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a021_aa(p3_va, p1_va, cind)            = -0.5   * chol3d_aa_ov(h3_oa, p1_va, cind) * t1_aa(p3_va, h3_oa)
    // _a021_bb(p3_vb, p1_vb, cind)            = -0.5   * chol3d_bb_ov(h3_ob, p1_vb, cind) * t1_bb(p3_vb, h3_ob)
    sptSparseTensor _a021_aa;
    sptSparseTensor _a021_bb;
    {
        static const sptIndex cmodes_X[] = [0];
        static const sptIndex cmodes_Y[] = [1];
        static const sptIndex cmodes_X2[] = [0];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a021_aa,
            /* X */ &chol3d_aa_ov,
            /* Y */ &t1_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a021_bb,
            /* X2 */ &chol3d_bb_ov,
            /* Y2 */ &t1_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a021_aa(p3_va, p1_va, cind)           +=  0.5   * chol3d_aa_vv(p3_va, p1_va, cind)
    sptFreeSparseTensor(&_a021_aa);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a021_aa,
            /* src */ chol3d_aa_vv,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a021_bb(p3_vb, p1_vb, cind)           +=  0.5   * chol3d_bb_vv(p3_vb, p1_vb, cind)
    sptFreeSparseTensor(&_a021_bb);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a021_bb,
            /* src */ chol3d_bb_vv,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a017_aa(p3_va, h2_oa, cind)           += -2.0   * t1_aa(p2_va, h2_oa) * _a021_aa(p3_va, p2_va, cind)
    // _a017_bb(p3_vb, h2_ob, cind)           += -2.0   * t1_bb(p2_vb, h2_ob) * _a021_bb(p3_vb, p2_vb, cind)
    sptFreeSparseTensor(&_a017_aa);
    sptFreeSparseTensor(&_a017_bb);
    {
        static const sptIndex cmodes_X[] = [0];
        static const sptIndex cmodes_Y[] = [1];
        static const sptIndex cmodes_X2[] = [0];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a017_aa,
            /* X */ &t1_aa,
            /* Y */ &_a021_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a017_bb,
            /* X2 */ &t1_bb,
            /* Y2 */ &_a021_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a008_aa(h3_oa, h1_oa, cind)            =  1.0   * _a009_aa(h3_oa, h1_oa, cind)
    sptSparseTensor _a008_aa;
    {
        int result = sptCopySparseTensor(
            /* dest */ _a008_aa,
            /* src */ _a009_aa,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a008_bb(h3_ob, h1_ob, cind)            =  1.0   * _a009_bb(h3_ob, h1_ob, cind)
    sptSparseTensor _a008_bb;
    {
        int result = sptCopySparseTensor(
            /* dest */ _a008_bb,
            /* src */ _a009_bb,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a009_aa(h3_oa, h1_oa, cind)           +=  1.0   * chol3d_aa_oo(h3_oa, h1_oa, cind)
    sptFreeSparseTensor(&_a009_aa);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a009_aa,
            /* src */ chol3d_aa_oo,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a009_bb(h3_ob, h1_ob, cind)           +=  1.0   * chol3d_bb_oo(h3_ob, h1_ob, cind)
    sptFreeSparseTensor(&_a009_bb);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a009_bb,
            /* src */ chol3d_bb_oo,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a001_aa(p4_va, p2_va)                  = -2.0   * _a021_aa(p4_va, p2_va, cind) * _a007(cind)
    // _a001_bb(p4_vb, p2_vb)                  = -2.0   * _a021_bb(p4_vb, p2_vb, cind) * _a007(cind)
    sptSparseTensor _a001_aa;
    sptSparseTensor _a001_bb;
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [0];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a001_aa,
            /* X */ &_a021_aa,
            /* Y */ &_a007,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a001_bb,
            /* X2 */ &_a021_bb,
            /* Y2 */ &_a007,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a001_aa(p4_va, p2_va)                 += -1.0   * _a017_aa(p4_va, h2_oa, cind) * chol3d_aa_ov(h2_oa, p2_va, cind)
    // _a001_bb(p4_vb, p2_vb)                 += -1.0   * _a017_bb(p4_vb, h2_ob, cind) * chol3d_bb_ov(h2_ob, p2_vb, cind)
    sptFreeSparseTensor(&_a001_aa);
    sptFreeSparseTensor(&_a001_bb);
    {
        static const sptIndex cmodes_X[] = [0, 2];
        static const sptIndex cmodes_Y[] = [0, 2];
        static const sptIndex cmodes_X2[] = [0, 2];
        static const sptIndex cmodes_Y2[] = [0, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a001_aa,
            /* X */ &_a017_aa,
            /* Y */ &chol3d_aa_ov,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a001_bb,
            /* X2 */ &_a017_bb,
            /* Y2 */ &chol3d_bb_ov,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a006_aa(h4_oa, h1_oa)                 +=  1.0   * _a009_aa(h4_oa, h1_oa, cind) * _a007(cind)
    // _a006_bb(h4_ob, h1_ob)                 +=  1.0   * _a009_bb(h4_ob, h1_ob, cind) * _a007(cind)
    sptFreeSparseTensor(&_a006_aa);
    sptFreeSparseTensor(&_a006_bb);
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [0];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a006_aa,
            /* X */ &_a009_aa,
            /* Y */ &_a007,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a006_bb,
            /* X2 */ &_a009_bb,
            /* Y2 */ &_a007,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a006_aa(h4_oa, h1_oa)                 += -1.0   * _a009_aa(h3_oa, h1_oa, cind) * _a008_aa(h4_oa, h3_oa, cind)
    // _a006_bb(h4_ob, h1_ob)                 += -1.0   * _a009_bb(h3_ob, h1_ob, cind) * _a008_bb(h4_ob, h3_ob, cind)
    sptFreeSparseTensor(&_a006_aa);
    sptFreeSparseTensor(&_a006_bb);
    {
        static const sptIndex cmodes_X[] = [0, 2];
        static const sptIndex cmodes_Y[] = [2, 1];
        static const sptIndex cmodes_X2[] = [0, 2];
        static const sptIndex cmodes_Y2[] = [2, 1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a006_aa,
            /* X */ &_a009_aa,
            /* Y */ &_a008_aa,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a006_bb,
            /* X2 */ &_a009_bb,
            /* Y2 */ &_a008_bb,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a019_aaaa(h4_oa, h3_oa, h1_oa, h2_oa)  =  0.25  * _a009_aa(h4_oa, h1_oa, cind) * _a009_aa(h3_oa, h2_oa, cind)
    // _a019_abab(h4_oa, h3_ob, h1_oa, h2_ob)  =  0.25  * _a009_aa(h4_oa, h1_oa, cind) * _a009_bb(h3_ob, h2_ob, cind)
    sptSparseTensor _a019_aaaa;
    sptSparseTensor _a019_abab;
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a019_aaaa,
            /* X */ &_a009_aa,
            /* Y */ &_a009_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a019_abab,
            /* X2 */ &_a009_aa,
            /* Y2 */ &_a009_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a019_bbbb(h4_ob, h3_ob, h1_ob, h2_ob)  =  0.25  * _a009_bb(h4_ob, h1_ob, cind) * _a009_bb(h3_ob, h2_ob, cind)
    // _a020_aaaa(p4_va, h4_oa, p1_va, h1_oa)  = -2.0   * _a009_aa(h4_oa, h1_oa, cind) * _a021_aa(p4_va, p1_va, cind)
    sptSparseTensor _a019_bbbb;
    sptSparseTensor _a020_aaaa;
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a019_bbbb,
            /* X */ &_a009_bb,
            /* Y */ &_a009_bb,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a020_aaaa,
            /* X2 */ &_a009_aa,
            /* Y2 */ &_a021_aa,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a020_abab(p4_va, h4_ob, p1_va, h1_ob)  = -2.0   * _a009_bb(h4_ob, h1_ob, cind) * _a021_aa(p4_va, p1_va, cind)
    // _a020_baba(p4_vb, h4_oa, p1_vb, h1_oa)  = -2.0   * _a009_aa(h4_oa, h1_oa, cind) * _a021_bb(p4_vb, p1_vb, cind)
    sptSparseTensor _a020_abab;
    sptSparseTensor _a020_baba;
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a020_abab,
            /* X */ &_a009_bb,
            /* Y */ &_a021_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a020_baba,
            /* X2 */ &_a009_aa,
            /* Y2 */ &_a021_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a020_bbbb(p4_vb, h4_ob, p1_vb, h1_ob)  = -2.0   * _a009_bb(h4_ob, h1_ob, cind) * _a021_bb(p4_vb, p1_vb, cind)
    // _a017_aa(p3_va, h2_oa, cind)           +=  1.0   * t1_aa(p3_va, h3_oa) * chol3d_aa_oo(h3_oa, h2_oa, cind)
    sptSparseTensor _a020_bbbb;
    sptFreeSparseTensor(&_a017_aa);
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [1];
        static const sptIndex cmodes_Y2[] = [0];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a020_bbbb,
            /* X */ &_a009_bb,
            /* Y */ &_a021_bb,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a017_aa,
            /* X2 */ &t1_aa,
            /* Y2 */ &chol3d_aa_oo,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a017_aa(p3_va, h2_oa, cind)           += -1.0   * chol3d_aa_vo(p3_va, h2_oa, cind)
    sptFreeSparseTensor(&_a017_aa);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a017_aa,
            /* src */ chol3d_aa_vo,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a017_bb(p3_vb, h2_ob, cind)           += -1.0   * chol3d_bb_vo(p3_vb, h2_ob, cind)
    sptFreeSparseTensor(&_a017_bb);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a017_bb,
            /* src */ chol3d_bb_vo,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a017_bb(p3_vb, h2_ob, cind)           +=  1.0   * t1_bb(p3_vb, h3_ob) * chol3d_bb_oo(h3_ob, h2_ob, cind)
    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)     =  0.5   * _a017_aa(p3_va, h1_oa, cind) * _a017_aa(p4_va, h2_oa, cind)
    sptFreeSparseTensor(&_a017_bb);
    {
        static const sptIndex cmodes_X[] = [1];
        static const sptIndex cmodes_Y[] = [0];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a017_bb,
            /* X */ &t1_bb,
            /* Y */ &chol3d_bb_oo,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_aaaa,
            /* X2 */ &_a017_aa,
            /* Y2 */ &_a017_aa,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)     =  0.5   * _a017_bb(p3_vb, h1_ob, cind) * _a017_bb(p4_vb, h2_ob, cind)
    // i0_abab(p3_va, p4_vb, h1_oa, h2_ob)     =  1.0   * _a017_aa(p3_va, h1_oa, cind) * _a017_bb(p4_vb, h2_ob, cind)
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_bbbb,
            /* X */ &_a017_bb,
            /* Y */ &_a017_bb,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_abab,
            /* X2 */ &_a017_aa,
            /* Y2 */ &_a017_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a022_aaaa(p3_va,p4_va,p2_va,p1_va)     =  1.0   * _a021_aa(p3_va,p2_va,cind) * _a021_aa(p4_va,p1_va,cind)
    // _a022_abab(p3_va,p4_vb,p2_va,p1_vb)     =  1.0   * _a021_aa(p3_va,p2_va,cind) * _a021_bb(p4_vb,p1_vb,cind)
    sptSparseTensor _a022_aaaa;
    sptSparseTensor _a022_abab;
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a022_aaaa,
            /* X */ &_a021_aa,
            /* Y */ &_a021_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a022_abab,
            /* X2 */ &_a021_aa,
            /* Y2 */ &_a021_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a022_bbbb(p3_vb,p4_vb,p2_vb,p1_vb)     =  1.0   * _a021_bb(p3_vb,p2_vb,cind) * _a021_bb(p4_vb,p1_vb,cind)
    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)    +=  1.0   * _a022_aaaa(p3_va, p4_va, p2_va, p1_va) * t2_aaaa(p2_va,p1_va,h1_oa,h2_oa)
    sptSparseTensor _a022_bbbb;
    {
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [2];
        static const sptIndex cmodes_X2[] = [1, 3];
        static const sptIndex cmodes_Y2[] = [0, 1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a022_bbbb,
            /* X */ &_a021_bb,
            /* Y */ &_a021_bb,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_aaaa,
            /* X2 */ &_a022_aaaa,
            /* Y2 */ &t2_aaaa,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)    +=  1.0   * _a022_bbbb(p3_vb, p4_vb, p2_vb, p1_vb) * t2_bbbb(p2_vb,p1_vb,h1_ob,h2_ob)
    // i0_abab(p3_va, p4_vb, h1_oa, h2_ob)    +=  4.0   * _a022_abab(p3_va, p4_vb, p2_va, p1_vb) * t2_abab(p2_va,p1_vb,h1_oa,h2_ob)
    {
        static const sptIndex cmodes_X[] = [1, 3];
        static const sptIndex cmodes_Y[] = [0, 1];
        static const sptIndex cmodes_X2[] = [1, 3];
        static const sptIndex cmodes_Y2[] = [0, 1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_bbbb,
            /* X */ &_a022_bbbb,
            /* Y */ &t2_bbbb,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_abab,
            /* X2 */ &_a022_abab,
            /* Y2 */ &t2_abab,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a019_aaaa(h4_oa, h3_oa, h1_oa, h2_oa) += -0.125 * _a004_aaaa(p1_va, p2_va, h3_oa, h4_oa) * t2_aaaa(p1_va,p2_va,h1_oa,h2_oa)
    // _a019_abab(h4_oa, h3_ob, h1_oa, h2_ob) +=  0.25  * _a004_abab(p1_va, p2_vb, h4_oa, h3_ob) * t2_abab(p1_va,p2_vb,h1_oa,h2_ob)
    sptFreeSparseTensor(&_a019_aaaa);
    sptFreeSparseTensor(&_a019_abab);
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [0, 1];
        static const sptIndex cmodes_X2[] = [0, 1];
        static const sptIndex cmodes_Y2[] = [0, 1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a019_aaaa,
            /* X */ &_a004_aaaa,
            /* Y */ &t2_aaaa,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a019_abab,
            /* X2 */ &_a004_abab,
            /* Y2 */ &t2_abab,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a019_bbbb(h4_ob, h3_ob, h1_ob, h2_ob) += -0.125 * _a004_bbbb(p1_vb, p2_vb, h3_ob, h4_ob) * t2_bbbb(p1_vb,p2_vb,h1_ob,h2_ob)
    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)    +=  1.0   * _a019_aaaa(h4_oa, h3_oa, h1_oa, h2_oa) * t2_aaaa(p3_va, p4_va, h4_oa, h3_oa)
    sptFreeSparseTensor(&_a019_bbbb);
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [0, 1];
        static const sptIndex cmodes_X2[] = [0, 1];
        static const sptIndex cmodes_Y2[] = [3, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a019_bbbb,
            /* X */ &_a004_bbbb,
            /* Y */ &t2_bbbb,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_aaaa,
            /* X2 */ &_a019_aaaa,
            /* Y2 */ &t2_aaaa,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)    +=  1.0   * _a019_bbbb(h4_ob, h3_ob, h1_ob, h2_ob) * t2_bbbb(p3_vb, p4_vb, h4_ob, h3_ob)
    // i0_abab(p3_va, p4_vb, h1_oa, h2_ob)    +=  4.0   * _a019_abab(h4_oa, h3_ob, h1_oa, h2_ob) * t2_abab(p3_va, p4_vb, h4_oa, h3_ob)
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [3, 2];
        static const sptIndex cmodes_X2[] = [0, 1];
        static const sptIndex cmodes_Y2[] = [2, 3];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_bbbb,
            /* X */ &_a019_bbbb,
            /* Y */ &t2_bbbb,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_abab,
            /* X2 */ &_a019_abab,
            /* Y2 */ &t2_abab,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a020_aaaa(p1_va, h3_oa, p4_va, h2_oa) +=  0.5   * _a004_aaaa(p2_va, p4_va, h3_oa, h1_oa) * t2_aaaa(p1_va,p2_va,h1_oa,h2_oa)
    // _a020_baab(p1_vb, h3_oa, p4_va, h2_ob)  = -0.5   * _a004_aaaa(p2_va, p4_va, h3_oa, h1_oa) * t2_abab(p2_va,p1_vb,h1_oa,h2_ob)
    sptFreeSparseTensor(&_a020_aaaa);
    sptSparseTensor _a020_baab;
    {
        static const sptIndex cmodes_X[] = [0, 3];
        static const sptIndex cmodes_Y[] = [1, 2];
        static const sptIndex cmodes_X2[] = [0, 3];
        static const sptIndex cmodes_Y2[] = [0, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a020_aaaa,
            /* X */ &_a004_aaaa,
            /* Y */ &t2_aaaa,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a020_baab,
            /* X2 */ &_a004_aaaa,
            /* Y2 */ &t2_abab,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a020_abba(p1_va, h3_ob, p4_vb, h2_oa)  = -0.5   * _a004_bbbb(p2_vb, p4_vb, h3_ob, h1_ob) * t2_abab(p1_va,p2_vb,h2_oa,h1_ob)
    // _a020_bbbb(p1_vb, h3_ob, p4_vb, h2_ob) +=  0.5   * _a004_bbbb(p2_vb, p4_vb, h3_ob, h1_ob) * t2_bbbb(p1_vb,p2_vb,h1_ob,h2_ob)
    sptSparseTensor _a020_abba;
    sptFreeSparseTensor(&_a020_bbbb);
    {
        static const sptIndex cmodes_X[] = [0, 3];
        static const sptIndex cmodes_Y[] = [1, 3];
        static const sptIndex cmodes_X2[] = [0, 3];
        static const sptIndex cmodes_Y2[] = [1, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a020_abba,
            /* X */ &_a004_bbbb,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a020_bbbb,
            /* X2 */ &_a004_bbbb,
            /* Y2 */ &t2_bbbb,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a020_baba(p1_vb, h7_oa, p6_vb, h2_oa) +=  1.0   * _a004_abab(p5_va, p6_vb, h7_oa, h8_ob) * t2_abab(p5_va,p1_vb,h2_oa,h8_ob)
    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)    +=  1.0   * _a020_aaaa(p4_va, h4_oa, p1_va, h1_oa) * t2_aaaa(p3_va, p1_va, h4_oa, h2_oa)
    sptFreeSparseTensor(&_a020_baba);
    {
        static const sptIndex cmodes_X[] = [0, 3];
        static const sptIndex cmodes_Y[] = [0, 3];
        static const sptIndex cmodes_X2[] = [0, 1];
        static const sptIndex cmodes_Y2[] = [1, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &_a020_baba,
            /* X */ &_a004_abab,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_aaaa,
            /* X2 */ &_a020_aaaa,
            /* Y2 */ &t2_aaaa,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)    += -1.0   * _a020_abba(p4_va, h4_ob, p1_vb, h1_oa) * t2_abab(p3_va, p1_vb, h2_oa, h4_ob)
    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)    +=  1.0   * _a020_bbbb(p4_vb, h4_ob, p1_vb, h1_ob) * t2_bbbb(p3_vb, p1_vb, h4_ob, h2_ob)
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [1, 3];
        static const sptIndex cmodes_X2[] = [0, 1];
        static const sptIndex cmodes_Y2[] = [1, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_aaaa,
            /* X */ &_a020_abba,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_bbbb,
            /* X2 */ &_a020_bbbb,
            /* Y2 */ &t2_bbbb,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)    += -1.0   * _a020_baab(p4_vb, h4_oa, p1_va, h1_ob) * t2_abab(p1_va, p3_vb, h4_oa, h2_ob)
    // i0_abab(p3_va, p1_vb, h2_oa, h4_ob)    +=  1.0   * _a020_baba(p1_vb, h7_oa, p6_vb, h2_oa) * t2_abab(p3_va, p6_vb, h7_oa, h4_ob)
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [0, 2];
        static const sptIndex cmodes_X2[] = [0, 1];
        static const sptIndex cmodes_Y2[] = [1, 2];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_bbbb,
            /* X */ &_a020_baab,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_abab,
            /* X2 */ &_a020_baba,
            /* Y2 */ &t2_abab,
            /* num_cmodes_2 */ 2,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a001_aa(p4_va, p1_va)                 += -1.0   * f1_aa_vv(p4_va, p1_va)
    sptFreeSparseTensor(&_a001_aa);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a001_aa,
            /* src */ f1_aa_vv,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a001_bb(p4_vb, p1_vb)                 += -1.0   * f1_bb_vv(p4_vb, p1_vb)
    sptFreeSparseTensor(&_a001_bb);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a001_bb,
            /* src */ f1_bb_vv,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a006_aa(h9_oa, h1_oa)                 +=  1.0   * f1_aa_oo(h9_oa, h1_oa)
    sptFreeSparseTensor(&_a006_aa);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a006_aa,
            /* src */ f1_aa_oo,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // _a006_bb(h9_ob, h1_ob)                 +=  1.0   * f1_bb_oo(h9_ob, h1_ob)
    sptFreeSparseTensor(&_a006_bb);
    {
        int result = sptCopySparseTensor(
            /* dest */ _a006_bb,
            /* src */ f1_bb_oo,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p3_va, p1_vb, h2_oa, h4_ob)    +=  1.0   * _a020_abab(p3_va, h8_ob, p5_va, h4_ob) * t2_abab(p5_va, p1_vb, h2_oa, h8_ob)
    // _a006_aa(h9_oa, h1_oa)                 +=  1.0   * t1_aa(p8_va, h1_oa) * f1_aa_ov(h9_oa, p8_va)
    sptFreeSparseTensor(&_a006_aa);
    {
        static const sptIndex cmodes_X[] = [0, 3];
        static const sptIndex cmodes_Y[] = [0, 3];
        static const sptIndex cmodes_X2[] = [0];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_abab,
            /* X */ &_a020_abab,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a006_aa,
            /* X2 */ &t1_aa,
            /* Y2 */ &f1_aa_ov,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p3_va, p4_vb, h2_oa, h1_ob)    +=  1.0   * _a020_bbbb(p4_vb, h4_ob, p1_vb, h1_ob) * t2_abab(p3_va, p1_vb, h2_oa, h4_ob)
    // _a006_bb(h9_ob, h1_ob)                 +=  1.0   * t1_bb(p8_vb, h1_ob) * f1_bb_ov(h9_ob, p8_vb)
    sptFreeSparseTensor(&_a006_bb);
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [1, 3];
        static const sptIndex cmodes_X2[] = [0];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_abab,
            /* X */ &_a020_bbbb,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &_a006_bb,
            /* X2 */ &t1_bb,
            /* Y2 */ &f1_bb_ov,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p3_va, p4_vb, h2_oa, h1_ob)    += -1.0   * _a020_baab(p4_vb, h4_oa, p1_va, h1_ob) * t2_aaaa(p3_va, p1_va, h4_oa, h2_oa)
    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)    += -0.5   * t2_aaaa(p3_va, p2_va, h1_oa, h2_oa) * _a001_aa(p4_va, p2_va)
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [1, 2];
        static const sptIndex cmodes_X2[] = [1];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_abab,
            /* X */ &_a020_baab,
            /* Y */ &t2_aaaa,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_aaaa,
            /* X2 */ &t2_aaaa,
            /* Y2 */ &_a001_aa,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p4_va, p3_vb, h1_oa, h2_ob)    +=  1.0   * _a020_aaaa(p4_va, h4_oa, p1_va, h1_oa) * t2_abab(p1_va, p3_vb, h4_oa, h2_ob)
    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)    += -0.5   * t2_bbbb(p3_vb, p2_vb, h1_ob, h2_ob) * _a001_bb(p4_vb, p2_vb)
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [0, 2];
        static const sptIndex cmodes_X2[] = [1];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_abab,
            /* X */ &_a020_aaaa,
            /* Y */ &t2_abab,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_bbbb,
            /* X2 */ &t2_bbbb,
            /* Y2 */ &_a001_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p4_va, p3_vb, h1_oa, h2_ob)    += -1.0   * _a020_abba(p4_va, h4_ob, p1_vb, h1_oa) * t2_bbbb(p3_vb, p1_vb, h4_ob, h2_ob)
    // i0_aaaa(p3_va, p4_va, h2_oa, h1_oa)    += -0.5   * t2_aaaa(p3_va, p4_va, h3_oa, h1_oa) * _a006_aa(h3_oa, h2_oa)
    {
        static const sptIndex cmodes_X[] = [0, 1];
        static const sptIndex cmodes_Y[] = [1, 2];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_abab,
            /* X */ &_a020_abba,
            /* Y */ &t2_bbbb,
            /* num_cmodes */ 2,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_aaaa,
            /* X2 */ &t2_aaaa,
            /* Y2 */ &_a006_aa,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p3_va, p4_vb, h1_oa, h2_ob)    += -1.0   * t2_abab(p3_va, p2_vb, h1_oa, h2_ob) * _a001_bb(p4_vb, p2_vb)
    // i0_bbbb(p3_vb, p4_vb, h2_ob, h1_ob)    += -0.5   * t2_bbbb(p3_vb, p4_vb, h3_ob, h1_ob) * _a006_bb(h3_ob, h2_ob)
    {
        static const sptIndex cmodes_X[] = [1];
        static const sptIndex cmodes_Y[] = [1];
        static const sptIndex cmodes_X2[] = [2];
        static const sptIndex cmodes_Y2[] = [1];
        int result = sptSparseTensorMulTensor2TCs(
            /* Z */ &i0_abab,
            /* X */ &t2_abab,
            /* Y */ &_a001_bb,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            /* Z2 */ &i0_bbbb,
            /* X2 */ &t2_bbbb,
            /* Y2 */ &_a006_bb,
            /* num_cmodes_2 */ 1,
            (sptIndex *) cmodes_X2,
            (sptIndex *) cmodes_Y2,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_atmp(p3_va, p4_va, h1_oa, h2_oa)     =  1.0   * i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)
    sptSparseTensor i0_atmp;
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_atmp,
            /* src */ i0_aaaa,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_atmp(p3_va, p4_va, h1_oa, h2_oa)    +=  1.0   * i0_aaaa(p4_va, p3_va, h2_oa, h1_oa)
    sptFreeSparseTensor(&i0_atmp);
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_atmp,
            /* src */ i0_aaaa,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_atmp(p3_va, p4_va, h1_oa, h2_oa)    += -1.0   * i0_aaaa(p3_va, p4_va, h2_oa, h1_oa)
    sptFreeSparseTensor(&i0_atmp);
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_atmp,
            /* src */ i0_aaaa,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_atmp(p3_va, p4_va, h1_oa, h2_oa)    += -1.0   * i0_aaaa(p4_va, p3_va, h1_oa, h2_oa)
    sptFreeSparseTensor(&i0_atmp);
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_atmp,
            /* src */ i0_aaaa,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_btmp(p3_vb, p4_vb, h1_ob, h2_ob)     =  1.0   * i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)
    sptSparseTensor i0_btmp;
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_btmp,
            /* src */ i0_bbbb,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_btmp(p3_vb, p4_vb, h1_ob, h2_ob)    +=  1.0   * i0_bbbb(p4_vb, p3_vb, h2_ob, h1_ob)
    sptFreeSparseTensor(&i0_btmp);
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_btmp,
            /* src */ i0_bbbb,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_btmp(p3_vb, p4_vb, h1_ob, h2_ob)    += -1.0   * i0_bbbb(p3_vb, p4_vb, h2_ob, h1_ob)
    sptFreeSparseTensor(&i0_btmp);
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_btmp,
            /* src */ i0_bbbb,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_btmp(p3_vb, p4_vb, h1_ob, h2_ob)    += -1.0   * i0_bbbb(p4_vb, p3_vb, h1_ob, h2_ob)
    sptFreeSparseTensor(&i0_btmp);
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_btmp,
            /* src */ i0_bbbb,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_aaaa(p3_va, p4_va, h1_oa, h2_oa)     =  1.0   * i0_atmp(p3_va, p4_va, h1_oa, h2_oa)
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_aaaa,
            /* src */ i0_atmp,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_bbbb(p3_vb, p4_vb, h1_ob, h2_ob)     =  1.0   * i0_btmp(p3_vb, p4_vb, h1_ob, h2_ob)
    {
        int result = sptCopySparseTensor(
            /* dest */ i0_bbbb,
            /* src */ i0_btmp,
            /* nt */ 1,
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p4_va, p3_vb, h1_oa, h2_ob)    += -1.0   * t2_abab(p2_va, p3_vb, h1_oa, h2_ob) * _a001_aa(p4_va, p2_va)
    {
        static const sptIndex modes_Z[] = [0, 1, 2, 3];
        static const sptIndex cmodes_X[] = [0];
        static const sptIndex cmodes_Y[] = [1];
        int result = sptSparseTensorMulTensor(
            /* Z */ &i0_abab,
            /* X */ &t2_abab,
            /* Y */ &_a001_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            (sptIndex *) modes_Z,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p3_va, p4_vb, h2_oa, h1_ob)    += -1.0   * t2_abab(p3_va, p4_vb, h3_oa, h1_ob) * _a006_aa(h3_oa, h2_oa)
    {
        static const sptIndex modes_Z[] = [0, 1, 2, 3];
        static const sptIndex cmodes_X[] = [2];
        static const sptIndex cmodes_Y[] = [1];
        int result = sptSparseTensorMulTensor(
            /* Z */ &i0_abab,
            /* X */ &t2_abab,
            /* Y */ &_a006_aa,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            (sptIndex *) modes_Z,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    // i0_abab(p3_va, p4_vb, h1_oa, h2_ob)    += -1.0   * t2_abab(p3_va, p4_vb, h1_oa, h3_ob) * _a006_bb(h3_ob, h2_ob)
    {
        static const sptIndex modes_Z[] = [0, 1, 2, 3];
        static const sptIndex cmodes_X[] = [3];
        static const sptIndex cmodes_Y[] = [1];
        int result = sptSparseTensorMulTensor(
            /* Z */ &i0_abab,
            /* X */ &t2_abab,
            /* Y */ &_a006_bb,
            /* num_cmodes */ 1,
            (sptIndex *) cmodes_X,
            (sptIndex *) cmodes_Y,
            (sptIndex *) modes_Z,
            /* nt */ 1,
            /* output_sorting */ 1,
            /* opt_summation */ 1,
            /* placement */ 0
        );
        if(unlikely(result != 0)) {
            sptFreeSparseTensor(&i0_btmp);
            sptFreeSparseTensor(&i0_atmp);
            sptFreeSparseTensor(&_a020_abba);
            sptFreeSparseTensor(&_a020_baab);
            sptFreeSparseTensor(&_a022_bbbb);
            sptFreeSparseTensor(&_a022_abab);
            sptFreeSparseTensor(&_a022_aaaa);
            sptFreeSparseTensor(&_a020_bbbb);
            sptFreeSparseTensor(&_a020_baba);
            sptFreeSparseTensor(&_a020_abab);
            sptFreeSparseTensor(&_a020_aaaa);
            sptFreeSparseTensor(&_a019_bbbb);
            sptFreeSparseTensor(&_a019_abab);
            sptFreeSparseTensor(&_a019_aaaa);
            sptFreeSparseTensor(&_a001_bb);
            sptFreeSparseTensor(&_a001_aa);
            sptFreeSparseTensor(&_a008_bb);
            sptFreeSparseTensor(&_a008_aa);
            sptFreeSparseTensor(&_a021_bb);
            sptFreeSparseTensor(&_a021_aa);
            sptFreeSparseTensor(&_a009_bb);
            sptFreeSparseTensor(&_a009_aa);
            sptFreeSparseTensor(&_a007);
            sptFreeSparseTensor(&_a006_bb);
            sptFreeSparseTensor(&_a006_aa);
            sptFreeSparseTensor(&_a017_bb);
            sptFreeSparseTensor(&_a017_aa);
            spt_CheckError(result, "CCSD", NULL);
        }
    }

    sptFreeSparseTensor(&i0_btmp);
    sptFreeSparseTensor(&i0_atmp);
    sptFreeSparseTensor(&_a020_abba);
    sptFreeSparseTensor(&_a020_baab);
    sptFreeSparseTensor(&_a022_bbbb);
    sptFreeSparseTensor(&_a022_abab);
    sptFreeSparseTensor(&_a022_aaaa);
    sptFreeSparseTensor(&_a020_bbbb);
    sptFreeSparseTensor(&_a020_baba);
    sptFreeSparseTensor(&_a020_abab);
    sptFreeSparseTensor(&_a020_aaaa);
    sptFreeSparseTensor(&_a019_bbbb);
    sptFreeSparseTensor(&_a019_abab);
    sptFreeSparseTensor(&_a019_aaaa);
    sptFreeSparseTensor(&_a001_bb);
    sptFreeSparseTensor(&_a001_aa);
    sptFreeSparseTensor(&_a008_bb);
    sptFreeSparseTensor(&_a008_aa);
    sptFreeSparseTensor(&_a021_bb);
    sptFreeSparseTensor(&_a021_aa);
    sptFreeSparseTensor(&_a009_bb);
    sptFreeSparseTensor(&_a009_aa);
    sptFreeSparseTensor(&_a007);
    sptFreeSparseTensor(&_a006_bb);
    sptFreeSparseTensor(&_a006_aa);
    sptFreeSparseTensor(&_a017_bb);
    sptFreeSparseTensor(&_a017_aa);
    return 0;
}

