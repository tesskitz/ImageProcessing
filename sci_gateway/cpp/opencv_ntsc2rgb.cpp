/*--------------------------------------  
 function-ntsc2rgb
 Author :Tess Zacharias    
------------------------------------- */
#include <numeric>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include<stdio.h>
#include <sciprint.h>
#include<string.h>
using namespace cv;
using namespace std;
  extern "C"
  {
  #include "api_scilab.h"
  #include "Scierror.h"
  #include "BOOL.h"
  #include <localization.h>
  #include "../common.h"
  #define REF_X .95047; // Observer= 2°, Illuminant= D65
  #define REF_Y 1.00000;
  #define REF_Z 1.08883;
  struct Color
  {
    float R,G,B,Y,I,Q;
  };
  Color ntsc2rgb(float Y, float I, float Q)
  {
        /*colorspace conversion from ntsc to rgb  */
         float r= 1.000*Y+0.956*I+0.621*Q;
         float g =1.000*Y-0.272*I-0.647*Q;
         float b =1.000*Y-1.106*I+1.703*Q;
    Color rgb;
    rgb.R= r;
    rgb.G= g;
    rgb.B= b;
    return rgb;

} 
int opencv_ntsc2rgb(char *fname, unsigned long fname_len)
{ 
   SciErr sciErr;
   int* piAddr1=NULL;
   int* piAddr2=NULL;
   int* piAddr3=NULL;
   int* piAddrNew=NULL;
   int iRows		= 0;
   int iCols		= 0;
   CheckInputArgument(pvApiCtx,1,3);
   CheckOutputArgument(pvApiCtx,1,1);
   int m=0;
   int iType = 0;
   double *value=NULL;
   int iPrec= 0;
   Color out;
   float Y,I,Q;
   sciErr =getVarAddressFromPosition(pvApiCtx,1,&piAddr1);
   sciErr = getVarType(pvApiCtx, piAddr1, &iType);
   switch(iType)
    {
      case sci_matrix:
      {
        /*retrieve matrix values */
        sciErr = getMatrixOfDouble(pvApiCtx, piAddr1, &iRows, &iCols,&value);
        if(sciErr.iErr)
        {
          printError(&sciErr, 0);
          return 0;
        }
        double *output=NULL;
        output=( double *)malloc(sizeof(double)*iRows*iCols);
        int j=0;
        for(int i=0;i<iRows;i++)
          {
            out=ntsc2rgb(value[j],value[j+1],value[j+2]);
            output[j]=out.R;
            output[j+1]=out.G;
            output[j+2]=out.B;
            j=j+3;
          }
        
       sciErr = createMatrixOfDouble(pvApiCtx, nbInputArgument(pvApiCtx) + 1,iRows,iCols,output);
       free(output);
       if (sciErr.iErr)
           {
                printError(&sciErr, 0);
                return 0;
           }         
        break;
       }
      case sci_list:
       {
          /* retrieve image values as list */
          int k=0;
          double *pstDataR = NULL;
          double *pstDataG = NULL;
          double *pstDataB = NULL; 
          sciErr = getVarAddressFromPosition(pvApiCtx,1,&piAddr1);
          if(sciErr.iErr)   
          {
              printError(&sciErr, 0);
              return 0;
          }
          sciErr =  getMatrixOfDoubleInList(pvApiCtx, piAddr1, 1, &iRows, &iCols, &pstDataR);
          if(sciErr.iErr)
          {
              printError(&sciErr, 0);
              return 0;
          }
          sciErr = getVarAddressFromPosition(pvApiCtx,1,&piAddr1);
          if(sciErr.iErr)   
          {
               printError(&sciErr, 0);
               return 0;
          }   
          sciErr = getMatrixOfDoubleInList(pvApiCtx, piAddr1, 2, &iRows, &iCols, &pstDataG);
          if(sciErr.iErr)
          {
               printError(&sciErr, 0);
               return 0;
          }
          sciErr = getVarAddressFromPosition(pvApiCtx,1,&piAddr1);
          if(sciErr.iErr)   
          {
                printError(&sciErr, 0);
                return 0;
          }   
          sciErr = getMatrixOfDoubleInList(pvApiCtx, piAddr1, 3, &iRows, &iCols, &pstDataB);
          if(sciErr.iErr)
          {
                printError(&sciErr, 0);
                return 0;
          }
         int m=0;
         double *r1,*g1,*b1;
         r1=(double *)malloc(sizeof(double)*iRows*iCols);
         g1=(double *)malloc(sizeof(double)*iRows*iCols);
         b1=(double *)malloc(sizeof(double)*iRows*iCols);
                               for(int i=0;i<iRows;i++)
                               {
                                  for(int j=0;j<iCols;j++)
                                   {
                                          Y= (pstDataR[k]);
                                          I= (pstDataG[k]);
                                          Q= (pstDataB[k++]);
                                          out=ntsc2rgb(Y,I,Q);
                                          r1[m]=(out.R);
                                          g1[m]=(out.G);
                                          b1[m++]=(out.B); 
                                         
                                   }
                               }
                     
       
         sciErr = createList(pvApiCtx, nbInputArgument(pvApiCtx) + 1, 3, &piAddrNew);
         if(sciErr.iErr)
         {
            printError(&sciErr, 0);
            return 0;
         }
         sciErr = createMatrixOfDoubleInList(pvApiCtx, nbInputArgument(pvApiCtx)+1 , piAddrNew, 1, iRows,iCols, r1);
         free(r1);
         if(sciErr.iErr)
         {
            printError(&sciErr, 0);
            return 0;
         }
        sciErr = createMatrixOfDoubleInList(pvApiCtx, nbInputArgument(pvApiCtx)+1 , piAddrNew, 2, iRows, iCols, g1);
        free(g1);
        if(sciErr.iErr)
        {
          printError(&sciErr, 0);
          return 0;
        }
       sciErr = createMatrixOfDoubleInList(pvApiCtx, nbInputArgument(pvApiCtx)+1 , piAddrNew, 3, iRows, iCols, b1);
       free(b1);
       if(sciErr.iErr)
       {
          printError(&sciErr, 0);
          return 0;
       } 
     break;
     }
    default:
        sciprint("input argument should be either of double matrix or image !\n"); // Should never happen
  }
 
      
     AssignOutputVariable(pvApiCtx, 1) = nbInputArgument(pvApiCtx) + 1;
     ReturnArguments(pvApiCtx);            
     return 0;                
 }
}
