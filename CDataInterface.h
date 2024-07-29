#pragma once
#include "pch.h"
#include "CInfo.h"

class CDataInterface
{
public:
	bool Open(const CString& filename);
	void Add(CInfo info);
	void Update(int index, CInfo info);
	void Delete(int index);
	CInfo Read(int index);
	bool Save(CString filename);

	vector<CInfo> v;
};
