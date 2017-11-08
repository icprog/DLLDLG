#ifndef __TEMPLATE__DLL_LOADER__
#define __TEMPLATE__DLL_LOADER__

template<class DLLCLASS,class ClassCreationDef>
class DLLLoader
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



		CString dllpath=DllName;
		hLibrary =  LoadLibrary(dllpath);

		if(hLibrary)
		{
			CTypeDef=(ClassCreationDef)GetProcAddress(hLibrary, _T("CreatePluginObj"));
		}
	}

	virtual DLLCLASS GetDLLCLass()
	{
		DLLCLASS ret=NULL;
		if(CTypeDef)
			ret=(CTypeDef)();
		return ret;
	}
	
	~DLLLoader()
	{
		FreeLibrary(hLibrary);
	}
private:
	ClassCreationDef CTypeDef;
	HINSTANCE hLibrary;
};

#endif