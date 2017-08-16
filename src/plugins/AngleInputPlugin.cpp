#include "AngleInputPlugin.h"
#include "AngleInput.h"
#include <QtPlugin>

namespace GlmVisu {

	AngleInputPlugin::AngleInputPlugin(QObject *parent)
		: QObject(parent)
		, initialized(false)
	{
	}

	bool AngleInputPlugin::isContainer() const
	{
		return false;
	}

	bool AngleInputPlugin::isInitialized() const
	{
		return initialized;
	}

	QIcon AngleInputPlugin::icon() const
	{
		return QIcon();
	}

	QString AngleInputPlugin::domXml() const
	{
		return
			"<ui language=\"c++\"> displayname=\"AngleInput\">\n"
			"	<widget class=\"GlmVisu::AngleInput\" name=\"angleInput\">\n"
			"	</widget>\n"
			"	<customwidgets>"
			"		<customwidget>"
			"		<class>GlmVisu::AngleInput</class>"
			"		<extends>QGroupBox</extends>"
			"		<header>AngleInput.h</header>"
			"		<container>0</container>"
			"		<slots>"
			"			<slot>changeAngleValue(double)</slot>"
			"			<signal>angleValueChanged(double)</signal>"
			"			<signal>degreeValueChanged(double)</signal>"
			"			<signal>radiansValueChanged(double)</signal>"
			"		</slots>"
			"		<properties>"
			"			<property type=\"GlmVisu::AngleType::Types\"/>"
			"		</properties>"
			"		</customwidget>"
			"	</customwidgets>"
			"</ui>";
	}

	QString AngleInputPlugin::group() const
	{
		return GLMVISU_GROUP;
	}

	QString AngleInputPlugin::includeFile() const
	{
		return "AngleInput.h";
	}

	QString AngleInputPlugin::name() const
	{
		return "GlmVisu::AngleInput";
	}
	QString AngleInputPlugin::toolTip() const
	{
		return QString();
	}
	QString AngleInputPlugin::whatsThis() const
	{
		return QString();
	}
	QWidget * AngleInputPlugin::createWidget(QWidget * parent)
	{
		return new GlmVisu::AngleInput(parent);
	}
	void AngleInputPlugin::initialize(QDesignerFormEditorInterface * core)
	{
		if (initialized)
			return;

		initialized = true;
	}
	//Q_EXPORT_PLUGIN2(mycustomplugin, plugin::MyCustomPlugin)
}