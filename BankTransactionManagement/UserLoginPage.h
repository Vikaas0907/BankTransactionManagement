#pragma once


// UserLoginPage dialog

class UserLoginPage : public CDialogEx
{
	DECLARE_DYNAMIC(UserLoginPage)

public:
	UserLoginPage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserLoginPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERLOGINPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_username;
	CEdit m_userpwd;
};
