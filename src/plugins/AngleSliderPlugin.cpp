#include "AngleSliderPlugin.h"
#include "AngleSlider.h"
#include <QtPlugin>

namespace GlmVisu {

	AngleSliderPlugin::AngleSliderPlugin(QObject *parent)
		: QObject(parent)
		, initialized(false)
	{
	}

	bool AngleSliderPlugin::isContainer() const
	{
		return false;
	}

	bool AngleSliderPlugin::isInitialized() const
	{
		return initialized;
	}

	QIcon AngleSliderPlugin::icon() const
	{
		return QIcon();
	}

	QString AngleSliderPlugin::domXml() const
	{
		return 
			"<widget class=\"GlmVisu::AngleSlider\" name=\"angleSlider\">\n"
			"</widget>\n";
	}

	QString AngleSliderPlugin::group() const
	{
		return GLMVISU_GROUP;
	}

	QString AngleSliderPlugin::includeFile() const
	{
		return "AngleSlider.h";
	}

	QString AngleSliderPlugin::name() const
	{
		return "GlmVisu::AngleSlider";
	}
	QString AngleSliderPlugin::toolTip() const
	{
		return QString();
	}
	QString AngleSliderPlugin::whatsThis() const
	{
		return QString();
	}
	QWidget * AngleSliderPlugin::createWidget(QWidget * parent)
	{
		return new GlmVisu::AngleSlider(parent);
	}
	void AngleSliderPlugin::initialize(QDesignerFormEditorInterface * core)
	{
		if (initialized)
			return;

		initialized = true;
	}
	//Q_EXPORT_PLUGIN2(mycustomplugin, plugin::MyCustomPlugin)
}