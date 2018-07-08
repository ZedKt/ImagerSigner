#ifndef IMAGESIGNER_H
#define IMAGESIGNER_H

#include <QtGui/QMainWindow>
#include "ui_imagesigner.h"
#include <QFileDialog>
#include <QDir>
#include <QPainter>
#include <QMessageBox>
#include <Qwidget.h>
#include "Pt_FFT.h"
#include "ui_About.h"


class ProAbout:public QWidget
{
	Q_OBJECT
public:
	ProAbout(QWidget *parent = 0, Qt::WindowFlags f = 0)
	{
		ui.setupUi(this);
	}
protected:
private:
	Ui::Form_About ui;
};


class ImageSigner : public QMainWindow
{
	Q_OBJECT

public:
	ImageSigner(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ImageSigner();
	void SignImage();
	void DisplaySourceImage();
	void DisplaySignImage();
public slots:
	void SLOT_LoadResPixmap();
	void SLOT_LoadSigPixmap();
	void SLOT_DoSign();
	void SLOT_SaveTo();
	void SLOT_About();
private:
	QPixmap m_Signmap;
	QPixmap m_Resmap;
	QPixmap m_SignedMap;
	ProAbout *about;
	Ui::ImageSignerClass ui;
	//����ǩ��ͼƬ���sign_width��ǩ��ͼƬΪ�����Σ���ǩ��ͼƬ������Ҫ��ǩ��ͼƬ�ĳ�����������
	static const int sign_width = 128;
	static const int source_width = sign_width * 2;
};

#endif // IMAGESIGNER_H
