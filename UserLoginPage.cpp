// UserLoginPage.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "UserLoginPage.h"
#include "afxdialogex.h"
#include "UserMainForm.h"

// UserLoginPage dialog

IMPLEMENT_DYNAMIC(UserLoginPage, CDialogEx)

UserLoginPage::UserLoginPage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USERLOGINPAGE, pParent)
{

}

UserLoginPage::~UserLoginPage()
{
}

void UserLoginPage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_username);
	DDX_Control(pDX, IDC_EDIT2, m_userpwd);
}


BEGIN_MESSAGE_MAP(UserLoginPage, CDialogEx)
	ON_BN_CLICKED(IDOK, &UserLoginPage::OnBnClickedOk)
END_MESSAGE_MAP()


// UserLoginPage message handlers


void UserLoginPage::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	// TODO: Add your control notification handler code here
	//MessageBox(L"Hello Admin");
	//CWnd* obj = AdminMainForm;
	//obj::DoModal();
	//AdminMainForm::DoModal();
	CString uname = _T("");
	CString pwd = _T("");
	m_username.GetWindowTextW(uname);
	m_userpwd.GetWindowTextW(pwd);

	if (!uname.IsEmpty() && !pwd.IsEmpty())
	{
		CStdioFile readFile;
		CFileException fileException;
		UpdateData();
		CString empnum = _T("");
		CString strFilePath = _T("D:\\AccData.txt");
		CString strLine = _T("");
		if (readFile.Open(strFilePath, CFile::modeRead, &fileException))
		{
			int flag = 0;
			int bucket = 0;
			while (readFile.ReadString(strLine))
			{
				//MessageBox(strLine);
				CString sToken = _T("");
				CStringArray saItems;

				//char Output[20];
				int i = 0; // substring index to extract
				while (AfxExtractSubString(sToken, strLine, i, '&'))
				{
					//.. 
					//work with sToken
					//..
					//MessageBox(strLine);				
					saItems.Add(sToken);
					i++;
				}

				//CString str= "Rno : " + r + " Roll Num : " + saItems[0];
	//			MessageBox(_T(saItems[0]).GetLength());
	//			MessageBox("Rno : " + (rollnum.GetLength()));
				//MessageBox(str);

				//bucket = bucket + 1;

				char Output[20];
				//sprintf(Output, "%s%d", "Bucket ", bucket);

				if (saItems[0] == uname && saItems[1] == pwd)
				{
					flag = 1;
					break;
					UpdateData(false);
				}
			}
			if (flag == 1)
			{
				UserMainForm obj;
				obj.DoModal();
			}
			else
			{
				MessageBox(L"Sorry Data Not Found");
			}
		}
		else
		{
			MessageBox(L"Sorry Some Error Occurs");
			//CString strErrorMsg;
			//strErrorMsg.Format(_T("Can't open file %s , error : %u"), strFilePath, fileException.m_cause);
			//AfxMessageBox(strErrorMsg);
		}

		readFile.Close();

	}
	else
	{
		MessageBox(L"Uname / Pwd is Empty");
	}

	UpdateData(FALSE);
}
