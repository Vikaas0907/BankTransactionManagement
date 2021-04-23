#pragma once


// ViewAll dialog

class ViewAll : public CDialogEx
{
	DECLARE_DYNAMIC(ViewAll)

public:
	ViewAll(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ViewAll();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VIEWALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_contents;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
