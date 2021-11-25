#pragma once

#include "CAbstract.h"

#define ASSIGNTHICKNESS(VALUE)\
{\
	m_Pentype.ePenThickness = VALUE;\
}

#define ASSIGNCOLOR(VALUE)\
{\
	m_Pentype.ePenColor = VALUE;\
}

enum PenThickness
{
	SmallPen = 1,
	MediumPen = 3,
	BigPen = 5
};

enum PenColor
{
	Red,
	Yellow,
	Blue,
	Green,
	Black,
	White,
};

enum ButtonType
{
	Thickness,
	Color,
	AllType
};

struct SPenType
{
	PenThickness ePenThickness;
	PenColor ePenColor;
};

class CSetPen : public QWidget
{
	Q_OBJECT
public:
	CSetPen(QPoint& qPoint);

	~CSetPen() {}

	void InitWindow(QPoint& qPoint);

	void InitButton(ButtonType btnType);

	void getButtonObject();

	void InitConnect();

	void setClickBlock(QPushButton* pButton,QString qstrImageName);

signals:
	void signPenType(SPenType& sPentype);

public slots:


public:
	QPoint m_qPointPress;

	QPushButton* m_pBtnSmallPen;
	QPushButton* m_pBtnMediumPen;
	QPushButton* m_pBtnBigPen;
	QPushButton* m_pBtnRedRect;
	QPushButton* m_pBtnYellowRect;
	QPushButton* m_pBtnBlueRect;
	QPushButton* m_pBtnGreenRect;
	QPushButton* m_pBtnBlackRect;
	QPushButton* m_pBtnWhiteRect;

	SPenType m_Pentype;
};

