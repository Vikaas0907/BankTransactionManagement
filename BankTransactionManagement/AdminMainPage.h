#pragma once


// AdminMainPage dialog

class AdminMainPage : public CDialogEx
{
	DECLARE_DYNAMIC(AdminMainPage)

public:
	AdminMainPage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~AdminMainPage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADMINMAINPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
