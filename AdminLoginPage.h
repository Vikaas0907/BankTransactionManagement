#pragma once


// AdminLoginPage dialog

class AdminLoginPage : public CDialogEx
{
	DECLARE_DYNAMIC(AdminLoginPage)

public:
	AdminLoginPage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AdminLoginPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMINLOGINPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_adminname;
	CEdit m_adminpwd;
	afx_msg void OnBnClickedOk();
};
