#include "CCanvas.h"
#include "CQThreadCilck.h"
#include "CScreenShot.h"

void CCanvas::slotFullScreen()
{
	this->setWindowFlags(Qt::Window); // ������ô˺�����������ε���ȫ����ʧЧ

	// ��ȫ��ͼƬ��·��
	this->m_BlackScreenPainerpath.moveTo(0, 0);
	this->m_BlackScreenPainerpath.lineTo(this->m_qPixmap.width(),0);
	this->m_BlackScreenPainerpath.lineTo(this->m_qPixmap.width(),this->m_qPixmap.height());
	this->m_BlackScreenPainerpath.lineTo(0,this->m_qPixmap.height());
	this->m_BlackScreenPainerpath.lineTo(0,0);

	this->m_bFirstPress = false;
	this->m_bLeftMousePress = false;

	// ȫ����ʾ
	this->showFullScreen();
}

void CCanvas::paintEvent(QPaintEvent* pEvent)
{
	// ������ĻΪ������
	//setScreenBlack();

	// ���û���͸�� - ����ͼƬ����
	//this->setScreenTransparent(qPainter);

	this->update();

	// ��׽�����׿�
	getCaptureWhiteFrame();

	// �׿������ڵĶ���
	if (isMoveWhiteFrame())
	{
		switch (this->m_Shapetype)
		{
		case RectType: // ����
			drawPaintRect();
			break;
		case CircleType: // Բ��
			drawPaintCircle();
			break;
		case LineType: // ֱ��
			drawPaintLine();
			break;
		case ArrowType: // ��ͷ
			drawPaintArrow();
			break;
		case TextType: // �ı�
			drawPaintText();
			break;
		default:
			qDebug() << "Warning: No Click Shape Type";
			break;
		}
	}
}

void CCanvas::getCaptureWhiteFrame()
{
	QPainter qPainter(this);
	QPainterPath qPaintPath;
	QPen qPen;

	qPen.setColor(Qt::white);
	qPainter.setPen(qPen);

	// ����ͼ�����֮���ͼƬ�����и���
	if (!this->m_qCanvasmap.isNull())
	{
		qPainter.drawPixmap(0, 0, this->m_qCanvasmap);
	}
	else
	{
		// ����ͼƬ��ͬʱ������ɫ���ð��߲�׽�����ڵ�ǰ��͸��ͼƬ��
		qPainter.drawPixmap(0, 0, this->m_qPixmap);
		qPainter.setBrush(QColor(0, 0, 0, 100));
	}

	// ���ư׿�
	qPaintPath.moveTo(this->m_qPointPress.x(), this->m_qPointPress.y());
	qPaintPath.lineTo(this->m_qPointMove.x(), this->m_qPointPress.y());
	qPaintPath.lineTo(this->m_qPointMove.x(), this->m_qPointMove.y());
	qPaintPath.lineTo(this->m_qPointPress.x(), this->m_qPointMove.y());
	qPaintPath.lineTo(this->m_qPointPress.x(), this->m_qPointPress.y());

	// �������
	if (this->m_bLeftMousePress)
	{
		// ��ͼ
		qPainter.drawPath(this->m_BlackScreenPainerpath.subtracted(qPaintPath));
	}
	else
	{
		// �������ֻ��ʾ����
		qPainter.drawPath(this->m_BlackScreenPainerpath);
	}
}

void CCanvas::setPainterPenType(QPainter& qPainter)
{
	QPen qPen;
	Qt::GlobalColor qtGlobaColor = getPenColor(this->m_Pentype); // ѡ�����ɫ

	// ���
	qPen.setWidth(this->m_Pentype.ePenThickness);
	qPen.setColor(qtGlobaColor);
	qPainter.setPen(qPen);
}

void CCanvas::drawPaintRect()
{
	QPainter qPainter(this);
	QPainterPath qPaintPath;

	// ���û��ʿ�Ⱥ���ɫ
	setPainterPenType(qPainter);

	// ���ƽ����׿�
	qPaintPath.moveTo(this->m_qPointPainterPress.x(), this->m_qPointPainterPress.y());
	qPaintPath.lineTo(this->m_qPointPainterMove.x(), this->m_qPointPainterPress.y());
	qPaintPath.lineTo(this->m_qPointPainterMove.x(), this->m_qPointPainterMove.y());
	qPaintPath.lineTo(this->m_qPointPainterPress.x(), this->m_qPointPainterMove.y());
	qPaintPath.lineTo(this->m_qPointPainterPress.x(), this->m_qPointPainterPress.y());

	qPainter.drawPath(qPaintPath);
}

void CCanvas::drawPaintCircle()
{
	QPainter qPainter(this);

	// ���û��ʿ�Ⱥ���ɫ
	setPainterPenType(qPainter);

	// �ƶ����ȥ�����
	int iWidth = this->m_qPointPainterMove.x() - this->m_qPointPainterPress.x();
	int iHeight = this->m_qPointPainterMove.y() - this->m_qPointPainterPress.y();

	// ����ĵ����һ�����ε����Ͻ�
	qPainter.drawEllipse(this->m_qPointPainterPress.x(),this->m_qPointPainterPress.y(),iWidth,iHeight);
}

void CCanvas::drawPaintLine()
{
	QPainter qPainter(this);
	QPainterPath qPainterPath;

	// ���û��ʿ�Ⱥ���ɫ
	setPainterPenType(qPainter);

	qPainterPath.moveTo(this->m_qPointPainterPress);

	//qPainterPath.quadTo(this->m_qPointPainterPress,(this->m_qPointPainterPress + this->m_qPointPainterMove) / 2);

	// ����������,����Ч����ֱ�ߣ�Ԥ�ڵ�Ч���ǻ�������·�������ߣ����Ż��ķ�����????
	qPainterPath.cubicTo(this->m_qPointPainterPress, (this->m_qPointPainterPress + this->m_qPointPainterMove) / 2, this->m_qPointPainterMove);

	qPainter.drawPath(qPainterPath);
}

void CCanvas::drawPaintArrow()
{
	QPainter qPainter(this);

	// ���û��ʿ�Ⱥ���ɫ
	setPainterPenType(qPainter);

	// ����ͷ
	drawArrow(qPainter);
}

void CCanvas::drawArrow(QPainter& qPainter)
{
	if ((!this->m_qPointPainterPress.isNull()) && (!this->m_qPointPainterMove.isNull()))
	{
		// ���ȸ��������ƶ���ֱ��
		qPainter.drawLine(this->m_qPointPainterPress, this->m_qPointPainterMove);

		QLineF qLineMove(this->m_qPointPainterPress, this->m_qPointPainterMove);
		QLineF qLineExtend;
		QLineF qLineVectorOne;
		QLineF qLineVectorTwo;
		QLineF qLineConnectTopLeft;
		QLineF qLineConnectLeftRight;
		QLineF qLineConnectRightTop;

		QPointF qPointTriangleTop;
		QPointF qPointTriangleLeft;
		QPointF qPointTriangleRight;

		qLineExtend = qLineMove.unitVector(); // �����ֱ�ߴ���һ��������
		qLineExtend.setLength(qLineMove.length() / 20); // ���ó���
		qLineExtend.translate(QPointF(qLineMove.dx(), qLineMove.dy())); // ���ݵ����ˮƽƫ��

		/*
				   |
				   |
			_______|_______
		*/

		qLineVectorOne = qLineExtend.normalVector(); // ���������� -- ��ֱֱ�Ǳ�
		qLineVectorOne.setLength(qLineExtend.length() / 2); 

		qLineVectorTwo = qLineVectorOne.normalVector().normalVector(); // �õ�һ���ԳƵķ�����

		// ÿ���ߵ��յ�
		qPointTriangleTop = qLineExtend.p2();
		qPointTriangleLeft = qLineVectorOne.p2();
		qPointTriangleRight = qLineVectorTwo.p2();

		// ���������εĶ��㡢��㡢�ҵ�
		qLineConnectTopLeft.setPoints(qPointTriangleTop, qPointTriangleLeft);
		qLineConnectLeftRight.setPoints(qPointTriangleLeft, qPointTriangleRight);
		qLineConnectRightTop.setPoints(qPointTriangleRight, qPointTriangleTop);

		// ����
		qPainter.drawLine(qLineConnectTopLeft);
		qPainter.drawLine(qLineConnectLeftRight);
		qPainter.drawLine(qLineConnectRightTop);
	}
}

void CCanvas::drawPaintText()
{
	if (!this->m_punTextEdit) // ��paintevent��Ҫ�ظ�show������д���ǲ�����ģ���û���Ż��ķ���??
	{
		this->m_punTextEdit = std::make_unique<QTextEdit>(this); // һ��Ҫ�ڸ�������ʾ
		// �߿�̶�Ϊ��ɫ��������͸�����ı��༭��
		this->m_punTextEdit->setStyleSheet( 
			"\
			QTextEdit\
			{\
				border-width: 3px;\
				border-style: solid;\
				border-color: red;\
				background-color: transparent;\
			}\
			"
		);
		// ���������λ��ȫ����ʾ�ı��༭��
		this->m_punTextEdit->setGeometry(this->m_qPointPainterPress.x(), this->m_qPointPainterPress.y(), 300, 100);
		this->m_punTextEdit->verticalScrollBar()->hide(); // ���ؽ�����
		this->m_punTextEdit->show();
	}

	QFont qFont("Microsoft YaHei"); // ΢���ź�
	Qt::GlobalColor qtGlobaColor;

	// ò����������ô�С������paintevent��ʵʱ��ʾ����
	// ����������ɫ��������ʵʱ��ʾ����
	if (SmallPen == this->m_Pentype.ePenThickness)
	{
		qFont.setPixelSize(10);
	}
	else if (MediumPen == this->m_Pentype.ePenThickness)
	{
		qFont.setPixelSize(20);
	}
	else if (BigPen == this->m_Pentype.ePenThickness)
	{
		qFont.setPixelSize(30);
	}

	qtGlobaColor = getPenColor(this->m_Pentype); // ������ɫ

	if (this->m_punTextEdit) // ���ݴ���������ɫ�ʹ�С�ı�
	{
		this->m_punTextEdit->setFont(qFont);
		this->m_punTextEdit->setTextColor(qtGlobaColor);
	}
}

void CCanvas::CreateTextEditShow()
{
	// Ϊ���ڳɹ������ı���֮���ٴ����ı����ⲿ�����꣬�ܹ����δ����ı��򣬲���֮ǰ���ı����ܹ�͸����ʾ����Ļ�ϣ������ı������ݺ���ɫ��Ҫ����¼
	// ����ʱ��QTextEdit���뵽�����У�Ȼ��show��������¼֮ǰ�ı��������
	// �и��õķ�����????

	std::unique_ptr<QTextEdit>punTextTemp = std::make_unique<QTextEdit>(this);

	punTextTemp->move(this->m_qPointPainterPress);

	this->m_qRectWhiteFrame.contains(punTextTemp->rect());

	punTextTemp->setStyleSheet(
		"\
		QTextEdit\
		{\
			border: none;\
			background-color: transparent;\
		}\
		"
	);
	punTextTemp->setTextColor(this->m_punTextEdit->textColor());
	punTextTemp->setPlainText(this->m_punTextEdit->toPlainText());
	punTextTemp->setFont(this->m_punTextEdit->font());
	punTextTemp->verticalScrollBar()->hide();

	this->m_vctTextEdit.push_back(std::move(punTextTemp)); 

	for (auto& it : this->m_vctTextEdit)
	{
		it->show();
	}
}

void CCanvas::setScreenTransparent(QPainter& qPainter)
{
	// �����ɫ
	QPixmap qPixTemp(this->m_qPixmap.width(), this->m_qPixmap.height());
	qPixTemp.fill(QColor(0, 0, 0, 100));

	// ����ͼƬ����
	qPainter.drawPixmap(0, 0, qPixTemp);
	qPainter.drawPixmap(0, 0, this->m_qPixmap);
}

void CCanvas::setScreenBlack()
{
	QPixmap qPixTemp(this->m_qPixmap.size());
	qPixTemp.fill(Qt::transparent);

	QPainter qPaint(&qPixTemp);
	qPaint.setCompositionMode(QPainter::CompositionMode_Source);
	qPaint.drawPixmap(0, 0, this->m_qPixmap);
	qPaint.setCompositionMode(QPainter::CompositionMode_DestinationIn);

	// 100��ʾ͸���ȣ���ֵ0��ʾ��ȫ͸������ֵ255��ʾ��͸��
	qPaint.fillRect(qPixTemp.rect(), QColor(0, 0, 0, 100));

	// ���ñ���
	QPalette qPalette;
	qPalette.setBrush(qPalette.Background, QBrush(qPixTemp));
	this->setPalette(qPalette);
}

void CCanvas::mousePressEvent(QMouseEvent* pEvent)
{
	if (!this->m_punOptionBox) // û�е����ɫ���Կ��ʱ��
	{
		if (Qt::LeftButton == pEvent->button()) // ���
		{
			this->m_bLeftMousePress = true;
			this->m_qPointPress = pEvent->pos(); // �����׿�������λ��
		}
		else
		{
			this->m_bLeftMousePress = false;
		}
	}
	else // �������ɫ���Կ�֮��
	{
		if (this->m_punTextEdit) // �����ı���ʱ
		{
			if (!this->m_punTextEdit->toPlainText().isEmpty())
			{
				// ��ε�������ı��򣬼�¼֮ǰ���ı�������
				CreateTextEditShow();
			}

			this->m_punTextEdit.reset();
		}

		this->m_qPointPainterPress = pEvent->pos(); // ����ͼ�ε������λ��
	}

	this->update(); // ���ĵ���ƶ���Ҫ��ʱ����
}

void CCanvas::mouseMoveEvent(QMouseEvent* pEvent)
{
	if (!this->m_punOptionBox) // û�е����ɫ���Կ��ʱ��
	{
		this->m_qPointMove = pEvent->pos(); // �����׿������ƶ�λ��
	}
	else
	{
		this->m_qPointPainterMove = pEvent->pos(); // ����ͼ�ε�����ƶ�λ��
	}

	this->update(); // ���ĵ���ƶ���Ҫ��ʱ����
}

void CCanvas::mouseReleaseEvent(QMouseEvent* pEvent)
{
	if (!this->m_punOptionBox) // û�е����ɫ���Կ��ʱ��
	{
		this->m_qPointRelease = pEvent->pos(); // �����׿������ͷ�λ��

		// ����׿�ľ���
		QRect qRectTemp(this->m_qPointPress, this->m_qPointRelease);
		this->m_qRectWhiteFrame = qRectTemp;

		// �������
		if (this->m_bLeftMousePress)
		{
			QPoint qPoint;
			qPoint.setX(this->m_qPointPress.x() + ((this->m_qPointRelease.x() - this->m_qPointPress.x()) / 2));
			qPoint.setY(this->m_qPointRelease.y() + 5);

			// ��ʾͼ��ѡ���
			this->m_punOptionBox = std::make_unique<COptionBox>(qPoint);
			this->m_punOptionBox->show();

			InitOptionBoxConnect();
		}
	}
	else
	{
		this->m_qPointPainterRelease = pEvent->pos(); // ����ͼ�ε�����ͷ�λ��
		
		if (this->m_Shapetype != TextType) // �ı���ʱ����Ҫ��ͼ
		{
			this->m_qCanvasmap = CScreenShot::getScreenPixmap(); // ����ͼ�����֮���ȫ��ͼƬ
		}
	}

	this->update(); // ���ĵ���ƶ���Ҫ��ʱ����
}

void CCanvas::InitOptionBoxConnect()
{
	connect(this->m_punOptionBox.get(), &COptionBox::signQuit, [this] {
		emit signMainwindowShow();
	});
	
	connect(this->m_punOptionBox.get(), &COptionBox::signDone, [this] {
		this->m_qScreenmap = getScreenmap();
		CCanvas::savePixmap(this->m_qScreenmap);

		// ��ȡ������ָ�룬��ͼƬ��ͼͼƬ������������
		QClipboard* pClipboard = QGuiApplication::clipboard();
		QImage qImage = this->m_qScreenmap.toImage();

		pClipboard->setImage(qImage);

		emit signMainwindowShow();
	});

	connect(this->m_punOptionBox.get(), &COptionBox::signDownLoad, [this] {
		// �߳̿���ѡ���
		QThread* pThread = new QThread;

		CQThreadCilck* pClickThread = new CQThreadCilck(pThread);

		pClickThread->moveToThread(pThread);
		pThread->start();

		connect(this, &CCanvas::signDownLoad, pClickThread, &CQThreadCilck::slotDownLoad,Qt::DirectConnection);

		emit signDownLoad(this, this->m_punOptionBox.get(),getScreenmap());
	});
}

void CCanvas::slotCanvasClose()
{
	emit signMainwindowShow();
}

void CCanvas::slotPenType(SPenType& sPentype)
{
	this->m_Pentype = sPentype;
}

void CCanvas::slotShapeType(ShapeType enShapetype)
{
	this->m_Shapetype = enShapetype;
}

bool CCanvas::savePixmap(QPixmap& qPixmap, QString qstrPath /* = "" */)
{
	if (qPixmap.isNull())
	{
		return false;
	}

	QString qstrDate = QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss");
	QString qstrCurrentPath = QCoreApplication::applicationDirPath(); // ��ǰexe·��

	qstrCurrentPath += "\\ImageSave";

	if (qstrPath.isEmpty())
	{
		QDir qDir;

		if (!qDir.exists(qstrCurrentPath))
		{
			if (!qDir.mkpath(qstrCurrentPath))
			{
				return false;
			}
		}

		qstrPath += qstrCurrentPath;
	}

	qstrPath += "\\Screen_";
	qstrPath += qstrDate;
	qstrPath += ".png";

	if (!qPixmap.save(qstrPath, nullptr))
	{
		return false;
	}

	return true;
}

bool CCanvas::isMoveWhiteFrame()
{
	if (this->m_qPointPainterPress.isNull())
	{
		return false;
	}

	// ��ͼ�İ׿��������
	if (!this->m_qRectWhiteFrame.isNull())
	{
		// ����Ƿ����ھ�����
		if (this->m_qRectWhiteFrame.contains(this->m_qPointPainterPress))
		{
			return true;
		}
	}

	return false;
}


QPixmap& CCanvas::getScreenmap()
{
	// ������������ͷŵ������ȡͼƬ
	return this->m_qScreenmap = this->grab(QRect(this->m_qPointPress, QSize(this->m_qPointRelease.x() - this->m_qPointPress.x(), this->m_qPointRelease.y() - this->m_qPointPress.y())));
}

Qt::GlobalColor CCanvas::getPenColor(SPenType& sPentype)
{
	Qt::GlobalColor qtGlobaColor;

	// ��ɫ
	switch (sPentype.ePenColor)
	{
	case Red:
		qtGlobaColor = Qt::red;
		break;
	case Yellow:
		qtGlobaColor = Qt::yellow;
		break;
	case Blue:
		qtGlobaColor = Qt::blue;
		break;
	case Green:
		qtGlobaColor = Qt::green;
		break;
	case Black:
		qtGlobaColor = Qt::black;
		break;
	case White:
		qtGlobaColor = Qt::white;
		break;
	default:
		qDebug() << "Warning: No Pen Color";
		break;
	}

	return qtGlobaColor;
}

