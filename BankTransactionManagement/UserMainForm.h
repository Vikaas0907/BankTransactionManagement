#pragma once


// UserMainForm dialog

class UserMainForm : public CDialogEx
{
	DECLARE_DYNAMIC(UserMainForm)

public:
	UserMainForm(CWnd* pParent = nullptr);   // standard constructor
	virtual ~UserMainForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERMAINFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CEdit m_accountnum;
	CEdit m_amount;
};
