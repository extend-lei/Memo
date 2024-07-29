// MemoDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Memo.h"
#include "MemoDlg.h"
#include "afxdialogex.h"
#include "EditInfoDlg.h"
#include "CTool.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMemoDlg 对话框


CMemoDlg::CMemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MEMO_DIALOG, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMemoDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMemoDlg 消息处理程序

BOOL CMemoDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE); // 设置大图标
	SetIcon(m_hIcon, FALSE); // 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_list.InsertColumn(0, TEXT("编号"), 0, 150);
	m_list.InsertColumn(1, TEXT("姓氏"), 0, 150);
	m_list.InsertColumn(2, TEXT("名字"), 0, 150);
	m_list.InsertColumn(3, TEXT("日期"), 0, 150);
	m_list.InsertColumn(4, TEXT("内容"), 0, 300);

	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE; // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMemoDlg::OnPaint() {
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMemoDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}


void CMemoDlg::OnBnClickedButton1() {
	// TODO: 在此添加控件通知处理程序代码
	// TODO: Add your control notification handler code here   
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);


	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		DataInterface.Open(strFilePath);
		UpdateList();
	}
}

void CMemoDlg::UpdateList() {
	m_list.DeleteAllItems();
	CString cstr;
	for (int i = 0; i < DataInterface.v.size(); ++i)
	{
		cstr.Format(TEXT("%d"), DataInterface.v[i].m_id);
		m_list.InsertItem(i, cstr);

		m_list.SetItemText(i, 1, DataInterface.v[i].m_lastname.c_str());
		m_list.SetItemText(i, 2, DataInterface.v[i].m_firstname.c_str());
		m_list.SetItemText(i, 3, DataInterface.v[i].m_date.c_str());
		m_list.SetItemText(i, 4, DataInterface.v[i].m_content.c_str());
	}
}


void CMemoDlg::OnBnClickedButton4() {
	// TODO: 在此添加控件通知处理程序代码
	EditInfoDlg dlg;
	if (IDOK == dlg.DoModal())
	{
		std::string stdStr(CT2CA(dlg.m_id));
		CInfo info(std::stoi(stdStr), dlg.m_lastname.GetBuffer(),
		           dlg.m_firstname.GetBuffer(), dlg.m_date.GetBuffer(), dlg.m_content.GetBuffer());
		DataInterface.v.push_back(info);
		UpdateList();
	}
}
