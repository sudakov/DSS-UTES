//---------------------------------------------------------------------------
// DSS Library
// Author: Afonin C.A., Bomas V.V., Sudakov V.A., 1997/1999 Russia
//---------------------------------------------------------------------------
// Description: Description of Factory that generates exponent and scale objects
//---------------------------------------------------------------------------

#ifndef DSSLIB_FACTORY_H
#define DSSLIB_FACTORY_H

struct strcType
{
	int ID;
	char Name[40];
};

#define EXPONENT_LEXICAL		1
#define EXPONENT_NUMBER			2
#define EXPONENT_GROUP			3

#define SCALE_LEXICAL			1
#define SCALE_INTERVAL			2
#define SCALE_DISCRET			3
#define SCALE_PREFERENCE		4

#define METHOD_PREFERENCE		1
#define METHOD_WEIGHT			2
#define METHOD_POINT			4



class CExponentFactory
{
public:
	CExponentFactory();
	~CExponentFactory();

	CExponent* CreateObject(int Type);
	
	int GetTypeLex(int Type, CString& Name);	//return 0 if successful
	int GetAllID(int* IDs);					// return number of types
	int Count;
};



class CScaleFactory
{
public:
	CScaleFactory();
	~CScaleFactory();

	CScale* CreateObject(int Type);
	
	int GetTypeLex(int Type,CString& Name);	//return 0 if successful
	int GetAllID(int* IDs);					// return number of types
	int GetAllForType(int ExpType,int* IDs);
	int Count;
};

class CMethodFactory
{
public:
	CMethodFactory();
	~CMethodFactory();

	CMethod* CreateObject(int Type);
	
	int GetTypeLex(int Type,CString& Name);	//return 0 if successful
	int GetAllID(int* IDs);					// return number of types
	int GetProgID(int Type, CString& ProgID);
	int GetProgID2(int Type,CString& ProgID);
	int Count;

private:
	CStringList m_Names;
	CList <int,int&> m_IDs;
	CStringList m_ProgID;
	CStringList m_ProgID2;
};

#endif //DSSLIB_FACTORY_H