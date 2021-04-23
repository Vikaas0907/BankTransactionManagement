#pragma once


// ViewAllTransctions dialog

class ViewAllTransctions : public CDialogEx
{
	DECLARE_DYNAMIC(ViewAllTransctions)

public:
	ViewAllTransctions(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ViewAllTransctions();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOWLLTRANSACTIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedCancel3();
	CEdit m_contents;
};
