#pragma once


// ViewAllUsers dialog

class ViewAllUsers : public CDialogEx
{
	DECLARE_DYNAMIC(ViewAllUsers)

public:
	ViewAllUsers(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ViewAllUsers();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CEdit m_contents;
};
