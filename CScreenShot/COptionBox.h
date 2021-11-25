#pragma once

#include "CAbstract.h"
#include "CSetPen.h"

enum ShapeType
{
	RectType,
	CircleType,
	ArrowType,
	LineType,
	TextType
};

class COptionBox : public QWidget
{
	Q_OBJECT
public:
	COptionBox(QPoint qPoint);

	~COptionBox();

	void InitUiQss();

	void InitConnect();

	void CreateSetpenShow();

	static void setButtonStyle(QPushButton* pButton,QSize& qSize,QString qstrImage);
	
signals:
	void signQuit();
	void signDone();
	void signDownLoad();
	void signShapeType(ShapeType enShapetype);

public slots:


public:
	QPoint m_qPointWidgetPos;
	QPoint m_qPointPress;
	
	QPushButton* m_pBtnRect;
	QPushButton* m_pBtnCircle;
	QPushButton* m_pBtnBrushPen;
	QPushButton* m_pBtnDone;
	QPushButton* m_pBtnDownLoad;
	QPushButton* m_pBtnForward;
	QPushButton* m_pBtnLine;
	QPushButton* m_pBtnQuit;
	QPushButton* m_pBtnText;

	std::unique_ptr<CSetPen>m_punSetpen;

	ShapeType m_Shapetype;
};

