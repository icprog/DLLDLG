#include "stdafx.h"
#include "ComponentEtraInfoExport.h"
#include "DLLUI_ExtraCompInfo.h"

IDLLUI_Plugin<MFCTRL_ENUM,ExtraInfoDisplayData>*   CreatePluginObj()
{
	return new  ExtraCompInfoCtrl();
}