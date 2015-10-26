/*--------------------------------------  
 function-rgb2xyz
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
  struct Color
  {
    float R,G,B,X,Y,Z;
  };
  Color rgb2xyz1(float R, float G, float B,char* s)
  {
       /*colorspace conversion rgb to xyz  */
         float r,g,b;
         if(!strcmp(s,"image"))
          {
            r = R/255.f; //R 0..1
            g = G/255.f; //G 0..1
            b = B/255.f; //B 0..1
          }
         else if(!strcmp(s,"matrix"))
          {
            r=R;
            g=G;
            b=B;
          }
         float eps = 216.f/24389.f;
         float k = 24389.f/27.f;
         float  fx,fy,fz;
         if (r <= 0.04045)
             r = r/12.92;
         else
             r = (float)pow((r+0.055)/1.055,2.4);
         if (g <= 0.04045)
             g = g/12.92;
         else
             g = (float)pow((g+0.055)/1.055,2.4);
         if (b <= 0.04045)
             b = b/12.92;
         else
             b = (float)pow((b+0.055)/1.055,2.4);
         float X1 =  0.4124*r     + 0.3576*g + 0.1805*b;
         float Y1 =  0.2126*r     + 0.7152 *g + 0.0722 *b;
         float Z1 =  0.0193*r     + 0.1192*g + 0.9505 *b;
         Color xyz;
         xyz.X= X1;
         xyz.Y= Y1;
         xyz.Z= Z1;
         return xyz;    

  } 
 Color rgb2xyz2(float R, float G, float B,char* s,char* s1)
  {
    
    float eps = 216.f/24389.f;
    float k = 24389.f/27.f;
    float  fx,fy,fz,X1,Y1,Z1,xr,yr,zr;
    float r,g,b;
    if(!strcmp(s,"image"))
    {
      r = R/255.f; //R 0..1
      g = G/255.f; //G 0..1
      b = B/255.f; //B 0..1
    }
    else if(!strcmp(s,"matrix"))
    {
       r=R;
       g=G;
       b=B;
    }
    if (r <= 0.04045)
       r = r/12.92;
    else
       r = (float)pow((r+0.055)/1.055,2.4);
    if (g <= 0.04045)
       g = g/12.92;
    else
       g = (float)pow((g+0.055)/1.055,2.4);
    if (b <= 0.04045)
       b = b/12.92;
    else
      b = (float)pow((b+0.055)/1.055,2.4);
    if(strcasecmp(s1,"a")==0)
    {
                   
          X1 =  0.61026813175*r+ 0.305727868386*g + 0.022956704621*b;
          Y1 =  0.301271*r+ 0.6013*g + 0.020*b;
          Z1 =  0.020397576891*r+ 0.06302610596*g + 0.24740212077*b;
    }
    else if(strcasecmp(s1,"c")==0)
    {
          
          X1 =  0.398117244057*r+ 0.38768041601*g + 0.24243019805*b;
          Y1 =  0.197*r+ 0.754*g + 0.094*b;
          Z1 =  0.01223983361*r+ 0.09882754336*g + 1.0873948033*b;
    }
    else if(strcasecmp(s1,"d50")==0)
    {
          
          X1 =  0.4360747*r+ 0.3850649*g + 0.1430804*b;
          Y1 =  0.225045*r+ 0.7078786*g + 0.0606169*b;
          Z1 =  0.0139322*r+ 0.0971045*g + 0.7141733*b;
    }
     else if(strcasecmp(s1,"d65")==0)
    {
          
          X1 =  0.4124564*r+ 0.3575761*g + 0.1804375*b;
          Y1 =  0.2126729*r+ 0.7151522*g + 0.0721750*b;
          Z1 =  0.0193339*r+ 0.1191920*g + 0.9503041*b;
    }
     else if(strcasecmp(s1,"d55")==0)
    {
          
          X1 =  0.40373088594*r+ 0.38030882247*g + 0.1705028163*b;
          Y1 =  0.206*r+ 0.728*g + 0.069*b;
          Z1 =  0.01999648064*r+ 0.09980196597*g + 0.91811162916*b;
          
    }
    else if(strcasecmp(s1,"icc")==0)
    {
          
          X1 =  0.390373088594*r+ 0.39103792*g + 0.20063315*b;
          Y1 =  0.190*r+ 0.728*g + 0.085*b;
          Z1 =  0.0118997*r+ 0.05895*g + 1.00138953645*b;
    }
   Color xyz;
   xyz.X= X1;
   xyz.Y= Y1;
   xyz.Z= Z1;
   return xyz;
 }  
 Color rgb2xyz3(float R, float G, float B,char* s,char* s1)
 {
    float eps = 216.f/24389.f;
    float k = 24389.f/27.f;
    float  fx,fy,fz,X1,Y1,Z1,xr,yr,zr;
    float r,g,b;
    if(!strcmp(s,"image"))
    {
       r = R/255.f; //R 0..1
       g = G/255.f; //G 0..1
       b = B/255.f; //B 0..1
    }
    else if(!strcmp(s,"matrix"))
    {
        r=R;
        g=G;
        b=B;
    }
    if (r <= 0.04045)
       r = r/12.92;
    else
       r = (float)pow((r+0.055)/1.055,2.4);
    if (g <= 0.04045)
       g = g/12.92;
    else
       g = (float)pow((g+0.055)/1.055,2.4);
    if (b <= 0.04045)
       b = b/12.92;
    else
      b = (float)pow((b+0.055)/1.055,2.4);
   
    if(strcasecmp(s1,"sRGB")==0)
    {
          
          X1 =  0.4124564*r+ 0.3575761*g + 0.1804375*b;
          Y1 =  0.2126729*r+ 0.7151522*g + 0.0721750*b;
          Z1 =  0.0193339*r+ 0.1191920*g + 0.9503041*b;
    }
     else if(strcasecmp(s1,"adobe-rgb-1998")==0)
    {
          
          X1 =  0.703*r+ 0.1702*g + 0.020534*b;
          Y1 =  0.346*r+ 0.5628*g + 0.077*b;
          Z1 =  0.0201165*r+ 0.04013*g + 1.011295*b;
          
    }
    Color xyz;
    xyz.X= X1;
    xyz.Y= Y1;
    xyz.Z= Z1;
    return xyz;
  }   
int opencv_rgb2xyz(char *fname, unsigned long fname_len)
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
   sciErr =getVarAddressFromPosition(pvApiCtx,1,&piAddr1);
   sciErr = getVarType(pvApiCtx, piAddr1, &iType);
   if(nbInputArgument(pvApiCtx)==3)
   {
      /*retrieve second argument  */
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
        //important
        int j=0;
        if(nbInputArgument(pvApiCtx)==1)
        {
          for(int i=0;i<iRows;i++)
          {
            out=rgb2xyz1(value[j],value[j+1],value[j+2],"matrix");
            output[j]=out.X;
            output[j+1]=out.Y;
            output[j+2]=out.Z;
            j=j+3;
          }
        }
        else if(nbInputArgument(pvApiCtx)==3)
        {
          for(int i=0;i<iRows;i++)
          {
            if(!strcasecmp(pstData1,"d65")||!strcasecmp(pstData1,"d50")||!strcasecmp(pstData1,"d55")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"a")||!strcasecmp(pstData1,"c"))
            {
               out=rgb2xyz2(value[j],value[j+1],value[j+2],"matrix",pstData1);
            }
            else if(!strcasecmp(pstData1,"sRGB")||!strcasecmp(pstData1,"adobe-rgb-1998"))
            {
               out=rgb2xyz3(value[j],value[j+1],value[j+2],"matrix",pstData1);
            }
            output[j]=out.X;
            output[j+1]=out.Y;
            output[j+2]=out.Z;
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
         /*retrieve image value as matrix  */
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
                  if(nbInputArgument(pvApiCtx)==1)
                  {
                    out=rgb2xyz1(R,G,B,"image");
                  }
                  if(nbInputArgument(pvApiCtx)==3)
                  {
                   if(!strcasecmp(pstData1,"d65")||!strcasecmp(pstData1,"d50")||!strcasecmp(pstData1,"d55")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"icc")||!strcasecmp(pstData1,"a")||!strcasecmp(pstData1,"c"))
                    {
                     out=rgb2xyz2(R,G,B,"image",pstData1);
                    }
                   else if(!strcasecmp(pstData1,"sRGB")||!strcasecmp(pstData1,"adobe-rgb-1998"))
                    {
                     out=rgb2xyz3(R,G,B,"image",pstData1);
                    }
                  }
                  r1[m]=out.X;
                  g1[m]=out.Y;
                  b1[m++]=out.Z;  
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
