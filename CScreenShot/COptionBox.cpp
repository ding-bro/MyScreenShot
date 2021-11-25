#include "COptionBox.h"
#include "CScreenShot.h"

COptionBox::COptionBox(QPoint qPoint)
{
	this->m_qPointWidgetPos = qPoint;

	InitUiQss();

	InitConnect();
}

COptionBox::~COptionBox()
{

}

void COptionBox::InitUiQss()
{
	this->setFixedSize(500, 40);
	this->move(this->m_qPointWidgetPos);

	// 无窗口标题 | Qt::Tool 保持窗口始终在前，但是不阻塞父窗口，同时也可以与父窗口交互
	//this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Tool);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint); 

	this->setStyleSheet("QWidget{background-color: white}");

	// 水平布局
	QHBoxLayout* pBoxLay = new QHBoxLayout(this);

	pBoxLay->setContentsMargins(5,0,5,0);
	pBoxLay->setSpacing(5);

	this->m_pBtnRect = new QPushButton;
	setButtonStyle(this->m_pBtnRect,QSize(50, 50) ,"RectAngle");
	pBoxLay->addWidget(this->m_pBtnRect);

	this->m_pBtnCircle = new QPushButton;
	setButtonStyle(this->m_pBtnCircle, QSize(50, 50), "Circle");
	pBoxLay->addWidget(this->m_pBtnCircle);

	this->m_pBtnBrushPen = new QPushButton;
	setButtonStyle(this->m_pBtnBrushPen, QSize(50, 50), "BrushPen");
	pBoxLay->addWidget(this->m_pBtnBrushPen);
	
	this->m_pBtnLine = new QPushButton;
	setButtonStyle(this->m_pBtnLine, QSize(50, 50), "Line");
	pBoxLay->addWidget(this->m_pBtnLine);;

	this->m_pBtnText = new QPushButton;
	setButtonStyle(this->m_pBtnText, QSize(50, 50), "Text");
	pBoxLay->addWidget(this->m_pBtnText);

	this->m_pBtnForward = new QPushButton;
	setButtonStyle(this->m_pBtnForward, QSize(50, 50), "Forward");
	pBoxLay->addWidget(this->m_pBtnForward);

	this->m_pBtnDownLoad = new QPushButton;
	setButtonStyle(this->m_pBtnDownLoad, QSize(50, 50), "DownLoad");
	pBoxLay->addWidget(this->m_pBtnDownLoad);

	this->m_pBtnQuit = new QPushButton;
	setButtonStyle(this->m_pBtnQuit, QSize(50, 50), "Quit");
	pBoxLay->addWidget(this->m_pBtnQuit);

	this->m_pBtnDone = new QPushButton;
	setButtonStyle(this->m_pBtnDone, QSize(50, 50), "Done");
	pBoxLay->addWidget(this->m_pBtnDone);
}

void COptionBox::InitConnect()
{
	connect(this,&COptionBox::signShapeType,ex_pshCanvas.get(),&CCanvas::slotShapeType);

	// 矩形
	connect(this->m_pBtnRect, &QPushButton::clicked, [=] {
		emit signShapeType(RectType);
		CreateSetpenShow(); // 显示选择框
	});

	// 圆形
	connect(this->m_pBtnCircle, &QPushButton::clicked, [=] {
		emit signShapeType(CircleType);
		CreateSetpenShow();
	});

	// 笔
	connect(this->m_pBtnBrushPen, &QPushButton::clicked, [=] {
		emit signShapeType(LineType);
		CreateSetpenShow();
	});

	// 箭头
	connect(this->m_pBtnLine, &QPushButton::clicked, [=] {
		emit signShapeType(ArrowType);
		CreateSetpenShow();
	});

	// 文字
	connect(this->m_pBtnText, &QPushButton::clicked, [=] {
		emit signShapeType(TextType);
		CreateSetpenShow();
	});

	// 保存
	connect(this->m_pBtnDownLoad, &QPushButton::clicked, [=] {
		emit signDownLoad();
	});

	// 退出
	connect(this->m_pBtnQuit, &QPushButton::clicked, [=] {
		this->close();
		emit signQuit();
	});

	// 完成
	connect(this->m_pBtnDone, &QPushButton::clicked, [=] {
		this->close();
		emit signDone();
	});
}

void COptionBox::CreateSetpenShow()
{
	this->m_qPointPress = this->m_pBtnRect->mapToGlobal(this->m_pBtnRect->pos()); // 将此控件对于窗口的位置转换为全局位置
	this->m_punSetpen = std::make_unique<CSetPen>(this->m_qPointPress); // 显示画笔颜色选择框
	this->m_punSetpen->show();
}

void COptionBox::setButtonStyle(QPushButton* pButton,QSize& qSize,QString qstrImage)
{
	QString qstrStyle(
		"QPushButton\
		{\
			background-image: url(:/Source/***.png);\
			background-repeat: no-repeat;\
			background-position: top;\
			border: none;\
		}\
		QPushButton:hover\
		{\
			background-image: url(:/Source/***-hover.png);\
			background-repeat: no-repeat;\
			background-position: top;\
			border: none;\
		}"
	);

	qstrStyle.replace("***", qstrImage);

	pButton->setObjectName("NoEvent");
	pButton->setFixedSize(qSize);
	pButton->setStyleSheet(qstrStyle);
}
