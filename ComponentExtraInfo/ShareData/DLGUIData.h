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

class ExtraInfoDisplayData
{
public:
	ExtraInfoDisplayData()
	{
		ActiveData=NULL;
	}

	~ExtraInfoDisplayData()
	{
		ClearDisplayData();
	}

	void ClearDisplayData()
	{
		const size_t num_Data=ListVec.size();
		for(size_t i=0;i<num_Data;i++)
		{
			if(ListVec[i])
				delete ListVec[i];
		}

		ListVec.clear();
	}

	void SetDispDataVec(std::vector<DispData*> & input)
	{
		CString CompttypeName;
		CString CompName;
		if(ActiveData) //Keep Previous Item
		{
			CompttypeName=ActiveData->_ComponentTypeName;
			CompName=ActiveData->_ComponentDataName;
		}
		
		ClearDisplayData();
		ListVec=input;

		SelectGivenItem(CompttypeName,  CompName);
	}
	
	void AddListData(CString &TypeName, CString CompName)
	{
		ListVec.push_back(new DispData(TypeName,CompName));
	}

	std::vector<DispData*>  GetDisplayData()
	{
		return  ListVec;
	}

	void SetClientRect(CRect& inputRect)
	{
		DisplayRect=inputRect;
	}

	CRect GetDisplayRect()
	{
		return DisplayRect;
	}

	void SetUIDisplayStr(MFCTRL_ENUM ctrlenmu,CString& dispstr)
	{
		ItemMap[ctrlenmu]=dispstr;
	}

	void GetDisplayStr(MFCTRL_ENUM ctrlenum,CString &outstr)
	{
		std::map<MFCTRL_ENUM,CString>::iterator pos=ItemMap.begin();
		std::map<MFCTRL_ENUM,CString>::iterator endpos=ItemMap.end();
		for(;pos!=endpos;pos++)
		{
			if(pos->first==ctrlenum)
			{
				outstr=pos->second;
				return;
			}
		}

	}

	DispData* GetActiveData()
	{
		return ActiveData;
	}

	void SelectGivenItem(CString &CompttypeName, CString & CompName)
	{
		ActiveData=GetDispData(CompttypeName,  CompName);
	}

	DispData* GetDispData(CString &CompttypeName, CString & CompName)
	{
		const size_t num_Data= ListVec.size();
		for(size_t i=0;i<num_Data;i++)
		{
			DispData* pData=ListVec[i];
			if(pData)
			{
				if (pData->_ComponentTypeName==CompttypeName && pData->_ComponentDataName==CompName)
				{
					return pData;
				}
			}
		}

		return NULL;
	}
private:
	

	CRect DisplayRect;
	std::vector<DispData*>  ListVec;
	DispData* ActiveData;
	std::map<MFCTRL_ENUM,CString>  ItemMap;
};

#endif