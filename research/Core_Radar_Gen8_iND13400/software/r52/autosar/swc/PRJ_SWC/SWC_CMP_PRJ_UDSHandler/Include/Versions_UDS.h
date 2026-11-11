#ifndef VERSIONS_UDS_H
#define VERSIONS_UDS_H

/*will be updated after storing in ptp*/
#define SW_VERSIONS      1U
#define PART_NO_LENGTH   15U
#define SW_VERSIONS_FULL 5U

#define APP_SW_PART_NUMBER_LENGTH  12U
#define BOOT_SW_PART_NUMBER_LENGTH 12U
#define AUTOSAR_SW_VERSION_LENGTH  3U
#define ECU_ID_INDEX               9U

#define PRODUCT_CODE_SRR_FC 0x35 /* ASCII '5' */
#define PRODUCT_CODE_SRR_RL 0x36 /* ASCII '6' */

#define COMPONENT_CODE_A 'A'
#define COMPONENT_CODE_B 'B'
#define COMPONENT_CODE_C 'C'
#define COMPONENT_CODE_D 'D'

/* Data for DID $F188 (Appl SW part number)*/
uint8 Appl_SW_Part_Number[APP_SW_PART_NUMBER_LENGTH] = {0x41, 0x76, 0x2D, 0x06, 0x2D, 0x00, 0x2D, 0xFF, 0x2E, 0xFF, 0x2E, 0xFF};

/* Data for DID $F180 (Boot SW part number)*/
uint8 Bootloader_SW_Part_Number[BOOT_SW_PART_NUMBER_LENGTH] = {0x41, 0x76, 0x2D, 0x06, 0x2D, 0x00,
                                                               0x2D, 0xFF, 0x2E, 0xFF, 0x2E, 0xFF};

/* Data for Autosar version*/
uint8 AutOSAR_SW_Version[AUTOSAR_SW_VERSION_LENGTH] = {0x04, 0x03, 0x00};

/* DID 0xA001 - Base Software Part Number & Revision */
/* SRR-FC ASCII Value - AL5AA1.4.00.00 */
uint8 Base_Software_Part_Number_and_Revision_SRR[14] = {0x41, 0x4C, 0x35, 0x41, 0x41, 0x31, 0x2E,
                                                        0x34, 0x2E, 0x30, 0x30, 0x2E, 0x30, 0x30};

/* DID 0xF189 - Base Software Version Number */
/* ASCII Value - 4.00.00 */
uint8 Base_Software_Version_Number[7] = {0x34, 0x2E, 0x30, 0x30, 0x2E, 0x30, 0x30};

/* DID 0xF150 - Hardware Version Number */
/* ASCII Value - 01.00*/
uint8 Hardware_Version_Number[5] = {'0', '1', '.', '0', '0'};

/* DID 0xA002 - Dataset Part Number and Revision */
/* SRR-FC ASCII Value - AL5AD4.00.00 */
uint8 Dataset_Part_Number_and_Revision_SRR[12] = {0x41, 0x4C, 0x35, 0x41, 0x44, 0x34, 0x2E, 0x30, 0x30, 0x2E, 0x30, 0x30};

/* DID 0xF180 - ECU Bootloader Software Part Number and Revision */
/* SRR-FC ASCII Value - AL5AB4.00.00 */
uint8 Bootloader_Software_Part_Number_and_Revision[12] = {0x41, 0x4C, 0x35, 0x41, 0x42, 0x34, 0x2E, 0x30, 0x30, 0x2E, 0x30, 0x30};

/* DID 0xA003 - SMC Part Number and Revision */
/* SRR-RL ASCII Value - AL5AC4.00.00 */
uint8 SMC_Part_Number_and_Revision[12] = {'A', 'L', '5', 'A', 'C', '4', '.', '0', '0', '.', '0', '0'};

/* DID 0xF191 - ECU Hardware Part Number */
/* SRR-RL ASCII Value - ALSRR-H.01.00   */
uint8 ECU_Hardware_Part_Number[15] = {'A', 'L', 'S', 'R', 'R', '-', 'H', '.', '0', '1', '.', '0', '0'};

/* DID 0xF19D - VCAN DBC Version */
uint8 VCAN_DBC_Version[2] = {3, 7};

/* DID 0xF19E - PCAN DBC Version */
uint8 PCAN_DBC_Version[2] = {2, 0};

/* DID 0xF15A - Software Fingerprint Information */
uint8 software_fingerprint_info[4] = {0x00, 0x25, 0x08, 0x26};

#endif /* End VERSIONS_UDS_H */
