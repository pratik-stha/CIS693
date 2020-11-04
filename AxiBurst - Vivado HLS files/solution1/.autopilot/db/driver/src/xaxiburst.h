// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XAXIBURST_H
#define XAXIBURST_H

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
#include "xaxiburst_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Sqrt_BaseAddress;
} XAxiburst_Config;
#endif

typedef struct {
    u32 Sqrt_BaseAddress;
    u32 IsReady;
} XAxiburst;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XAxiburst_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XAxiburst_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XAxiburst_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XAxiburst_ReadReg(BaseAddress, RegOffset) \
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
int XAxiburst_Initialize(XAxiburst *InstancePtr, u16 DeviceId);
XAxiburst_Config* XAxiburst_LookupConfig(u16 DeviceId);
int XAxiburst_CfgInitialize(XAxiburst *InstancePtr, XAxiburst_Config *ConfigPtr);
#else
int XAxiburst_Initialize(XAxiburst *InstancePtr, const char* InstanceName);
int XAxiburst_Release(XAxiburst *InstancePtr);
#endif

void XAxiburst_Start(XAxiburst *InstancePtr);
u32 XAxiburst_IsDone(XAxiburst *InstancePtr);
u32 XAxiburst_IsIdle(XAxiburst *InstancePtr);
u32 XAxiburst_IsReady(XAxiburst *InstancePtr);
void XAxiburst_EnableAutoRestart(XAxiburst *InstancePtr);
void XAxiburst_DisableAutoRestart(XAxiburst *InstancePtr);
u32 XAxiburst_Get_return(XAxiburst *InstancePtr);

void XAxiburst_Set_array_r(XAxiburst *InstancePtr, u32 Data);
u32 XAxiburst_Get_array_r(XAxiburst *InstancePtr);

void XAxiburst_InterruptGlobalEnable(XAxiburst *InstancePtr);
void XAxiburst_InterruptGlobalDisable(XAxiburst *InstancePtr);
void XAxiburst_InterruptEnable(XAxiburst *InstancePtr, u32 Mask);
void XAxiburst_InterruptDisable(XAxiburst *InstancePtr, u32 Mask);
void XAxiburst_InterruptClear(XAxiburst *InstancePtr, u32 Mask);
u32 XAxiburst_InterruptGetEnabled(XAxiburst *InstancePtr);
u32 XAxiburst_InterruptGetStatus(XAxiburst *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
