function [status] = addpaths(integTesting)
   if integTesting == 1
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\Matlab_Simulator_B0plus');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\ADC_Data_Examples');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\helper_functions');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\RA_Command_Functions');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\calibrations');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\sub_functions');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\Test_Script');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\ridm_spec');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\FLR8_rdd_streamline_AF_and_calibration_v1p0\AF_FLR8_rdd_streamline_v1p0');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\FLR8_rdd_streamline_AF_and_calibration_v1p0\AF_FLR8_rdd_streamline_v1p0\USC');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\FLR8_rdd_streamline_AF_and_calibration_v1p0\AF_FLR8_rdd_streamline_v1p0\LUT');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\FLR8_rdd_streamline_AF_and_calibration_v1p0\AF_FLR8_rdd_streamline_v1p0\helpfun');
      addpath('..\..\Mex_Executable_Specs\Core_Radar_Gen8_iND13400_Matlab\Design_Spec\FLR8_rdd_streamline_AF_and_calibration_v1p0\AF_FLR8_rdd_streamline_v1p0\calibration_monitoring');

      status = 1;
   else
      status = 0;
   end
