// This file is released under the 3-clause BSD license. See COPYING-BSD.
// Generated by builder.sce : Please, do not edit this file
// ----------------------------------------------------------------------------
//
libskeleton_imagepr_path = get_absolute_file_path('loader.sce');
//
// ulink previous function with same name
[bOK, ilib] = c_link('libskeleton_imageprocessing');
if bOK then
  ulink(ilib);
end
//
list_functions = [ 'imread';
                   'rgb2lab';
                   'rgb2xyz';
                   'rgb2ntsc';
                   'ntsc2rgb';
                   'xyz2rgb';
                   'lab2rgb';
                   'xyz2lab';
                   'lab2xyz';
                   'whitepoint';
                   'lab2double';
                   'xyz2double';
                   'lab2uint8';
                   'impyramid';
                   'impyramid';
                   'makecform';
                   'applycform';
                   'watershed';
                   'fftshift';
                   'ifftshift';
                   'imabsdiff';
                   'imsubtract';
                   'imadd';
                   'immultiply';
                   'imdivide';
                   'imcomplement';
                   'imlincomb';
                   'impixel';
                   'bwconvhull';
                   'imcontour';
                   'lab2uint16';
                   'xyz2uint16';
                   'imfindcircles';
                   'viscircles';
                   'corner';
];
addinter(libskeleton_imagepr_path + filesep() + 'libskeleton_imageprocessing' + getdynlibext(), 'libskeleton_imageprocessing', list_functions);
// remove temp. variables on stack
clear libskeleton_imagepr_path;
clear bOK;
clear ilib;
clear list_functions;
// ----------------------------------------------------------------------------
