// ViewAllTransctions.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "ViewAllTransctions.h"
#include "afxdialogex.h"


// ViewAllTransctions dialog

IMPLEMENT_DYNAMIC(ViewAllTransctions, CDialogEx)

ViewAllTransctions::ViewAllTransctions(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOWLLTRANSACTIONS, pParent)
{
	CDialogEx::OnCancel();
}

ViewAllTransctions::~ViewAllTransctions()
{
}

void ViewAllTransctions::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_contents);
}


BEGIN_MESSAGE_MAP(ViewAllTransctions, CDialogEx)
	ON_BN_CLICKED(IDOK2, &ViewAllTransctions::OnBnClickedOk2)
	ON_BN_CLICKED(IDCANCEL3, &ViewAllTransctions::OnBnClickedCancel3)
END_MESSAGE_MAP()


// ViewAllTransctions message handlers


void ViewAllTransctions::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
	CStdioFile readFile;
	CFileException fileException;
	UpdateData();
	CString strFilePath = _T("D:\\BalanceData.txt");
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


			CString contents = saItems[0] + "  " + saItems[1] + "   " + saItems[2] + "\r\n";

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


void ViewAllTransctions::OnBnClickedCancel3()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
