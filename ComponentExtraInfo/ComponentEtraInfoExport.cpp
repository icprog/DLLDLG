#include "stdafx.h"
#include "ComponentEtraInfoExport.h"
#include "DLLUI_ExtraCompInfo.h"

IDLLPluginInterface*   CreatePluginObj()
{
	return new  ExtraCompInfoCtrl();
}