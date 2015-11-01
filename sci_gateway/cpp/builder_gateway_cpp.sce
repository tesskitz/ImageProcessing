// This file is released under the 3-clause BSD license. See COPYING-BSD.

names = [	
	   "imread","opencv_imread";
     	   "rgb2lab","opencv_rgb2lab";
           "rgb2xyz","opencv_rgb2xyz";
           "rgb2ntsc","opencv_rgb2ntsc";
           "ntsc2rgb","opencv_ntsc2rgb";
           "xyz2rgb","opencv_xyz2rgb";
           "lab2rgb","opencv_lab2rgb";
           "xyz2lab","opencv_xyz2lab";
           "lab2xyz","opencv_lab2xyz";
           "whitepoint","opencv_whitepoint";
           "lab2double","opencv_lab2double"; 
           "xyz2double","opencv_xyz2double"; 
           "lab2uint8","opencv_lab2uint8"; 
           "impyramid","opencv_impyramid"; 
           "impyramid","opencv_impyramid"; 
           "makecform","opencv_makecform"; 
           "applycform","opencv_applycform"; 
           "watershed","opencv_watershed"; 
           "fftshift","opencv_fftshift"; 
           "ifftshift","opencv_ifftshift"; 
           "imabsdiff","opencv_imabsdiff"; 
           "imsubtract","opencv_imsubtract"; 
           "imadd","opencv_imadd"; 
           "immultiply","opencv_immultiply"; 
           "imdivide","opencv_imdivide"; 
           "imcomplement","opencv_imcomplement"; 
           "imlincomb","opencv_imlincomb"; 
           "impixel","opencv_impixel"; 
           "bwconvhull","opencv_bwconvhull"; 
           "imcontour","opencv_imcontour"; 
           "lab2uint16","opencv_lab2uint16"; 
           "xyz2uint16","opencv_xyz2uint16"; 
           "imfindcircles","opencv_imfindcircles";
           "viscircles","opencv_viscircles"; 
           "corner","opencv_corner"; 
		];

files = [
	    "opencv_imread.cpp",
            "opencv_rgb2lab.cpp",
            "opencv_rgb2xyz.cpp",
            "opencv_rgb2ntsc.cpp",
            "opencv_ntsc2rgb.cpp",
            "opencv_xyz2rgb.cpp",
            "opencv_lab2rgb.cpp",
            "opencv_xyz2lab.cpp",
            "opencv_lab2xyz.cpp",
            "opencv_whitepoint.cpp",
            "opencv_lab2double.cpp",
            "opencv_xyz2double.cpp",
            "opencv_lab2uint8.cpp",
            "opencv_impyramid.cpp",
            "opencv_makecform.cpp",
            "opencv_applycform.cpp",
            "opencv_watershed.cpp",
            "opencv_fftshift.cpp",
            "opencv_ifftshift.cpp",
            "opencv_imabsdiff.cpp",
            "opencv_imsubtract.cpp",
            "opencv_imadd.cpp",
            "opencv_immultiply.cpp",
            "opencv_imdivide.cpp",
            "opencv_imcomplement.cpp",
            "opencv_imlincomb.cpp",
            "opencv_impixel.cpp",
            "opencv_bwconvhull.cpp",
            "opencv_imcontour.cpp",
            "opencv_lab2uint16.cpp",
            "opencv_xyz2uint16.cpp",
            "opencv_imfindcircles.cpp",
            "opencv_viscircles.cpp",
            "opencv_corner.cpp",
		];
 

function builder_gw_cpp()
    WITHOUT_AUTO_PUTLHSVAR = %t;
    copyfile("sci_gateway/cpp/common.h",TMPDIR);
    copyfile("sci_gateway/cpp/common.cpp",TMPDIR);
tbx_build_gateway("skeleton_imageprocessing", ..
	names, ..
    files, ..
    get_absolute_file_path("builder_gateway_cpp.sce"),[],["-lopencv_core -lopencv_highgui -lopencv_imgproc"],["-I/usr/local/include/opencv/ -I/usr/local/include/opencv2/"],"g++ ")
endfunction

builder_gw_cpp();
clear builder_gw_cpp; // remove builder_gw_cpp on stack
