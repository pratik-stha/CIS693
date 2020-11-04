// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xaxiburst.h"

extern XAxiburst_Config XAxiburst_ConfigTable[];

XAxiburst_Config *XAxiburst_LookupConfig(u16 DeviceId) {
	XAxiburst_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XAXIBURST_NUM_INSTANCES; Index++) {
		if (XAxiburst_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XAxiburst_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XAxiburst_Initialize(XAxiburst *InstancePtr, u16 DeviceId) {
	XAxiburst_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XAxiburst_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XAxiburst_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

