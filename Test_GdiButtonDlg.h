
// Test_GdiButtonDlg.h: 헤더 파일
//

#pragma once

#include <deque>

#include "../../Common/GdiplusBitmap.h"
#include "../../Common/CButton/GdiButton/GdiButton.h"
#include "../../Common/ResizeCtrl.h"
#include "../../Common/CStatic/SCStatic/SCStatic.h"
#include "../../Common/CStatic/XPGroupBox/XPGroupBox.h"
#include "../../Common/CSliderCtrl/SCSliderCtrl/SCSliderCtrl.h"

// CTestGdiButtonDlg 대화 상자
class CTestGdiButtonDlg : public CDialogEx
{
// 생성입니다.
public:
	CTestGdiButtonDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CResizeCtrl			m_resize;

	CToolTipCtrl		m_tooltip;

	CGdiplusBitmap		m_img;

	std::deque<CGdiplusBitmap*>	m_img_back;
	int					m_img_back_index;
	int					m_img_back_mode;		//origin? zoom? stretch?
	void				load_back_images();
	void				release_back_images();

	LRESULT				on_message_CSCSliderCtrl(WPARAM wParam, LPARAM lParam);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_GDIBUTTON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_back_image;
	afx_msg void OnCbnSelchangeComboBackImage();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CSCStatic m_static_back_image;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CGdiButton m_check_stretch;
	afx_msg void OnBnClickedCheckStretch();
	afx_msg void OnWindowPosChanged(WINDOWPOS* lpwndpos);
	CGdiButton m_button_ok;
	CGdiButton m_button_cancel;
	CGdiButton m_check_align[3];
	CGdiButton m_check_fit_to_control;
	CGdiButton m_check_fit_to_image;
	CGdiButton m_radio_default[3];
	CGdiButton m_radio_image[3];
	CXPGroupBox m_group_back_image;
	CXPGroupBox m_group_default_checkbox;
	CXPGroupBox m_group_image_checkbox;
	CXPGroupBox m_group_radio_button;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CXPGroupBox m_group_auto_shadow;
	CGdiButton m_button_shadow_right;
	CGdiButton m_button_shadow_left;
	CGdiButton m_button_shadow;
	CSCSliderCtrl m_slider_shadow_weight;
	CSCSliderCtrl m_slider_shadow_blur;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
