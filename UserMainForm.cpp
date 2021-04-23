// UserMainForm.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "UserMainForm.h"
#include "afxdialogex.h"


// UserMainForm dialog

IMPLEMENT_DYNAMIC(UserMainForm, CDialogEx)

UserMainForm::UserMainForm(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USERMAINFORM, pParent)
{

}

UserMainForm::~UserMainForm()
{
}

void UserMainForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_accountnum);
	DDX_Control(pDX, IDC_EDIT2, m_amount);
}


BEGIN_MESSAGE_MAP(UserMainForm, CDialogEx)
	ON_BN_CLICKED(IDCANCEL2, &UserMainForm::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL, &UserMainForm::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &UserMainForm::OnBnClickedOk)
END_MESSAGE_MAP()


// UserMainForm message handlers


void UserMainForm::OnBnClickedCancel2()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void UserMainForm::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	//Deposit

	UpdateData();
	CString accnum = _T(""), amount = _T("");
	m_accountnum.GetWindowTextW(accnum);
	m_amount.GetWindowTextW(amount);

	int flag = 0;
	CStdioFile writeToFile;
	CFileException fileException;
	CString strFilePath = _T("D:\\BalanceData.txt");

	CStdioFile readFile;
	CString strLine;

	CString contents = accnum + "&Deposit&" + amount;

	//	MessageBox(contents);
	if (writeToFile.Open(strFilePath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate), &fileException)
	{
		writeToFile.SeekToEnd();
		//writeToFile.WriteString(_T("\n"));
		writeToFile.WriteString((contents));
		writeToFile.WriteString(_T("\n"));
		//writeToFile.WriteString(_T("Bye\n"));
		MessageBox(L"Amount Deposit Success");
	}
	else
	{
		CString strErrorMsg;
		MessageBox(L"Sorry Amount Deposit Not Success");
		//strErrorMsg.Format(_T("Can't open file %s , error : %u"), strFilePath, fileException.m_cause);
		//AfxMessageBox(strErrorMsg);
	}
	writeToFile.Close();
}


void UserMainForm::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	//WithDraw
	UpdateData();
	CString accnum = _T(""), amount = _T("");
	m_accountnum.GetWindowTextW(accnum);
	m_amount.GetWindowTextW(amount);
	
	int flag = 0;
	CStdioFile writeToFile;
	CFileException fileException;
	CString strFilePath = _T("D:\\BalanceData.txt");

	CStdioFile readFile;
	CString strLine;
	
	CString contents = accnum + "&WithDraw&" +  amount;

		//	MessageBox(contents);
		if (writeToFile.Open(strFilePath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate), &fileException)
		{
			writeToFile.SeekToEnd();
			//writeToFile.WriteString(_T("\n"));
			writeToFile.WriteString((contents));
			writeToFile.WriteString(_T("\n"));
			//writeToFile.WriteString(_T("Bye\n"));
			MessageBox(L"Amount WithDrawn Success");
		}
		else
		{
			CString strErrorMsg;
			MessageBox(L"Sorry Amount WithDrawn Not Success");
			//strErrorMsg.Format(_T("Can't open file %s , error : %u"), strFilePath, fileException.m_cause);
			//AfxMessageBox(strErrorMsg);
		}
		writeToFile.Close();
}

