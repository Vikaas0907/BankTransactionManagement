#pragma once


// NewUserPage dialog

class NewUserPage : public CDialogEx
{
	DECLARE_DYNAMIC(NewUserPage)

public:
	NewUserPage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~NewUserPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWUSER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CEdit m_accountnum;
//	CEdit m_customername;
	CEdit m_password;
	CEdit m_custname;
	CEdit m_balance;
};
