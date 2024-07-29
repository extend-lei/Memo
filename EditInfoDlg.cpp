// EditInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "Memo.h"
#include "afxdialogex.h"
#include "EditInfoDlg.h"
#include <string>  // For std::stoi
#include <stdexcept>  // For std::invalid_argument and std::out_of_range


// EditInfoDlg 对话框

IMPLEMENT_DYNAMIC(EditInfoDlg, CDialogEx)

EditInfoDlg::EditInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDITINFO_DIALOG, pParent)
	  , m_id(_T(""))
	  , m_lastname(_T(""))
	  , m_firstname(_T(""))
	  , m_date(_T(""))
	  , m_content(_T("")) {
}

EditInfoDlg::~EditInfoDlg() {
}

void EditInfoDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_lastname);
	DDX_Text(pDX, IDC_EDIT3, m_firstname);
	DDX_Text(pDX, IDC_EDIT4, m_date);
	DDX_Text(pDX, IDC_EDIT5, m_content);
}


BEGIN_MESSAGE_MAP(EditInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EditInfoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// EditInfoDlg 消息处理程序


void EditInfoDlg::OnBnClickedButton1() {
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	if (m_id.IsEmpty() || m_lastname.IsEmpty() || m_firstname.IsEmpty()
		|| m_date.IsEmpty() || m_content.IsEmpty())
	{
		AfxMessageBox(_T("所有输入框不能为空"));
		// 弹出带有 Yes 和 No 按钮的消息框
		//int result = AfxMessageBox(_T("Do you want to continue?"), MB_YESNOCANCEL | MB_ICONQUESTION);
	}
	else
	{
		// 将 CString 转换为 std::string
		std::string stdStr{CT2CA(m_id)};
		try
		{
			size_t pos;
			// 使用 std::stoi 进行转换
			(void)std::stoi(stdStr, &pos);
			// 检查是否整个字符串都被转换
			if (pos != stdStr.length())
			{
				// 输入字符串中还有剩余部分，说明不完全符合预期格式
				AfxMessageBox(_T("输入的ID不完全合法"));
				return;
			}
			OnOK();
		}
		catch (const std::invalid_argument& e)
		{
			// 处理无效的输入
			AfxMessageBox(_T("输入的ID无效"));
		}
		catch (const std::out_of_range& e)
		{
			// 处理超出范围的输入
			AfxMessageBox(_T("输入的ID超出范围"));
		}
	}
}
