//#include "CAbstract.h"
//
//void CAbstract::getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CScreenShot* pScreen, pFunctionScreenShot funcScreen)
//{
//	// ½ØÍ¼ÈÈ¼ü
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