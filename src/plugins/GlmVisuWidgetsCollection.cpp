#include "GlmVisuWidgetsCollection.h"


namespace GlmVisu {
	GlmVisuWidgetsCollection::GlmVisuWidgetsCollection(QObject *parent)
		: QObject(parent) 
	{
		widgets.append(new AngleSliderPlugin(this));
		widgets.append(new RotationInputPlugin(this));
	}



	QList<QDesignerCustomWidgetInterface*> GlmVisuWidgetsCollection::customWidgets() const
	{
		return widgets;
	}
}
