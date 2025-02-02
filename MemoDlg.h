﻿// MemoDlg.h: 头文件
//

#pragma once
#include "CDataInterface.h"

// CMemoDlg 对话框
class CMemoDlg : public CDialogEx
{
	// 构造
public:
	CMemoDlg(CWnd* pParent = nullptr); // 标准构造函数

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持


	// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButton1();
	CString strFilePath;
	CDataInterface DataInterface;
	void UpdateList();
	afx_msg void OnBnClickedButton4();
};
