// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xpartitioncheckii.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XPartitioncheckii_CfgInitialize(XPartitioncheckii *InstancePtr, XPartitioncheckii_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Sqrt_BaseAddress = ConfigPtr->Sqrt_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XPartitioncheckii_Start(XPartitioncheckii *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL) & 0x80;
    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL, Data | 0x01);
}

u32 XPartitioncheckii_IsDone(XPartitioncheckii *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XPartitioncheckii_IsIdle(XPartitioncheckii *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XPartitioncheckii_IsReady(XPartitioncheckii *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XPartitioncheckii_EnableAutoRestart(XPartitioncheckii *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL, 0x80);
}

void XPartitioncheckii_DisableAutoRestart(XPartitioncheckii *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_CTRL, 0);
}

u32 XPartitioncheckii_Get_return(XPartitioncheckii *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_AP_RETURN);
    return Data;
}
void XPartitioncheckii_Set_array_r(XPartitioncheckii *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_ARRAY_R_DATA, Data);
}

u32 XPartitioncheckii_Get_array_r(XPartitioncheckii *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_ARRAY_R_DATA);
    return Data;
}

void XPartitioncheckii_InterruptGlobalEnable(XPartitioncheckii *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_GIE, 1);
}

void XPartitioncheckii_InterruptGlobalDisable(XPartitioncheckii *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_GIE, 0);
}

void XPartitioncheckii_InterruptEnable(XPartitioncheckii *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_IER);
    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_IER, Register | Mask);
}

void XPartitioncheckii_InterruptDisable(XPartitioncheckii *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_IER);
    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_IER, Register & (~Mask));
}

void XPartitioncheckii_InterruptClear(XPartitioncheckii *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XPartitioncheckii_WriteReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_ISR, Mask);
}

u32 XPartitioncheckii_InterruptGetEnabled(XPartitioncheckii *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_IER);
}

u32 XPartitioncheckii_InterruptGetStatus(XPartitioncheckii *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XPartitioncheckii_ReadReg(InstancePtr->Sqrt_BaseAddress, XPARTITIONCHECKII_SQRT_ADDR_ISR);
}

