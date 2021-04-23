// ViewAllUsers.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "ViewAllUsers.h"
#include "afxdialogex.h"


// ViewAllUsers dialog

IMPLEMENT_DYNAMIC(ViewAllUsers, CDialogEx)

ViewAllUsers::ViewAllUsers(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

ViewAllUsers::~ViewAllUsers()
{
}

void ViewAllUsers::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_contents);
}


BEGIN_MESSAGE_MAP(ViewAllUsers, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &ViewAllUsers::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &ViewAllUsers::OnBnClickedOk)
END_MESSAGE_MAP()


// ViewAllUsers message handlers


void ViewAllUsers::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void ViewAllUsers::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();

	CStdioFile readFile;
	CFileException fileException;
	UpdateData();
	CString strFilePath = _T("D:\\AccData.txt");
	CString str = _T("");
	CString strLine;
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

			CString contents = saItems[0] + "  " + saItems[1] + "   " + saItems[2] + "  " + saItems[3] + "\r\n";

			str = str + contents;

		}

	}
	else
	{
		CString strErrorMsg;
		MessageBox(L"Sorry File Not Open");
		//strErrorMsg.Format(_T("Can't open file %s , error : %u"), strFilePath, fileException.m_cause);
		//AfxMessageBox(strErrorMsg);
	}
	m_contents.SetWindowTextW(str);
	readFile.Close();


}
