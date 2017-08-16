#include "GlmVisuWidgetsCollection.h"
#include "AngleSliderPlugin.h"
#include "RotationInputPlugin.h"
#include "AngleInputPlugin.h"

namespace GlmVisu {
	GlmVisuWidgetsCollection::GlmVisuWidgetsCollection(QObject *parent)
		: QObject(parent) 
	{
		widgets.append(new AngleSliderPlugin(this));
		widgets.append(new RotationInputPlugin(this));
		widgets.append(new AngleInputPlugin(this));
	}



	QList<QDesignerCustomWidgetInterface*> GlmVisuWidgetsCollection::customWidgets() const
	{
		return widgets;
	}
}
