#include "CQThreadCilck.h"

CQThreadCilck::CQThreadCilck(QThread* pThread)
{
	this->m_pThread = pThread;
	this->InitConnect();
}

void CQThreadCilck::InitConnect()
{
	connect(this,&CQThreadCilck::signDialogSave,ex_pScreenShot,&CScreenShot::slotDownLoad);
	connect(ex_pScreenShot,&CScreenShot::signThreadQuit,this,&CQThreadCilck::slotThreadQuit);
}

void CQThreadCilck::slotThreadQuit()
{
	this->m_pThread->wait();
	this->m_pThread->quit();
}

void CQThreadCilck::slotDownLoad(CCanvas* pCanvas,COptionBox* pOption,QPixmap& qPixmap)
{
	emit signDialogSave(pCanvas,pOption,qPixmap);
}