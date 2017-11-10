#ifndef __TEMPLATE__DLL_LOADER__
#define __TEMPLATE__DLL_LOADER__


#include "IDLLLoader.h"
#include "..\Interface\DLLPluginInterface.h"

class IDLLPluginInterface;

typedef IDLLPluginInterface *(*IDLLPluginCreateor)();

class DLLLoader : public  IDLLLoader
{
public:
	DLLLoader(CString &DllName)
	{
		CTypeDef=NULL;

		char ownPth[MAX_PATH]; 

		HMODULE hModule = GetModuleHandle(NULL);
		if (hModule != NULL)
		{
			GetModuleFileName(hModule,ownPth, (sizeof(ownPth))); 
		}
		CString FullPathString=ownPth;
		int index=FullPathString.ReverseFind('\\');
		CString PathString=FullPathString.Mid(0,index);



		CString dllpath=PathString+CString(_T("/"))+DllName;
		hLibrary =  LoadLibrary(dllpath);

		if(hLibrary)
		{
			void * ptr=GetProcAddress(hLibrary, _T("CreatePluginObj"));
			CTypeDef=(IDLLPluginCreateor)GetProcAddress(hLibrary, _T("CreatePluginObj"));
		}
	}

	virtual IDLLPluginInterface* GetDLLCLass()
	{
		IDLLPluginInterface* ret=NULL;
		if(CTypeDef)
			ret=(CTypeDef)();
		return ret;
	}
	
	~DLLLoader()
	{
		FreeLibrary(hLibrary);
	}
private:
	IDLLPluginCreateor CTypeDef;
	HINSTANCE hLibrary;
};

#endif