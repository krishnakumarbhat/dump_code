#include "af_sil_utils.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

/*
 * Write all output formats
 */
void Write_AF_Outputs(Detection_Stream_T *out_buff, Detection_Debug_Stream_T *debug_buff, Down_selection_Stream_T *ds_buff)
{
   /* CSV files useful for comparison and matlab automation */
   Write_AF_Det_CSV_Outputs(out_buff, debug_buff);
   Write_AF_DS_Det_CSV_Outputs(ds_buff);

   /* Text files useful for quick inspection */
   Print_AF_Det_Outputs(out_buff, debug_buff);
   Print_AF_DS_Det_Outputs(ds_buff);
}

/*
 * This Function will be helpful in printing the AF SIL
 * outputs to a CSV file.
 * See tools/lauterbach/BBE32_AF/det_csv_compare.m for a tool to compare the
 * outputs to tv_anglefinding.
 */
void Write_AF_Det_CSV_Outputs(Detection_Stream_T *out_buff, Detection_Debug_Stream_T *debug_buff)
{
   uint16_t i, j;
   ofstream af_det_out_file("af_det_out_sil.csv");
   af_det_out_file << setprecision(10);

   af_det_out_file << "num_AF_det,target_selected_post_stage_1,target_selected_post_stage_2,target_selected_post_stage_3,"
                      "target_selected_post_stage_4,target_selected_post_stage_5,"
                      "ran,vel,pow,snr,theta,phi,rcs,spec_res,rdd_idx,az_conf,el_conf,Az_AF_type,"
                      "El_AF_type,f_single_target,f_superres_target,f_1az2el,f_bistatic";
   af_det_out_file << endl;

   for (i = 0; i < out_buff->num_af_det; i++)
   {
      if (0 == i)
      {
         af_det_out_file << out_buff->num_af_det;
         af_det_out_file << ',';
         af_det_out_file << debug_buff->af_det_debug_data.target_selected_post_stage_1;
         af_det_out_file << ',';
         af_det_out_file << debug_buff->af_det_debug_data.target_selected_post_stage_2;
         af_det_out_file << ',';
         af_det_out_file << debug_buff->af_det_debug_data.target_selected_post_stage_3;
         af_det_out_file << ',';
         af_det_out_file << debug_buff->af_det_debug_data.target_selected_post_stage_4;
         af_det_out_file << ',';
         af_det_out_file << debug_buff->af_det_debug_data.target_selected_post_stage_5;
         af_det_out_file << ',';
      }
      else
      {
         af_det_out_file << ",,,,,,";
      }
      af_det_out_file << out_buff->af_dets[i].ran;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].vel;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].pow;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].snr;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].theta;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].phi;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].rcs;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].spec_res;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_dets[i].rdd_idx;
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_dets[i].az_conf);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_dets[i].el_conf);
      af_det_out_file << ',';
      af_det_out_file << int(debug_buff->af_debug_detections[i].az_af_type);
      af_det_out_file << ',';
      af_det_out_file << int(debug_buff->af_debug_detections[i].el_af_type);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_dets[i].f_single_target);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_dets[i].f_superres_target);
      af_det_out_file << ',';
      af_det_out_file << int(debug_buff->af_debug_detections[i].f_1az2el);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_dets[i].f_bistatic);
      af_det_out_file << endl;
   }

   af_det_out_file.close();
}

void Write_AF_DS_Det_CSV_Outputs(Down_selection_Stream_T *out_buff)
{
   uint16_t i, j;
   ofstream af_det_out_file("af_ds_det_out_sil.csv");
   af_det_out_file << setprecision(10);

   af_det_out_file << "num_af_ds_det, ran, vel, pow, snr, theta, phi, rcs, spec_res, rdd_idx, az_conf, el_conf,"
                      "f_single_target,f_superres_target,f_bistatic";
   af_det_out_file << endl;

   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      if (0 == i)
      {
         af_det_out_file << out_buff->num_af_ds_det;
         af_det_out_file << ',';
      }
      else
      {
         af_det_out_file << ",";
      }
      af_det_out_file << out_buff->af_ds_dets[i].ran;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].vel;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].pow;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].snr;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].theta;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].phi;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].rcs;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].spec_res;
      af_det_out_file << ',';
      af_det_out_file << out_buff->af_ds_dets[i].rdd_idx;
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_ds_dets[i].az_conf);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_ds_dets[i].el_conf);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_ds_dets[i].f_single_target);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_ds_dets[i].f_superres_target);
      af_det_out_file << ',';
      af_det_out_file << int(out_buff->af_ds_dets[i].f_bistatic);
      af_det_out_file << endl;
   }

   af_det_out_file.close();
}

/*
 * This Function will be helpful in printing the AF SIL
 * outputs in text file.
 * */
void Print_AF_Det_Outputs(Detection_Stream_T *out_buff, Detection_Debug_Stream_T *debug_buff)
{
   uint16_t i, j;
   ofstream af_det_out_file("af_det_out_sil.txt");

   af_det_out_file << "num_af_det  : ";
   af_det_out_file << out_buff->num_af_det;
   af_det_out_file << endl;

   af_det_out_file << "ran  : ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].ran << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "vel  : ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].vel << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "pow  : ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].pow << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "snr  : ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].snr << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "theta: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].theta << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "phi  : ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].phi << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "rcs  : ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].rcs << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "spec_res: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].spec_res << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "rdd_idx: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << out_buff->af_dets[i].rdd_idx << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "az_conf: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(out_buff->af_dets[i].az_conf) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "el_conf: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(out_buff->af_dets[i].el_conf) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "az_af_type: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(debug_buff->af_debug_detections[i].az_af_type) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "el_af_type: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(debug_buff->af_debug_detections[i].el_af_type) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_single_target: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(out_buff->af_dets[i].f_single_target) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_superres_target: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(out_buff->af_dets[i].f_superres_target) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_1az2el: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(debug_buff->af_debug_detections[i].f_1az2el) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_bistatic: ";
   for (i = 0; i < out_buff->num_af_det; i++)
   {
      af_det_out_file << int(out_buff->af_dets[i].f_bistatic) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file.close();
}

void Print_AF_DS_Det_Outputs(Down_selection_Stream_T *out_buff)
{
   uint16_t i, j;
   ofstream af_det_out_file("af_ds_det_out_sil.txt");

   af_det_out_file << "num_af_ds_det  : ";
   af_det_out_file << out_buff->num_af_ds_det;
   af_det_out_file << endl;

   af_det_out_file << "ran  : ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].ran << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "vel  : ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].vel << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "pow  : ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].pow << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "snr  : ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].snr << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "theta: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].theta << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "phi  : ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].phi << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "rcs  : ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].rcs << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "spec_res: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].spec_res << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "rdd_idx: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << out_buff->af_ds_dets[i].rdd_idx << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "az_conf: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << int(out_buff->af_ds_dets[i].az_conf) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "el_conf: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << int(out_buff->af_ds_dets[i].el_conf) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_single_target: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << int(out_buff->af_ds_dets[i].f_single_target) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_superres_target: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << int(out_buff->af_ds_dets[i].f_superres_target) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file << "f_bistatic: ";
   for (i = 0; i < out_buff->num_af_ds_det; i++)
   {
      af_det_out_file << int(out_buff->af_ds_dets[i].f_bistatic) << ", ";
   }
   af_det_out_file << endl;

   af_det_out_file.close();
}
