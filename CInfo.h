#pragma once
#include "pch.h"

class CInfo
{
public:
	CInfo();
	CInfo(int id,
	      wstring lastname,
	      wstring firstname,
	      wstring date,
	      wstring content);

	void Load(wifstream& in);

	int m_id;
	wstring m_lastname;
	wstring m_firstname;
	wstring m_date;
	wstring m_content;
};
