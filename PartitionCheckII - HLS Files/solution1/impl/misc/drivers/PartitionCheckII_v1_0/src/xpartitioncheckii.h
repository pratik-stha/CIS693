// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XPARTITIONCHECKII_H
#define XPARTITIONCHECKII_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xpartitioncheckii_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Sqrt_BaseAddress;
} XPartitioncheckii_Config;
#endif

typedef struct {
    u32 Sqrt_BaseAddress;
    u32 IsReady;
} XPartitioncheckii;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XPartitioncheckii_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XPartitioncheckii_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XPartitioncheckii_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XPartitioncheckii_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XPartitioncheckii_Initialize(XPartitioncheckii *InstancePtr, u16 DeviceId);
XPartitioncheckii_Config* XPartitioncheckii_LookupConfig(u16 DeviceId);
int XPartitioncheckii_CfgInitialize(XPartitioncheckii *InstancePtr, XPartitioncheckii_Config *ConfigPtr);
#else
int XPartitioncheckii_Initialize(XPartitioncheckii *InstancePtr, const char* InstanceName);
int XPartitioncheckii_Release(XPartitioncheckii *InstancePtr);
#endif

void XPartitioncheckii_Start(XPartitioncheckii *InstancePtr);
u32 XPartitioncheckii_IsDone(XPartitioncheckii *InstancePtr);
u32 XPartitioncheckii_IsIdle(XPartitioncheckii *InstancePtr);
u32 XPartitioncheckii_IsReady(XPartitioncheckii *InstancePtr);
void XPartitioncheckii_EnableAutoRestart(XPartitioncheckii *InstancePtr);
void XPartitioncheckii_DisableAutoRestart(XPartitioncheckii *InstancePtr);
u32 XPartitioncheckii_Get_return(XPartitioncheckii *InstancePtr);

void XPartitioncheckii_Set_array_r(XPartitioncheckii *InstancePtr, u32 Data);
u32 XPartitioncheckii_Get_array_r(XPartitioncheckii *InstancePtr);

void XPartitioncheckii_InterruptGlobalEnable(XPartitioncheckii *InstancePtr);
void XPartitioncheckii_InterruptGlobalDisable(XPartitioncheckii *InstancePtr);
void XPartitioncheckii_InterruptEnable(XPartitioncheckii *InstancePtr, u32 Mask);
void XPartitioncheckii_InterruptDisable(XPartitioncheckii *InstancePtr, u32 Mask);
void XPartitioncheckii_InterruptClear(XPartitioncheckii *InstancePtr, u32 Mask);
u32 XPartitioncheckii_InterruptGetEnabled(XPartitioncheckii *InstancePtr);
u32 XPartitioncheckii_InterruptGetStatus(XPartitioncheckii *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
