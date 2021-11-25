#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_CScreenShot.h"

#include "CCanvas.h"
#include "CAbstract.h"

#define MAPASSIGN(VALUE)\
{\
    m_mapMenuBlock[Rect] = VALUE;\
    m_mapMenuBlock[Window] = VALUE;\
    m_mapMenuBlock[FullScreen] = VALUE;\
    m_mapMenuBlock[AnyFormat] = VALUE;\
}

class CScreenShot;
typedef void (CScreenShot::* pFunctionScreenShot)(void);
typedef void (CCanvas::* pFunctionCanvas)(void);

extern CScreenShot* ex_pScreenShot;
extern std::shared_ptr<CCanvas>ex_pshCanvas;

class CScreenShot : public QMainWindow
{
    Q_OBJECT

public:
    CScreenShot(QWidget *parent = Q_NULLPTR);

    ~CScreenShot();

    void InitUi();

    void InitParam();

	void ClickEvent();

    void CreateMenuShow();

    void mouseMoveEvent(QMouseEvent* pEvent);
    
    void setMenuShowBlock(ShapeOfScreenShot shapeofShot);

    void getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CScreenShot* pScreen, pFunctionScreenShot funcScreen);
    void getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CCanvas* pCanvas, pFunctionCanvas funcCanvas);

    void setButtonStyle(QPushButton* pButton,QString qstrImage);

    static QPixmap getScreenPixmap();

private:
    void getFilesName(string strPath, vector<string>& vctFiles);
    void setPixmapSize(QSize qSize);
    void setImageSuffix(string strSuffixName);

signals:
    void signScreenShot();
    void signThreadQuit();

public slots:
    void slotMainwidowShow();
    void slotStartScreenShot();
    void slotDownLoad(CCanvas* pCanvas, COptionBox* pOption, QPixmap& qPixmap);
    
    void slotTest(CSetPen* pSetpen);

public:
    QPixmap m_qPixmap;
    QMenu m_qMenu;

    QAction* m_pActionRect;
    QAction* m_pActionWindow;
    QAction* m_pActionFull;
    QAction* m_pActionAny;

    std::unique_ptr<QxtGlobalShortcut>m_punShortcutCtrlShiftA;
    std::unique_ptr<QxtGlobalShortcut>m_punShortcutEsc;

    std::map<ShapeOfScreenShot, bool>m_mapMenuBlock;

    ShapeOfScreenShot m_ShapeOfScreen;
private:
    Ui::UiCScreenShot ui;
};



