#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <assert.h>
#include <functional>
#include <windows.h>

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QToolBar>
#include <QLabel>
#include <QToolButton>
#include <QTextEdit>
#include <QFileDialog>
#include <QDebug>
#include <QScreen>
#include <QPainter>
#include <QMouseEvent>
#include <QBoxLayout>
#include <QClipboard>
#include <QThread>
#include <QTime>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QScrollBar>

#include "qxtglobalshortcut.h"

using namespace std;

enum ShapeOfScreenShot
{
	Rect,
	Window,
	FullScreen,
	AnyFormat
};

class CAbstract
{
public:
	CAbstract() {}

	~CAbstract() {}
};