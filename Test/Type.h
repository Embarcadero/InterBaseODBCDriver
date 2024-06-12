// Type.h: interface for the CType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYPE_H__52063CA1_54A0_11D2_AB3B_0000C01D2301__INCLUDED_)
#define AFX_TYPE_H__52063CA1_54A0_11D2_AB3B_0000C01D2301__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

enum CharWidth {
	oneByte,
	twoByte
	};

enum  Type {
    Unknown,
	Char,
	Varchar,
	Tiny,			// 8 bit int
	Short,			// 16 bit int
	Int,			// 32 bit int
	Long,			// 64 bit int
	Float,
	Double,
	Date,
	TextBlob,
	BinaryBlob,
	DispatchObject,
	Domain,			// fields only
	};


class CType  
{
public:
	CString getJdbcType();
	bool isCharacter();
	int getLength();
	CString getJavaType();
	CString getOleDbBindType();
	CString getCDeclaration (const char *name, CharWidth charWidth);
	int getCLength (CharWidth charWidth);
	int getBoundary (CharWidth charWidth);
	void setType (int dtodbcTypeype, int precision, const char *typeName);
	int getPrecision();
	bool isInteger();
	void setType (Type typ, int len);
	void setType (CType *type);
	VARTYPE getVariantType();
	bool isLargeObject();
	CType();
	virtual ~CType();

	Type	type;
	int	precision;
	int	length;
	int	scale;
	int	indirectCount;			
};

#endif // !defined(AFX_TYPE_H__52063CA1_54A0_11D2_AB3B_0000C01D2301__INCLUDED_)
