// AdminMainPage.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "AdminMainPage.h"
#include "afxdialogex.h"
#include "ViewAllUsers.h"
#include "ViewAllTransctions.h"
#include "ViewAll.h"

// AdminMainPage dialog

IMPLEMENT_DYNAMIC(AdminMainPage, CDialogEx)

AdminMainPage::AdminMainPage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADMINMAINPAGE, pParent)
{

}

AdminMainPage::~AdminMainPage()
{
}

void AdminMainPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AdminMainPage, CDialogEx)
	ON_BN_CLICKED(IDCANCEL2, &AdminMainPage::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL, &AdminMainPage::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &AdminMainPage::OnBnClickedOk)
END_MESSAGE_MAP()


// AdminMainPage message handlers


void AdminMainPage::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void AdminMainPage::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnCancel();
	//View All Transactions

	//ViewAllTransctions obj;
	//obj.DoModal();
	ViewAll obj;
	obj.DoModal();

}


void AdminMainPage::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
//	CDialogEx::OnOK();
	//View All Users
	ViewAllUsers obj;
	obj.DoModal();	
}
