#pragma once
#include "afxdialogex.h"


// EditInfoDlg 对话框

class EditInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditInfoDlg)

public:
	EditInfoDlg(CWnd* pParent = nullptr); // 标准构造函数
	virtual ~EditInfoDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITINFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CString m_id;
	CString m_lastname;
	CString m_firstname;
	CString m_date;
	CString m_content;
	afx_msg void OnBnClickedButton1();
};
