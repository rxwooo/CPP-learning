#pragma once
#include <graphics.h>
#include <Windows.h>
#include <string>
#include <map>
#include <functional>

#pragma region 枚举

// 简单形状的枚举
enum ESimpleShape
{
	RECTANGLE = 0,	// 矩形
	ROUNDRECT = 1,	// 圆角矩形
	CIRCLE = 2,		// 圆形
	ELLIPSE = 3,	// 椭圆
};
// 控件类型枚举
enum EUIElement
{
	UNKNOW = 0,		// 未知
	STATIC = 1,		// 静态风格，无法响应事件，只能绘制
	BUTTON = 2,		// 按钮
	DRAGBAR = 3,	// 拖动条
	INPUTBOX = 4,	// 输入框
	PREBAR = 5,		// 进度条
	CHECKBOX = 6,	// 选项框

	LASTOFENUM = 0xFFFF	// 枚举赋值的最大值，请不要超过这个值
};
// 事件类型枚举
enum EUIEvent
{
	MOUSE_MOVE = 0,		// 鼠标移动
	MOUSE_DOWN = 1,		// 鼠标按下
	MOUSE_UP = 2,		// 鼠标抬起
	KEYBOARD_INPUT = 3	// 键盘输入
};

#pragma endregion 枚举


#pragma region 绘制单元

// 绘制单元
// 所有可绘制对象的基类(抽象类)
// 继承此类的子类必须实现 Draw 函数
// 注意：如果想扩展绘制类型，绘制的模式需要基于 m_DrawPos，比如想绘制一个长宽为 20 的矩形
// 应该从 m_DrawPos 为左上角开始，绘制长宽为20的矩形
class CDrawCell
{
public:
	CDrawCell() { m_ChildCell = nullptr; }
	virtual ~CDrawCell() {
		if (m_ChildCell)
			delete m_ChildCell;
	}

	// 绘制函数
	virtual void Draw() = 0;

	// 设置绘制的位置
	void SetDrawPos(POINT pos) { m_DrawPos = pos; }
	// 获取绘制的位置
	POINT GetDrawPos() { return m_DrawPos; }
	// 设置孩子绘制器
	CDrawCell * SetChildCell(CDrawCell * cell) { m_ChildCell = cell; return m_ChildCell; }
	// 获取孩子绘制器
	CDrawCell * GetChileCell() { return m_ChildCell; }

protected:
	POINT m_DrawPos;				// 绘制的位置
	CDrawCell *		m_ChildCell;	// 孩子绘制器
private:
};

// 简单的绘制图形，如矩形，圆角矩形，椭圆(圆)等
// 这个类定义了这类图形的共有属性
// 目的是为了减少代码分散
class CSimpleShape :public CDrawCell
{
public:
	CSimpleShape()
	{
		m_FillStyle.style = BS_SOLID;
		m_FillStyle.hatch = NULL;
		m_FillStyle.ppattern = 0;
		m_LineStyle.style = PS_SOLID;
		m_LineStyle.thickness = 1;
		m_LineStyle.puserstyle = nullptr;
		m_LineStyle.userstylecount = 0;
		m_bFill = true;
	}
	virtual ~CSimpleShape() {}

	CSimpleShape * Fill(bool Fill) { m_bFill = Fill; return this; }
	bool GetFill() { return m_bFill; }
	CSimpleShape * LineColor(COLORREF color) { m_LineColor = color; return this; }
	COLORREF GetLineColor() { return m_LineColor; }
	CSimpleShape * FillColor(COLORREF color) { m_FillColor = color; return this; }
	COLORREF GetFillColor() { return m_FillColor; }
	CSimpleShape * LineStyle(const LINESTYLE & style) { m_LineStyle = style; return this; }
	CSimpleShape * LineStyle(DWORD style) { m_LineStyle.style = style; return this; }
	CSimpleShape * LineThickness(int thickness) { m_LineStyle.thickness = thickness; return this; }
	LINESTYLE * GetLineStyle() { return &m_LineStyle; }
	CSimpleShape * FillStyle(const FILLSTYLE & style) { m_FillStyle = style; return this; }
	CSimpleShape * FillStyle(int style) { m_FillStyle.style = style; return this; }
	FILLSTYLE * GetFillStyle() { return &m_FillStyle; }

protected:
	bool		m_bFill;		// 是否填充
	COLORREF	m_LineColor;	// 线条颜色
	COLORREF	m_FillColor;	// 填充颜色
	LINESTYLE	m_LineStyle;	// 线条类型
	FILLSTYLE	m_FillStyle;	// 填充类型

	void UseAttribute()			// 应用属性(应用颜色和填充属性)
	{
		setlinecolor(m_LineColor);
		setfillcolor(m_FillColor);
		setlinestyle(&m_LineStyle);
		setfillstyle(&m_FillStyle);
	}
private:

};

// 拥有大小的类
// 同样是为了减少代码分散
class CHaveSize
{
public:
	CHaveSize() {}
	virtual ~CHaveSize() {}

	void SetWidth(int width) { m_iWidth = width; }
	int GetWidth() { return m_iWidth; }
	void SetHeight(int height) { m_iHeight = height; }
	int GetHeight() { return m_iHeight; }
protected:
	int			m_iWidth;		// 宽度
	int			m_iHeight;		// 高度
private:
};

// 画圆类
class CCircle :
	public CSimpleShape
{
public:
	CCircle(POINT pos = { 0, 0 }, int radius = 0, COLORREF lineColor = WHITE, COLORREF fillColor = WHITE);
	~CCircle();

	void SetRadius(int round) { m_iRadius = round; }
	int GetRadius() { return m_iRadius; }

	void Draw();
protected:

private:
	int m_iRadius;
};

// 绘制椭圆类
class CEllipse :
	public CSimpleShape,
	public CHaveSize
{
public:
	CEllipse(POINT pos = { 0, 0 }, int width = 0, int height = 0, COLORREF lineColor = WHITE, COLORREF fillColor = WHITE);
	~CEllipse();


	void Draw();

protected:

private:
};

// 绘制一个矩形
class CRect :
	public CSimpleShape,
	public CHaveSize
{
public:
	CRect(POINT pos = { 0, 0 }, int width = 0, int height = 0, COLORREF lineColor = WHITE, COLORREF fillColor = WHITE);
	~CRect();


	void Draw();

protected:


private:
};

// 绘制圆角矩形的类
class CRoundRect :
	public CSimpleShape,
	public CHaveSize
{
public:
	CRoundRect(POINT pos = { 0, 0 }, int width = 0, int height = 0,
		int roundWidth = 0, int roundHeight = 0, COLORREF lineColor = WHITE, COLORREF fillColor = WHITE);
	~CRoundRect();

	void SetRoundWidth(int width) { m_iRoundWidth = width; }
	int GetRoundWidth() { return m_iRoundWidth; }
	void SetRoundHeight(int height) { m_iRoundHeight = height; }
	int GetRoundHeight() { return m_iRoundHeight; }

	void Draw();

protected:

private:
	int			m_iRoundWidth;	// 圆角宽度
	int			m_iRoundHeight;	// 圆角高度

};

// 文本输出类
class CText :
	public CDrawCell
{
public:
	CText(POINT pos = { 0, 0 }, std::wstring text = L"") { m_strText = text; m_DrawPos = pos; }
	~CText();
	void SetText(std::wstring text) { m_strText = text; }
	std::wstring & GetText() { return m_strText; }

	void Draw();

protected:

private:
	std::wstring m_strText;

};

// 图片绘制类，为了区别于 easyx 的 Image 类
class CUIImage :
	public CDrawCell,
	public CHaveSize
{
public:
	CUIImage(IMAGE * image = nullptr, IMAGE * mask = nullptr);
	~CUIImage();

	void CompareImageSize() { if (!m_pImage) return; m_iHeight = m_pImage->getheight(); m_iWidth = m_pImage->getwidth(); }
	void SetImage(IMAGE * image, bool destroyOld = true) { if (m_pImage && destroyOld) delete m_pImage; m_pImage = image; }
	void SetImage(LPCTSTR Address, bool destroyOld = true) { if (m_pImage && destroyOld) delete m_pImage; m_pImage = new IMAGE; loadimage(m_pImage, Address); }
	IMAGE * GetImage() { return m_pImage; }
	void SetMask(IMAGE * mask, bool apllyImage, bool destroyOld = true);
	IMAGE * GetMask() { return m_pMask; }

	// 这个函数用于生成一个简单几何图形的遮罩区域来用于裁剪图片
	// 这个函数会从左上角开始，依照绘制单元的绘制模式，剪裁绘制图片的形状
	// filp：是否使用反向剪裁，
	// 比如：勾选-从图片中抠出不画的圆形区域
	// 		不勾-只绘制圆形区域内的图片
	void CreatMask(CSimpleShape * shape, bool flip = false);

	void Draw();

protected:

private:
	IMAGE * m_pImage;		// 绘制的图片
	IMAGE * m_pMask;		// 遮罩图

};

#pragma endregion 绘制单元


#pragma region 触发器

// 触发器类，所有触发器的基类
class CTrigger
{
public:
	CTrigger();
	virtual ~CTrigger();

	virtual bool PtInTrigger(POINT point) = 0;
	void SetTriggerPos(POINT pos) { m_TriggerPos = pos; }
	POINT GetTriggerPos() { return m_TriggerPos; }

protected:
	POINT	m_TriggerPos;	// 触发器的位置

private:
};

// 圆形触发器
class CCircleTrigger :
	public CTrigger
{
public:
	CCircleTrigger(int Radius = 0) { m_iRadius = Radius; }
	~CCircleTrigger();
	bool PtInTrigger(POINT point);
	void SetRadius(int radius) { m_iRadius = radius; }
	int GetRadius() { return m_iRadius; }
protected:

private:
	int m_iRadius;	// 半径
};

// 使用遮罩图来确定是否响应事件的类
// 使用黑白图片，白色为响应，黑色为不响应
class CMaskTrigger :
	public CTrigger
{
public:
	CMaskTrigger(int width, int height, IMAGE * mask = nullptr) { m_iWidth = width; m_iHeight = height; m_pMask = mask; }
	~CMaskTrigger();

	void SetMask(IMAGE * mask) { m_pMask = mask; }
	IMAGE * GetMask() { return m_pMask; }
	void SetWidth(int width) { m_iWidth = width; }
	int GetWidth() { return m_iWidth; }
	void SetHeight(int height) { m_iHeight = height; }
	int GetHeight() { return m_iHeight; }

	// 这个函数用于生成一个简单几何图形的遮罩区域来用于判断是否触发事件
	// filp：是否使用反向剪裁，
	// 比如：勾选-从矩形中扣出来不响应的圆形区域
	// 		不勾-响应圆形区域内的事件
	void CreatMask(CSimpleShape * shape, bool flip = false);

	bool PtInTrigger(POINT point);

protected:

private:
	IMAGE *		m_pMask;	// 遮罩图
	int			m_iWidth;	// 宽度
	int			m_iHeight;	// 高度
	RECT m_rectRc;	// 矩形
};

// 矩形触发器
class CRectTrigger :
	public CTrigger
{
public:
	CRectTrigger(int width = 0, int height = 0) { m_iWidth = width; m_iHeight = height; }
	~CRectTrigger();

	void SetWidth(int width) { m_iWidth = width; }
	int GetWidth() { return m_iWidth; }
	void SetHeight(int height) { m_iHeight = height; }
	int GetHeight() { return m_iHeight; }

	bool PtInTrigger(POINT point);

protected:

private:
	int m_iWidth;	// 宽度
	int m_iHeight;	// 高度
	RECT m_rectRc;	// 矩形
};

#pragma endregion 触发器


#pragma region 控件

// UI 元件类，一切 UI 控件的基类，定义了所有 UI 的基本属性
// 所有的 UI 采用树的结构存储
class CGUIElement
{
public:
	CGUIElement(EUIElement type);
	virtual ~CGUIElement();

	EUIElement GetUIType() { return m_eUIType; }
	void SetUIPos(POINT pos) { m_UIPos = pos; }
	POINT GetUIPos() { return m_UIPos; }
	void SetUIActive(bool active) { m_bActive = active; }
	bool GetUIActive() { return m_bActive; }
	void SetUIEventable(bool eventable) { m_bEventable = eventable; }
	bool GetUIEventable() { return m_bEventable; }
	void SetLayer(int layer) { m_iLayer = layer; }
	int GetLayer() { return m_iLayer; }

	virtual void Draw() = 0;
	virtual void OnEvent(EUIEvent event, LPARAM Param) = 0;

protected:

	EUIElement		m_eUIType;		// UI 类型
	POINT			m_UIPos;		// UI 的位置
	bool			m_bActive;		// UI 是否被启用
	bool			m_bEventable;	// UI 是否可以响应事件
	int				m_iLayer;		// UI 的层级
private:
};

// 按钮控件
class CButton :
	public CGUIElement
{
public:
	CButton();
	~CButton();

	void Draw();
	void OnEvent(EUIEvent event, LPARAM Param);
	CDrawCell * GetNormal() { return m_pNormal; }
	CButton * Normal(CDrawCell * style) { m_pNormal = style; return this; }
	CDrawCell * GetDown() { return m_pDown; }
	CButton * Down(CDrawCell * style) { m_pDown = style; return this; }
	CDrawCell * GetMouseIn() { return m_pMouseIn; }
	CButton * MouseIn(CDrawCell * style) { m_pMouseIn = style; return this; }
	CTrigger * GetTrigger() { return m_pTrigger; }
	CButton * Trigger(CTrigger * trigger) { m_pTrigger = trigger; return this; }
	CButton * CallBack(std::function<void(void)> callback) { m_pCallBack = callback; return this; }

protected:

private:
	bool		m_bPressed;	// 被按下
	bool		m_bMouseIn;	// 鼠标在控件内
	CDrawCell * m_pNormal;	// 普通情况下的按钮风格
	CDrawCell * m_pDown;	// 按下状态下的按钮风格
	CDrawCell * m_pMouseIn;	// 鼠标在内情况下的按钮风格
	CTrigger *	m_pTrigger;	// 触发器
	std::function<void(void)>	m_pCallBack;	// 回调函数
};

// 选择框控件
class CCheckBox :
	public CGUIElement
{
public:
	CCheckBox();
	~CCheckBox();

	void Draw();
	void OnEvent(EUIEvent event, LPARAM Param);

	CCheckBox * BackBox(CDrawCell * cell) { m_pBackBox = cell; return this; }
	CDrawCell * GetBackBox() { return m_pBackBox; }
	CCheckBox * Checked(CDrawCell * cell) { m_pChecked = cell; return this; }
	CDrawCell * GetChecked() { return m_pChecked; }
	CCheckBox * Trigger(CTrigger * trigger) { m_pTrigger = trigger; return this; }
	CTrigger * GetTrigger() { return m_pTrigger; }
	CCheckBox *	OnValueChange(std::function<void(bool)> callBack) { m_pCallBack = callBack; return this; }

	void SetValue(bool value) { m_bSelected = value; if (m_pCallBack) m_pCallBack(value); }
	bool GetValue() { return m_bSelected; }

protected:
private:
	CDrawCell *		m_pBackBox;		// 选项框背景
	CDrawCell *		m_pChecked;		// 选择后的
	CTrigger *		m_pTrigger;		// 触发器
	bool			m_bSelected;	// 是否被选中
	std::function<void(bool)>	m_pCallBack;	// 回调函数
};

// 拖动条控件
class CDragBar :
	public CGUIElement
{
public:
	CDragBar();
	~CDragBar();

	void Draw();
	void OnEvent(EUIEvent event, LPARAM Param);

	CDragBar * BlockCenter(POINT pos) { m_BlockCenter = pos; return this; }
	CDragBar * LineSize(POINT size) { m_LineSize = size; return this; }
	CDragBar * Block(CDrawCell * block) { m_pDragBlock = block; return this; }
	CDragBar * Line(CDrawCell * line) { m_pDragLine = line; return this; }
	CDragBar * BlockTrigger(CTrigger * trigger) { m_pBlockTrigger = trigger; return this; }
	CDragBar * LineTrigger(CTrigger * trigger) { m_pLineTrigger = trigger; return this; }
	CDragBar * OnValueChange(std::function<void(float)> callBack) { m_pCallBack = callBack; return this; }
	CDragBar * OnExit(std::function<void(float)> callBack) { m_pCallBackExit = callBack; return this; }

	CDrawCell * GetBlock() { return m_pDragBlock; }
	CDrawCell * GetLine() { return m_pDragLine; }

	void SetValue(float value) { m_fValue = value; }
	float GetValue() { return m_fValue; }

protected:
private:
	std::function<void(float)>	m_pCallBack;	// 回调函数
	std::function<void(float)>	m_pCallBackExit;	// 回调函数

	CDrawCell *		m_pDragBlock;		// 拖动块
	CDrawCell *		m_pDragLine;		// 拖动条背后的线
	CTrigger *		m_pBlockTrigger;	// 拖动块的触发器
	CTrigger *		m_pLineTrigger;		// 线的触发器
	float			m_fValue;			// 拖动条的值
	POINT			m_LineSize;			// 拖动条的大小
	POINT			m_BlockCenter;		// 拖动块的中心点
	bool			m_bPressed;			// 被点击
};

// 输入框控件
class CInputTextBox :
	public CGUIElement
{
public:
	CInputTextBox();
	~CInputTextBox();

	void Draw();
	void OnEvent(EUIEvent event, LPARAM Param);

	std::wstring GetText();
	void SetText(std::wstring text);

	void SetWidth(int width) { m_iWidth = width; }
	int GetWidth() { return m_iWidth; }
	void SetHeight(int height) { m_iHeight = height; }
	int GetHeight() { return m_iHeight; }

	CInputTextBox * CursorColor(COLORREF color) { m_pCursor->LineColor(color); m_pCursor->FillColor(color); return this; }
	CInputTextBox * XSpace(int space) { m_iXSpace = space; return this; }
	CInputTextBox * YSpace(int space) { m_iYSpace = space; return this; }
	CInputTextBox * BackBox(CRect * rect);
	CInputTextBox * BackBox(CRoundRect * roundRc);
	CInputTextBox * Trigger(CTrigger * trigger) { if (m_pTrigger) delete m_pTrigger; m_pTrigger = trigger; return this; }
	CInputTextBox * OnValueChange(std::function<void(std::wstring)> callBack) { m_pCallBack = callBack; return this; }
	CInputTextBox * OnExit(std::function<void(std::wstring)> callBack) { m_pCallBackExit = callBack; return this; }
	CDrawCell * GetBackBox() { return m_pBackBox; }

protected:
private:
	int				m_iWidth;		// 宽度
	int				m_iHeight;		// 高度
	int				m_iXSpace;		// 水平空格
	int				m_iYSpace;		// 垂直空格
	CDrawCell *		m_pBackBox;		// 背景盒
	CRect *			m_pCursor;		// 光标
	CText *			m_strText;		// 文本
	CTrigger *		m_pTrigger;		// 触发器

	std::function<void(std::wstring)>	m_pCallBack;		// 回调函数
	std::function<void(std::wstring)>	m_pCallBackExit;	// 回调函数
	int				m_lastChangeTime;	// 上次光标切换状态的时间
	bool			m_bPressed;			// 是否被选中
	bool			m_bShowCursor;		// 是否显示光标

};

// 进度条控件
class CPreBar :
	public CGUIElement
{
public:
	CPreBar();
	~CPreBar();

	void Draw();
	void OnEvent(EUIEvent event, LPARAM Param) {}

	void SetValue(float value) { m_fValue = value; if (m_fValue >= 1) m_fValue = 1; if (m_fValue <= 0)m_fValue = 0; }	// 设置进度条的值
	float GetValue() { return m_fValue; }

	CPreBar * Background(CRoundRect * back) { m_pBackground = back; return this; }
	CPreBar * Background(CRect * back) { m_pBackground = back; return this; }
	CSimpleShape * GetBackground() { return m_pBackground; }
	CPreBar * Mask(CRoundRect * mask) { m_pMask = mask; return this; }
	CPreBar * Mask(CRect * mask) { m_pMask = mask; return this; }
	CPreBar * Padding(POINT padding) { m_Padding = padding; return this; }
	POINT GetPadding() { return m_Padding; }
	CSimpleShape * GetMask() { return m_pMask; }

protected:
private:
	CSimpleShape *	m_pBackground;	// 背景条
	CSimpleShape *	m_pMask;		// 覆盖条
	float			m_fValue;		// 进度条的值
	POINT			m_Padding;		// 内边距
};

// 静态 UI 控件
class CStaticUI :
	public CGUIElement
{
public:
	CStaticUI();
	~CStaticUI();


	void Draw();
	void OnEvent(EUIEvent event, LPARAM Param) {}
	CStaticUI * DrawCell(CDrawCell * drawcell) { m_pDrawCell = drawcell; return this; }
	CDrawCell * GetDrawCell() { return m_pDrawCell; }

protected:
private:
	CDrawCell *		m_pDrawCell;		// 绘制单元

};

#pragma endregion 控件

// UI 管理类
class CUIManager
{

	static CUIManager * Instance;
	CUIManager();
public:
	~CUIManager();
	static CUIManager * GetInstance() { if (!Instance) Instance = new CUIManager; return Instance; }

	void Draw();			// 绘制
	void ProcessEvent();	// 处理事件
	void AddUIElement(std::wstring name, CGUIElement * element) {
		m_allUIElement[name] = element;
	}	  // 添加 UI 控件
	CGUIElement * GetUIElement(std::wstring name);	// 获取 UI 控件

protected:

private:
	std::map<std::wstring, CGUIElement*>			m_allUIElement;	// 保存所有的 UI
	std::multimap<int, CGUIElement *>	m_mapDrawSort;				// 用于绘制排序
};
