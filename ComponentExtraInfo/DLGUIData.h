#ifndef __DLG__UI_DATA__
#define __DLG__UI_DATA__


#include <vector>
#include <map>
#include <atlstr.h>
#include "ExtraDisplayData.h"


enum MFCTRL_ENUM
{
	MFCTRL_ENUM_REFRESH_BTN,
};

struct ExtraInfoDisplayData
{
public:
	~ExtraInfoDisplayData()
	{
		const size_t num_Data=ListVec.size();
		for(size_t i=0;i<num_Data;i++)
		{
		   if(ListVec[i])
			   delete ListVec[i];
		}

		ListVec.clear();
	}
	
	void AddListData(CString &TypeName, CString CompName)
	{
		ListVec.push_back(new DispData(TypeName,CompName));
	}

	CRect DisplayRect;
	std::vector<DispData*>  ListVec;
	std::map<MFCTRL_ENUM,CString>  ItemMap;
};

#endif