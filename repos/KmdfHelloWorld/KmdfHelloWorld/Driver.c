/*ntddk.h contains definitions for the kernel (DRIVER_INITIALIZE, PUNICODE_STRING)*/
#include <ntddk.h>
/*wdf.h contains definitions for WDF driver functions (WDF_DRIVER_CONFIG, WDF_DRIVER_CONFIG_INIT, WdfDriverCreate)*/
#include <wdf.h>

/*DriverEntry, kmdfHelloWorldEvtDeviceAdd are callbacks*/
/*What's written here are function declarations*/
DRIVER_INITIALIZE DriverEntry;
/*This will be called when a device is (physically) added*/
EVT_WDF_DRIVER_DEVICE_ADD kmdfHelloWorldEvtDeviceAdd;

NTSTATUS
/*DriverEntry is the main() for Windows Drivers*/
DriverEntry(
	_In_ PDRIVER_OBJECT  DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{
	NTSTATUS status = STATUS_SUCCESS;
	WDF_DRIVER_CONFIG config;
	/* DPFLTR Display Filter */
	/* IHV Independent Hardware Vendor */
	/* IHV provides support for hardwares regardless(independent) of the manufacturer, as long as the standards are supported. */
	KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry\n"));

	WDF_DRIVER_CONFIG_INIT(&config, kmdfHelloWorldEvtDeviceAdd);

	/*The driver object is only created now, which is the parent for all other WDF(framework) objects.*/
	/*All the actions above are just the initialization*/
	status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);

	return status;
}

NTSTATUS kmdfHelloWorldEvtDeviceAdd(
	_In_ WDFDRIVER Driver,
	/*P(pointer to) WDF DEVICE INIT*/
	_Inout_ PWDFDEVICE_INIT DeviceInit
)
{
	/*Because the code doesn't ever use this parameter, call UNREFERENCED_PARAMETER() to suppress warnings*/
	UNREFERENCED_PARAMETER(Driver);

	NTSTATUS status;
	WDFDEVICE hDevice;
	KdPrintEx(( DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: KmdfHelloWorldEvtDeviceAdd\n" ));
	status = WdfDeviceCreate(&DeviceInit, WDF_NO_OBJECT_ATTRIBUTES, &hDevice);
	return status;
}
