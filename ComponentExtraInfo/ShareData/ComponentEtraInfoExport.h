#ifndef __COMP_EXTRA_INFO_EXPORT__
#define __COMP_EXTRA_INFO_EXPORT__


#include "..\..\Interface\DLLPluginInterface.h"


#ifdef COMPEXTRAIFNO_EXPORTS
#define DLLCATPREFIX __declspec(dllexport)
#else
#define DLLCATPREFIX __declspec(dllimport)
#endif



extern "C"
{
	DLLCATPREFIX IDLLPluginInterface*  CreatePluginObj();
}

#endif