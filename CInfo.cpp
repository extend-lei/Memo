#include "pch.h"
#include "CInfo.h"

CInfo::CInfo() {
}

CInfo::CInfo(int id, wstring lastname, wstring firstname, wstring date, wstring content) {
	this->m_id = id;
	this->m_lastname = lastname;
	this->m_firstname = firstname;
	this->m_date = date;
	this->m_content = content;
}

void CInfo::Load(wifstream& in) {
	in >> m_id;
	in >> m_lastname;
	in >> m_firstname;
	in >> m_date;
	in >> m_content;
}
