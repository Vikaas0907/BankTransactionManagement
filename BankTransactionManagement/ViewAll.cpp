// ViewAll.cpp : implementation file
//

#include "pch.h"
#include "BankTransactionManagement.h"
#include "ViewAll.h"
#include "afxdialogex.h"


// ViewAll dialog

IMPLEMENT_DYNAMIC(ViewAll, CDialogEx)

ViewAll::ViewAll(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VIEWALL, pParent)
{

}

ViewAll::~ViewAll()
{
}

void ViewAll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_contents);
}


BEGIN_MESSAGE_MAP(ViewAll, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &ViewAll::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &ViewAll::OnBnClickedOk)
END_MESSAGE_MAP()


// ViewAll message handlers


void ViewAll::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void ViewAll::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
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

			//CString str= "Rno : " + r + " Roll Num : " + saItems[0];
//			MessageBox(_T(saItems[0]).GetLength());
//			MessageBox("Rno : " + (rollnum.GetLength()));
			//MessageBox(str);

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
