// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xpartitioncheckii.h"

extern XPartitioncheckii_Config XPartitioncheckii_ConfigTable[];

XPartitioncheckii_Config *XPartitioncheckii_LookupConfig(u16 DeviceId) {
	XPartitioncheckii_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XPARTITIONCHECKII_NUM_INSTANCES; Index++) {
		if (XPartitioncheckii_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XPartitioncheckii_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XPartitioncheckii_Initialize(XPartitioncheckii *InstancePtr, u16 DeviceId) {
	XPartitioncheckii_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XPartitioncheckii_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XPartitioncheckii_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

