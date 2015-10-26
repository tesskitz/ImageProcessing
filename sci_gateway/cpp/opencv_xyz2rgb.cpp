/*--------------------------------------  
 function-xyz2rgb
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
    float X,Y,Z,R,G,B;
  };
  Color xyz2rgb1(float X, float Y, float Z)
  {
         /*colorspace conversion from xyz to rgb  */
         float x = X; 
         float y = Y; 
         float z = Z; 
         float R1 = 3.2404542*x-1.5371385*y-0.4985314*z;
         float G1 =-0.9692660*x+1.8760108*y+0.0415560 *z;
         float B1 = 0.0556434*x-0.2040259*y+1.0572252*z;
         if( R1 > 0.0031308 )
		R1 =  1.055 * ( pow( R1, 1./2.4 ) ) - 0.055;
	 else
		R1 = 12.92 * R1;
         if( G1 > 0.0031308 )
		G1 =  1.055 * ( pow( G1, 1./2.4 ) ) - 0.055;
	 else
		G1 = 12.92 * G1;
         if( B1 > 0.0031308 )
		B1 =  1.055 * ( pow( B1, 1./2.4 ) ) - 0.055;
	 else
		B1= 12.92 * B1;
         
         Color rgb;
         rgb.R= R1;
         rgb.G= G1;
         rgb.B= B1;
         return rgb;
 } 
 Color xyz2rgb2(float X, float Y, float Z,char *s)
 {
    double REF_X1;
    double REF_Y1;
    double REF_Z1;
    float x = X; 
    float y = Y; 
    float z = Z;
    float R1,G1,B1;
    if(!strcasecmp(s,"a"))
    {
           R1=2.185*X-1.099*Y-0.114*Z;
           G1=-1.098*X+2.230*Y-0.078*Z;
           B1=0.100*X-0.477*Y+4.071*Z;
    }
    else if(!strcasecmp(s,"c"))
    {
            R1=3.341*X-1.639*Y-0.603*Z;
            G1=-0.878*X+1.772*Y+0.043*Z;
            B1=0.042*X-0.143*Y+0.923*Z;
    }
    else if(!strcasecmp(s,"d50"))
    {
           R1=3.162*X-1.652*Y-0.493*Z;
           G1=-1.012*X+1.958*Y+0.036*Z;
           B1=0.076*X-0.234*Y+1.405*Z;
    }
     else if(!strcasecmp(s,"d65"))
    {
          R1=3.240479*X-1.537150*Y -0.498535 *Z;
          G1=-0.969256*X+1.875992 *Y+0.041556* Z;
          B1=0.055648*X-0.204043*Y +1.057311*Z;
    }
    else if(!strcasecmp(s,"icc"))
    {
          R1=3.462*X-1.816*Y-0.539*Z;
          G1=-0.905*X+1.858*Y+0.024*Z;
          B1=0.012*X-0.088*Y+1.004*Z;    
    }
     else if(!strcasecmp(s,"d55"))
    {
          R1=3.363*X-1.689*Y-0.498*Z;
          G1=-0.955*X+1.867*Y+0.037*Z;
          B1=0.031*X-0.166*Y+ 1.096*Z;
    }
        
         if( R1 > 0.0031308 )
		R1 =  1.055 * ( pow( R1, 1./2.4 ) ) - 0.055;
	 else
		R1 = 12.92 * R1;
         if( G1 > 0.0031308 )
		G1 =  1.055 * ( pow( G1, 1./2.4 ) ) - 0.055;
	 else
		G1 = 12.92 * G1;
         if( B1 > 0.0031308 )
		B1 =  1.055 * ( pow( B1, 1./2.4 ) ) - 0.055;
	 else
		B1= 12.92 * B1;
         
    Color rgb;
    rgb.R= R1;
    rgb.G= G1;
    rgb.B= B1;
    return rgb;
         

}  
Color xyz2rgb3(float X, float Y, float Z,char *s)
{
    double REF_X1;
    double REF_Y1;
    double REF_Z1;
    float x = X; 
    float y = Y; 
    float z = Z;
    float R1,G1,B1;
    if(!strcasecmp(s,"sRGB"))
    {
          R1=3.240479*X-1.537150*Y -0.498535 *Z;
          G1=-0.969256*X+1.875992 *Y+0.041556* Z;
          B1=0.055648*X-0.204043*Y +1.057311*Z;
    }
    else if(!strcasecmp(s,"adobe-rgb-1998"))
    {
          R1=3.462*X-1.816*Y-0.539*Z;
          G1=-0.905*X+1.858*Y+0.024*Z;
          B1=0.012*X-0.088*Y+1.004*Z;     
    }
    if( R1 > 0.0031308 )
	R1 =  1.055 * ( pow( R1, 1./2.4 ) ) - 0.055;
    else
	R1 = 12.92 * R1;
    if( G1 > 0.0031308 )
	G1 =  1.055 * ( pow( G1, 1./2.4 ) ) - 0.055;
    else
	G1 = 12.92 * G1;
    if( B1 > 0.0031308 )
	B1 =  1.055 * ( pow( B1, 1./2.4 ) ) - 0.055;
    else
	B1= 12.92 * B1;
    Color rgb;
    rgb.R= R1;
    rgb.G= G1;
    rgb.B= B1;
    return rgb;
 }  
int opencv_xyz2rgb(char *fname, unsigned long fname_len)
{
   SciErr sciErr;
   int* piAddr1=NULL;
   int* piAddr2=NULL;
   int* piAddr3=NULL;
   int* piAddrNew=NULL;
   int iRows		= 0;
   int iCols		= 0;
   char* pstData = NULL;
   char* pstData1 = NULL;
   CheckInputArgument(pvApiCtx,1,3);
   CheckOutputArgument(pvApiCtx,1,1);
   int m=0;
   int iType = 0;
   double *value=NULL;
   int iPrec= 0;
   Mat img,k;
   int iRet    = 0;
   int iRet1    = 0;
   Color out;
   float X,Y,Z;
   sciErr =getVarAddressFromPosition(pvApiCtx,1,&piAddr1);
   sciErr = getVarType(pvApiCtx, piAddr1, &iType);
   if(nbInputArgument(pvApiCtx)==3)
   {   /*retrieve second argument  */
      sciErr = getVarAddressFromPosition(pvApiCtx, 2,&piAddr2);
      if(sciErr.iErr)
      {
         printError(&sciErr, 0);
	 return 0;
      }               
     if(isStringType(pvApiCtx, piAddr2))
      {
	if(isScalar(pvApiCtx, piAddr2))
         {
	   iRet = getAllocatedSingleString(pvApiCtx, piAddr2, &pstData);
         }
      }
      else
      {
        sciprint(" The second argument should be string  ");
        return 0;
      }
      if((strcasecmp(pstData,"whitepoint")!=0)&&(strcasecmp(pstData,"Colorspace")!=0))    
       {
          sciprint("\n Second argument should be any of these string :'whitepoint','Colorspace'");
          return 0;
       }
       /*retrieve third argument  */
      sciErr = getVarAddressFromPosition(pvApiCtx, 3,&piAddr3);
      if(sciErr.iErr)
      {
          printError(&sciErr, 0);
	  return 0;
      }               
      if(isStringType(pvApiCtx, piAddr3))
      {
         if(isScalar(pvApiCtx, piAddr2))
           {
	     iRet1 = getAllocatedSingleString(pvApiCtx, piAddr3, &pstData1);
           }
       }
       else
       {
          sciprint(" The third argument should be string  ");
          return 0;
       }
       if((strcasecmp(pstData,"whitepoint")==0))
       {
         if((strcasecmp(pstData1,"d65")!=0)&&(strcasecmp(pstData1,"d50")!=0)&&(strcasecmp(pstData1,"d55")!=0)&&(strcasecmp(pstData1,"icc")!=0)&&(strcasecmp(pstData1,"icc")!=0)&&(strcasecmp(pstData1,"a")!=0)&&(strcasecmp(pstData1,"c")!=0))
           {
              sciprint("\nIf Second argument is 'whitepoint' then Third argument should be any of these  string :'a','d65','d55','d50','icc','c'");
                return 0;
            }
         }
       if((strcasecmp(pstData,"Colorspace")==0))
       {
         if((strcasecmp(pstData1,"sRGB")!=0)&&(strcasecmp(pstData1,"adobe-rgb-1998")!=0))
           {
              sciprint("\nIf Second argument is 'Colorspace' then Third argument should be any of these  string :'sRGB','adobe-rgb-1998'");
                return 0;
           }
       }    
    }  
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
        if(nbInputArgument(pvApiCtx)==1)
        {
          for(int i=0;i<iRows;i++)
          {
            out=xyz2rgb1(value[j],value[j+1],value[j+2]);
            output[j]=round(out.R);
            output[j+1]=round(out.G);
            output[j+2]=round(out.B);
            j=j+3;
          }
        }
        else if(nbInputArgument(pvApiCtx)==3)
        {
          for(int i=0;i<iRows;i++)
          {
            if(!strcasecmp(pstData1,"d65")||!strcasecmp(pstData1,"d50")||!strcasecmp(pstData1,"d55")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"a")||!strcasecmp(pstData1,"c"))
            {
               out=xyz2rgb2(value[j],value[j+1],value[j+2],pstData1);
            }
            else if(!strcasecmp(pstData1,"sRGB")||!strcasecmp(pstData1,"adobe-rgb-1998"))
            {
               out=xyz2rgb3(value[j],value[j+1],value[j+2],pstData1);
            }
            output[j]=round(out.R);
            output[j+1]=round(out.G);
            output[j+2]=round(out.B);
            j=j+3;
          }
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
         /*retrieve image value as list*/
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
                  X= (pstDataR[k]);
                  Y= (pstDataG[k]);
                  Z= (pstDataB[k++]);
                  if(nbInputArgument(pvApiCtx)==1)
                  {
                    out=xyz2rgb1(X,Y,Z);
                  }
                  if(nbInputArgument(pvApiCtx)==3)
                  {
                   if(!strcasecmp(pstData1,"d65")||!strcasecmp(pstData1,"d50")||!strcasecmp(pstData1,"d55")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"a")||!strcasecmp(pstData1,"c"))
                    {
                     out=xyz2rgb2(X,Y,Z,pstData1);
                    }
                   else if(!strcasecmp(pstData1,"sRGB")||!strcasecmp(pstData1,"adobe-rgb-1998"))
                    {
                     out=xyz2rgb3(X,Y,Z,pstData1);
                    }
                  }
                  r1[m]=out.R;
                  g1[m]=out.G;
                  b1[m++]=out.B;  
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
