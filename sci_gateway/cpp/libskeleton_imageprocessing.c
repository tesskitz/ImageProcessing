#ifdef __cplusplus
extern "C" {
#endif
#include <mex.h> 
#include <sci_gateway.h>
#include <api_scilab.h>
#include <MALLOC.h>
static int direct_gateway(char *fname,void F(void)) { F();return 0;};
extern Gatefunc opencv_imread;
extern Gatefunc opencv_rgb2lab;
extern Gatefunc opencv_rgb2xyz;
extern Gatefunc opencv_rgb2ntsc;
extern Gatefunc opencv_ntsc2rgb;
extern Gatefunc opencv_xyz2rgb;
extern Gatefunc opencv_lab2rgb;
extern Gatefunc opencv_xyz2lab;
extern Gatefunc opencv_lab2xyz;
extern Gatefunc opencv_whitepoint;
extern Gatefunc opencv_lab2double;
extern Gatefunc opencv_xyz2double;
extern Gatefunc opencv_lab2uint8;
extern Gatefunc opencv_impyramid;
extern Gatefunc opencv_impyramid;
extern Gatefunc opencv_makecform;
extern Gatefunc opencv_applycform;
extern Gatefunc opencv_watershed;
extern Gatefunc opencv_fftshift;
extern Gatefunc opencv_ifftshift;
extern Gatefunc opencv_imabsdiff;
extern Gatefunc opencv_imsubtract;
extern Gatefunc opencv_imadd;
extern Gatefunc opencv_immultiply;
extern Gatefunc opencv_imdivide;
extern Gatefunc opencv_imcomplement;
extern Gatefunc opencv_imlincomb;
extern Gatefunc opencv_impixel;
extern Gatefunc opencv_bwconvhull;
extern Gatefunc opencv_imcontour;
extern Gatefunc opencv_lab2uint16;
extern Gatefunc opencv_xyz2uint16;
static GenericTable Tab[]={
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imread,"imread"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rgb2lab,"rgb2lab"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rgb2xyz,"rgb2xyz"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_rgb2ntsc,"rgb2ntsc"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ntsc2rgb,"ntsc2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2rgb,"xyz2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2rgb,"lab2rgb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2lab,"xyz2lab"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2xyz,"lab2xyz"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_whitepoint,"whitepoint"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2double,"lab2double"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2double,"xyz2double"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2uint8,"lab2uint8"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_impyramid,"impyramid"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_impyramid,"impyramid"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_makecform,"makecform"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_applycform,"applycform"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_watershed,"watershed"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_fftshift,"fftshift"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_ifftshift,"ifftshift"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imabsdiff,"imabsdiff"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imsubtract,"imsubtract"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imadd,"imadd"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_immultiply,"immultiply"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imdivide,"imdivide"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcomplement,"imcomplement"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imlincomb,"imlincomb"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_impixel,"impixel"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_bwconvhull,"bwconvhull"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_imcontour,"imcontour"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_lab2uint16,"lab2uint16"},
  {(Myinterfun)sci_gateway_without_putlhsvar,opencv_xyz2uint16,"xyz2uint16"},
};
 
int C2F(libskeleton_imageprocessing)()
{
  Rhs = Max(0, Rhs);
  if (*(Tab[Fin-1].f) != NULL) 
  {
     if(pvApiCtx == NULL)
     {
       pvApiCtx = (StrCtx*)MALLOC(sizeof(StrCtx));
     }
     pvApiCtx->pstName = (char*)Tab[Fin-1].name;
    (*(Tab[Fin-1].f))(Tab[Fin-1].name,Tab[Fin-1].F);
  }
  return 0;
}
#ifdef __cplusplus
}
#endif
