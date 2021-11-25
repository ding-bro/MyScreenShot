#pragma once

#include "CAbstract.h"
#include "CCanvas.h"
#include "CScreenShot.h"

class CQThreadCilck : public QObject
{
Q_OBJECT

public:
	CQThreadCilck(QThread* pThread);
	~CQThreadCilck() {}

	void InitConnect();

signals:
	void signThreadQuit();
	void signDialogSave(CCanvas* pCanvas, COptionBox* pOption,QPixmap& qPixmap);

public slots:
	void slotDownLoad(CCanvas* pCanvas,COptionBox* pOption,QPixmap& qPixmap);
	void slotThreadQuit();

public:
	QThread* m_pThread;
};

