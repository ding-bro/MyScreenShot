#include "CScreenShot.h"

CScreenShot* ex_pScreenShot;
std::shared_ptr<CCanvas>ex_pshCanvas;

CScreenShot::CScreenShot(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	InitUi();

	InitParam();

	ClickEvent();
}

CScreenShot::~CScreenShot()
{
	
}

void CScreenShot::getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CScreenShot* pScreen, pFunctionScreenShot funcScreen)
{
	// 截图热键
	if (pShortcut->setShortcut(QKeySequence(strCombineKey)))
	{
		QObject::connect(pShortcut, &QxtGlobalShortcut::activated, pScreen, funcScreen);
	}
}

void CScreenShot::getShortcutTransfer(QString strCombineKey, QxtGlobalShortcut* pShortcut, CCanvas* pCanvas, pFunctionCanvas funcCanvas)
{
	if (pShortcut->setShortcut(QKeySequence(strCombineKey)))
	{
		QObject::connect(pShortcut, &QxtGlobalShortcut::activated, pCanvas, funcCanvas);
	}
}

void CScreenShot::setButtonStyle(QPushButton* pButton, QString qstrImage)
{
	QString qstrBtnQss(
		"QPushButton\
		{\
			border-image: url(:/Source/***.png);\
			border-position: top;\
			border: none;\
			text-align: bottom;\
		}\
		QPushButton:hover\
		{\
			border-image: url(:/Source/***-hover.png);\
		}\
		QPushButton:pressed\
		{\
			border-image: url(:/Source/***-Press.png);\
		}"
	);

	qstrBtnQss.replace("***", qstrImage);
	pButton->setStyleSheet(qstrBtnQss);
}

void CScreenShot::InitUi()
{
	this->setFixedSize(450, 240);
	this->setWindowTitle("ScreenShot");
	this->setWindowIcon(QIcon(":/Source/ScreenShotIcon.png"));

	this->setStyleSheet("QMainWindow{background-color: white;}");
	this->setButtonStyle(ui.btnScreenShot, "Cut");  
	this->setButtonStyle(ui.btnModel, "Model");
	this->setButtonStyle(ui.btnArrow, "Arrow");
}

void CScreenShot::InitParam()
{
	ex_pScreenShot = this;

	MAPASSIGN(false);

	// mouseMoveEvent的 QMainWindow开启鼠标追踪
	// 貌似 QMainWindow要对centralWidget进行操作
	this->centralWidget()->setMouseTracking(true);
	this->setMouseTracking(true);
}

void CScreenShot::slotMainwidowShow()
{
	ex_pshCanvas->close();
	this->show();

	// 避免热键冲突
	ex_pshCanvas.reset();
	this->m_punShortcutCtrlShiftA.reset();
	this->m_punShortcutEsc.reset();
}

void CScreenShot::slotTest(CSetPen* pSetpen)
{
	
}

void CScreenShot::slotDownLoad(CCanvas* pCanvas,COptionBox* pOption,QPixmap& qPixmap)
{
	QString qstrDir = QFileDialog::getExistingDirectory(nullptr, QString::fromLocal8Bit("save"));

	if (!CCanvas::savePixmap(qPixmap, qstrDir))
	{
		QMessageBox::warning(nullptr, QString::fromLocal8Bit("Warning"), QString::fromLocal8Bit("Save Image Failed!"), QMessageBox::Yes);
	}

	pCanvas->close();
	pOption->close();

	emit signThreadQuit();
	slotMainwidowShow();
}

void CScreenShot::slotStartScreenShot()
{
	this->m_punShortcutCtrlShiftA = std::make_unique<QxtGlobalShortcut>();
	this->m_punShortcutEsc = std::make_unique<QxtGlobalShortcut>();

	this->close();

	// 窗口没那么快关闭，避免截到窗口
	Sleep(200);

	// 获取整个屏幕图片
	std::shared_ptr<CCanvas>pshCanvas = std::make_shared<CCanvas>(this->getScreenPixmap());
	ex_pshCanvas = pshCanvas->getSharedpointThis(); // 返回自身指针

	connect(this, &CScreenShot::signScreenShot, ex_pshCanvas.get(), &CCanvas::slotFullScreen);
	connect(ex_pshCanvas.get(), &CCanvas::signMainwindowShow, this, &CScreenShot::slotMainwidowShow);

	// 全局热键connect
	getShortcutTransfer("Ctrl+Shift+A", this->m_punShortcutCtrlShiftA.get(), this, &CScreenShot::slotStartScreenShot);
	getShortcutTransfer("Esc",this->m_punShortcutEsc.get(), ex_pshCanvas.get(), &CCanvas::slotCanvasClose);

	ex_pshCanvas->show();

	emit signScreenShot();
}

void CScreenShot::ClickEvent()
{
	// 截图
	connect(ui.btnScreenShot, &QPushButton::clicked, this,&CScreenShot::slotStartScreenShot);

	connect(ui.btnModel, &QPushButton::clicked,[=] {
		//setPixmapSize(QSize(25, 25));
		//setImageSuffix("png");
	});

	connect(ui.btnArrow, &QPushButton::clicked, [&] {
		CreateMenuShow();
	});
}

QPixmap CScreenShot::getScreenPixmap()
{
	// 截取整个屏幕的图片
	QScreen* pScreen = QGuiApplication::primaryScreen();
	QPixmap qPixmap = pScreen->grabWindow(0);	

	return qPixmap;
}

void CScreenShot::mouseMoveEvent(QMouseEvent* pEvent)
{
	// 鼠标离开箭头时，窗口关闭
	if(!this->m_qMenu.isEmpty())
	{
		this->m_qMenu.close();
		this->m_qMenu.clear();
	}

	// 直接用 ui.btnArrow.rect()
	// { return QRect(0,0,data->crect.width(),data->crect.height()); } 点是从0,0开始的,不行
	QPoint qPos;
	QRect qRect;

	qPos = pEvent->pos();

	// qt捕捉点的范围好像不精确......
	// 只能暂时这样微调
	// 有好的解决方法吗?
	qRect.setX(ui.btnArrow->x() - 10);
	qRect.setY(ui.btnArrow->y() - 5);
	qRect.setWidth(ui.btnArrow->width() + 20);
	qRect.setHeight(ui.btnArrow->height() + 20);
	
	if (qRect.contains(qPos))
	{
		CreateMenuShow();
	}
}

void CScreenShot::CreateMenuShow()
{
	QPoint qPos;
	bool bIsBlock = false;

	qPos.setX(ui.btnArrow->x());
	qPos.setY(ui.btnArrow->y() + ui.btnArrow->height() + 10);

	this->m_qMenu.setParent(this);
	this->m_qMenu.setStyleSheet(
		"\
			QMenu:item:selected\
			{\
				background-color: grey;\
			}\
		"
	);
	this->m_qMenu.setFixedSize(200, 95);
	this->m_qMenu.move(qPos);

	this->m_pActionRect = this->m_qMenu.addAction(QString::fromLocal8Bit("矩形截图"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[Rect] = true;
		setMenuShowBlock(Rect);
	});
	this->m_pActionWindow = this->m_qMenu.addAction(QString::fromLocal8Bit("窗口截图"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[Window] = true;
		setMenuShowBlock(Window);
	});
	this->m_pActionFull = this->m_qMenu.addAction(QString::fromLocal8Bit("全屏幕截图"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[FullScreen] = true;
		setMenuShowBlock(FullScreen);
	});
	this->m_pActionAny = this->m_qMenu.addAction(QString::fromLocal8Bit("任意格式截图"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[AnyFormat] = true;
		setMenuShowBlock(AnyFormat);
	});

	// 设置属性是为了区分菜单这四个选项
	// 多出来的几个不知道是哪里的
	this->m_pActionRect->setObjectName("Menu");
	this->m_pActionWindow->setObjectName("Menu");
	this->m_pActionFull->setObjectName("Menu");
	this->m_pActionAny->setObjectName("Menu");

	// 因为函数在moveevent的事件循环里
	// 所以做这个判断为了记住之前所选择的项
	for (auto& it : this->findChildren<QAction*>())
	{
		if ("Menu" == it->objectName())
		{
			for (auto& itmap : this->m_mapMenuBlock)
			{
				if (itmap.second)
				{
					bIsBlock = true;
					setMenuShowBlock(itmap.first);
				}
			}

			// 如果没有选中的项，就默认选矩形截图
			if (!bIsBlock)
			{
				setMenuShowBlock(Rect);
			}
		}
	}

	this->m_qMenu.show();
}

void CScreenShot::setMenuShowBlock(ShapeOfScreenShot shapeofShot)
{
	QAction* pAction = nullptr;

	if (!this->m_qMenu.isEmpty())
	{
		for (auto& it : this->findChildren<QAction*>())
		{
			if ("Menu" == it->objectName())
			{
				it->setCheckable(false);
				it->setChecked(false);
			}
		}
	}

	switch (shapeofShot)
	{
	case Rect:
		this->m_ShapeOfScreen = Rect;
		pAction = this->m_pActionRect;
		break;
	case Window:
		this->m_ShapeOfScreen = Window;
		pAction = this->m_pActionWindow;
		break;
	case FullScreen:
		this->m_ShapeOfScreen = FullScreen;
		pAction = this->m_pActionFull;
		break;
	case AnyFormat:
		this->m_ShapeOfScreen = AnyFormat;
		pAction = this->m_pActionAny;
		break;
	default:
		break;
	}

	if (pAction != nullptr)
	{
		pAction->setCheckable(true);
		pAction->setChecked(true);
	}
}

void CScreenShot::getFilesName(string strPath, vector<string>& vctFiles)
{
	//文件句柄  
	long long hFile = 0;
	//文件信息，声明一个存储文件信息的结构体  
	struct _finddata_t fileinfo;
	string p;//字符串，存放路径
	if ((hFile = _findfirst(p.assign(strPath).append("\\*").c_str(), &fileinfo)) != -1)//若查找成功，则进入
	{
		do
		{
			//如果是目录,迭代之（即文件夹内还有文件夹）  
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				//文件名不等于"."&&文件名不等于".."
				//.表示当前目录
				//..表示当前目录的父目录
				//判断时，两者都要忽略，不然就无限递归跳不出去了！
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFilesName(p.assign(strPath).append("\\").append(fileinfo.name), vctFiles);
			}
			//如果不是,加入列表  
			else
			{
				vctFiles.push_back(p.assign(strPath).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		//_findclose函数结束查找
		_findclose(hFile);
	}
}


void CScreenShot::setImageSuffix(string strSuffixName)
{
	QString qstrImagePath;
	QString qstrOutputPath;

	vector<string>vctImageNames;
	map<string, std::shared_ptr<QPixmap>>mapImageName;

	if (strSuffixName.empty())
	{
		return;
	}

	qstrImagePath = QFileDialog::getExistingDirectory(nullptr, "Open", "F:\\code\\MyScreenShot\\MyScreenShot\\CScreenShot");
	if (qstrImagePath.isEmpty())
	{
		return;
	}

	getFilesName(qstrImagePath.toStdString(), vctImageNames);

	for (auto& it : vctImageNames)
	{
		if (!it.empty())
		{
			std::shared_ptr<QPixmap>pshPixmap = std::make_shared<QPixmap>();
			if (!pshPixmap->load(it.c_str()))
			{
				mapImageName["Failed"] = nullptr;
				return;
			}

			if (string::npos != it.find("."))
			{
				int iPos = it.find(".");
				it.replace(iPos + 1, it.size() - iPos + 1, strSuffixName);

				if (string::npos != it.find("\\"))
				{
					it.erase(it.begin(), it.begin() + it.find("\\") + 1);
					mapImageName[it] = pshPixmap;
				}
			}
		}
	}

	qstrOutputPath = QFileDialog::getExistingDirectory(nullptr, "Save", "F:\\code\\MyScreenShot\\MyScreenShot\\CScreenShot");
	if (qstrOutputPath.isEmpty())
	{
		return;
	}

	for (auto& it : mapImageName)
	{
		QString qstrTemp = qstrOutputPath + "\\";
		qstrTemp += it.first.c_str();

		if (!it.second->save(qstrTemp))
		{
			return;
		}
	}
}

void CScreenShot::setPixmapSize(QSize qSize)
{
	vector<string>vctImageNames;
	QString qstrImagePath;

	qstrImagePath = QFileDialog::getExistingDirectory(nullptr, "Open", "F:\\code\\MyScreenShot\\MyScreenShot\\CScreenShot");
	if (qstrImagePath.isEmpty())
	{
		return;
	}

	getFilesName(qstrImagePath.toStdString(), vctImageNames);

	for (vector<string>::iterator it = vctImageNames.begin(); it != vctImageNames.end(); it++)
	{
		if (!(*it).empty())
		{
			QPixmap qPixmap;
			if (!qPixmap.load((*it).c_str()))
			{
				string str;
			}

			string strTemp = *it;
			if (string::npos != strTemp.find("\\"))
			{
				strTemp.erase(strTemp.begin(), strTemp.begin() + strTemp.find("\\") + 1);
			}

			// 保存大小至25,25像素
			qPixmap = qPixmap.scaled(qSize);
			if (!qPixmap.save(strTemp.c_str()))
			{
				QMessageBox::warning(nullptr, "warning", strTemp.c_str(), QMessageBox::Ok);
			}
		}
	}
}
