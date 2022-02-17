#include <graphics.h>
#include <conio.h>
#include <functional>
#include "EasyUI.h"

// !!!!!所有带有 * 的都是必填参数
// 一般来说，组件的绘制单元和响应器以及位置都是必填
// 
// 关于绑定类中的回调函数的方法
// 先包含头文件 functional
// 通常使用 std::bind() 函数实现
// 参数意义如下
// bind(函数指针(&[类名]::[函数名]), 类指针, 参数位置)
// 参数位置一般用 std::placeholders::_x 来表示，x 是一个数字，表示是第几个参数，一般会按照顺序写下去
// 示例中有一些地方使用了这种方式，可以作为参考
// 
// 关于 UI 的名字，名字是 UI 的唯一标识，不可以重复

// 产生一个消息窗口
void Message()
{
	MessageBox(nullptr, L"按钮点击", L"消息", MB_OK);
}
// 输出一条字符串
void MessageStr(std::wstring message)
{
	MessageBox(nullptr, message.c_str(), L"消息", MB_OK);
}
// 输出一个浮点数
void MessageFloat(float value)
{
	wchar_t str[20];
	swprintf_s(str, L"%f", value);
	MessageBox(nullptr, str, L"消息", MB_OK);
}

// 生成一个静态UI的示例
void StaticUI()
{
	CUIImage * image = new CUIImage();		// 生成一张 UI 图
	IMAGE *maskImage = new IMAGE;			// 遮罩图
	loadimage(maskImage, L"mask.png");		// 加载遮罩图
	image->SetDrawPos({ 0, 0 });			// *设置绘制位置
	image->SetImage(L"test.jpg");			// 加载一张图片，也可以选择自己加载图片并传入指针
	image->SetMask(maskImage, true);		// 设置一张遮罩图，并对原图进行抠图，(如果设置为 false，则不抠)
	image->CompareImageSize();				// *适配图片的大小，图片支持缩放，但是不推荐使用(图片质量损失极大)
	image->SetChildCell(new CText({ 270, 130 }));		// 设置一个孩子控件，这个控件在输入框时被使用

	CStaticUI * staticUI = new CStaticUI();
	staticUI->DrawCell(image)				// *设置静态UI的绘制单元
		->SetLayer(-1);						// 设置UI层级，使其在底层显示
	// 添加到UI管理
	CUIManager::GetInstance()->AddUIElement(L"背景图", staticUI);
}

// 生成一个按钮的示例
void Button()
{
	CButton *button = new CButton;
	button->SetUIPos({ 50, 50 });			// *设置按钮的位置
	button->Normal(new CEllipse({ 50, 50 }, 100, 40, RED, BLUE))	// *设置普通状态下的样式
		->MouseIn(new CEllipse({ 50, 50 }, 100, 40, RED, RED))		// *设置鼠标进入后的样式
		->Down(new CEllipse({ 50, 50 }, 100, 40, RED, RGB(100, 100, 100)))	// *设置鼠标按下后的样式
		->Trigger(new CMaskTrigger(100, 40))						// *设置响应器的样式
		->CallBack(Message);				// 设置按钮按下的回调函数

	// 由于这里使用的是椭圆，所以采用遮罩图的方式响应事件
	// 遮罩图的事件响应是像素级的，非常精准
	// 这里创建了一个椭圆遮罩
	// 图省事把获取遮罩触发器组件和创建椭圆遮罩以及设置遮罩写一起了。。。。。
	// 所以看起来比较恐怖
	((CMaskTrigger*)(button->GetTrigger()))->CreatMask((CSimpleShape*)button->GetNormal());

	// 接下来向按钮内添加了子控件(让按钮内有字，或者别的东西)
	button->GetNormal()													// 获取普通状态下的绘制单元
		->SetChildCell(new CRect({ 80, 60 }, 40, 20, YELLOW, BLACK))	// 加入一个矩形绘制
		->SetChildCell(new CText({ 83, 63 }, L"START"));					// 可以连续使用这个函数添加
	button->GetDown()
		->SetChildCell(new CText({ 83, 63 }, L"START"));

	// 最后把按钮加入 UI 管理器中参与响应，大功告成
	// 所有UI都由UI管理器来维护和销毁
	// 相当于使用者设计 UI，然后交给 UI 管理器
	// 所以无需担心内存泄漏
	CUIManager::GetInstance()->AddUIElement(L"按钮", button);
}

// 生成一个输入框的示例
void InputTextBox()
{
	CInputTextBox * inputbox = new CInputTextBox();
	// 这句长的过分，可以当指针考试题了=-=，总之就是获取到在创建背景 UI 时添加的孩子(文本)
	CText * text = (CText *)((CStaticUI*)(CUIManager::GetInstance()->GetUIElement(L"背景图")))->GetDrawCell()->GetChileCell();

	inputbox->SetUIPos({ 50, 120 });	// *设置输入框位置
	inputbox->XSpace(7)->YSpace(8)		// 设置水平和垂直间距
		->BackBox(new CRoundRect({ 0, 0 }, 200, 35, 9, 9, RED, BLUE))	// *添加一个背景框
		->Trigger(new CRectTrigger(200, 35))		// *设置一个响应器
		->CursorColor(YELLOW)			// 设置光标的颜色
		->OnValueChange(std::bind(&CText::SetText, text, std::placeholders::_1))	// 设置当输入框值改变的时候调用的函数
		->OnExit(MessageStr);			// 设置当文本框离开焦点的时候调用的函数

	// 添加到UI管理
	CUIManager::GetInstance()->AddUIElement(L"输入框", inputbox);
}

// 生成一个进度条的示例
void PreBar()
{
	CPreBar * preBar = new CPreBar();
	preBar->SetUIPos({ 50, 190 });					// *设置 UI 位置
	preBar->Background(new CRoundRect({ 0, 0 }, 380, 20, 6, 6, YELLOW, RGB(190, 190, 190)))	// *设置背景框
		->Mask(new CRoundRect({ 0, 0 }, 200, 20, 3, 3, GREEN, GREEN))						// *设置遮罩框
		->Padding({ 3, 3 });						// 设置内边距

	preBar->GetBackground()->LineThickness(3);		// 设置外部框粗细

	// 添加到UI管理
	CUIManager::GetInstance()->AddUIElement(L"进度条", preBar);
}

// 生成一个拖动条的示例
void DragBar()
{
	CDragBar *bar = new CDragBar();

	CPreBar * preBar = (CPreBar *)CUIManager::GetInstance()->GetUIElement(L"进度条");	// 从管理类中取出进度条

	bar->SetUIPos({ 50, 250 });						// *设置UI的位置
	bar->Block(new CCircle({ 0, 0 }, 9, RED, RGB(150, 150, 150)))		// *设置拖动块
		->BlockTrigger(new CCircleTrigger(9))		// *设置拖动块的触发器
		->BlockCenter({ 0, 0 })						// *设置拖动块的中心，这里圆是特殊的，因为它是从中心绘制的，别的图像都从左上角开始绘制
		->Line(new CRoundRect({ 0, 0 }, 250, 6, 3, 3, RED, BLUE))		// *设置背景条
		->LineTrigger(new CRectTrigger(250, 6))		// *设置背景条的触发器
		->LineSize({ 250, 6 })						// *设置背景条的尺寸
		->OnValueChange(std::bind(&CPreBar::SetValue, preBar, std::placeholders::_1))		// 设置数值改变的时候的回调
		->OnExit(MessageFloat);						// 设置退出的时候的回调函数
	
	// 添加到UI管理
	CUIManager::GetInstance()->AddUIElement(L"拖动条", bar);
}

// 生成一个选择框的示例
void CheckBox()
{
	CGUIElement * element = CUIManager::GetInstance()->GetUIElement(L"背景图");
	CCheckBox * checkBox = new CCheckBox;

	checkBox->SetUIPos({ 50, 300 });		// *设置 UI 的位置
	checkBox->BackBox(new CCircle({ 50, 300 }, 8, RGB(100, 100, 100), RGB(200, 200, 200)))		// *设置背景盒子
		->Checked(new CCircle({ 50, 300 }, 6, RGB(40, 40, 40), RGB(40, 40, 40)))				// *设置选中后显示的
		->Trigger(new CCircleTrigger(8))	// *设置响应器
		->OnValueChange(std::bind(&CGUIElement::SetUIActive, element, std::placeholders::_1))	// 设置回调函数
		->SetValue(true);					// 设置状态为选中

	// 添加到 UI 管理
	CUIManager::GetInstance()->AddUIElement(L"选项框", checkBox);
}


int main(void)
{
	unsigned int curTime, preTime;
	curTime = preTime = GetTickCount();
	initgraph(640, 640);
	setbkcolor(RGB(80, 80, 80));
	setbkmode(TRANSPARENT);
	BeginBatchDraw();

	// 运行示例
	StaticUI();
	Button();
	InputTextBox();
	PreBar();
	DragBar();
	CheckBox();

	// 必须建立一个循环来响应 UI 事件哦
	while (true)
	{
		curTime = GetTickCount();
		if (curTime - preTime >= 16)
		{
			cleardevice();
			CUIManager::GetInstance()->Draw();			// 绘制
			CUIManager::GetInstance()->ProcessEvent();	// 响应事件
			FlushBatchDraw();
			preTime = curTime;
		}
		else
			Sleep(1);
	}

	_getch();
	delete CUIManager::GetInstance();	// 别忘了释放空间
	EndBatchDraw();
	closegraph();
	return 0;
}
