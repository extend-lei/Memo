#include "pch.h"
#include "CTool.h"

/// ת��std::stringΪstd::wstring
/// @param str string
/// @return wstring
wstring CTool::String2W(string str) {
	// ��ȡ��Ҫ�Ļ�������С
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), NULL, 0);

	// ������ַ���������
	std::wstring wstr(size_needed, 0);

	// ִ��ת��
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), &wstr[0], size_needed);

	return wstr;
}
