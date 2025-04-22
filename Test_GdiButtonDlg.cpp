
// Test_GdiButtonDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Test_GdiButton.h"
#include "Test_GdiButtonDlg.h"
#include "afxdialogex.h"

#include "../../Common/Functions.h"
#include "../../Common/MemoryDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestGdiButtonDlg 대화 상자



CTestGdiButtonDlg::CTestGdiButtonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_GDIBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestGdiButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_BACK_IMAGE, m_combo_back_image);
	DDX_Control(pDX, IDC_STATIC_BACK_IMAGE, m_static_back_image);
	DDX_Control(pDX, IDC_CHECK_STRETCH, m_check_stretch);
	DDX_Control(pDX, IDOK, m_button_ok);
	DDX_Control(pDX, IDCANCEL, m_button_cancel);
	DDX_Control(pDX, IDC_CHECK_ALIGN_DEFAULT, m_check_align[0]);
	DDX_Control(pDX, IDC_CHECK_ALIGN_CENTER, m_check_align[1]);
	DDX_Control(pDX, IDC_CHECK_ALIGN_RIGHT, m_check_align[2]);
	DDX_Control(pDX, IDC_CHECK_FIT_TO_CONTROL, m_check_fit_to_control);
	DDX_Control(pDX, IDC_CHECK_FIT_TO_IMAGE, m_check_fit_to_image);
	DDX_Control(pDX, IDC_RADIO_DEFAULT0, m_radio_default[0]);
	DDX_Control(pDX, IDC_RADIO_DEFAULT1, m_radio_default[1]);
	DDX_Control(pDX, IDC_RADIO_DEFAULT2, m_radio_default[2]);
	DDX_Control(pDX, IDC_RADIO_IMAGE0, m_radio_image[0]);
	DDX_Control(pDX, IDC_RADIO_IMAGE1, m_radio_image[1]);
	DDX_Control(pDX, IDC_RADIO_IMAGE2, m_radio_image[2]);
	DDX_Control(pDX, IDC_GROUP_BACK_IMAGE, m_group_back_image);
	DDX_Control(pDX, IDC_GROUP_DEFAULT_CHECKBOX, m_group_default_checkbox);
	DDX_Control(pDX, IDC_GROUP_IMAGE_CHECKBOX, m_group_image_checkbox);
	DDX_Control(pDX, IDC_GROUP_RADIO_BUTTON, m_group_radio_button);
	DDX_Control(pDX, IDC_GROUP_AUTO_SHADOW, m_group_auto_shadow);
	DDX_Control(pDX, IDC_BUTTON_SHADOW_RIGHT, m_button_shadow_right);
	DDX_Control(pDX, IDC_BUTTON_SHADOW_LEFT, m_button_shadow_left);
	DDX_Control(pDX, IDC_BUTTON_SHADOW, m_button_shadow);
	DDX_Control(pDX, IDC_SLIDER_SHADOW_WEIGHT, m_slider_shadow_weight);
	DDX_Control(pDX, IDC_SLIDER_SHADOW_BLUR, m_slider_shadow_blur);
	DDX_Control(pDX, IDC_STATIC_WEIGHT_PARAM, m_static_weight_param);
	DDX_Control(pDX, IDC_STATIC_BLUR_PARAM2, m_static_blur_param);
}

BEGIN_MESSAGE_MAP(CTestGdiButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_BACK_IMAGE, &CTestGdiButtonDlg::OnCbnSelchangeComboBackImage)
	ON_BN_CLICKED(IDOK, &CTestGdiButtonDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTestGdiButtonDlg::OnBnClickedCancel)
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CHECK_STRETCH, &CTestGdiButtonDlg::OnBnClickedCheckStretch)
	ON_WM_WINDOWPOSCHANGED()
	ON_WM_HSCROLL()
	ON_REGISTERED_MESSAGE(Message_CSCSliderCtrl, &CTestGdiButtonDlg::on_message_CSCSliderCtrl)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK_FIT_TO_IMAGE, &CTestGdiButtonDlg::OnBnClickedCheckFitToImage)
END_MESSAGE_MAP()


// CTestGdiButtonDlg 메시지 처리기

BOOL CTestGdiButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_resize.Create(this);
	m_resize.Add(IDOK, 100, 100, 0, 0);
	m_resize.Add(IDCANCEL, 100, 100, 0, 0);

	m_tooltip.Create(this);// , TTS_ALWAYSTIP | TTS_NOPREFIX | TTS_NOANIMATE);

	load_back_images();

	m_static_back_image.set_transparent();

	m_check_stretch.set_3state();
	m_check_stretch.set_transparent();
	m_img_back_mode = AfxGetApp()->GetProfileInt(_T("setting"), _T("stretch mode"), BST_CHECKED);
	m_check_stretch.SetCheck(m_img_back_mode);
	OnBnClickedCheckStretch();

	int i;

	for (i = 0; i < 3; i++)
	{
		m_check_align[i].set_transparent(true, m_cr_back);
		m_radio_default[i].set_transparent(true, m_cr_back);
		m_radio_image[i].set_transparent(true, m_cr_back);
	}

	m_check_fit_to_control.add_images(_T("PNG"), IDB_BTN_SIZEAUTO_NORMAL, IDB_BTN_SIZEAUTO_CLICK);
	m_check_fit_to_control.set_back_color(Gdiplus::Color::White);
	m_tooltip.AddTool(&m_check_fit_to_control, _T("버튼 크기대로 이미지 크기를 조정"));

	m_check_fit_to_image.add_images(_T("PNG"), IDB_BTN_SIZEAUTO_NORMAL, IDB_BTN_SIZEAUTO_CLICK);
	m_check_fit_to_image.set_back_color(Gdiplus::Color::White);
	m_check_fit_to_image.fit_to_image(true);
	m_check_fit_to_image.use_hover();
	m_tooltip.AddTool(&m_check_fit_to_image, _T("이미지 크기대로 버튼 크기를 조정"));

	m_button_shadow_left.add_image(IDB_ARROW_LEFT);
	//m_button_shadow_left.set_back_color(Gdiplus::Color::White);
	//m_button_shadow_left.fit_to_image(false);
	//m_button_shadow_left.draw_border(true, -1, 10);
	m_button_shadow_left.draw_shadow();//true , 1.0f, 2.0f);

	m_button_shadow_right.add_image(IDB_ARROW_RIGHT);
	//m_button_shadow_right.fit_to_image(false);
	//m_button_shadow_right.draw_hover_rect(true, -1, 10);
	m_button_shadow_right.draw_shadow();

	m_button_shadow.add_image(IDB_ARROW_LEFT);
	m_button_shadow.fit_to_image(true);
	m_button_shadow.use_hover();
	//m_button_shadow.draw_border(true, -1, 10);
	m_button_shadow.draw_shadow(true, 0.5f, 2.0f);


	m_slider_shadow_weight.set_style(CSCSliderCtrl::style_thumb_round);
	m_slider_shadow_weight.set_back_color(RGB(255, 255, 255));
	m_slider_shadow_weight.SetRange(0, 100);

	m_slider_shadow_blur.set_style(CSCSliderCtrl::style_thumb_round);
	m_slider_shadow_blur.set_back_color(RGB(255, 255, 255));
	m_slider_shadow_blur.SetRange(0, 100);


	//draw_border()를 호출할 때 round를 1 이상의 값을 주면 m_transparent = true가 되므로 약간의 깜빡임이 발생할 수 있다.
	//m_button_ok.draw_border(true, 1, 44);
	m_button_ok.use_hover();
	m_button_ok.set_header_image(IDB_CHECKED_BLUE);
	m_button_ok.set_header_image_gap(8);
	m_button_ok.set_back_color(Gdiplus::Color::LightBlue);
	m_button_ok.set_round(40);
	//m_button_ok.set_transparent(true, m_cr_back);
	//m_button_ok.draw_shadow();


	m_button_cancel.set_round(40);
	m_button_cancel.set_back_color(Gdiplus::Color::Beige);
	//m_button_cancel.set_transparent(true, m_cr_back);
	//m_button_cancel.draw_border(true, 1, 14);

	m_img.load(IDB_ARROW_LEFT);
	m_img.save(_T("d:\\arrow_left.png"));
	m_img.set_alpha(128);
	//m_img.resize(200, 0);
	//m_img.resize(0, 356);

	CRect r = m_img.get_transparent_rect();

	SetWindowTheme(GetDlgItem(IDC_EDIT1)->m_hWnd, _T(""), _T(""));

	RestoreWindowPosition(&theApp, this);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTestGdiButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTestGdiButtonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc1(this);
		CRect rc;

		GetClientRect(rc);
		CMemoryDC dc(&dc1, &rc);

		Gdiplus::Graphics g(dc.GetSafeHdc());

		if (m_img_back_index > 0 && m_img_back_index < m_img_back.size())
			m_img_back[m_img_back_index]->draw(g, rc, m_img_back_mode);

		//우측 상단에 이미지를 표시는 예졔코드
		m_img.draw(g, rc.right - m_img.width - 20, rc.top + 20);

		/*
		CRect r;
		m_button_ok.GetWindowRect(r);
		ScreenToClient(r);
		r.InflateRect(8, 8);
		CGdiplusBitmap img;
		img.round_shadow_rect(r.Width(), r.Height(), 14.0f, 2.f, Gdiplus::Color(255, 192, 192, 192));
		img.draw(g, r.left, r.top);
		*/
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTestGdiButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestGdiButtonDlg::load_back_images()
{
	m_combo_back_image.ResetContent();
	release_back_images();

	m_combo_back_image.AddString(_T("없음"));
	m_img_back.push_back(new CGdiplusBitmap());

	std::deque<CString> dq_images = find_all_files(get_exe_directory() + _T("\\images\\back"), _T("*"), FILE_EXTENSION_IMAGE, _T(""), false);
	for (const auto& img : dq_images)
	{
		CGdiplusBitmap* image = new CGdiplusBitmap();
		if (image->load(img))
		{
			image->resize(640, 0);
			//else if (image->width > 1920)
			//	image->resize(0.5f, 0.5f);
			m_combo_back_image.AddString(get_part(img, fn_name));
			m_img_back.push_back(image);
		}
	}

	m_img_back_index = AfxGetApp()->GetProfileInt(_T("setting"), _T("back image index"), 0);
	Clamp(m_img_back_index, 0, (int)m_img_back.size());

	m_combo_back_image.SetCurSel(m_img_back_index);
}

void CTestGdiButtonDlg::release_back_images()
{
	for (auto img : m_img_back)
	{
		img->release();
		delete img;
	}

	m_img_back.clear();
}

void CTestGdiButtonDlg::OnCbnSelchangeComboBackImage()
{
	int index = m_combo_back_image.GetCurSel();
	if (index < 0 || index >= m_img_back.size())
		return;

	m_img_back_index = index;
	m_check_stretch.EnableWindow(m_img_back_index != 0);

	AfxGetApp()->WriteProfileInt(_T("setting"), _T("back image index"), m_img_back_index);
	Invalidate();
}


void CTestGdiButtonDlg::OnBnClickedOk()
{
	//refresh_tray_icon();
	//m_img_back[m_img_back_index]->blur(10.0f, 1);
	//Invalidate();
}


void CTestGdiButtonDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfxMessageBox(_T("exit?"), MB_OKCANCEL) == IDCANCEL)
		return;

	CDialogEx::OnCancel();
}


void CTestGdiButtonDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	release_back_images();
}


BOOL CTestGdiButtonDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return FALSE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CTestGdiButtonDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	Invalidate();
}


void CTestGdiButtonDlg::OnBnClickedCheckStretch()
{
	m_img_back_mode = m_check_stretch.GetCheck();
	TRACE(_T("m_img_back_mode = %d\n"), m_img_back_mode);
	if (m_img_back_mode == BST_UNCHECKED)
		m_check_stretch.SetWindowText(_T("원래 크기"));
	else if (m_img_back_mode == BST_CHECKED)
		m_check_stretch.SetWindowText(_T("늘리기"));
	if (m_img_back_mode == BST_INDETERMINATE)
		m_check_stretch.SetWindowText(_T("비율 유지"));

	AfxGetApp()->WriteProfileInt(_T("setting"), _T("stretch mode"), m_img_back_mode);

	Invalidate();
}


void CTestGdiButtonDlg::OnWindowPosChanged(WINDOWPOS* lpwndpos)
{
	CDialogEx::OnWindowPosChanged(lpwndpos);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	SaveWindowPosition(&theApp, this);
}


BOOL CTestGdiButtonDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_tooltip.m_hWnd)
	{
		//msg를 따로 선언해서 사용하지 않고 *pMsg를 그대로 이용하면 이상한 현상이 발생한다.
		MSG msg = *pMsg;
		msg.hwnd = (HWND)m_tooltip.SendMessage(TTM_WINDOWFROMPOINT, 0, (LPARAM) & (msg.pt));

		CPoint pt = msg.pt;

		if (msg.message >= WM_MOUSEFIRST && msg.message <= WM_MOUSELAST)
			::ScreenToClient(msg.hwnd, &pt);

		msg.lParam = MAKELONG(pt.x, pt.y);

		// relay mouse event before deleting old tool
		m_tooltip.SendMessage(TTM_RELAYEVENT, 0, (LPARAM)&msg);
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CTestGdiButtonDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar == (CScrollBar*)&m_slider_shadow_weight)
	{
		TRACE(_T("weight = %f\n"), (float)nPos / 10.0f);
		m_button_shadow.draw_shadow(true, (float)nPos / 10.0f, -1.0f);
	}
	else if (pScrollBar == (CScrollBar*)&m_slider_shadow_blur)
	{
		TRACE(_T("blur = %f\n"), (float)nPos / 10.0f);
		m_button_shadow.draw_shadow(true, -1.0f, (float)nPos / 10.0f);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

LRESULT CTestGdiButtonDlg::on_message_CSCSliderCtrl(WPARAM wParam, LPARAM lParam)
{
	CSCSliderCtrlMsg* msg = (CSCSliderCtrlMsg*)wParam;
	if (msg->pThis == &m_slider_shadow_weight)
	{
		TRACE(_T("shadow_weight = %f\n"), (float)msg->pos / 10.0f);
		m_static_weight_param.set_textf(-1, _T("%.1f"), (float)msg->pos / 10.0f);
		m_button_shadow.draw_shadow(true, (float)msg->pos / 10.0f, -1.0f);
		m_button_shadow_left.draw_shadow(true, (float)msg->pos / 10.0f, -1.0f);
		m_button_shadow_right.draw_shadow(true, (float)msg->pos / 10.0f, -1.0f);
	}
	else if (msg->pThis == &m_slider_shadow_blur)
	{
		TRACE(_T("shadow_blur = %f\n"), (float)msg->pos / 10.0f);
		m_static_blur_param.set_textf(-1, _T("%.1f"), (float)msg->pos / 10.0f);
		m_button_shadow.draw_shadow(true, -1.0f, (float)msg->pos / 10.0f);
		m_button_shadow_left.draw_shadow(true, -1.0f, (float)msg->pos / 10.0f);
		m_button_shadow_right.draw_shadow(true, -1.0f, (float)msg->pos / 10.0f);
	}
	return 0;
}


HBRUSH CTestGdiButtonDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	switch (nCtlColor)
	{
		//STATIC은 투명하게 표시되는데
		case CTLCOLOR_STATIC:
		//EDIT은 투명하게 되지 않는다.
		case CTLCOLOR_EDIT:
			pDC->SetTextColor(RGB(255, 0, 0));
			pDC->SetBkMode(TRANSPARENT);
			hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
			break;
	}

	return hbr;
}

void CTestGdiButtonDlg::OnBnClickedCheckFitToImage()
{
	m_check_fit_to_control.EnableWindow(m_check_fit_to_image.GetCheck() == BST_CHECKED ? FALSE : TRUE);
}
