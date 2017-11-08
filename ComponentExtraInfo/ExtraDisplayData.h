#ifndef ___EXTRA_DISP_DATA__
#define ___EXTRA_DISP_DATA__

class DispData
{
public:
  DispData(CString &TypName,CString &DataName)
  {
	  _ComponentTypeName=TypName;
	  _ComponentDataName=DataName;
  }

  CString _ComponentTypeName;
  CString _ComponentDataName;
};

#endif