#include "pch.h"
#include "CDataInterface.h"

#include <codecvt>

bool CDataInterface::Open(const CString& filename) {
	wifstream in;
	in.imbue(std::locale(in.getloc(), new codecvt_utf8<wchar_t>));
	in.open(filename);
	if (in.is_open())
	{
		int cnt;
		in >> cnt;
		v.clear();
		CInfo info;
		for (int i = 0; i < cnt; ++i)
		{
			info.Load(in);
			v.push_back(info);
		}
		return true;
	}
	return false;
}
