// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xaxiburst.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XAxiburst_CfgInitialize(XAxiburst *InstancePtr, XAxiburst_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Sqrt_BaseAddress = ConfigPtr->Sqrt_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XAxiburst_Start(XAxiburst *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL) & 0x80;
    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL, Data | 0x01);
}

u32 XAxiburst_IsDone(XAxiburst *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XAxiburst_IsIdle(XAxiburst *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XAxiburst_IsReady(XAxiburst *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XAxiburst_EnableAutoRestart(XAxiburst *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL, 0x80);
}

void XAxiburst_DisableAutoRestart(XAxiburst *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_CTRL, 0);
}

u32 XAxiburst_Get_return(XAxiburst *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_AP_RETURN);
    return Data;
}
void XAxiburst_Set_array_r(XAxiburst *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_ARRAY_R_DATA, Data);
}

u32 XAxiburst_Get_array_r(XAxiburst *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_ARRAY_R_DATA);
    return Data;
}

void XAxiburst_InterruptGlobalEnable(XAxiburst *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_GIE, 1);
}

void XAxiburst_InterruptGlobalDisable(XAxiburst *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_GIE, 0);
}

void XAxiburst_InterruptEnable(XAxiburst *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_IER);
    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_IER, Register | Mask);
}

void XAxiburst_InterruptDisable(XAxiburst *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_IER);
    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_IER, Register & (~Mask));
}

void XAxiburst_InterruptClear(XAxiburst *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XAxiburst_WriteReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_ISR, Mask);
}

u32 XAxiburst_InterruptGetEnabled(XAxiburst *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_IER);
}

u32 XAxiburst_InterruptGetStatus(XAxiburst *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XAxiburst_ReadReg(InstancePtr->Sqrt_BaseAddress, XAXIBURST_SQRT_ADDR_ISR);
}

