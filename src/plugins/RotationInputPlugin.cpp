#include "RotationInputPlugin.h"
#include "RotationInput.h"
#include <QtPlugin>

namespace GlmVisu {

	RotationInputPlugin::RotationInputPlugin(QObject *parent)
		: QObject(parent)
		, initialized(false)
	{
	}

	bool RotationInputPlugin::isContainer() const
	{
		return false;
	}

	bool RotationInputPlugin::isInitialized() const
	{
		return initialized;
	}

	QIcon RotationInputPlugin::icon() const
	{
		return QIcon();
	}

	QString RotationInputPlugin::domXml() const
	{
		return 
			"<widget class=\"GlmVisu::RotationInput\" name=\"rotationInput\">\n"
			"</widget>\n";
	}

	QString RotationInputPlugin::group() const
	{
	}

	QString RotationInputPlugin::includeFile() const
	{
		return "RotationInput.h";
	}

	QString RotationInputPlugin::name() const
	{
		return "GlmVisu::RotationInput";
	}
	QString RotationInputPlugin::toolTip() const
	{
		return QString();
	}
	QString RotationInputPlugin::whatsThis() const
	{
		return QString();
	}
	QWidget * RotationInputPlugin::createWidget(QWidget * parent)
	{
		return new GlmVisu::RotationInput(parent);
	}
	void RotationInputPlugin::initialize(QDesignerFormEditorInterface * core)
	{
		if (initialized)
			return;

		initialized = true;
	}
	//Q_EXPORT_PLUGIN2(mycustomplugin, plugin::MyCustomPlugin)
}
