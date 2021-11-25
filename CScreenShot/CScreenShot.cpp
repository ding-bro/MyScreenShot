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
	// ��ͼ�ȼ�
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

	// mouseMoveEvent�� QMainWindow�������׷��
	// ò�� QMainWindowҪ��centralWidget���в���
	this->centralWidget()->setMouseTracking(true);
	this->setMouseTracking(true);
}

void CScreenShot::slotMainwidowShow()
{
	ex_pshCanvas->close();
	this->show();

	// �����ȼ���ͻ
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

	// ����û��ô��رգ�����ص�����
	Sleep(200);

	// ��ȡ������ĻͼƬ
	std::shared_ptr<CCanvas>pshCanvas = std::make_shared<CCanvas>(this->getScreenPixmap());
	ex_pshCanvas = pshCanvas->getSharedpointThis(); // ��������ָ��

	connect(this, &CScreenShot::signScreenShot, ex_pshCanvas.get(), &CCanvas::slotFullScreen);
	connect(ex_pshCanvas.get(), &CCanvas::signMainwindowShow, this, &CScreenShot::slotMainwidowShow);

	// ȫ���ȼ�connect
	getShortcutTransfer("Ctrl+Shift+A", this->m_punShortcutCtrlShiftA.get(), this, &CScreenShot::slotStartScreenShot);
	getShortcutTransfer("Esc",this->m_punShortcutEsc.get(), ex_pshCanvas.get(), &CCanvas::slotCanvasClose);

	ex_pshCanvas->show();

	emit signScreenShot();
}

void CScreenShot::ClickEvent()
{
	// ��ͼ
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
	// ��ȡ������Ļ��ͼƬ
	QScreen* pScreen = QGuiApplication::primaryScreen();
	QPixmap qPixmap = pScreen->grabWindow(0);	

	return qPixmap;
}

void CScreenShot::mouseMoveEvent(QMouseEvent* pEvent)
{
	// ����뿪��ͷʱ�����ڹر�
	if(!this->m_qMenu.isEmpty())
	{
		this->m_qMenu.close();
		this->m_qMenu.clear();
	}

	// ֱ���� ui.btnArrow.rect()
	// { return QRect(0,0,data->crect.width(),data->crect.height()); } ���Ǵ�0,0��ʼ��,����
	QPoint qPos;
	QRect qRect;

	qPos = pEvent->pos();

	// qt��׽��ķ�Χ���񲻾�ȷ......
	// ֻ����ʱ����΢��
	// �кõĽ��������?
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

	this->m_pActionRect = this->m_qMenu.addAction(QString::fromLocal8Bit("���ν�ͼ"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[Rect] = true;
		setMenuShowBlock(Rect);
	});
	this->m_pActionWindow = this->m_qMenu.addAction(QString::fromLocal8Bit("���ڽ�ͼ"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[Window] = true;
		setMenuShowBlock(Window);
	});
	this->m_pActionFull = this->m_qMenu.addAction(QString::fromLocal8Bit("ȫ��Ļ��ͼ"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[FullScreen] = true;
		setMenuShowBlock(FullScreen);
	});
	this->m_pActionAny = this->m_qMenu.addAction(QString::fromLocal8Bit("�����ʽ��ͼ"), [&] {
		MAPASSIGN(false);
		this->m_mapMenuBlock[AnyFormat] = true;
		setMenuShowBlock(AnyFormat);
	});

	// ����������Ϊ�����ֲ˵����ĸ�ѡ��
	// ������ļ�����֪���������
	this->m_pActionRect->setObjectName("Menu");
	this->m_pActionWindow->setObjectName("Menu");
	this->m_pActionFull->setObjectName("Menu");
	this->m_pActionAny->setObjectName("Menu");

	// ��Ϊ������moveevent���¼�ѭ����
	// ����������ж�Ϊ�˼�ס֮ǰ��ѡ�����
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

			// ���û��ѡ�е����Ĭ��ѡ���ν�ͼ
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
	//�ļ����  
	long long hFile = 0;
	//�ļ���Ϣ������һ���洢�ļ���Ϣ�Ľṹ��  
	struct _finddata_t fileinfo;
	string p;//�ַ��������·��
	if ((hFile = _findfirst(p.assign(strPath).append("\\*").c_str(), &fileinfo)) != -1)//�����ҳɹ��������
	{
		do
		{
			//�����Ŀ¼,����֮�����ļ����ڻ����ļ��У�  
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				//�ļ���������"."&&�ļ���������".."
				//.��ʾ��ǰĿ¼
				//..��ʾ��ǰĿ¼�ĸ�Ŀ¼
				//�ж�ʱ�����߶�Ҫ���ԣ���Ȼ�����޵ݹ�������ȥ�ˣ�
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFilesName(p.assign(strPath).append("\\").append(fileinfo.name), vctFiles);
			}
			//�������,�����б�  
			else
			{
				vctFiles.push_back(p.assign(strPath).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		//_findclose������������
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

			// �����С��25,25����
			qPixmap = qPixmap.scaled(qSize);
			if (!qPixmap.save(strTemp.c_str()))
			{
				QMessageBox::warning(nullptr, "warning", strTemp.c_str(), QMessageBox::Ok);
			}
		}
	}
}
