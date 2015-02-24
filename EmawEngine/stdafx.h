// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#include <d3d11.h>
#include <d3dcompiler.h>
#include "HelperStructs.h"
#include <string>
#include <atlstr.h>
#include "WindowSize.h"
#include "graphics_device_interface.h"
#include "HelperStructs.h"

#pragma comment(lib, "d3d11.lib")
