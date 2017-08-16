#pragma once
#include <QtDesigner/QtDesigner>
#include <QtCore/qplugin.h>

namespace GlmVisu {
	class GlmVisuWidgetsCollection : public QObject, public QDesignerCustomWidgetCollectionInterface
	{
		Q_OBJECT
			Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetCollectionInterface")
			Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

	public:
		GlmVisuWidgetsCollection(QObject *parent = 0);

		QList<QDesignerCustomWidgetInterface*> customWidgets() const Q_DECL_OVERRIDE;

	private:
		QList<QDesignerCustomWidgetInterface*> widgets;
	};
}

