/* Include files */

#include "RaspPiPilot_sfun.h"
#include "RaspPiPilot_sfun_debug_macros.h"
#include "c1_RaspPiPilot.h"
#include "c2_RaspPiPilot.h"
#include "c3_RaspPiPilot.h"
#include "c4_RaspPiPilot.h"
#include "c5_RaspPiPilot.h"
#include "c6_RaspPiPilot.h"
#include "c8_RaspPiPilot.h"
#include "c10_RaspPiPilot.h"
#include "c13_RaspPiPilot.h"
#include "c14_RaspPiPilot.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _RaspPiPilotMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void RaspPiPilot_initializer(void)
{
}

void RaspPiPilot_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_RaspPiPilot_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_RaspPiPilot_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_RaspPiPilot_process_testpoint_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "RaspPiPilot")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 5:
      {
        extern mxArray *sf_c5_RaspPiPilot_get_testpoint_info(void);
        plhs[0] = sf_c5_RaspPiPilot_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_RaspPiPilot_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1848057450U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3547876373U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1410564597U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3029806031U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(430726819U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3268617788U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(111423723U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3174797309U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c1_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c2_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c3_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c4_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c5_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c6_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c8_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c10_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c13_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_RaspPiPilot_get_check_sum(mxArray *plhs[]);
          sf_c14_RaspPiPilot_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3084158392U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2524169757U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2812955680U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(245732821U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3334278401U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2330367496U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(706307046U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2968498969U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_RaspPiPilot_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "mXSoG9tcS3iDDpefjwimGC") == 0) {
          extern mxArray *sf_c1_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c1_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "tPwGHEH8lNaxSv2XFBdrnH") == 0) {
          extern mxArray *sf_c2_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c2_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "VuOrAnr8IPwDgE4ZXNKAkG") == 0) {
          extern mxArray *sf_c3_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c3_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "NHWS4lVhwLVTeyeOS0ya4C") == 0) {
          extern mxArray *sf_c4_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c4_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "Tim7K7aYOU0FNLZ19SbbJF") == 0) {
          extern mxArray *sf_c5_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c5_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "d81UuYDdc5y8y73jfihDoD") == 0) {
          extern mxArray *sf_c6_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c6_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "AQDsDKWtBoIGBhDpgwclRE") == 0) {
          extern mxArray *sf_c8_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c8_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "XbrBH2gCVDFBU3a8VcFIGG") == 0) {
          extern mxArray *sf_c10_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c10_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "33npUFsGFtiMXcsCyGlPSE") == 0) {
          extern mxArray *sf_c13_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c13_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "l9G7QTYZtAVNpVNKYj3GhB") == 0) {
          extern mxArray *sf_c14_RaspPiPilot_get_autoinheritance_info(void);
          plhs[0] = sf_c14_RaspPiPilot_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_RaspPiPilot_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_RaspPiPilot_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_RaspPiPilot_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_RaspPiPilot_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "1kReuTTQiolV0QPkwyBQKC") == 0) {
          extern mxArray *sf_c1_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c1_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NsmTegGtgBBc5KWpgyeLWE") == 0) {
          extern mxArray *sf_c2_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c2_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "84v3kiws2azHchpKkEZloH") == 0) {
          extern mxArray *sf_c3_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c3_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "punfGm8b6K2n88XWVjdrJ") == 0) {
          extern mxArray *sf_c4_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c4_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "pJeXPbgpNiw7KdSt4hFzCF") == 0) {
          extern mxArray *sf_c5_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c5_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "eqbd66cAnbN86sNh2dY7YC") == 0) {
          extern mxArray *sf_c6_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c6_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "zjhAfaHBBgCyN3fOMsNleC") == 0) {
          extern mxArray *sf_c8_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c8_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "o8KY0hG91xhuqbEFb6AEvB") == 0) {
          extern mxArray *sf_c10_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c10_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "TPRSuwvJ7JjKggp1NfAojB") == 0) {
          extern mxArray *sf_c13_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c13_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "1rX0AF8HqZM5PXCOLjAQiB") == 0) {
          extern mxArray *sf_c14_RaspPiPilot_third_party_uses_info(void);
          plhs[0] = sf_c14_RaspPiPilot_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_RaspPiPilot_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "1kReuTTQiolV0QPkwyBQKC") == 0) {
          extern mxArray *sf_c1_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "NsmTegGtgBBc5KWpgyeLWE") == 0) {
          extern mxArray *sf_c2_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "84v3kiws2azHchpKkEZloH") == 0) {
          extern mxArray *sf_c3_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "punfGm8b6K2n88XWVjdrJ") == 0) {
          extern mxArray *sf_c4_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "pJeXPbgpNiw7KdSt4hFzCF") == 0) {
          extern mxArray *sf_c5_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "eqbd66cAnbN86sNh2dY7YC") == 0) {
          extern mxArray *sf_c6_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "zjhAfaHBBgCyN3fOMsNleC") == 0) {
          extern mxArray *sf_c8_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "o8KY0hG91xhuqbEFb6AEvB") == 0) {
          extern mxArray *sf_c10_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c10_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "TPRSuwvJ7JjKggp1NfAojB") == 0) {
          extern mxArray *sf_c13_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "1rX0AF8HqZM5PXCOLjAQiB") == 0) {
          extern mxArray *sf_c14_RaspPiPilot_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_RaspPiPilot_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void RaspPiPilot_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _RaspPiPilotMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "RaspPiPilot","sfun",0,10,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_RaspPiPilotMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_RaspPiPilotMachineNumber_,
    0);
}

void RaspPiPilot_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_RaspPiPilot_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("RaspPiPilot",
      "RaspPiPilot");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_RaspPiPilot_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
