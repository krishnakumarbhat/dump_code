#include "common.ld"
#ifdef TRACKER_DISABLED
__stack_size =   0x8000;                       /* SOFTWARE STACK SIZE       */
#else /* TRACKER_ENABLED ROT10.30 needed larger stack during chamber tests */
__stack_size =   0x8500;                       /* SOFTWARE STACK SIZE       */
#endif
/* This linker script generated from xt-genldscripts.tpp for LSP bbe32_luna-min-rt-local */
/* Linker Script for default link */
MEMORY
{
  iram0_0_seg :                       	org = ORIGIN(BBE32_ITCM), len = 0x2E0
  iram0_2_seg :                       	org = ORIGIN(BBE32_ITCM) + 0x310, len = 0x180
  iram0_4_seg :                       	org = ORIGIN(BBE32_ITCM) + 0x800, len = 0x178
  iram0_6_seg :                       	org = ORIGIN(BBE32_ITCM) + 0x97C, len = 0x1C
  iram0_8_seg :                       	org = ORIGIN(BBE32_ITCM) + 0x99C, len = 0x1C
  iram0_10_seg :                      	org = ORIGIN(BBE32_ITCM) + 0x9BC, len = 0x1C
  iram0_12_seg :                      	org = ORIGIN(BBE32_ITCM) + 0x9DC, len = 0x1C
  iram0_14_seg :                      	org = ORIGIN(BBE32_ITCM) + 0x9FC, len = 0x1C
  iram0_16_seg :                      	org = ORIGIN(BBE32_ITCM) + 0xA1C, len = 0x1C
  iram0_18_seg :                      	org = ORIGIN(BBE32_ITCM) + 0xA3C, len = 0x1C
  iram0_20_seg :                      	org = ORIGIN(BBE32_ITCM) + 0xA5C, len = 0x1C
#ifdef TRACKER_DISABLED
  iram0_21_seg :                      	org = ORIGIN(BBE32_ITCM) + 0xA78, len = 0x3AD88  /*(0x3F588-0xAC00) 18KB reseved for F360 Tracker for standalone build */
#else
  iram0_21_seg :                      	org = ORIGIN(BBE32_ITCM) + 0xA78, len = 0x3F588  /* Chandra B0 has 256KB DSP IRAM */
#endif
  periph_seg :                        	org = 0x84100000, len = 0xD837000
}
PHDRS
{
  sram0_phdr PT_LOAD;
  sram0_tracker_phdr PT_LOAD;
  sram0_bss_phdr PT_LOAD;
  sram0_tracker_bss_phdr PT_LOAD;
  sram1_phdr PT_LOAD;
  sram1_bss_phdr PT_LOAD;
  sram1_ipc_section_phdr PT_LOAD;
  sram1_ipc_d2m PT_LOAD;
  sram1_ipc_m2d PT_LOAD;
  buf0_phdr PT_LOAD;
  buf1_phdr PT_LOAD;
  dram0_0_phdr PT_LOAD;
  dram0_0_bss_phdr PT_LOAD;
  buf2_phdr PT_LOAD;
  buf3_phdr PT_LOAD;
  dram1_0_phdr PT_LOAD;
  dram1_0_bss_phdr PT_LOAD;
  iram0_0_phdr PT_LOAD;
  iram0_1_phdr PT_LOAD;
  iram0_2_phdr PT_LOAD;
  iram0_3_phdr PT_LOAD;
  iram0_4_phdr PT_LOAD;
  iram0_5_phdr PT_LOAD;
  iram0_6_phdr PT_LOAD;
  iram0_7_phdr PT_LOAD;
  iram0_8_phdr PT_LOAD;
  iram0_9_phdr PT_LOAD;
  iram0_10_phdr PT_LOAD;
  iram0_11_phdr PT_LOAD;
  iram0_12_phdr PT_LOAD;
  iram0_13_phdr PT_LOAD;
  iram0_14_phdr PT_LOAD;
  iram0_15_phdr PT_LOAD;
  iram0_16_phdr PT_LOAD;
  iram0_17_phdr PT_LOAD;
  iram0_18_phdr PT_LOAD;
  iram0_19_phdr PT_LOAD;
  iram0_20_phdr PT_LOAD;
  iram0_21_phdr PT_LOAD;
  periph_phdr PT_LOAD;
}
/*  Default entry point:  */
ENTRY(_ResetVector)
/*  Memory boundary addresses:  */
_memmap_mem_sram0_start = 0x80000000;
_memmap_mem_sram0_end   = 0x82000000;
_memmap_mem_sram1_start = 0x82000000;
_memmap_mem1_shared_space = 0x821FC000;
_memmap_mem_sram1_end   = 0x84000000;
_memmap_mem_dram0_start = 0x84020000;
_memmap_mem_dram0_end   = 0x84030000;
_memmap_mem_dram1_start = 0x84030000;
_memmap_mem_dram1_end   = 0x84040000;
_memmap_mem_iram0_start = 0x84040000;
_memmap_mem_iram0_end   = 0x84080000;
_memmap_mem_periph_start = 0x84100000;
_memmap_mem_periph_end   = 0x91937000;
/* Used for BBE MPU */
__SYSMEM0_VIEW0_START_ADDR = ORIGIN(SYSMEM0_TRACKER);

__SYSMEM0_VIEW0_END_ADDR = ORIGIN(SYSMEM_IPC_D2M);
__SYSMEM0_VIEW1_START_ADDR = ORIGIN(SYSMEM0_R52_DATA)+LENGTH(SYSMEM0_R52_DATA);
__SYSMEM1_VIEW0_START_ADDR = ORIGIN(SYSMEM1_BBE32);
__SYSMEM1_SHARED = ORIGIN(SYSMEM_IPC_SHARED);
__SYSMEM1_VIEW1_START_ADDR = ORIGIN(SYSMEM_IPC_M2D)+LENGTH(SYSMEM_IPC_M2D);
__BBE_DRAM0_START_ADDR = ORIGIN(BBE32_DTCM0);
__BBE_DRAM1_START_ADDR = ORIGIN(BBE32_DTCM1);
__BBE_IRAM_START_ADDR = ORIGIN(BBE32_ITCM);
__UNUSED_POST_BBE_MEM = ORIGIN(BBE32_ITCM)+LENGTH(BBE32_ITCM);
__PERIPHERAL_START_ADDR = _memmap_mem_periph_start;
__UNUSED_POST_PERIPHERAL_START_ADDR = _memmap_mem_periph_end;
/*  Memory segment boundary addresses:  */
_memmap_seg_sram0_start = 0x80000000;
_memmap_seg_sram0_max   = 0x82000000;
_memmap_seg_sram1_start = 0x82000000;
_memmap_seg_sram1_max   = 0x84000000;
_memmap_seg_buf0_start = 0x84020000;
_memmap_seg_buf0_max   = 0x84022000;
_memmap_seg_buf1_start = 0x84022000;
_memmap_seg_buf1_max   = 0x84024000;
_memmap_seg_dram0_0_start = 0x84024000;
_memmap_seg_dram0_0_max   = 0x84030000;
_memmap_seg_buf2_start = 0x84030000;
_memmap_seg_buf2_max   = 0x84032000;
_memmap_seg_buf3_start = 0x84032000;
_memmap_seg_buf3_max   = 0x84034000;
_memmap_seg_dram1_0_start = 0x84034000;
_memmap_seg_dram1_0_max   = 0x84040000;
_memmap_seg_iram0_0_start = 0x84040000;
_memmap_seg_iram0_0_max   = 0x840402e0;
_memmap_seg_iram0_2_start = 0x84040310;
_memmap_seg_iram0_2_max   = 0x84040490;
_memmap_seg_iram0_4_start = 0x84040800;
_memmap_seg_iram0_4_max   = 0x84040978;
_memmap_seg_iram0_6_start = 0x8404097c;
_memmap_seg_iram0_6_max   = 0x84040998;
_memmap_seg_iram0_8_start = 0x8404099c;
_memmap_seg_iram0_8_max   = 0x840409b8;
_memmap_seg_iram0_10_start = 0x840409bc;
_memmap_seg_iram0_10_max   = 0x840409d8;
_memmap_seg_iram0_12_start = 0x840409dc;
_memmap_seg_iram0_12_max   = 0x840409f8;
_memmap_seg_iram0_14_start = 0x840409fc;
_memmap_seg_iram0_14_max   = 0x84040a18;
_memmap_seg_iram0_16_start = 0x84040a1c;
_memmap_seg_iram0_16_max   = 0x84040a38;
_memmap_seg_iram0_18_start = 0x84040a3c;
_memmap_seg_iram0_18_max   = 0x84040a58;
_memmap_seg_iram0_20_start = 0x84040a5c;
_memmap_seg_iram0_20_max   = 0x84040a78;
_memmap_seg_iram0_21_start = 0x84040a78;
_memmap_seg_iram0_21_max   = 0x84080000;
_memmap_seg_periph_start = 0x84100000;
_memmap_seg_periph_max   = 0x91937000;
_rom_store_table = 0;
PROVIDE(_memmap_reset_vector = 0x84040000);
PROVIDE(_memmap_vecbase_reset = 0x84040800);
/* Various memory-map dependent cache attribute settings: */
_memmap_cacheattr_wb_base = 0x00010000;
_memmap_cacheattr_wt_base = 0x00030000;
_memmap_cacheattr_bp_base = 0x00040000;
_memmap_cacheattr_unused_mask = 0xFFF0FFFF;
_memmap_cacheattr_wb_trapnull = 0x44414440;
_memmap_cacheattr_wba_trapnull = 0x44414440;
_memmap_cacheattr_wbna_trapnull = 0x44424440;
_memmap_cacheattr_wt_trapnull = 0x44434440;
_memmap_cacheattr_bp_trapnull = 0x44444440;
_memmap_cacheattr_wb_strict = 0x00010000;
_memmap_cacheattr_wt_strict = 0x00030000;
_memmap_cacheattr_bp_strict = 0x00040000;
_memmap_cacheattr_wb_allvalid = 0x44414444;
_memmap_cacheattr_wt_allvalid = 0x44434444;
_memmap_cacheattr_bp_allvalid = 0x44444444;
_memmap_region_map = 0x00000010;
PROVIDE(_memmap_cacheattr_reset = _memmap_cacheattr_wb_trapnull);
SECTIONS
{
   .sram0.rodata : ALIGN(4)
  {
    _sram0_rodata_start = ABSOLUTE(.);
    *(.sram0.rodata)
    *libinterference_detection_algo_feature_lib.a:(.rodata)
    *libinterference_detection_src_lib.a:(.rodata)
    *libdyn_align_wrapper.a:(.rodata)
    *libdyn_align_module_src_lib.a:(.rodata)
    *librc_wrapper_lib.a:(.rodata)
    *libradar_capability_feature_lib.a:(.rodata)
    *librc_common_module.a:(.rodata)
    *libblockage_module.a:(.rodata)
    *librc_diag_module.a:(.rodata)
    *libdm_module.a:(.rodata)
    *libfsc_module.a:(.rodata)
    *librc_fault_injection_lib.a:(.rodata)
    *libre_module.a:(.rodata)
    *libse_module.a:(.rodata)
    *libpbd_module.a:(.rodata)
    *libstatic_alignment.a:(.rodata)
    *libstatic_alignment_algo_src.a:(.rodata)
    *libdyn_align_wrapper.a:(.rodata.*)
    *libdyn_align_module_src_lib.a:(.rodata.*)
    *libinterference_detection_algo_feature_lib.a:(.rodata.*)
    *libinterference_detection_src_lib.a:(.rodata.*)
    *librc_wrapper_lib.a:(.rodata.*)
    *libradar_capability_feature_lib.a:(.rodata.*)
    *librc_common_module.a:(.rodata.*)
    *libblockage_module.a:(.rodata.*)
    *librc_diag_module.a:(.rodata.*)
    *libdm_module.a:(.rodata.*)
    *libfsc_module.a:(.rodata.*)
    *librc_fault_injection_lib.a:(.rodata.*)
    *libre_module.a:(.rodata.*)
    *libse_module.a:(.rodata.*)
    *libpbd_module.a:(.rodata.*)
    *libstatic_alignment.a:(.rodata.*)
    *libstatic_alignment_algo_src.a:(.rodata.*)
    . = ALIGN (4);
    _sram0_rodata_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
   .sram0.rodata.tracker  : ALIGN(4)
  {
    _sram0_rodata_start = ABSOLUTE(.);
    *libemb_tracker_wrapper.a:(.rodata)
    *libstate_manager.a:(.rodata)
    *libf360_get_wall_time.a:(.rodata)
    *libfusion_360*.a:(.rodata)
    *libocg.a:(.rodata)
    *libsg.a:(.rodata)
    *libstdc++.a:(.rodata)
    *libc.a:(.rodata)
    *libm.a:(.rodata)
    *libgcc.a:(.rodata)
    *libhandlers-board.a:(.rodata)
    *libhal.a:(.rodata)
    *libemb_tracker_wrapper.a:(.rodata.*)
    *libstate_manager.a:(.rodata.*)
    *libf360_get_wall_time.a:(.rodata.*)
    *libfusion_360*.a:(.rodata.*)
    *libocg.a:(.rodata.*)
    *libsg.a:(.rodata.*)
    *libstdc++.a:(.rodata.*)
    *libc.a:(.rodata.*)
    *libm.a:(.rodata.*)
    *libgcc.a:(.rodata.*)
    *libhandlers-board.a:(.rodata.*)
    *libhal.a:(.rodata.*)
    . = ALIGN (4);
    _sram0_rodata_end = ABSOLUTE(.);
#ifdef TRACKER_DISABLED
  } >SYSMEM1_BBE32 :sram1_phdr
#else
  } >SYSMEM0_TRACKER :sram0_tracker_phdr
#endif
   .sram0.rodata.feature  : ALIGN(4)
  {
    _sram0_rodata_start = ABSOLUTE(.);
    *libOLP_Core_Lib.a:(.rodata)
    *libml_core_lib.a:(.rodata)
    *libmode_manager_lib.a:(.rodata)
    *libcal_tool_lib.a:(.rodata)
    *libfbk_lib.a:(.rodata)
    *libbsis_lib.a:(.rodata)
    *libmois_lib.a:(.rodata)
    *libolp_wrapper_lib.a:(.rodata)
    *libWrappers_lib.a:(.rodata)

    *libOLP_Core_Lib.a:(.rodata.*)
    *libml_core_lib.a:(.rodata.*)
    *libmode_manager_lib.a:(.rodata.*)
    *libcal_tool_lib.a:(.rodata.*)
    *libfbk_lib.a:(.rodata.*)
    *libbsis_lib.a:(.rodata.*)
    *libmois_lib.a:(.rodata.*)
    *libolp_wrapper_lib.a:(.rodata.*)
    *libWrappers_lib.a:(.rodata.*)    
    . = ALIGN (4);
    _sram0_rodata_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
  .sram0.text : ALIGN(4)
  {
    _sram0_literal_start = ABSOLUTE(.);
    *(.sram0.literal .sram0.text)
    *(.sram.text)
    *libinterference_detection_algo_feature_lib.a:(.literal .text)
    *libinterference_detection_src_lib.a:(.literal .text)
    *libdyn_align_wrapper.a:(.literal .text)
    *libdyn_align_module_src_lib.a:(.literal .text)
    *librc_wrapper_lib.a:(.literal .text)
    *libradar_capability_feature_lib.a:(.literal .text)
    *librc_common_module.a:(.literal .text)
    *libblockage_module.a:(.literal .text)
    *librc_diag_module.a:(.literal .text)
    *libdm_module.a:(.literal .text)
    *libfsc_module.a:(.literal .text)
    *librc_fault_injection_lib.a:(.literal .text)
    *libre_module.a:(.literal .text)
    *libse_module.a:(.literal .text)
    *libpbd_module.a:(.literal .text)
    *libstatic_alignment.a:(.literal .text)
    *libstatic_alignment_algo_src.a:(.literal .text)
    *libdyn_align_wrapper.a:(.literal.* .text.*)
    *libdyn_align_module_src_lib.a:(.literal.* .text.*)
    *libinterference_detection_algo_feature_lib.a:(.literal.* .text.*)
    *libinterference_detection_src_lib.a:(.literal.* .text.*)
    *librc_wrapper_lib.a:(.literal.* .text.*)
    *libradar_capability_feature_lib.a:(.literal.* .text.*)
    *librc_common_module.a:(.literal.* .text.*)
    *libblockage_module.a:(.literal.* .text.*)
    *librc_diag_module.a:(.literal.* .text.*)
    *libdm_module.a:(.literal.* .text.*)
    *libfsc_module.a:(.literal.* .text.*)
    *librc_fault_injection_lib.a:(.literal.* .text.*)
    *libre_module.a:(.literal.* .text.*)
    *libse_module.a:(.literal.* .text.*)
    *libpbd_module.a:(.literal.* .text.*)
    *libstatic_alignment.a:(.literal.* .text.*)
    *libstatic_alignment_algo_src.a:(.literal.* .text.*)
    *libmain_application_lib.a:(.literal .text)
    *libangle_finding*.a:(.literal .text)
    *libipc_dsp_lib.a:(.literal .text)
    *libmain_application_lib.a:(.literal.* .text.*)
    *libangle_finding*.a:(.literal.* .text.*)
    *libipc_dsp_lib.a:(.literal.* .text.*)
    *libstdc++.a:(.literal .text)
    *libm.a:(.literal .text)
    *libhal.a:(.literal .text)
    *libstdc++.a:(.literal.* .text.*)
    *libm.a:(.literal.* .text.*)
    *libhal.a:(.literal.* .text.*)
    *libxtlx_stl.a:(.stl.literal .stl.text)
    . = ALIGN (4);
    _sram0_literal_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr

  .sram0.text2.tracker : ALIGN(4)
  {
    _sram0_literal_start = ABSOLUTE(.);
    *fusion_360_inputs_preprocessing*.a:(.literal .text)
    *fusion_360_internal_preprocessing*.a:(.literal .text)
    *libfusion_fusion_360_logging360*.a:(.literal .text)
    *fusion_360_measurement_update_tracks*.a:(.literal .text)
    *fusion_360_object_track_initialization*.a:(.literal .text)
    *fusion_360_occlusion*.a:(.literal .text)
    *fusion_360_passenger_trailer_estimator*.a:(.literal .text)
    *fusion_360_post_update_track_adjustments*.a:(.literal .text)
    
    *fusion_360_inputs_preprocessing*.a:(.literal.* .text.*)
    *fusion_360_internal_preprocessing*.a:(.literal.* .text.*)
    *libfusion_fusion_360_logging360*.a:(.literal.* .text.*)
    *fusion_360_measurement_update_tracks*.a:(.literal.* .text.*)
    *fusion_360_object_track_initialization*.a:(.literal.* .text.*)
    *fusion_360_occlusion*.a:(.literal.* .text.*)
    *fusion_360_passenger_trailer_estimator*.a:(.literal.* .text.*)
    *fusion_360_post_update_track_adjustments*.a:(.literal.* .text.*)

    . = ALIGN (4);
    _sram0_literal_end = ABSOLUTE(.);
#ifdef TRACKER_DISABLED
  } >SYSMEM1_BBE32 :sram1_phdr
#else
  } >SYSMEM1_BBE32 :sram0_tracker_phdr
#endif

  .sram0.text.tracker : ALIGN(4)
  {
    _sram0_literal_start = ABSOLUTE(.);
    *libfusion_360*.a:(.literal .text)
    
    *libfusion_360*.a:(.literal.* .text.*)

    . = ALIGN (4);
    _sram0_literal_end = ABSOLUTE(.);
#ifdef TRACKER_DISABLED
  } >SYSMEM1_BBE32 :sram1_phdr
#else
  } >SYSMEM0_TRACKER :sram0_tracker_phdr
#endif

  .sram0.text1.tracker : ALIGN(4)
  {
    *libemb_tracker_wrapper.a:(.literal .text)
    *libstate_manager.a:(.literal .text)
    *libf360_get_wall_time.a:(.literal .text)
    *libocg.a:(.literal .text)
    *libsg.a:(.literal .text)
    
    *libemb_tracker_wrapper.a:(.literal.* .text.*)
    *libstate_manager.a:(.literal.* .text.*)
    *libf360_get_wall_time.a:(.literal.* .text.*)
    *libocg.a:(.literal.* .text.*)
    *libsg.a:(.literal.* .text.*)
    . = ALIGN (4);
  } >SYSMEM1_BBE32 :sram1_phdr


   .sram0.text.feature  : ALIGN(4)
  {
    _sram0_literal_start = ABSOLUTE(.);
    *libOLP_Core_Lib.a:(.literal .text)
    *libml_core_lib.a:(.literal .text)
    *libmode_manager_lib.a:(.literal .text)
    *libcal_tool_lib.a:(.literal .text)
    *libfbk_lib.a:(.literal .text)
    *libbsis_lib.a:(.literal .text)
    *libmois_lib.a:(.literal .text)
    *libolp_wrapper_lib.a:(.literal .text)
    *libWrappers_lib.a:(.literal .text)

    *libOLP_Core_Lib.a:(.literal.* .text.*)
    *libml_core_lib.a:(.literal.* .text.*)
    *libmode_manager_lib.a:(.literal.* .text.*)
    *libcal_tool_lib.a:(.literal.* .text.*)
    *libfbk_lib.a:(.literal.* .text.*)
    *libbsis_lib.a:(.literal.* .text.*)
    *libmois_lib.a:(.literal.* .text.*)
    *libolp_wrapper_lib.a:(.literal.* .text.*)
    *libWrappers_lib.a:(.literal.* .text.*)    
    . = ALIGN (4);
    _sram0_literal_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
  .sram0.data : ALIGN(4)
  {
    _sram0_data_start = ABSOLUTE(.);
    *(.sram0.data)
    *libxtlx_stl.a:(.stl.data)
    *libxtlx_stl.a:(.stl.noncached.data)
    . = ALIGN (4);
    _sram0_data_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
.sram0.data.tracker : ALIGN(4)
  {
    _sram0_data_start = ABSOLUTE(.);
    *libemb_tracker_wrapper.a:(.data)
    *libf360_get_wall_time.a:(.data)
    *libstate_manager.a:(.data)
    *libfusion_360*.a:(.data)
    *libocg.a:(.data)
    *libsg.a:(.data)
    *libm.a:(.data)
    *libemb_tracker_wrapper.a:(.data.*)
    *libf360_get_wall_time.a:(.data.*)
    *libstate_manager.a:(.data.*)
    *libfusion_360*.a:(.data.*)
    *libocg.a:(.data.*)
    *libsg.a:(.data.*)
    *libm.a:(.data.*)
    . = ALIGN (4);
    _sram0_data_end = ABSOLUTE(.);
#ifdef TRACKER_DISABLED
  } >SYSMEM1_BBE32 :sram1_phdr
#else
  } >SYSMEM0_TRACKER :sram0_tracker_phdr
#endif
   .sram0.data.feature  : ALIGN(4)
  {
    _sram0_data_start = ABSOLUTE(.);
    *libOLP_Core_Lib.a:(.data)
    *libml_core_lib.a:(.data)
    *libmode_manager_lib.a:(.data)
    *libcal_tool_lib.a:(.data)
    *libfbk_lib.a:(.data)
    *libbsis_lib.a:(.data)
    *libmois_lib.a:(.data)
    *libolp_wrapper_lib.a:(.data)
    *libWrappers_lib.a:(.data)

    *libOLP_Core_Lib.a:(.data.*)
    *libml_core_lib.a:(.data.*)
    *libmode_manager_lib.a:(.data.*)
    *libcal_tool_lib.a:(.data.*)
    *libfbk_lib.a:(.data.*)
    *libbsis_lib.a:(.data.*)
    *libmois_lib.a:(.data.*)
    *libolp_wrapper_lib.a:(.data.*)
    *libWrappers_lib.a:(.data.*)    
    . = ALIGN (4);
    _sram0_data_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
  .sram0.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _sram0_bss_start = ABSOLUTE(.);
    *(.sram0.bss)
    *libdyn_align_wrapper.a:(.bss)
    *libdyn_align_module_src_lib.a:(.bss)
    *libinterference_detection_algo_feature_lib.a:(.bss)
    *libinterference_detection_src_lib.a:(.bss)
    *librc_wrapper_lib.a:(.bss)
    *libradar_capability_feature_lib.a:(.bss)
    *librc_common_module.a:(.bss)
    *libblockage_module.a:(.bss)
    *librc_diag_module.a:(.bss)
    *libdm_module.a:(.bss)
    *libfsc_module.a:(.bss)
    *librc_fault_injection_lib.a:(.bss)
    *libre_module.a:(.bss)
    *libse_module.a:(.bss)
    *libpbd_module.a:(.bss)
    *libstatic_alignment.a:(.bss)
    *libstatic_alignment_algo_src.a:(.bss)
    *libinterference_detection_algo_feature_lib.a:(.bss.*)
    *libinterference_detection_src_lib.a:(.bss.*)
    *libdyn_align_wrapper.a:(.bss.*)
    *libdyn_align_module_src_lib.a:(.bss.*)
    *librc_wrapper_lib.a:(.bss.*)
    *libradar_capability_feature_lib.a:(.bss.*)
    *librc_common_module.a:(.bss.*)
    *libblockage_module.a:(.bss.*)
    *librc_diag_module.a:(.bss.*)
    *libdm_module.a:(.bss.*)
    *libfsc_module.a:(.bss.*)
    *librc_fault_injection_lib.a:(.bss.*)
    *libre_module.a:(.bss.*)
    *libse_module.a:(.bss.*)
    *libpbd_module.a:(.bss.*)
    *libstatic_alignment.a:(.bss.*)
    *libstatic_alignment_algo_src.a:(.bss.*)
    . = ALIGN (8);
    _sram0_bss_end = ABSOLUTE(.);
    _memmap_seg_sram0_end = ALIGN(0x8);
  } >SYSMEM1_BBE32 :sram1_bss_phdr
  .sram0.bss.tracker (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _sram0_bss_start = ABSOLUTE(.);
    *libemb_tracker_wrapper.a:(.bss)
    *libf360_get_wall_time.a:(.bss)
    *libstate_manager.a:(.bss)
    *libfusion_360*.a:(.bss)
    *libocg.a:(.bss)
    *libsg.a:(.bss)
    
    *libstdc++.a:(.bss)
    *libm.a:(.bss)
    *libemb_tracker_wrapper.a:(.bss.*)
    *libf360_get_wall_time.a:(.bss.*)
    *libstate_manager.a:(.bss.*)
    *libfusion_360*.a:(.bss.*)
    *libocg.a:(.bss.*)
    *libsg.a:(.bss.*)
    
    *libstdc++.a:(.bss.*)
    *libm.a:(.bss.*)
    . = ALIGN (8);
    _sram0_bss_end = ABSOLUTE(.);
    _memmap_seg_sram0_end = ALIGN(0x8);
#ifdef TRACKER_DISABLED
  } >SYSMEM1_BBE32 :sram1_bss_phdr
#else
  } >SYSMEM1_BBE32 :sram1_bss_phdr
#endif
  .sram0.bss.feature (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _sram0_bss_start = ABSOLUTE(.);
        *libOLP_Core_Lib.a:(.bss)
    *libml_core_lib.a:(.bss)
    *libmode_manager_lib.a:(.bss)
    *libcal_tool_lib.a:(.bss)
    *libfbk_lib.a:(.bss)
    *libbsis_lib.a:(.bss)
    *libmois_lib.a:(.bss)
    *libolp_wrapper_lib.a:(.bss)
    *libWrappers_lib.a:(.bss)

    *libOLP_Core_Lib.a:(.bss.*)
    *libml_core_lib.a:(.bss.*)
    *libmode_manager_lib.a:(.bss.*)
    *libcal_tool_lib.a:(.bss.*)
    *libfbk_lib.a:(.bss.*)
    *libbsis_lib.a:(.bss.*)
    *libmois_lib.a:(.bss.*)
    *libolp_wrapper_lib.a:(.bss.*)
    *libWrappers_lib.a:(.bss.*)    
    . = ALIGN (8);
    _sram0_bss_end = ABSOLUTE(.);
    _memmap_seg_sram0_end = ALIGN(0x8);
  } >SYSMEM1_BBE32 :sram1_bss_phdr
  .sram1.rodata : ALIGN(4)
  {
    _sram1_rodata_start = ABSOLUTE(.);
    *(.sram1.rodata)
    . = ALIGN (4);
    _sram1_rodata_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
  .sram1.literal : ALIGN(4)
  {
    _sram1_literal_start = ABSOLUTE(.);
    *(.sram1.literal)
    . = ALIGN (4);
    _sram1_literal_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
  .sram1.data : ALIGN(4)
  {
    _sram1_data_start = ABSOLUTE(.);
    *(.sram1.data)
    *libinterference_detection_algo_feature_lib.a:(.data)
    *libinterference_detection_src_lib.a:(.data)
    *libdyn_align_wrapper.a:(.data)
    *libdyn_align_module_src_lib.a:(.data)
    *librc_wrapper_lib.a:(.data)
    *libradar_capability_feature_lib.a:(.data)
    *librc_common_module.a:(.data)
    *libblockage_module.a:(.data)
    *librc_diag_module.a:(.data)
    *libdm_module.a:(.data)
    *libfsc_module.a:(.data)
    *librc_fault_injection_lib.a:(.data)
    *libre_module.a:(.data)
    *libse_module.a:(.data)
    *libpbd_module.a:(.data)
    *libstatic_alignment.a:(.data)
    *libstatic_alignment_algo_src.a:(.data)
    *libinterference_detection_algo_feature_lib.a:(.data.*)
    *libinterference_detection_src_lib.a:(.data.*)
    *libdyn_align_wrapper.a:(.data.*)
    *libdyn_align_module_src_lib.a:(.data.*)
    *librc_wrapper_lib.a:(.data.*)
    *libradar_capability_feature_lib.a:(.data.*)
    *librc_common_module.a:(.data.*)
    *libblockage_module.a:(.data.*)
    *librc_diag_module.a:(.data.*)
    *libdm_module.a:(.data.*)
    *libfsc_module.a:(.data.*)
    *librc_fault_injection_lib.a:(.data.*)
    *libre_module.a:(.data.*)
    *libse_module.a:(.data.*)
    *libpbd_module.a:(.data.*)
    *libstatic_alignment.a:(.data.*)
    *libstatic_alignment_algo_src.a:(.data.*)
    . = ALIGN (4);
    _sram1_data_end = ABSOLUTE(.);
  } >SYSMEM1_BBE32 :sram1_phdr
  .sram1.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _sram1_bss_start = ABSOLUTE(.);
    *(.sram1.bss)
    . = ALIGN (8);
    _sram1_bss_end = ABSOLUTE(.);
    _memmap_seg_sram1_end = ALIGN(0x8);
  } >SYSMEM1_BBE32 :sram1_bss_phdr
  .sram_enet_sections :
  {
    *(.sram_streamdata_section)
  } > SYSMEM1_ENET_PKT
  .ipc_sections_d2m(NOLOAD) :
   {
    *(.ipc_dsp_to_r52)
   } >SYSMEM_IPC_D2M
  .ipc_sections_m2d(NOLOAD) :
   {
    *(.ipc_metadata_section)
   } >SYSMEM_IPC_SHARED
  _memmap_mem_sram1_max = ABSOLUTE(.);
   /* Allocate the stack at the beginning of DRAM0.
     If there is a stack overflow, this will cause an error
     condition to be generated. */
  .stack : ALIGN(4)
  {
    _dram0_stack_start = ABSOLUTE(.);
    *(.stack)
    . = ALIGN (4);
    . = . + __stack_size;
    _dram0_stack_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  PROVIDE(__stack = _dram0_stack_end);
  .dram0.rodata : ALIGN(4)
  {
    _dram0_rodata_start = ABSOLUTE(.);
    *(.dram0.rodata)
    . = ALIGN (4);
    _dram0_rodata_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .clib.rodata : ALIGN(4)
  {
    _clib_rodata_start = ABSOLUTE(.);
    *(.clib.rodata)
    . = ALIGN (4);
    _clib_rodata_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .rtos.rodata : ALIGN(4)
  {
    _rtos_rodata_start = ABSOLUTE(.);
    *(.rtos.rodata)
    . = ALIGN (4);
    _rtos_rodata_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .rodata : ALIGN(4)
  {
    _rodata_start = ABSOLUTE(.);
    *(.rodata)
    *(SORT(.rodata.sort.*))
    KEEP (*(SORT(.rodata.keepsort.*) .rodata.keep.*))
    *(.rodata.*)
    *(.gnu.linkonce.r.*)
    *(.rodata1)
    __XT_EXCEPTION_TABLE__ = ABSOLUTE(.);
    KEEP (*(.xt_except_table))
    KEEP (*(.gcc_except_table))
    *(.gnu.linkonce.e.*)
    *(.gnu.version_r)
    PROVIDE (__eh_frame_start = .);
    KEEP (*(.eh_frame))
    PROVIDE (__eh_frame_end = .);
    /*  C++ constructor and destructor tables, properly ordered:  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
    KEEP (*crtbegin.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
    /*  C++ exception handlers table:  */
    __XT_EXCEPTION_DESCS__ = ABSOLUTE(.);
    *(.xt_except_desc)
    *(.gnu.linkonce.h.*)
    __XT_EXCEPTION_DESCS_END__ = ABSOLUTE(.);
    *(.xt_except_desc_end)
    *(.dynamic)
    *(.gnu.version_d)
    . = ALIGN(4);		/* this table MUST be 4-byte aligned */
    _bss_table_start = ABSOLUTE(.);
    LONG(_sram1_bss_start)
    LONG(_sram1_bss_end)
    LONG(_bss_start)
    LONG(_bss_end)
    LONG(_dram1_bss_start)
    LONG(_dram1_bss_end)
    _bss_table_end = ABSOLUTE(.);
    . = ALIGN (4);
    _rodata_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .clib.data : ALIGN(4)
  {
    _clib_data_start = ABSOLUTE(.);
    *(.clib.data)
    . = ALIGN (4);
    _clib_data_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .clib.percpu.data : ALIGN(4)
  {
    _clib_percpu_data_start = ABSOLUTE(.);
    *(.clib.percpu.data)
    . = ALIGN (4);
    _clib_percpu_data_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .rtos.percpu.data : ALIGN(4)
  {
    _rtos_percpu_data_start = ABSOLUTE(.);
    *(.rtos.percpu.data)
    . = ALIGN (4);
    _rtos_percpu_data_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .rtos.data : ALIGN(4)
  {
    _rtos_data_start = ABSOLUTE(.);
    *(.rtos.data)
    . = ALIGN (4);
    _rtos_data_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .dram0.data : ALIGN(4)
  {
    _dram0_data_start = ABSOLUTE(.);
    *(.dram0.data)
    . = ALIGN (4);
    _dram0_data_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .data : ALIGN(4)
  {
    _data_start = ABSOLUTE(.);
    *(.data)
    *(SORT(.data.sort.*))
    KEEP (*(SORT(.data.keepsort.*) .data.keep.*))
    *(.data.*)
    *(.gnu.linkonce.d.*)
    KEEP(*(.gnu.linkonce.d.*personality*))
    *(.data1)
    *(.sdata)
    *(.sdata.*)
    *(.gnu.linkonce.s.*)
    *(.sdata2)
    *(.sdata2.*)
    *(.gnu.linkonce.s2.*)
    KEEP(*(.jcr))
    *(__llvm_prf_cnts)
    *(__llvm_prf_data)
    *(__llvm_prf_vnds)
    . = ALIGN (4);
    _data_end = ABSOLUTE(.);
  } >BBE32_DTCM0 :dram0_0_phdr
  .bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _bss_start = ABSOLUTE(.);
    *(.dynsbss)
    *(.sbss)
    *(.sbss.*)
    *(.gnu.linkonce.sb.*)
    *(.scommon)
    *(.sbss2)
    *(.sbss2.*)
    *(.gnu.linkonce.sb2.*)
    *(.dynbss)
    *(.bss)
    *(SORT(.bss.sort.*))
    KEEP (*(SORT(.bss.keepsort.*) .bss.keep.*))
    *(.bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    *(.clib.bss)
    *(.clib.percpu.bss)
    *(.rtos.percpu.bss)
    *(.rtos.bss)
    *(.dram0.bss)
    . = ALIGN (8);
    _bss_end = ABSOLUTE(.);
    _end = ALIGN(0x8);
    PROVIDE(end = ALIGN(0x8));
    _stack_sentry = ALIGN(0x8);
    _memmap_seg_dram0_0_end = ALIGN(0x8);
  } >BBE32_DTCM0 :dram0_0_bss_phdr
  _heap_sentry = 0x84010000;
  _memmap_mem_dram0_max = ABSOLUTE(.);
  .dram1.rodata : ALIGN(4)
  {
    _dram1_rodata_start = ABSOLUTE(.);
    *(.dram1.rodata)
    . = ALIGN (4);
    _dram1_rodata_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .ResetVector.literal : ALIGN(4)
  {
    _ResetVector_literal_start = ABSOLUTE(.);
    *(.ResetVector.literal)
    . = ALIGN (4);
    _ResetVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .MemoryExceptionVector.literal : ALIGN(4)
  {
    _MemoryExceptionVector_literal_start = ABSOLUTE(.);
    *(.MemoryExceptionVector.literal)
    . = ALIGN (4);
    _MemoryExceptionVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .Level2InterruptVector.literal : ALIGN(4)
  {
    _Level2InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level2InterruptVector.literal)
    . = ALIGN (4);
    _Level2InterruptVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .Level3InterruptVector.literal : ALIGN(4)
  {
    _Level3InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level3InterruptVector.literal)
    . = ALIGN (4);
    _Level3InterruptVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .Level4InterruptVector.literal : ALIGN(4)
  {
    _Level4InterruptVector_literal_start = ABSOLUTE(.);
    *(.Level4InterruptVector.literal)
    . = ALIGN (4);
    _Level4InterruptVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .DebugExceptionVector.literal : ALIGN(4)
  {
    _DebugExceptionVector_literal_start = ABSOLUTE(.);
    *(.DebugExceptionVector.literal)
    . = ALIGN (4);
    _DebugExceptionVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .NMIExceptionVector.literal : ALIGN(4)
  {
    _NMIExceptionVector_literal_start = ABSOLUTE(.);
    *(.NMIExceptionVector.literal)
    . = ALIGN (4);
    _NMIExceptionVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .KernelExceptionVector.literal : ALIGN(4)
  {
    _KernelExceptionVector_literal_start = ABSOLUTE(.);
    *(.KernelExceptionVector.literal)
    . = ALIGN (4);
    _KernelExceptionVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .UserExceptionVector.literal : ALIGN(4)
  {
    _UserExceptionVector_literal_start = ABSOLUTE(.);
    *(.UserExceptionVector.literal)
    . = ALIGN (4);
    _UserExceptionVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .DoubleExceptionVector.literal : ALIGN(4)
  {
    _DoubleExceptionVector_literal_start = ABSOLUTE(.);
    *(.DoubleExceptionVector.literal)
    . = ALIGN (4);
    _DoubleExceptionVector_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .iram0.literal : ALIGN(4)
  {
    _iram0_literal_start = ABSOLUTE(.);
    *(.iram0.literal)
    *(.iram.literal)
    *(.iram.text.literal)
    . = ALIGN (4);
    _iram0_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .rtos.literal : ALIGN(4)
  {
    _rtos_literal_start = ABSOLUTE(.);
    *(.rtos.literal)
    . = ALIGN (4);
    _rtos_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .clib.literal : ALIGN(4)
  {
    _clib_literal_start = ABSOLUTE(.);
    *(.clib.literal)
    . = ALIGN (4);
    _clib_literal_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .dram1.data : ALIGN(4)
  {
    _dram1_data_start = ABSOLUTE(.);
    *(.dram1.data)
    . = ALIGN (4);
    _dram1_data_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  __llvm_prf_names : ALIGN(4)
  {
    __llvm_prf_names_start = ABSOLUTE(.);
    *(__llvm_prf_names)
    . = ALIGN (4);
    __llvm_prf_names_end = ABSOLUTE(.);
  } >BBE32_DTCM1 :dram1_0_phdr
  .dram1.bss (NOLOAD) : ALIGN(8)
  {
    . = ALIGN (8);
    _dram1_bss_start = ABSOLUTE(.);
    *(.dram1.bss)
    . = ALIGN (8);
    _dram1_bss_end = ABSOLUTE(.);
    _memmap_seg_dram1_0_end = ALIGN(0x8);
  } >BBE32_DTCM1 :dram1_0_bss_phdr
  _memmap_mem_dram1_max = ABSOLUTE(.);
  .ResetVector.text : ALIGN(4)
  {
    _ResetVector_text_start = ABSOLUTE(.);
    KEEP (*(.ResetVector.text))
    . = ALIGN (4);
    _ResetVector_text_end = ABSOLUTE(.);
  } >iram0_0_seg :iram0_0_phdr
  .ResetHandler.text : ALIGN(4)
  {
    _ResetHandler_text_start = ABSOLUTE(.);
    *(.ResetHandler.literal .ResetHandler.text)
    . = ALIGN (4);
    _ResetHandler_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_0_end = ALIGN(0x8);
  } >iram0_0_seg :iram0_0_phdr
  .MemoryExceptionVector.text : ALIGN(4)
  {
    _MemoryExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.MemoryExceptionVector.text))
    . = ALIGN (4);
    _MemoryExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_2_end = ALIGN(0x8);
  } >iram0_2_seg :iram0_2_phdr
  .WindowVectors.text : ALIGN(4)
  {
    _WindowVectors_text_start = ABSOLUTE(.);
    KEEP (*(.WindowVectors.text))
    . = ALIGN (4);
    _WindowVectors_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_4_end = ALIGN(0x8);
  } >iram0_4_seg :iram0_4_phdr
  .Level2InterruptVector.text : ALIGN(4)
  {
    _Level2InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level2InterruptVector.text))
    . = ALIGN (4);
    _Level2InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_6_end = ALIGN(0x8);
  } >iram0_6_seg :iram0_6_phdr
  .Level3InterruptVector.text : ALIGN(4)
  {
    _Level3InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level3InterruptVector.text))
    . = ALIGN (4);
    _Level3InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_8_end = ALIGN(0x8);
  } >iram0_8_seg :iram0_8_phdr
  .Level4InterruptVector.text : ALIGN(4)
  {
    _Level4InterruptVector_text_start = ABSOLUTE(.);
    KEEP (*(.Level4InterruptVector.text))
    . = ALIGN (4);
    _Level4InterruptVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_10_end = ALIGN(0x8);
  } >iram0_10_seg :iram0_10_phdr
  .DebugExceptionVector.text : ALIGN(4)
  {
    _DebugExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.DebugExceptionVector.text))
    . = ALIGN (4);
    _DebugExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_12_end = ALIGN(0x8);
  } >iram0_12_seg :iram0_12_phdr
  .NMIExceptionVector.text : ALIGN(4)
  {
    _NMIExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.NMIExceptionVector.text))
    . = ALIGN (4);
    _NMIExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_14_end = ALIGN(0x8);
  } >iram0_14_seg :iram0_14_phdr
  .KernelExceptionVector.text : ALIGN(4)
  {
    _KernelExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.KernelExceptionVector.text))
    . = ALIGN (4);
    _KernelExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_16_end = ALIGN(0x8);
  } >iram0_16_seg :iram0_16_phdr
  .UserExceptionVector.text : ALIGN(4)
  {
    _UserExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.UserExceptionVector.text))
    . = ALIGN (4);
    _UserExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_18_end = ALIGN(0x8);
  } >iram0_18_seg :iram0_18_phdr
  .DoubleExceptionVector.text : ALIGN(4)
  {
    _DoubleExceptionVector_text_start = ABSOLUTE(.);
    KEEP (*(.DoubleExceptionVector.text))
    . = ALIGN (4);
    _DoubleExceptionVector_text_end = ABSOLUTE(.);
    _memmap_seg_iram0_20_end = ALIGN(0x8);
  } >iram0_20_seg :iram0_20_phdr
  .iram0.text : ALIGN(4)
  {
    _iram0_text_start = ABSOLUTE(.);
    *(.iram0.text)
    *(.iram.text)
    *libxtlx_stl.a:(.stl.iram0.literal .stl.iram0.text)
    *libxtlx_stl.a:(.stl.noncached.literal .stl.noncached.text)
    . = ALIGN (4);
    _iram0_text_end = ABSOLUTE(.);
  } >iram0_21_seg :iram0_21_phdr
  .literal : ALIGN(4)
  {
    _literal_start = ABSOLUTE(.);
    . = ALIGN (4);
    _literal_end = ABSOLUTE(.);
  } >iram0_21_seg :iram0_21_phdr
  .text : ALIGN(4)
  {
    _stext = .;
    _text_start = ABSOLUTE(.);
    *(.entry.text)
    *(.init.literal)
    KEEP (*(.init))
    *(.literal .text)
    *(SORT(.text.sort.*))
    KEEP (*(.literal.*personality*))
    KEEP (*(SORT(.text.keepsort.*) .text.keep.* .text.*personality*))
    *(.literal.* .text.*)
    *libfusion_360.a:(.text._GLOBAL__sub_I_f360_tracker.cpp .literal._GLOBAL__sub_I_f360_tracker.cpp)
    *(.gnu.linkonce.literal.*)
    *(.gnu.linkonce.t.*.literal)
    *(.gnu.linkonce.t.*)
    *(.stub)
    *(.gnu.warning)
    *(.fini.literal)
    KEEP (*(.fini))
    *(.gnu.version)
    . = ALIGN (4);
    _text_end = ABSOLUTE(.);
    _etext = .;
  } >iram0_21_seg :iram0_21_phdr
  .clib.text : ALIGN(4)
  {
    _clib_text_start = ABSOLUTE(.);
    *(.clib.text)
    . = ALIGN (4);
    _clib_text_end = ABSOLUTE(.);
  } >iram0_21_seg :iram0_21_phdr
  .rtos.text : ALIGN(4)
  {
    _rtos_text_start = ABSOLUTE(.);
    *(.rtos.text)
    . = ALIGN (4);
    _rtos_text_end = ABSOLUTE(.);
  } >iram0_21_seg :iram0_21_phdr
  _memmap_mem_iram0_max = ABSOLUTE(.);
  .periph.periph0 : ALIGN(4)
  {
    _periph_periph0_start = ABSOLUTE(.);
    KEEP (*(.periph.periph0))
    . = ALIGN (4);
    _periph_periph0_end = ABSOLUTE(.);
    _memmap_seg_periph_end = ALIGN(0x8);
  } >periph_seg :periph_phdr
  _memmap_mem_periph_max = ABSOLUTE(.);
  .debug  0 :  { *(.debug) }
  .line  0 :  { *(.line) }
  .debug_srcinfo  0 :  { *(.debug_srcinfo) }
  .debug_sfnames  0 :  { *(.debug_sfnames) }
  .debug_aranges  0 :  { *(.debug_aranges) }
  .debug_ranges   0 :  { *(.debug_ranges) }
  .debug_pubnames  0 :  { *(.debug_pubnames) }
  .debug_info  0 :  { *(.debug_info) }
  .debug_abbrev  0 :  { *(.debug_abbrev) }
  .debug_line  0 :  { *(.debug_line) }
  .debug_frame  0 :  { *(.debug_frame) }
  .debug_str  0 :  { *(.debug_str) }
  .debug_loc  0 :  { *(.debug_loc) }
  .debug_macinfo  0 :  { *(.debug_macinfo) }
  .debug_weaknames  0 :  { *(.debug_weaknames) }
  .debug_funcnames  0 :  { *(.debug_funcnames) }
  .debug_typenames  0 :  { *(.debug_typenames) }
  .debug_varnames  0 :  { *(.debug_varnames) }
  .xt.insn 0 :
  {
    KEEP (*(.xt.insn))
    KEEP (*(.gnu.linkonce.x.*))
  }
  .xt.prop 0 :
  {
    *(.xt.prop)
    *(.xt.prop.*)
    *(.gnu.linkonce.prop.*)
  }
  .xt.lit 0 :
  {
    *(.xt.lit)
    *(.xt.lit.*)
    *(.gnu.linkonce.p.*)
  }
  .xtensa.info 0 :
  {
    *(.xtensa.info)
  }
  .debug.xt.callgraph 0 :
  {
    KEEP (*(.debug.xt.callgraph .debug.xt.callgraph.* .gnu.linkonce.xt.callgraph.*))
  }
  .comment 0 :
  {
    KEEP(*(.comment))
  }
  .note.GNU-stack 0 :
  {
    *(.note.GNU-stack)
  }
}