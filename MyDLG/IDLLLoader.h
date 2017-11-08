#ifndef __IDLLLOADER__INTERFACE__
#define __IDLLLOADER__INTERFACE__

class IDLLLoader
{
public:
	virtual ~IDLLLoader(){}
	virtual IDLLPluginInterface* GetDLLCLass()=0;
private:
};
#endif