#include "pch.h"
#include "CTool.h"

/// 转换std::string为std::wstring
/// @param str string
/// @return wstring
wstring CTool::String2W(string str) {
	// 获取需要的缓冲区大小
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), NULL, 0);

	// 分配宽字符串缓冲区
	std::wstring wstr(size_needed, 0);

	// 执行转换
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), &wstr[0], size_needed);

	return wstr;
}
