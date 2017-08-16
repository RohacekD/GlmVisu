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
			"<ui language=\"c++\"> displayname=\"RotationInput\">\n"
			"	<widget class=\"GlmVisu::RotationInput\" name=\"rotationInput\">\n"
			"	</widget>\n"
			"	<customwidgets>"
			"		<customwidget>"
			"		<class>GlmVisu::RotationInput</class>"
			"		<addpagemethod>addPage</addpagemethod>"
			"		<propertyspecifications>"
			"			<stringpropertyspecification name=\"fileName\" notr=\"true\" type=\"singleline\"/>"
			"			<stringpropertyspecification name=\"text\" type=\"richtext\"/>"
			"			<tooltip name = \"text\">Explanatory text to be shown in Property Editor</tooltip>"
			"		</propertyspecifications>"
			"		</customwidget>"
			"	</customwidgets>"
			"</ui>";
	}

	QString RotationInputPlugin::group() const
	{
		return GLMVISU_GROUP;
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
		return "Input for 3D rotation.";
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