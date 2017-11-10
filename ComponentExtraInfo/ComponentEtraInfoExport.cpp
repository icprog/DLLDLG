#include "stdafx.h"
#include "DLLUI_ExtraCompInfo.h"
#include "ShareData\ComponentEtraInfoExport.h"


IDLLPluginInterface*   CreatePluginObj()
{
	return new  ExtraCompInfoCtrl();
}