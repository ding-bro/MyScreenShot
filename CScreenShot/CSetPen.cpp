#include "CSetPen.h"
#include "CScreenShot.h"

CSetPen::CSetPen(QPoint& qPoint)
{
	this->m_qPointPress.setX(qPoint.x());
	this->m_qPointPress.setY(qPoint.y() + 50);

	InitWindow(this->m_qPointPress);
	InitButton(AllType);
	InitConnect();

	// 默认选择的是 中笔和红色
	this->m_Pentype.ePenThickness = MediumPen;
	this->m_Pentype.ePenColor = Red;
	emit signPenType(this->m_Pentype);

	setClickBlock(this->m_pBtnMediumPen,"MediumPen");
	setClickBlock(this->m_pBtnRedRect,"RedRect");
}

void CSetPen::InitWindow(QPoint& qPoint)
{
	this->move(qPoint);
	this->setFixedSize(350, 40);

	//this->setWindowFlags(Qt::FramelessWindowHint); // 无框
	//this->setWindowFlags(Qt::CustomizeWindowHint | Qt::Tool);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);

	this->setStyleSheet("QWidget{background-color: white}");
	//this->setAttribute(Qt::WA_TranslucentBackground); // 去透明边框
}

void CSetPen::InitButton(ButtonType btnType)
{
	// 不重复构造按钮，避免按下的常亮状态有错误
	getButtonObject();

	QHBoxLayout* pHBoxLayout = new QHBoxLayout(this);
	pHBoxLayout->setContentsMargins(5, 5, 5, 5);
	pHBoxLayout->setSpacing(5);

	if ((Thickness == btnType) ||(AllType == btnType))
	{
		COptionBox::setButtonStyle(this->m_pBtnSmallPen, QSize(30, 30), "SmallPen");
		COptionBox::setButtonStyle(this->m_pBtnMediumPen, QSize(30, 30), "MediumPen");
		COptionBox::setButtonStyle(this->m_pBtnBigPen, QSize(30, 30), "BigPen");
	}

	if ((Color == btnType) || (AllType == btnType))
	{
		COptionBox::setButtonStyle(this->m_pBtnRedRect, QSize(30, 30), "RedRect");
		COptionBox::setButtonStyle(this->m_pBtnYellowRect, QSize(30, 30), "YellowRect");
		COptionBox::setButtonStyle(this->m_pBtnBlueRect, QSize(30, 30), "BlueRect");
		COptionBox::setButtonStyle(this->m_pBtnGreenRect, QSize(30, 30), "GreenRect");
		COptionBox::setButtonStyle(this->m_pBtnBlackRect, QSize(30, 30), "BlackRect");
		COptionBox::setButtonStyle(this->m_pBtnWhiteRect, QSize(30, 30), "WhiteRect");
	}

	pHBoxLayout->addWidget(this->m_pBtnSmallPen);
	pHBoxLayout->addWidget(this->m_pBtnMediumPen);
	pHBoxLayout->addWidget(this->m_pBtnBigPen);
	pHBoxLayout->addWidget(this->m_pBtnRedRect);
	pHBoxLayout->addWidget(this->m_pBtnYellowRect);
	pHBoxLayout->addWidget(this->m_pBtnBlueRect);
	pHBoxLayout->addWidget(this->m_pBtnGreenRect);
	pHBoxLayout->addWidget(this->m_pBtnBlackRect);
	pHBoxLayout->addWidget(this->m_pBtnWhiteRect);
}

void CSetPen::getButtonObject()
{
	auto qListButton = this->findChildren<QPushButton*>();
	if (qListButton.isEmpty())
	{
		this->m_pBtnSmallPen = new QPushButton;
		this->m_pBtnMediumPen = new QPushButton;
		this->m_pBtnBigPen = new QPushButton;
		this->m_pBtnRedRect = new QPushButton;
		this->m_pBtnYellowRect = new QPushButton;
		this->m_pBtnBlueRect = new QPushButton;
		this->m_pBtnGreenRect = new QPushButton;
		this->m_pBtnBlackRect = new QPushButton;
		this->m_pBtnWhiteRect = new QPushButton;
	}
}

void CSetPen::InitConnect()
{
	connect(this,&CSetPen::signPenType,ex_pshCanvas.get(),&CCanvas::slotPenType);

	connect(this->m_pBtnSmallPen, &QPushButton::clicked, [=] {
		ASSIGNTHICKNESS(SmallPen);
		emit signPenType(this->m_Pentype);

		// 同时重置其他按钮的状态
		InitButton(Thickness);
		setClickBlock(this->m_pBtnSmallPen,"SmallPen");
	});

	connect(this->m_pBtnMediumPen, &QPushButton::clicked, [=] {
		ASSIGNTHICKNESS(MediumPen);
		emit signPenType(this->m_Pentype);
		InitButton(Thickness);
		setClickBlock(this->m_pBtnMediumPen, "MediumPen");
	});

	connect(this->m_pBtnBigPen, &QPushButton::clicked, [=] {
		ASSIGNTHICKNESS(BigPen);
		emit signPenType(this->m_Pentype);
		InitButton(Thickness);
		setClickBlock(this->m_pBtnBigPen, "BigPen");
	});

	connect(this->m_pBtnRedRect, &QPushButton::clicked, [=] {
		ASSIGNCOLOR(Red);
		emit signPenType(this->m_Pentype);
		InitButton(Color);
		setClickBlock(this->m_pBtnRedRect, "RedRect");
	});

	connect(this->m_pBtnYellowRect, &QPushButton::clicked, [=] {
		ASSIGNCOLOR(Yellow);
		emit signPenType(this->m_Pentype);
		InitButton(Color);
		setClickBlock(this->m_pBtnYellowRect, "YellowRect");
	});

	connect(this->m_pBtnBlueRect, &QPushButton::clicked, [=] {
		ASSIGNCOLOR(Blue);
		emit signPenType(this->m_Pentype);
		InitButton(Color);
		setClickBlock(this->m_pBtnBlueRect, "BlueRect");
	});

	connect(this->m_pBtnGreenRect, &QPushButton::clicked, [=] {
		ASSIGNCOLOR(Green);
		emit signPenType(this->m_Pentype);
		InitButton(Color);
		setClickBlock(this->m_pBtnGreenRect, "GreenRect");
	});

	connect(this->m_pBtnBlackRect, &QPushButton::clicked, [=] {
		ASSIGNCOLOR(Black);
		emit signPenType(this->m_Pentype);
		InitButton(Color);
		setClickBlock(this->m_pBtnBlackRect, "BlackRect");
	});

	connect(this->m_pBtnWhiteRect, &QPushButton::clicked, [=] {
		ASSIGNCOLOR(White);
		emit signPenType(this->m_Pentype);
		InitButton(Color);
		setClickBlock(this->m_pBtnWhiteRect, "WhiteRect");
	});
}

void CSetPen::setClickBlock(QPushButton* pButton,QString qstrImageName)
{
	QString qstrStyle(
		"QPushButton\
		{\
			background-image: url(:/Source/***-hover.png);\
			background-repeat: no-repeat;\
			background-position: top;\
			border: none;\
		}"
	);

	qstrStyle.replace("***", qstrImageName);

	pButton->setObjectName("Cicked");
	pButton->setStyleSheet(qstrStyle);
}



