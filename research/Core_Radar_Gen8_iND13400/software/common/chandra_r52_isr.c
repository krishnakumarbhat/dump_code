/* This file contains the vector table used for handling interrupts
   the order of the handlers must match the order of the interrupts
   defined in the hardware, to give the handler for a particular
   interrupt a name:
   1. replace the entry at the relevant position in the array with
      the name
   2. make sure there is a 'protoype' declaration (complete with
      a 'weak alias' to the default handler for that function name)
   3. make sure that the relevant entry in the IRQn enum is set
      to a corresponding string
*/

// prototype declarations of all handlers mentioned in the vector table...
// 0..15  Software Generated Interrupts (SGIs)
void SGI0_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI1_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI2_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI3_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI4_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI5_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI6_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI7_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI8_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI9_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI10_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI11_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI12_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI13_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI14_Handler(void) __attribute__((weak, alias("default_handler")));
void SGI15_Handler(void) __attribute__((weak, alias("default_handler")));
// 16..31  Private Peripheral Interrupts (PPIs)
void DCC_Handler(void) __attribute__((weak, alias("default_handler")));
void PerfMonOverlow_Handler(void) __attribute__((weak, alias("default_handler")));
void CTI_Handler(void) __attribute__((weak, alias("default_handler")));
void VCIM_Handler(void) __attribute__((weak, alias("default_handler")));
void HypervisorTimer_Handler(void) __attribute__((weak, alias("default_handler")));
void VirtualTimer_Handler(void) __attribute__((weak, alias("default_handler")));
void NSPhysicalTimer_Handler(void) __attribute__((weak, alias("default_handler")));
// 32..104  Shared Peripheral Interrupts (SPIs)
void CANFD0_Handler(void) __attribute__((weak, alias("default_handler")));
void CANFD1_Handler(void) __attribute__((weak, alias("default_handler")));
void WATCHDOG_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void WATCHDOG1_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void WATCHDOG2_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void WATCHDOG3_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void UART_Handler(void) __attribute__((weak, alias("default_handler")));
void SPIM_SSI_Handler(void) __attribute__((weak, alias("default_handler")));
void QSPI_MMIC_Handler(void) __attribute__((weak, alias("default_handler")));
void MCDMA_Handler(void) __attribute__((weak, alias("default_handler")));
void ARTIE_MEM_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void GPADC_Handler(void) __attribute__((weak, alias("default_handler")));
void SERDES_TXPLL_LOCK_Handler(void) __attribute__((weak, alias("default_handler")));
void SERDES_RXPLL_LOCKA_Handler(void) __attribute__((weak, alias("default_handler")));
void SERDES_RXPLL_FLOCKA_Handler(void) __attribute__((weak, alias("default_handler")));
void DSP2SP_Handler(void) __attribute__((weak, alias("default_handler")));
void GPIO_Handler(void) __attribute__((weak, alias("default_handler")));
void I2CM_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER1_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER2_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER3_Handler(void) __attribute__((weak, alias("default_handler")));
void QSPI_FLASH_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET0_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET1_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET2_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET3_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET4_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET5_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET6_Handler(void) __attribute__((weak, alias("default_handler")));
void ETHERNET7_Handler(void) __attribute__((weak, alias("default_handler")));
void MACSEC_Handler(void) __attribute__((weak, alias("default_handler")));
void MACSEC_SECURE_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM0_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM1_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM2_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM3_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM4_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM5_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM6_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM7_Handler(void) __attribute__((weak, alias("default_handler")));
void MM_INTF0_Handler(void) __attribute__((weak, alias("default_handler")));
void MM_INTF1_Handler(void) __attribute__((weak, alias("default_handler")));
void MM_INTF2_Handler(void) __attribute__((weak, alias("default_handler")));
void BROWNOUT_0V8_Handler(void) __attribute__((weak, alias("default_handler")));
void BROWNOUT_1V8_Handler(void) __attribute__((weak, alias("default_handler")));
void RA_BBE_Handler(void) __attribute__((weak, alias("default_handler")));
void RA_Handler(void) __attribute__((weak, alias("default_handler")));
void RA_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SYSMEM0_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SYSMEM1_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void MIPI_FRM_START_Handler(void) __attribute__((weak, alias("default_handler")));
void MIPI_FRM_END_Handler(void) __attribute__((weak, alias("default_handler")));
void MIPI_CHP_START_Handler(void) __attribute__((weak, alias("default_handler")));
void MIPI_CHP_END_Handler(void) __attribute__((weak, alias("default_handler")));
void MIPI_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void AA0_Handler(void) __attribute__((weak, alias("default_handler")));
void AA1_Handler(void) __attribute__((weak, alias("default_handler")));
void AA0_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void AA1_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_WWDT_RST_REQ_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_WWDT_HBEAT_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_WWDT_ERST_REQ_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT0_ARLARM0_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT0_ARLARM1_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT0_SIG_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT0_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT1_ARLARM0_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT1_ARLARM1_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT1_SIG_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PVT1_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void IOCTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SYSCTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void DSP_CTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void AA_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void MIPI_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void RA_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void ADC_CTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SYSMEM_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_CTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void ARTIE_CTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PMIC_FAULTB_Handler(void) __attribute__((weak, alias("default_handler")));
void HSM_ALARM_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void STC_ALARM_Handler(void) __attribute__((weak, alias("default_handler")));
void CNOC_LATENT_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void CNOC_MISSION_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void CNOC_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void ANOC_LATENT_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void ANOC_MISSION_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void ANOC_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SNOC_LATENT_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SNOC_MISSION_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void SNOC_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_SP_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_SP_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_SP_GPIO0_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_SP_GPIO1_Handler(void) __attribute__((weak, alias("default_handler")));
void BBE_SP_GPIO2_Handler(void) __attribute__((weak, alias("default_handler")));
void DBG_MAILBOX_Handler(void) __attribute__((weak, alias("default_handler")));
void CTI0_Handler(void) __attribute__((weak, alias("default_handler")));
void CTI1_Handler(void) __attribute__((weak, alias("default_handler")));
void TMC_BUFFER_Handler(void) __attribute__((weak, alias("default_handler")));
void CSI2_DBG_FRM_START_Handler(void) __attribute__((weak, alias("default_handler")));
void CSI2_DBG_FRM_END_Handler(void) __attribute__((weak, alias("default_handler")));
void CSI2_DBG_CHP_START_Handler(void) __attribute__((weak, alias("default_handler")));
void CSI2_DBG_CHP_END_Handler(void) __attribute__((weak, alias("default_handler")));
void MCE_ERR_0_Handler(void) __attribute__((weak, alias("default_handler")));
void MCE_ERR_1_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_CLKMON_DSP_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_CLKMON_RA_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_CLKMON_MIPI_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_CLKMON_SERIAL_Handler(void) __attribute__((weak, alias("default_handler")));
void LBSC_FUNC_DONE_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_FREQMON_SYS_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_FREQMON_SERDES_RX_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_FREQMON_RCO_Handler(void) __attribute__((weak, alias("default_handler")));
void CRG_RMON_SWS_Handler(void) __attribute__((weak, alias("default_handler")));
void MCDMA_IF_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void MCDMA_SEC_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void MCDMA_DED_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void ARTIE_MEM_ROC_Handler(void) __attribute__((weak, alias("default_handler")));
void SYSMEM_RO_ERR_Handler(void) __attribute__((weak, alias("default_handler")));
void CRC_IF_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void PWM0123_CTRL_ERR_FUSA_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER4_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER5_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER6_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER7_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER8_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER9_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER10_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER11_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER12_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER13_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER14_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER15_Handler(void) __attribute__((weak, alias("default_handler")));
void TIMER16_Handler(void) __attribute__((weak, alias("default_handler")));

// to allow the implementation of the 'default handler' to effectively be replaced we
// implement our truly default behaviour here...
void default_handler_worker_of_last_resort(void)
{
   while (1)
   {
   }; // default_handler_worker_of_last_resort
}
// make this available via another weak symbol alias...
void default_handler_worker(void) __attribute__((weak, alias("default_handler_worker_of_last_resort")));
// which we call in actual default handler implementation (which is essentially just a veneer)...
void default_handler(void)
{
   default_handler_worker();
}
// declaration of a true 'default_handler_worker' function elsewhere can be used to override
// the 'while(1);' behaviour defined above

typedef void (*handler_fn)(void);

// the number of Chandra ISRs is 32 + 137 = 169 (SGI/PPI + SPI)
#define ISR_VECTOR_TABLE_LEN 169

handler_fn const IsrVectorTable[ISR_VECTOR_TABLE_LEN] = {
   // 0..15  Software Generated Interrupts (SGIs)
   SGI0_Handler,                   // id  0  SGI[ 0] // [captain] named purely for testing - feel free to replace
   SGI1_Handler,                   // id  1  SGI[ 1]
   SGI2_Handler,                   // id  2  SGI[ 2]
   SGI3_Handler,                   // id  3  SGI[ 3]
   SGI4_Handler,                   // id  4  SGI[ 4]
   SGI5_Handler,                   // id  5  SGI[ 5]
   SGI6_Handler,                   // id  6  SGI[ 6]
   SGI7_Handler,                   // id  7  SGI[ 7]
   SGI8_Handler,                   // id  8  SGI[ 8]
   SGI9_Handler,                   // id  9  SGI[ 9]
   SGI10_Handler,                  // id 10  SGI[10]
   SGI11_Handler,                  // id 11  SGI[11]
   SGI12_Handler,                  // id 12  SGI[12]
   SGI13_Handler,                  // id 13  SGI[13]
   SGI14_Handler,                  // id 14  SGI[14]
   SGI15_Handler,                  // id 15  SGI[15]
                                   // 16..31  Private Peripheral Interrupts (PPIs)
   0,                              // id 16  PPI[ 0]
   0,                              // id 17  PPI[ 1]
   0,                              // id 18  PPI[ 2]
   0,                              // id 19  PPI[ 3]
   0,                              // id 20  PPI[ 4]
   0,                              // id 21  PPI[ 5]
   DCC_Handler,                    // id 22  PPI[ 6]  (fixed) Debug Communications Channel interrupt
   PerfMonOverlow_Handler,         // id 23  PPI[ 7]  (fixed) Performance Monitor Counter Overflow interrupt
   CTI_Handler,                    // id 24  PPI[ 8]  (fixed) Cross Trigger Interface interrupt
   VCIM_Handler,                   // id 25  PPI[ 9]  (fixed) Virtual CPU Interface Maintenance interrupt
   HypervisorTimer_Handler,        // id 26  PPI[10]  (fixed) Hypervisor timer interrupt
   VirtualTimer_Handler,           // id 27  PPI[11]  (fixed) Virtual timer interrupt
   0,                              // id 28  PPI[12]
   0,                              // id 29  PPI[13]
   NSPhysicalTimer_Handler,        // id 30  PPI[14]  (fixed) Non-secure physical timer interrupt
   0,                              // id 31  PPI[15]
                                   // 32..168  Shared Peripheral Interrupts (SPIs)
   CANFD0_Handler,                 // id 32  SPI[ 0]
   CANFD1_Handler,                 // id 33  SPI[ 1]
   WATCHDOG_FUSA_Handler,          // id 34  SPI[ 2]
   WATCHDOG1_FUSA_Handler,         // id 35  SPI[ 3]
   WATCHDOG2_FUSA_Handler,         // id 36  SPI[ 4]
   WATCHDOG3_FUSA_Handler,         // id 37  SPI[ 5]
   UART_Handler,                   // id 38  SPI[ 6]
   SPIM_SSI_Handler,               // id 39  SPI[ 7]
   QSPI_MMIC_Handler,              // id 40  SPI[ 8]
   QSPI_FLASH_Handler,             // id 41  SPI[ 9]
   GPIO_Handler,                   // id 42  SPI[10]
   I2CM_Handler,                   // id 43  SPI[11]
   TIMER1_Handler,                 // id 44  SPI[12]
   TIMER2_Handler,                 // id 45  SPI[13]
   TIMER3_Handler,                 // id 46  SPI[14]
   ETHERNET0_Handler,              // id 47  SPI[15]
   ETHERNET1_Handler,              // id 48  SPI[16]
   ETHERNET2_Handler,              // id 49  SPI[17]
   ETHERNET3_Handler,              // id 50  SPI[18]
   ETHERNET4_Handler,              // id 51  SPI[19]
   ETHERNET5_Handler,              // id 52  SPI[20]
   ETHERNET6_Handler,              // id 53  SPI[21]
   ETHERNET7_Handler,              // id 54  SPI[22]
   MACSEC_Handler,                 // id 55  SPI[23]
   MACSEC_SECURE_Handler,          // id 56  SPI[24]
   HSM0_Handler,                   // id 57  SPI[25]
   HSM1_Handler,                   // id 58  SPI[26]
   HSM2_Handler,                   // id 59  SPI[27]
   HSM3_Handler,                   // id 60  SPI[28]
   HSM4_Handler,                   // id 61  SPI[29]
   HSM5_Handler,                   // id 62  SPI[30]
   HSM6_Handler,                   // id 63  SPI[31]
   HSM7_Handler,                   // id 64  SPI[32]
   MCDMA_Handler,                  // id 65  SPI[33]
   ARTIE_MEM_FUSA_Handler,         // id 66  SPI[34]
   GPADC_Handler,                  // id 67  SPI[35]
   SERDES_TXPLL_LOCK_Handler,      // id 68  SPI[36]
   SERDES_RXPLL_LOCKA_Handler,     // id 69  SPI[37]
   SERDES_RXPLL_FLOCKA_Handler,    // id 70  SPI[38]
   BBE_SP_Handler,                 // id 71  SPI[39]
   BBE_SP_FUSA_Handler,            // id 72  SPI[40]
   BBE_SP_GPIO0_Handler,           // id 73  SPI[41]
   BBE_SP_GPIO1_Handler,           // id 74  SPI[42]
   BBE_SP_GPIO2_Handler,           // id 75  SPI[43]
   RA_BBE_Handler,                 // id 76  SPI[44]
   RA_Handler,                     // id 77  SPI[45]
   RA_FUSA_Handler,                // id 78  SPI[46]
   SYSMEM0_FUSA_Handler,           // id 79  SPI[47]
   SYSMEM1_FUSA_Handler,           // id 80  SPI[48]
   MIPI_FRM_START_Handler,         // id 81  SPI[49]
   MIPI_FRM_END_Handler,           // id 82  SPI[50]
   MIPI_CHP_START_Handler,         // id 83  SPI[51]
   MIPI_CHP_END_Handler,           // id 84  SPI[52]
   MIPI_FUSA_Handler,              // id 85  SPI[53]
   AA0_Handler,                    // id 86  SPI[54]
   AA1_Handler,                    // id 87  SPI[55]
   AA0_FUSA_Handler,               // id 88  SPI[56]
   AA1_FUSA_Handler,               // id 89  SPI[57]
   MM_INTF0_Handler,               // id 90  SPI[58]
   MM_INTF1_Handler,               // id 91  SPI[59]
   MM_INTF2_Handler,               // id 92  SPI[60]
   BROWNOUT_0V8_Handler,           // id 93  SPI[61]
   BROWNOUT_1V8_Handler,           // id 94  SPI[62]
   PVT0_ARLARM0_FUSA_Handler,      // id 95  SPI[63]
   PVT0_ARLARM1_FUSA_Handler,      // id 96  SPI[64]
   PVT0_SIG_FUSA_Handler,          // id 97  SPI[65]
   PVT0_ERR_FUSA_Handler,          // id 98  SPI[66]
   PVT1_ARLARM0_FUSA_Handler,      // id 99  SPI[67]
   PVT1_ARLARM1_FUSA_Handler,      // id 100 SPI[68]
   PVT1_SIG_FUSA_Handler,          // id 101 SPI[69]
   PVT1_ERR_FUSA_Handler,          // id 102 SPI[70]
   BBE_WWDT_RST_REQ_FUSA_Handler,  // id 103 SPI[71]
   BBE_WWDT_HBEAT_FUSA_Handler,    // id 104 SPI[72]
   BBE_WWDT_ERST_REQ_FUSA_Handler, // id 105 SPI[73]
   IOCTRL_ERR_FUSA_Handler,        // id 106 SPI[74]
   SYSCTRL_ERR_FUSA_Handler,       // id 107 SPI[75]
   DSP_CTRL_ERR_FUSA_Handler,      // id 108 SPI[76]  DSP Ctrl SFR bank
   AA_ERR_FUSA_Handler,            // id 109 SPI[77]  AA Ctrl SFR bank
   MIPI_ERR_FUSA_Handler,          // id 110 SPI[78]  MIPI Ctrl SFR bank
   RA_ERR_FUSA_Handler,            // id 111 SPI[79]  RA Ctrl SFR bank
   ADC_CTRL_ERR_FUSA_Handler,      // id 112 SPI[80]  ADC Ctrl SFR bank
   SYSMEM_ERR_FUSA_Handler,        // id 113 SPI[81]  SysMem Ctrl SFR bank
   CRG_CTRL_ERR_FUSA_Handler,      // id 114 SPI[82]  CRG Ctrl SFR bank
   ARTIE_CTRL_ERR_FUSA_Handler,    // id 115 SPI[83]  Artie Ctrl SFR bank
   PMIC_FAULTB_Handler,            // id 116 SPI[84]
   HSM_ALARM_FUSA_Handler,         // id 117 SPI[85]
   STC_ALARM_Handler,              // id 118 SPI[86]
   0,                              // id 119 SPI[87]  Reserved
   0,                              // id 120 SPI[88]  Reserved
   CNOC_LATENT_FUSA_Handler,       // id 121 SPI[89]  Chandra NOC 
   CNOC_MISSION_FUSA_Handler,      // id 122 SPI[90]  Chandra NOC 
   CNOC_FUSA_Handler,              // id 123 SPI[91]  Chandra NOC 
   ANOC_LATENT_FUSA_Handler,       // id 124 SPI[92]  Artie Core NoC
   ANOC_MISSION_FUSA_Handler,      // id 125 SPI[93]  Artie Core NoC
   ANOC_FUSA_Handler,              // id 126 SPI[94]  Artie Core NoC
   SNOC_LATENT_FUSA_Handler,       // id 127 SPI[95]  Artie Wrapper NoC
   SNOC_MISSION_FUSA_Handler,      // id 128 SPI[96]  Artie Wrapper NoC
   SNOC_FUSA_Handler,              // id 129 SPI[97]  Artie Wrapper NoC
   DBG_MAILBOX_Handler,            // id 130 SPI[98]
   CTI0_Handler,                   // id 131 SPI[99]
   CTI1_Handler,                   // id 132 SPI[100]
   TMC_BUFFER_Handler,             // id 133 SPI[101]
   CSI2_DBG_FRM_START_Handler,     // id 134 SPI[102]
   CSI2_DBG_FRM_END_Handler,       // id 135 SPI[103]
   CSI2_DBG_CHP_START_Handler,     // id 136 SPI[104]
   CSI2_DBG_CHP_END_Handler,       // id 137 SPI[105]
   MCE_ERR_0_Handler,              // id 138 SPI[106]
   MCE_ERR_1_Handler,              // id 139 SPI[107]
   CRG_CLKMON_DSP_Handler,         // id 140 SPI[108]
   CRG_CLKMON_RA_Handler,          // id 141 SPI[109]
   CRG_CLKMON_MIPI_Handler,        // id 142 SPI[110]
   CRG_CLKMON_SERIAL_Handler,      // id 143 SPI[111]
   LBSC_FUNC_DONE_Handler,         // id 144 SPI[112]
   CRG_FREQMON_SYS_Handler,        // id 145 SPI[113]
   CRG_FREQMON_SERDES_RX_Handler,  // id 146 SPI[114]
   CRG_FREQMON_RCO_Handler,        // id 147 SPI[115]
   CRG_RMON_SWS_Handler,           // id 148 SPI[116]
   MCDMA_IF_ERR_FUSA_Handler,      // id 149 SPI[117]
   MCDMA_SEC_ERR_FUSA_Handler,     // id 150 SPI[118]
   MCDMA_DED_ERR_FUSA_Handler,     // id 151 SPI[119]
   ARTIE_MEM_ROC_Handler,          // id 152 SPI[120]
   SYSMEM_RO_ERR_Handler,          // id 153 SPI[121]
   CRC_IF_ERR_FUSA_Handler,        // id 154 SPI[122]
   PWM0123_CTRL_ERR_FUSA_Handler,  // id 155 SPI[123]
   TIMER4_Handler,                 // id 156 SPI[124]
   TIMER5_Handler,                 // id 157 SPI[125]
   TIMER6_Handler,                 // id 158 SPI[126]
   TIMER7_Handler,                 // id 159 SPI[127]
   TIMER8_Handler,                 // id 160 SPI[128]
   TIMER9_Handler,                 // id 161 SPI[129]
   TIMER10_Handler,                // id 162 SPI[130]
   TIMER11_Handler,                // id 163 SPI[131]
   TIMER12_Handler,                // id 164 SPI[132]
   TIMER13_Handler,                // id 165 SPI[133]
   TIMER14_Handler,                // id 166 SPI[134]
   TIMER15_Handler,                // id 167 SPI[135]
   TIMER16_Handler,                // id 168 SPI[136]
};

void el1_irq_zero_handler(unsigned int int_id) __attribute__((weak, alias("default_el1_irq_zero_handler")));
void el1_irq_bad_id_reporter(unsigned int int_id) __attribute__((weak, alias("default_el1_irq_bad_id_reporter")));
void el1_irq_spurious_id_reporter(unsigned int int_id) __attribute__((weak, alias("default_el1_irq_spurious_id_reporter")));

//------------------------------------------------------------------------------------------------------
// TODO: o remove/move these 'handlers of last resort'

void default_el1_irq_zero_handler(unsigned int int_id)
{
   (void)int_id;
   // called by the low-level handle dispatch code if no handler is defined
   // printf("WARNING: No handler defined for interrupt #%d\n", int_id);
}

void default_el1_irq_bad_id_reporter(unsigned int int_id)
{
   (void)int_id;
   // printf("WARNING: Interrupt with an overly high ID went unhandled (id:%d)\n", int_id);
}

void default_el1_irq_spurious_id_reporter(unsigned int int_id)
{
   (void)int_id;
   // printf("WARNING: IRQ dispatcher called to handle the 'Spurious' ID (id:%d)\n", int_id);
}
