/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that app can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_KmdfHelloWorld,
    0xdf5c9f1b,0x2aa6,0x456e,0xbe,0x69,0x7f,0xa3,0xe4,0xa3,0x4d,0x1f);
// {df5c9f1b-2aa6-456e-be69-7fa3e4a34d1f}
