#include "CCanvas.h"
#include "CQThreadCilck.h"
#include "CScreenShot.h"

void CCanvas::slotFullScreen()
{
	this->setWindowFlags(Qt::Window); // 必须调用此函数，否则二次调用全屏会失效

	// 画全屏图片的路径
	this->m_BlackScreenPainerpath.moveTo(0, 0);
	this->m_BlackScreenPainerpath.lineTo(this->m_qPixmap.width(),0);
	this->m_BlackScreenPainerpath.lineTo(this->m_qPixmap.width(),this->m_qPixmap.height());
	this->m_BlackScreenPainerpath.lineTo(0,this->m_qPixmap.height());
	this->m_BlackScreenPainerpath.lineTo(0,0);

	this->m_bFirstPress = false;
	this->m_bLeftMousePress = false;

	// 全屏显示
	this->showFullScreen();
}

void CCanvas::paintEvent(QPaintEvent* pEvent)
{
	// 设置屏幕为黑亮度
	//setScreenBlack();

	// 设置画布透明 - 两张图片叠加
	//this->setScreenTransparent(qPainter);

	this->update();

	// 捕捉截屏白框
	getCaptureWhiteFrame();

	// 白框区域内的动作
	if (isMoveWhiteFrame())
	{
		switch (this->m_Shapetype)
		{
		case RectType: // 矩形
			drawPaintRect();
			break;
		case CircleType: // 圆形
			drawPaintCircle();
			break;
		case LineType: // 直线
			drawPaintLine();
			break;
		case ArrowType: // 箭头
			drawPaintArrow();
			break;
		case TextType: // 文本
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

	// 绘制图形完成之后的图片，进行覆盖
	if (!this->m_qCanvasmap.isNull())
	{
		qPainter.drawPixmap(0, 0, this->m_qCanvasmap);
	}
	else
	{
		// 设置图片，同时设置颜色，让白线捕捉作用在当前的透明图片上
		qPainter.drawPixmap(0, 0, this->m_qPixmap);
		qPainter.setBrush(QColor(0, 0, 0, 100));
	}

	// 绘制白框
	qPaintPath.moveTo(this->m_qPointPress.x(), this->m_qPointPress.y());
	qPaintPath.lineTo(this->m_qPointMove.x(), this->m_qPointPress.y());
	qPaintPath.lineTo(this->m_qPointMove.x(), this->m_qPointMove.y());
	qPaintPath.lineTo(this->m_qPointPress.x(), this->m_qPointMove.y());
	qPaintPath.lineTo(this->m_qPointPress.x(), this->m_qPointPress.y());

	// 限制左键
	if (this->m_bLeftMousePress)
	{
		// 抠图
		qPainter.drawPath(this->m_BlackScreenPainerpath.subtracted(qPaintPath));
	}
	else
	{
		// 不是左键只显示黑屏
		qPainter.drawPath(this->m_BlackScreenPainerpath);
	}
}

void CCanvas::setPainterPenType(QPainter& qPainter)
{
	QPen qPen;
	Qt::GlobalColor qtGlobaColor = getPenColor(this->m_Pentype); // 选择的颜色

	// 宽度
	qPen.setWidth(this->m_Pentype.ePenThickness);
	qPen.setColor(qtGlobaColor);
	qPainter.setPen(qPen);
}

void CCanvas::drawPaintRect()
{
	QPainter qPainter(this);
	QPainterPath qPaintPath;

	// 设置画笔宽度和颜色
	setPainterPenType(qPainter);

	// 绘制截屏白框
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

	// 设置画笔宽度和颜色
	setPainterPenType(qPainter);

	// 移动点减去点击点
	int iWidth = this->m_qPointPainterMove.x() - this->m_qPointPainterPress.x();
	int iHeight = this->m_qPointPainterMove.y() - this->m_qPointPainterPress.y();

	// 点击的点就是一个矩形的左上角
	qPainter.drawEllipse(this->m_qPointPainterPress.x(),this->m_qPointPainterPress.y(),iWidth,iHeight);
}

void CCanvas::drawPaintLine()
{
	QPainter qPainter(this);
	QPainterPath qPainterPath;

	// 设置画笔宽度和颜色
	setPainterPenType(qPainter);

	qPainterPath.moveTo(this->m_qPointPainterPress);

	//qPainterPath.quadTo(this->m_qPointPainterPress,(this->m_qPointPainterPress + this->m_qPointPainterMove) / 2);

	// 贝塞尔曲线,但是效果是直线，预期的效果是画出自由路径的曲线，有优化的方法吗????
	qPainterPath.cubicTo(this->m_qPointPainterPress, (this->m_qPointPainterPress + this->m_qPointPainterMove) / 2, this->m_qPointPainterMove);

	qPainter.drawPath(qPainterPath);
}

void CCanvas::drawPaintArrow()
{
	QPainter qPainter(this);

	// 设置画笔宽度和颜色
	setPainterPenType(qPainter);

	// 画箭头
	drawArrow(qPainter);
}

void CCanvas::drawArrow(QPainter& qPainter)
{
	if ((!this->m_qPointPainterPress.isNull()) && (!this->m_qPointPainterMove.isNull()))
	{
		// 首先跟着鼠标的移动画直线
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

		qLineExtend = qLineMove.unitVector(); // 从鼠标直线创建一个线向量
		qLineExtend.setLength(qLineMove.length() / 20); // 设置长度
		qLineExtend.translate(QPointF(qLineMove.dx(), qLineMove.dy())); // 根据点进行水平偏移

		/*
				   |
				   |
			_______|_______
		*/

		qLineVectorOne = qLineExtend.normalVector(); // 创建法向量 -- 垂直直角边
		qLineVectorOne.setLength(qLineExtend.length() / 2); 

		qLineVectorTwo = qLineVectorOne.normalVector().normalVector(); // 得到一个对称的法向量

		// 每条线的终点
		qPointTriangleTop = qLineExtend.p2();
		qPointTriangleLeft = qLineVectorOne.p2();
		qPointTriangleRight = qLineVectorTwo.p2();

		// 连接三角形的顶点、左点、右点
		qLineConnectTopLeft.setPoints(qPointTriangleTop, qPointTriangleLeft);
		qLineConnectLeftRight.setPoints(qPointTriangleLeft, qPointTriangleRight);
		qLineConnectRightTop.setPoints(qPointTriangleRight, qPointTriangleTop);

		// 画线
		qPainter.drawLine(qLineConnectTopLeft);
		qPainter.drawLine(qLineConnectLeftRight);
		qPainter.drawLine(qLineConnectRightTop);
	}
}

void CCanvas::drawPaintText()
{
	if (!this->m_punTextEdit) // 在paintevent不要重复show，这种写法是不合理的，有没有优化的方法??
	{
		this->m_punTextEdit = std::make_unique<QTextEdit>(this); // 一定要在父级上显示
		// 边框固定为红色，背景是透明的文本编辑框
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
		// 根据鼠标点击位置全局显示文本编辑框
		this->m_punTextEdit->setGeometry(this->m_qPointPainterPress.x(), this->m_qPointPainterPress.y(), 300, 100);
		this->m_punTextEdit->verticalScrollBar()->hide(); // 隐藏进度条
		this->m_punTextEdit->show();
	}

	QFont qFont("Microsoft YaHei"); // 微软雅黑
	Qt::GlobalColor qtGlobaColor;

	// 貌似字体的设置大小可以在paintevent里实时显示出来
	// 但是设置颜色并不可以实时显示出来
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

	qtGlobaColor = getPenColor(this->m_Pentype); // 字体颜色

	if (this->m_punTextEdit) // 根据传过来的颜色和大小改变
	{
		this->m_punTextEdit->setFont(qFont);
		this->m_punTextEdit->setTextColor(qtGlobaColor);
	}
}

void CCanvas::CreateTextEditShow()
{
	// 为了在成功建立文本框之后，再次在文本框外部点击鼠标，能够二次创建文本框，并且之前的文本框能够透明显示在屏幕上，而且文本的内容和颜色需要被记录
	// 将临时的QTextEdit插入到容器中，然后show出来，记录之前文本框的属性
	// 有更好的方法吗????

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
	// 填充颜色
	QPixmap qPixTemp(this->m_qPixmap.width(), this->m_qPixmap.height());
	qPixTemp.fill(QColor(0, 0, 0, 100));

	// 两张图片叠加
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

	// 100表示透明度，数值0表示完全透明，数值255表示不透明
	qPaint.fillRect(qPixTemp.rect(), QColor(0, 0, 0, 100));

	// 设置背景
	QPalette qPalette;
	qPalette.setBrush(qPalette.Background, QBrush(qPixTemp));
	this->setPalette(qPalette);
}

void CCanvas::mousePressEvent(QMouseEvent* pEvent)
{
	if (!this->m_punOptionBox) // 没有点击颜色属性框的时候
	{
		if (Qt::LeftButton == pEvent->button()) // 左键
		{
			this->m_bLeftMousePress = true;
			this->m_qPointPress = pEvent->pos(); // 截屏白框的鼠标点击位置
		}
		else
		{
			this->m_bLeftMousePress = false;
		}
	}
	else // 点击了颜色属性框之后
	{
		if (this->m_punTextEdit) // 当是文本框时
		{
			if (!this->m_punTextEdit->toPlainText().isEmpty())
			{
				// 多次点击创建文本框，记录之前的文本框内容
				CreateTextEditShow();
			}

			this->m_punTextEdit.reset();
		}

		this->m_qPointPainterPress = pEvent->pos(); // 绘制图形的鼠标点击位置
	}

	this->update(); // 鼠标的点击移动需要随时更新
}

void CCanvas::mouseMoveEvent(QMouseEvent* pEvent)
{
	if (!this->m_punOptionBox) // 没有点击颜色属性框的时候
	{
		this->m_qPointMove = pEvent->pos(); // 截屏白框的鼠标移动位置
	}
	else
	{
		this->m_qPointPainterMove = pEvent->pos(); // 绘制图形的鼠标移动位置
	}

	this->update(); // 鼠标的点击移动需要随时更新
}

void CCanvas::mouseReleaseEvent(QMouseEvent* pEvent)
{
	if (!this->m_punOptionBox) // 没有点击颜色属性框的时候
	{
		this->m_qPointRelease = pEvent->pos(); // 截屏白框的鼠标释放位置

		// 捕获白框的矩形
		QRect qRectTemp(this->m_qPointPress, this->m_qPointRelease);
		this->m_qRectWhiteFrame = qRectTemp;

		// 限制左键
		if (this->m_bLeftMousePress)
		{
			QPoint qPoint;
			qPoint.setX(this->m_qPointPress.x() + ((this->m_qPointRelease.x() - this->m_qPointPress.x()) / 2));
			qPoint.setY(this->m_qPointRelease.y() + 5);

			// 显示图形选择框
			this->m_punOptionBox = std::make_unique<COptionBox>(qPoint);
			this->m_punOptionBox->show();

			InitOptionBoxConnect();
		}
	}
	else
	{
		this->m_qPointPainterRelease = pEvent->pos(); // 绘制图形的鼠标释放位置
		
		if (this->m_Shapetype != TextType) // 文本框时不需要截图
		{
			this->m_qCanvasmap = CScreenShot::getScreenPixmap(); // 绘制图形完成之后的全屏图片
		}
	}

	this->update(); // 鼠标的点击移动需要随时更新
}

void CCanvas::InitOptionBoxConnect()
{
	connect(this->m_punOptionBox.get(), &COptionBox::signQuit, [this] {
		emit signMainwindowShow();
	});
	
	connect(this->m_punOptionBox.get(), &COptionBox::signDone, [this] {
		this->m_qScreenmap = getScreenmap();
		CCanvas::savePixmap(this->m_qScreenmap);

		// 获取剪贴板指针，将图片截图图片保存至剪贴板
		QClipboard* pClipboard = QGuiApplication::clipboard();
		QImage qImage = this->m_qScreenmap.toImage();

		pClipboard->setImage(qImage);

		emit signMainwindowShow();
	});

	connect(this->m_punOptionBox.get(), &COptionBox::signDownLoad, [this] {
		// 线程开启选择框
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
	QString qstrCurrentPath = QCoreApplication::applicationDirPath(); // 当前exe路径

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

	// 截图的白框矩形区域
	if (!this->m_qRectWhiteFrame.isNull())
	{
		// 鼠标是否点击在矩形内
		if (this->m_qRectWhiteFrame.contains(this->m_qPointPainterPress))
		{
			return true;
		}
	}

	return false;
}


QPixmap& CCanvas::getScreenmap()
{
	// 根据鼠标点击和释放的坐标截取图片
	return this->m_qScreenmap = this->grab(QRect(this->m_qPointPress, QSize(this->m_qPointRelease.x() - this->m_qPointPress.x(), this->m_qPointRelease.y() - this->m_qPointPress.y())));
}

Qt::GlobalColor CCanvas::getPenColor(SPenType& sPentype)
{
	Qt::GlobalColor qtGlobaColor;

	// 颜色
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

