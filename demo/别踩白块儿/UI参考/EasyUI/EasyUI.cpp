#include "conio.h"
#include "EasyUI.h"



CGUIElement::CGUIElement(EUIElement type)
{
	m_bActive = true;
	m_bEventable = true;
	m_iLayer = 0;
}

CGUIElement::~CGUIElement()
{
}


CTrigger::CTrigger()
{
}


CTrigger::~CTrigger()
{
}

CCircle::CCircle(POINT pos, int radius, COLORREF lineColor, COLORREF fillColor)
{
	m_DrawPos = pos;
	m_iRadius = radius;
	m_LineColor = lineColor;
	m_FillColor = fillColor;
}

CCircle::~CCircle()
{
}

void CCircle::Draw()
{
	this->UseAttribute();
	if (m_bFill)
		fillcircle(m_DrawPos.x, m_DrawPos.y, m_iRadius);
	else
		circle(m_DrawPos.x, m_DrawPos.y, m_iRadius);
	if (m_ChildCell)
		m_ChildCell->Draw();
}


CEllipse::CEllipse(POINT pos, int width, int height, COLORREF lineColor, COLORREF fillColor)
{
	m_DrawPos = pos;
	m_iWidth = width;
	m_iHeight = height;
	m_LineColor = lineColor;
	m_FillColor = fillColor;
}

CEllipse::~CEllipse()
{
}

void CEllipse::Draw()
{
	this->UseAttribute();
	if (m_bFill)
		fillellipse(m_DrawPos.x, m_DrawPos.y, m_DrawPos.x + m_iWidth, m_DrawPos.y + m_iHeight);
	else
		ellipse(m_DrawPos.x, m_DrawPos.y, m_DrawPos.x + m_iWidth, m_DrawPos.y + m_iHeight);
	if (m_ChildCell)
		m_ChildCell->Draw();
}

CRect::CRect(POINT pos, int width, int height, COLORREF lineColor, COLORREF fillColor)
{
	m_DrawPos = pos;
	m_iWidth = width;
	m_iHeight = height;
	m_LineColor = lineColor;
	m_FillColor = fillColor;
}

CRect::~CRect()
{
}

void CRect::Draw()
{
	this->UseAttribute();
	if (m_bFill)
		fillrectangle(m_DrawPos.x, m_DrawPos.y, m_DrawPos.x + m_iWidth, m_DrawPos.y + m_iHeight);
	else
		rectangle(m_DrawPos.x, m_DrawPos.y, m_DrawPos.x + m_iWidth, m_DrawPos.y + m_iHeight);
	if (m_ChildCell)
		m_ChildCell->Draw();
}


CRoundRect::CRoundRect(POINT pos, int width, int height, int roundWidth, int roundHeight, COLORREF lineColor, COLORREF fillColor)
{
	m_DrawPos = pos;
	m_iWidth = width;
	m_iHeight = height;
	m_iRoundWidth = roundWidth;
	m_iRoundHeight = roundHeight;
	m_LineColor = lineColor;
	m_FillColor = fillColor;
}

CRoundRect::~CRoundRect()
{
}

void CRoundRect::Draw()
{
	this->UseAttribute();
	if (m_bFill)
		fillroundrect(m_DrawPos.x, m_DrawPos.y, m_DrawPos.x + m_iWidth, m_DrawPos.y + m_iHeight, m_iRoundWidth, m_iRoundHeight);
	else
		roundrect(m_DrawPos.x, m_DrawPos.y, m_DrawPos.x + m_iWidth, m_DrawPos.y + m_iHeight, m_iRoundWidth, m_iRoundHeight);
	if (m_ChildCell)
		m_ChildCell->Draw();
}

CText::~CText()
{
}

void CText::Draw()
{
	TCHAR text[256];
	wcscpy_s(text, 256, m_strText.c_str());
	outtextxy(m_DrawPos.x, m_DrawPos.y, text);
}

CUIImage::CUIImage(IMAGE * image, IMAGE * mask)
{
	m_pImage = image;
	m_pMask = mask;
}

CUIImage::~CUIImage()
{
	if (m_pImage)
		delete m_pImage;
	if (m_pMask)
		delete m_pMask;
}

void CUIImage::SetMask(IMAGE * mask, bool apllyImage, bool destroyOld)
{
	if (m_pMask&&destroyOld)
		delete m_pMask;
	m_pMask = mask;
	if (apllyImage)
	{
		int width, height;
		width = m_pImage->getwidth() < m_pMask->getwidth() ? m_pImage->getwidth() : m_pMask->getwidth();
		height = m_pImage->getheight() < m_pMask->getheight() ? m_pImage->getheight() : m_pMask->getheight();
		DWORD * imageBuf = GetImageBuffer(m_pImage);
		DWORD * maskBuf = GetImageBuffer(m_pMask);
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				if (!(maskBuf[i * m_pMask->getwidth() + j] << 8))
					imageBuf[i * m_pImage->getwidth() + j] = WHITE;
			}
		}
	}
}

void CUIImage::CreatMask(CSimpleShape * shape, bool flip)
{
	// 清空遮罩
	if (!m_pMask)
		m_pMask = new IMAGE;
	m_pMask->Resize(m_pImage->getwidth(), m_pImage->getheight());
	SetWorkingImage(m_pMask);

	// 保存绘制单元状态
	COLORREF lastLineColor = shape->GetLineColor();
	COLORREF lastFillColor = shape->GetFillColor();
	bool fill = shape->GetFill();

	shape->Fill(true);	// 必须是填充的

	// 开始绘制遮罩和处理原图
	if (flip)
	{
		setfillcolor(WHITE);
		solidrectangle(0, 0, m_pMask->getwidth(), m_pMask->getheight());
		shape->FillColor(BLACK);
		shape->LineColor(BLACK);
		shape->Draw();
		SetWorkingImage(m_pImage);
		shape->FillColor(WHITE);
		shape->LineColor(WHITE);
		shape->Draw();
	}
	else
	{
		setfillcolor(BLACK);
		solidrectangle(0, 0, m_pMask->getwidth(), m_pMask->getheight());
		shape->FillColor(WHITE);
		shape->LineColor(WHITE);
		shape->Draw();
		DWORD * imageBuf = GetImageBuffer(m_pImage);
		DWORD * maskBuf = GetImageBuffer(m_pMask);
		for (int i = 0; i < m_pMask->getheight(); i++)
		{
			for (int j = 0; j < m_pMask->getwidth(); j++)
			{
				if (maskBuf[i * m_pMask->getwidth() + j] == BLACK)
					imageBuf[i * m_pMask->getwidth() + j] = WHITE;
			}
		}
	}

	shape->FillColor(lastFillColor);
	shape->LineColor(lastLineColor);
	shape->Fill(fill);
	SetWorkingImage(nullptr);
}

void CUIImage::Draw()
{
	if (!m_pImage)return;
	float xScale = (float)m_iWidth / (float)m_pImage->getwidth();
	float yScale = (float)m_iHeight / (float)m_pImage->getheight();
	setaspectratio(xScale, yScale);
	if (m_pMask)
	{
		putimage(m_DrawPos.x, m_DrawPos.y, m_pMask, NOTSRCERASE);
		putimage(m_DrawPos.x, m_DrawPos.y, m_pImage, SRCINVERT);
	}
	else
		putimage(m_DrawPos.x, m_DrawPos.y, m_pImage);

	setaspectratio(1, 1);
	if (m_ChildCell)
		m_ChildCell->Draw();
}


CCircleTrigger::~CCircleTrigger()
{
}

bool CCircleTrigger::PtInTrigger(POINT point)
{
	float distance = powf((float)(point.x - this->m_TriggerPos.x), 2) + powf((float)(point.y - this->m_TriggerPos.y), 2);
	return distance <= powf((float)m_iRadius, 2);
}


CMaskTrigger::~CMaskTrigger()
{
}

void CMaskTrigger::CreatMask(CSimpleShape * shape, bool flip)
{
	if (!m_pMask)
		m_pMask = new IMAGE(m_iWidth, m_iHeight);
	// 保存绘制单元状态
	COLORREF lastLineColor = shape->GetLineColor();
	COLORREF lastFillColor = shape->GetFillColor();
	POINT pos = shape->GetDrawPos();
	bool fill = shape->GetFill();

	shape->Fill(true);	// 必须是填充的
	shape->SetDrawPos({ 0, 0 });

	SetWorkingImage(m_pMask);
	setfillcolor(BLACK);
	solidrectangle(0, 0, m_pMask->getwidth(), m_pMask->getheight());
	shape->FillColor(WHITE);
	shape->LineColor(WHITE);
	shape->Draw();

	shape->SetDrawPos(pos);
	shape->FillColor(lastFillColor);
	shape->LineColor(lastLineColor);
	shape->Fill(fill);
	SetWorkingImage(nullptr);
}

bool CMaskTrigger::PtInTrigger(POINT point)
{
	m_rectRc.left = m_TriggerPos.x;
	m_rectRc.top = m_TriggerPos.y;
	m_rectRc.right = m_TriggerPos.x + m_iWidth;
	m_rectRc.bottom = m_TriggerPos.y + m_iHeight;
	if (PtInRect(&m_rectRc, point))
	{
		DWORD * buffer = GetImageBuffer(m_pMask);
		return buffer[(point.y - m_TriggerPos.y) * m_iWidth + (point.x - m_TriggerPos.x)] == WHITE;
	}
	return false;
}

CRectTrigger::~CRectTrigger()
{
}

bool CRectTrigger::PtInTrigger(POINT point)
{
	m_rectRc.left = m_TriggerPos.x;
	m_rectRc.top = m_TriggerPos.y;
	m_rectRc.right = m_TriggerPos.x + m_iWidth;
	m_rectRc.bottom = m_TriggerPos.y + m_iHeight;
	return PtInRect(&m_rectRc, point);
}


CUIManager * CUIManager::Instance = nullptr;

CUIManager::CUIManager()
{
}


CUIManager::~CUIManager()
{
	for (auto it : m_allUIElement)
	{
		delete it.second;
	}
}

void CUIManager::Draw()
{
	m_mapDrawSort.clear();
	for (auto it : m_allUIElement)
	{
		m_mapDrawSort.insert(std::make_pair(it.second->GetLayer(), it.second));
	}
	for (auto it : m_mapDrawSort)
	{
		it.second->Draw();
	}
}

void CUIManager::ProcessEvent()
{
	MOUSEMSG msg;
	EUIEvent event = MOUSE_UP;
	while (MouseHit())
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_MOUSEMOVE:
			event = MOUSE_MOVE;
			break;
		case WM_LBUTTONDOWN:
			event = MOUSE_DOWN;
			break;
		case WM_LBUTTONUP:
			event = MOUSE_UP;
			break;
		default:
			return;
		}
		for (auto it : m_allUIElement)
		{
			it.second->OnEvent(event, MAKELPARAM(msg.x, msg.y));
		}
	}

	while (_kbhit())
	{
		char ch = _getch();
		event = KEYBOARD_INPUT;
		for (auto it : m_allUIElement)
		{
			it.second->OnEvent(event, ch);
		}
	}
}

CGUIElement * CUIManager::GetUIElement(std::wstring name)
{
	if (m_allUIElement.find(name) == m_allUIElement.end())
		return nullptr;
	return m_allUIElement[name];
}

CButton::CButton() :
	CGUIElement(BUTTON)
{
	m_pNormal = m_pDown = m_pMouseIn = nullptr;
	m_bPressed = false;
	m_bMouseIn = false;
	m_pCallBack = nullptr;
}


CButton::~CButton()
{
	if (m_pNormal)delete m_pNormal;
	if (m_pDown) delete m_pDown;
	if (m_pMouseIn)delete m_pMouseIn;
	if (m_pTrigger) delete m_pTrigger;
}

void CButton::Draw()
{
	if (!m_bActive) return;
	if (m_bPressed)
		m_pDown->Draw();
	else if (m_bMouseIn)
		m_pMouseIn->Draw();
	else
		m_pNormal->Draw();
}

void CButton::OnEvent(EUIEvent event, LPARAM Param)
{
	if (!m_pTrigger || !m_bActive || !m_bEventable) return;
	m_pTrigger->SetTriggerPos(m_UIPos);
	switch (event)
	{
	case MOUSE_MOVE:
		if (m_pTrigger->PtInTrigger({ LOWORD(Param), HIWORD(Param) }))
			m_bMouseIn = true;
		else
			m_bMouseIn = false;
		break;
	case MOUSE_DOWN:
		if (m_pTrigger->PtInTrigger({ LOWORD(Param), HIWORD(Param) }))
			m_bPressed = true;
		else
			m_bPressed = false;
		break;
	case MOUSE_UP:
		if (m_bPressed && m_pTrigger->PtInTrigger({ LOWORD(Param), HIWORD(Param) }) && m_pCallBack)
			m_pCallBack();
		m_bPressed = false;
		break;
	}
}

CCheckBox::CCheckBox() :
	CGUIElement(CHECKBOX)
{
	m_bSelected = false;
	m_pTrigger = nullptr;
	m_pBackBox = nullptr;
	m_pCallBack = nullptr;
	m_pChecked = nullptr;
}


CCheckBox::~CCheckBox()
{
	delete m_pTrigger;
	delete m_pBackBox;
	delete m_pChecked;
}

void CCheckBox::Draw()
{
	if (!m_bActive) return;
	m_pBackBox->Draw();
	if (m_bSelected)
		m_pChecked->Draw();
}

void CCheckBox::OnEvent(EUIEvent event, LPARAM Param)
{
	if (!m_bActive || !m_bEventable) return;
	m_pTrigger->SetTriggerPos(m_UIPos);
	switch (event)
	{
	case MOUSE_DOWN:
		if (m_pTrigger->PtInTrigger({ LOWORD(Param), HIWORD(Param) }))
		{
			m_bSelected = !m_bSelected;
			if (m_pCallBack)
				m_pCallBack(m_bSelected);
		}
		break;
	}
}

CDragBar::CDragBar() :
	CGUIElement(DRAGBAR)
{
}


CDragBar::~CDragBar()
{
	delete m_pDragBlock;
	delete m_pBlockTrigger;
	delete m_pLineTrigger;
	delete m_pDragLine;
}

void CDragBar::Draw()
{
	if (!m_bActive) return;
	POINT BlockPos = m_UIPos;
	BlockPos.y = m_UIPos.y + m_LineSize.y / 2 - m_BlockCenter.y;
	BlockPos.x = m_UIPos.x + (int)((float)m_LineSize.x * m_fValue) - m_BlockCenter.x;
	m_pDragBlock->SetDrawPos(BlockPos);
	m_pDragLine->SetDrawPos(m_UIPos);

	m_pDragLine->Draw();
	m_pDragBlock->Draw();
}

void CDragBar::OnEvent(EUIEvent event, LPARAM Param)
{
	if (!m_bActive || !m_bEventable) return;
	POINT BlockPos = m_UIPos;
	BlockPos.y = m_UIPos.y + m_LineSize.y / 2 - m_BlockCenter.y;
	BlockPos.x = m_UIPos.x + (int)((float)m_LineSize.x * m_fValue) - m_BlockCenter.x;
	m_pBlockTrigger->SetTriggerPos(BlockPos);
	m_pLineTrigger->SetTriggerPos(m_UIPos);
	POINT mousePos = { LOWORD(Param), HIWORD(Param) };
	switch (event)
	{
	case MOUSE_DOWN:
		if (m_pBlockTrigger->PtInTrigger(mousePos) || m_pLineTrigger->PtInTrigger(mousePos))
		{
			m_bPressed = true;
			m_fValue = (float)(mousePos.x - m_UIPos.x) / (float)m_LineSize.x;
			if (m_fValue <= 0) m_fValue = 0;
			if (m_fValue >= 1) m_fValue = 1;
		}
		break;
	case MOUSE_MOVE:
		if (m_bPressed)
		{
			m_fValue = (float)(mousePos.x - m_UIPos.x) / (float)m_LineSize.x;
			if (m_fValue <= 0) m_fValue = 0;
			if (m_fValue >= 1) m_fValue = 1;
			if (m_pCallBack) m_pCallBack(m_fValue);
		}
		break;
	case MOUSE_UP:
		if (m_bPressed == true && m_pCallBackExit)
			m_pCallBackExit(m_fValue);
		m_bPressed = false;
		break;
	}

}

CInputTextBox::CInputTextBox() :
	CGUIElement(INPUTBOX)
{
	m_pCursor = new CRect({ 0, 0 }, 2, 5);
	m_strText = new CText();
	m_lastChangeTime = GetTickCount();
	m_pCallBack = nullptr;
}


CInputTextBox::~CInputTextBox()
{
	delete m_pBackBox;
	delete m_pCursor;
	delete m_strText;
}

void CInputTextBox::Draw()
{
	if (!m_bActive) return;
	POINT pos = m_UIPos;
	pos.x += m_iXSpace;
	pos.y += m_iYSpace;
	TCHAR text[256];
	wcscpy_s(text, 256, m_strText->GetText().c_str());
	pos.x += (textwidth(text)) + 3;
	m_pCursor->SetHeight(m_iHeight - m_iYSpace * 2);
	m_pCursor->SetDrawPos(pos);

	pos = m_UIPos;
	pos.x += m_iXSpace;
	pos.y += (m_iHeight - textheight(L"a")) / 2;
	m_strText->SetDrawPos(pos);
	m_pBackBox->SetDrawPos(m_UIPos);


	m_pBackBox->Draw();
	m_strText->Draw();
	if (m_bShowCursor && m_bPressed) m_pCursor->Draw();
	if (m_bPressed && GetTickCount() - m_lastChangeTime >= 800)
	{
		m_bShowCursor = !m_bShowCursor;
		m_lastChangeTime = GetTickCount();
	}
}

void CInputTextBox::OnEvent(EUIEvent event, LPARAM Param)
{
	if (!m_pTrigger || !m_bActive || !m_bEventable) return;
	m_pTrigger->SetTriggerPos(m_UIPos);
	switch (event)
	{
	case MOUSE_DOWN:
		if (m_pTrigger->PtInTrigger({ LOWORD(Param), HIWORD(Param) }))
			m_bPressed = true;
		else
		{
			if (m_bPressed && m_pCallBackExit)
				m_pCallBackExit(m_strText->GetText());
			m_bPressed = false;
		}
		break;
	case KEYBOARD_INPUT:
		if (!m_bPressed) return;
		if (Param == '\b')
		{
			if (!m_strText->GetText().empty())
			{
				m_strText->GetText().pop_back();
				if (m_pCallBack)
					m_pCallBack(m_strText->GetText());
			}
		}
		else
		{
			m_strText->GetText().push_back((char)Param);
			if (m_pCallBack)
				m_pCallBack(m_strText->GetText());
		}
		break;
	}
}

std::wstring CInputTextBox::GetText()
{
	return m_strText->GetText();
}

void CInputTextBox::SetText(std::wstring text)
{
	m_strText->SetText(text);
	if (m_pCallBack)
		m_pCallBack(text);
}

CInputTextBox * CInputTextBox::BackBox(CRect * rect)
{
	if (m_pBackBox)
		delete m_pBackBox;
	m_pBackBox = rect;
	m_iHeight = rect->GetHeight();
	m_iWidth = rect->GetWidth();
	return this;
}

CInputTextBox * CInputTextBox::BackBox(CRoundRect * roundRc)
{
	if (m_pBackBox)
		delete m_pBackBox;
	m_pBackBox = roundRc;
	m_iHeight = roundRc->GetHeight();
	m_iWidth = roundRc->GetWidth();
	return this;
}

CPreBar::CPreBar() :
	CGUIElement(PREBAR)
{
	delete m_pBackground;
	delete m_pMask;
}


CPreBar::~CPreBar()
{
}

void CPreBar::Draw()
{
	if (!m_bActive) return;
	m_pBackground->SetDrawPos(m_UIPos);
	POINT maskPos = m_UIPos;
	maskPos.x += m_Padding.x;
	maskPos.y += m_Padding.y;
	m_pMask->SetDrawPos(maskPos);
	int width = (int)((float)(dynamic_cast<CHaveSize*>(m_pBackground)->GetWidth() - m_Padding.x * 2) * m_fValue);
	int height = (int)((float)dynamic_cast<CHaveSize*>(m_pBackground)->GetHeight() - m_Padding.y * 2);
	dynamic_cast<CHaveSize*>(m_pMask)->SetWidth(width);
	dynamic_cast<CHaveSize*>(m_pMask)->SetHeight(height);

	m_pBackground->Draw();
	m_pMask->Draw();
}

CStaticUI::CStaticUI() :
	CGUIElement(STATIC)
{
	delete m_pDrawCell;
}


CStaticUI::~CStaticUI()
{
}

void CStaticUI::Draw()
{
	if (!m_bActive) return;
	m_pDrawCell->Draw();
}
