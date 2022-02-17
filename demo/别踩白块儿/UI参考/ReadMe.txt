EasyUI 类构成指南

EasyUI 将 UI 拆分成了两个部分--绘制单元和事件触发器。
使用者可以使用绘制单元来控制 UI 的风格，同时选择一定的事件触发器来使 UI 具备响应事件的功能。

绘制单元：
    -CDrawCell：所有绘制单元的基类
    -CSimpleShape：继承自 CDrawCell，集成了通过 EasyX 图形绘制函数绘制的图形属性
    -CHaveSize：所有拥有大小的类的基类
    -CRect：继承自 CSimpleShape，绘制一个矩形
    -CRoundRect：继承自 CSimpleShape，绘制一个圆角矩形
    -CCircle：继承自 CSimpleShape，绘制一个圆形，并以绘制位置为中心(所有绘制单元都从左上角画起，除了圆)
    -CEllipse：继承自 CSimpleShap，绘制一个椭圆（通过外接矩形）
    -CText：继承自 CDrawCell，输出一串字符串
    -CUIImage：继承自 CDrawCell，绘制一张图片

触发器：
    -CTrigger：所有触发器的基类
    -CRectTrigger：矩形触发器
    -CCircleTrigger：圆形触发器(同样是特殊的，以圆心为位置中心)
    -CMaskTrigger：遮罩图触发器，通过像素级的判断，实现精准的位置判断(对 png 支持并不好)

控件：
    -CGUIElement：所有 UI 的基类
    -CStaticUI：静态 UI，拥有 1 个风格，不存在事件响应
    -CButton：按钮组件，拥有 3 种状态下的风格，以及 1 个触发器，通过回调函数执行点击事件，绘制器的位置不随按钮位置改变（考虑到按钮的风格定制）
    -CInputTextBox：输入框组件，拥有 1 个输入框背景的风格定制，以及 1 个触发器，可以设置 1 个当值改变时执行的函数和 1 个当退出焦点时执行的函数
    -CDragBar：拖动条组件，拥有拖动块和背景条 2 个风格定制，以及同样的 2 个触发器，支持值改变时和松开时执行的函数，值范围 0-1
    -CPreBar：进度条组件，拥有覆盖条和背景框 2 个风格定制，不支持事件响应，值范围 0-1
    -CCheckBox：选项框组件，拥有选择后显示的内容和背景框 2 个风格定制，支持值改变的时候执行的函数

Tips：
    -如何构建一个复杂的绘制单元（如矩形内包含圆形再包含图片，文字）？
        通过 CDrawCell 的 SetChildCell，添加子单元，子单元将在覆盖再父单元上绘制，理论上可以设置无数层子单元。
    -如何扩展绘制单元风格？
        继承 CDrawCell 即可，需要注意的是，必须根据单元的位置进行绘制，并且写好子单元绘制来支持子单元。
    -示例中没用到的功能：CreateMask(CSimpleShape*,bool):
        使用图形简单的抠图，并可以实现反向剪裁，需要注意的是，传入的绘制单元的位置是相对于图片左上角的位置。