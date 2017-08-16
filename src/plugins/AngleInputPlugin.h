#pragma once
#include <QObject>
#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include <QtUiPlugin/customwidget.h>
namespace GlmVisu {
	class AngleInputPlugin : public QObject, public QDesignerCustomWidgetInterface
	{
		Q_OBJECT
			Q_INTERFACES(QDesignerCustomWidgetInterface)
	public:
		explicit AngleInputPlugin(QObject *parent = 0);

		bool isContainer() const override;
		bool isInitialized() const override;
		QIcon icon() const override;
		QString domXml() const override;
		QString group() const override;
		QString includeFile() const override;
		QString name() const override;
		QString toolTip() const override;
		QString whatsThis() const override;
		QWidget *createWidget(QWidget *parent) override;
		void initialize(QDesignerFormEditorInterface *core) override;

	private:
		bool initialized;
	};
}