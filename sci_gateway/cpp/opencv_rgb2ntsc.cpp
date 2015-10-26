/*--------------------------------------  
 function-rgb2ntsc
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
  Color rgb2ntsc(float R, float G, float B,char* s)
  {
         /* color space conversion from rgb to ntsc  */
         float r,g,b,y,i,q;
         if(!strcmp(s,"image"))
          {
            r = R/255.f; //R 0..1
            g = G/255.f; //G 0..1
            b = B/255.f; //B 0..1
            y =  0.299*r+ 0.587*g + 0.114*b;
            i =  0.596*r-0.274 *g - 0.322*b;
            q =  0.211*r- 0.523*g + 0.312*b;
          }
         else if(!strcmp(s,"matrix"))
          {
            r=R;
            g=G;
            b=B;
            y =round(0.299*r+ 0.587*g + 0.114*b);
            i =round(0.596*r-0.274 *g - 0.322*b);
            q =round(0.211*r- 0.523*g + 0.312*b);
          }
        
         Color ntsc;
         ntsc.Y= y;
         ntsc.I= i;
         ntsc.Q= q;
        return ntsc;
  } 
int opencv_rgb2ntsc(char *fname, unsigned long fname_len)
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
   Mat img,k;
   Color out;
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
            out=rgb2ntsc(value[j],value[j+1],value[j+2],"matrix");
            output[j]=out.Y;
            output[j+1]=out.I;
            output[j+2]=out.Q;
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
        /*retrieve image value as matrix */
        retrieveImage(img,1);
        if(img.channels() !=3) 
        {
          sciprint(" Should give proper input image");
          return 0;
        }
        double *r1,*g1,*b1;
        r1=(double *)malloc(sizeof(double)*img.rows*img.cols);
        g1=(double *)malloc(sizeof(double)*img.rows*img.cols);
        b1=(double *)malloc(sizeof(double)*img.rows*img.cols);
        for(int i=0;i<img.rows;i++)  
          {
            for(int j=0;j<img.cols;j++)
               {
                  Vec3b intensity = img.at<Vec3b>(i,j);
                  float R= intensity.val[2];
                  float G= intensity.val[1];
                  float B= intensity.val[0];
                  out=rgb2ntsc(R,G,B,"image");
                  r1[m]=out.Y;
                  g1[m]=out.I;
                  b1[m++]=out.Q;  
                }
            }
         sciErr = createList(pvApiCtx, nbInputArgument(pvApiCtx) + 1, 3, &piAddrNew);
         if(sciErr.iErr)
         {
            printError(&sciErr, 0);
            return 0;
         }
         //Adding the R value matrix to the list
         //Syntax : createMatrixOfInteger32InList(void* _pvCtx, int _iVar, int* _piParent, int _iItemPos, int _iRows, int _iCols, const int* _piData)
         sciErr = createMatrixOfDoubleInList(pvApiCtx, nbInputArgument(pvApiCtx)+1 , piAddrNew, 1, img.rows,img.cols, r1);
         free(r1);
         if(sciErr.iErr)
         {
            printError(&sciErr, 0);
            return 0;
         }
        //Adding the G value matrix to the list
        sciErr = createMatrixOfDoubleInList(pvApiCtx, nbInputArgument(pvApiCtx)+1 , piAddrNew, 2, img.rows, img.cols, g1);
        free(g1);
        if(sciErr.iErr)
        {
          printError(&sciErr, 0);
          return 0;
        }
       sciErr = createMatrixOfDoubleInList(pvApiCtx, nbInputArgument(pvApiCtx)+1 , piAddrNew, 3, img.rows, img.cols, b1);
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
