#pragma once

#include "ui_CCanvas.h"
#include "CAbstract.h"
#include "COptionBox.h"
#include <thread>

class CCanvas : public QWidget,public enable_shared_from_this<CCanvas>,public CAbstract
{
	Q_OBJECT

public:
	CCanvas() {}
	CCanvas(QPixmap qPixTemp) : m_qPixmap(qPixTemp) {}

	~CCanvas() 
	{
		if (this->m_punOptionBox)
		{
			this->m_punOptionBox.reset();
		}
	}

	void InitOptionBoxConnect();

	void paintEvent(QPaintEvent* pEvent);
	void mousePressEvent(QMouseEvent* pEvent);
	void mouseMoveEvent(QMouseEvent* pEvent);
	void mouseReleaseEvent(QMouseEvent* pEvent);

	void setScreenBlack();

	void setScreenTransparent(QPainter& qPainter);

	void setPainterPenType(QPainter& qPainter);

	void getCaptureWhiteFrame();

	void drawPaintRect();
	void drawPaintCircle();
	void drawPaintLine();
	void drawPaintArrow();
	void drawArrow(QPainter& qPainter);
	void drawPaintText();

	void CreateTextEditShow();

	bool isMoveWhiteFrame();
	static bool savePixmap(QPixmap& qPixmap, QString qstrPath = "");

	std::shared_ptr<CCanvas>getSharedpointThis() { return shared_from_this(); }

	QPixmap& getScreenmap();

	Qt::GlobalColor getPenColor(SPenType& sPentype);

signals:
	void signMainwindowShow();
	void signDownLoad(CCanvas* pCanvas,COptionBox* pOption ,QPixmap& qPixmap);

public slots:
	void slotFullScreen();
	void slotCanvasClose();
	void slotPenType(SPenType& sPentype);
	void slotShapeType(ShapeType enShapetype);


public:
	QPixmap m_qPixmap;
	QPixmap m_qScreenmap;
	QPixmap m_qCanvasmap;

	QPainterPath m_BlackScreenPainerpath;

	QPoint m_qPointPress;
	QPoint m_qPointMove;
	QPoint m_qPointRelease;
	QPoint m_qPointPainterPress;
	QPoint m_qPointPainterMove;
	QPoint m_qPointPainterRelease;

	QRect m_qRectWhiteFrame;
	
	std::unique_ptr<QTextEdit>m_punTextEdit;
	std::unique_ptr<COptionBox>m_punOptionBox;
	std::shared_ptr<CCanvas>m_pshShared;

	SPenType m_Pentype;
	ShapeType m_Shapetype;

	std::vector<std::unique_ptr<QTextEdit>>m_vctTextEdit;

	bool m_bFirstPress;
	bool m_bLeftMousePress;

public:
	Ui::UiCCanvas ui;
};



