// AdminLoginPage.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "AdminLoginPage.h"
#include "afxdialogex.h"
#include "AdminMainPage.h"


// AdminLoginPage dialog

IMPLEMENT_DYNAMIC(AdminLoginPage, CDialogEx)

AdminLoginPage::AdminLoginPage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMINLOGINPAGE, pParent)
{

}

AdminLoginPage::~AdminLoginPage()
{
}

void AdminLoginPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_adminname);
	DDX_Control(pDX, IDC_EDIT2, m_adminpwd);
}


BEGIN_MESSAGE_MAP(AdminLoginPage, CDialogEx)
	ON_BN_CLICKED(IDOK, &AdminLoginPage::OnBnClickedOk)
END_MESSAGE_MAP()


// AdminLoginPage message handlers


void AdminLoginPage::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
//	CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
	//MessageBox(L"Hello Admin");
	//CWnd* obj = AdminMainForm;
	//obj::DoModal();
	//AdminMainForm::DoModal();
	CString uname = _T("");
	CString pwd = _T("");
	m_adminname.GetWindowTextW(uname);
	m_adminpwd.GetWindowTextW(pwd);

	if (!uname.IsEmpty() && !pwd.IsEmpty())
	{
		if (uname == "admin" && pwd == "admin")
		{
			AdminMainPage obj;
			obj.DoModal();
		}
		else
		{
			MessageBox(L"Invalid Uname / Pwd");
		}
	}
	else
	{
		MessageBox(L"Uname / Pwd is Empty");
	}

	UpdateData(FALSE);


}
