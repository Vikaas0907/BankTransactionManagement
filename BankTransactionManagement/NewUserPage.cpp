// NewUserPage.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "NewUserPage.h"
#include "afxdialogex.h"


// NewUserPage dialog

IMPLEMENT_DYNAMIC(NewUserPage, CDialogEx)

NewUserPage::NewUserPage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWUSER, pParent)
{

}

NewUserPage::~NewUserPage()
{
}

void NewUserPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_accountnum);
	//  DDX_Control(pDX, IDC_EDIT2, m_customername);
	DDX_Control(pDX, IDC_EDIT2, m_password);
	DDX_Control(pDX, IDC_EDIT3, m_custname);
	DDX_Control(pDX, IDC_EDIT4, m_balance);
}


BEGIN_MESSAGE_MAP(NewUserPage, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &NewUserPage::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &NewUserPage::OnBnClickedOk)
END_MESSAGE_MAP()


// NewUserPage message handlers


void NewUserPage::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void NewUserPage::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();

		// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData();
	CString accnum = _T(""), cname = _T(""), pwd = _T(""), balance = _T("");
	m_accountnum.GetWindowTextW(accnum);
	m_password.GetWindowTextW(pwd);
	m_custname.GetWindowTextW(cname);
	m_balance.GetWindowTextW(balance);
	

	int flag = 0;
	CStdioFile writeToFile;
	CFileException fileException;
	CString strFilePath = _T("D:\\AccData.txt");

	CStdioFile readFile;
	CString strLine;


	if (readFile.Open(strFilePath, CFile::modeRead, &fileException))
	{
		while (readFile.ReadString(strLine))
		{
			CString sToken = _T("");
			CStringArray saItems;

			int i = 0; // substring index to extract
			while (AfxExtractSubString(sToken, strLine, i, '&'))
			{
				//				MessageBox(strLine);
				saItems.Add(sToken);
				i++;
			}

			//CString str = "Rno : " + rollnum + " Roll Num : " + saItems[0];

			if (saItems[0] == accnum)
			{
				flag = 1;
				break;
			}
			/*if(flag==1)
			{
				MessageBox("Sorry Record Already Exists");
				break;
			}
			*/
		}
	}

	readFile.Close();
	//MessageBox("hi");

	if (flag == 1)
	{
		MessageBox(L"Sorry Acoount Already Exists");
	}
	else {

		//MessageBox("hi");
		CString contents = accnum + "&" + pwd + "&" + cname + "&" + balance;

		//	MessageBox(contents);
		if (writeToFile.Open(strFilePath, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate), &fileException)
		{
			writeToFile.SeekToEnd();
			//writeToFile.WriteString(_T("\n"));
			writeToFile.WriteString((contents));
			writeToFile.WriteString(_T("\n"));
			//writeToFile.WriteString(_T("Bye\n"));
			MessageBox(L"Employee Data Inserted Success");
		}
		else
		{
			CString strErrorMsg;
			MessageBox(L"Sorry Account Details Not Inserted");
			//strErrorMsg.Format(_T("Can't open file %s , error : %u"), strFilePath, fileException.m_cause);
			//AfxMessageBox(strErrorMsg);
		}
		writeToFile.Close();
	}

}
