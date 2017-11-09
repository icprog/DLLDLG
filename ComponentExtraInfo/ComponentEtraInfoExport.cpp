#include "stdafx.h"
#include "DLLUI_ExtraCompInfo.h"


IDLLPluginInterface*   CreatePluginObj()
{
	return new  ExtraCompInfoCtrl();
}