//#include "CAbstract.h"
//
//void CAbstract::getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CScreenShot* pScreen, pFunctionScreenShot funcScreen)
//{
//	// ��ͼ�ȼ�
//	if (pShortcut->setShortcut(QKeySequence(strCombineKey)))
//	{
//		QObject::connect(pShortcut, &QxtGlobalShortcut::activated, pScreen, funcScreen);
//	}
//}
//
//void CAbstract::getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CCanvas* pCanvas, pFunctionCanvas funcCanvas)
//{
//	if (pShortcut->setShortcut(QKeySequence(strCombineKey)))
//	{
//		QObject::connect(pShortcut, &QxtGlobalShortcut::activated, pCanvas, funcCanvas);
//	}
//}