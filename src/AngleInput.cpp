#include "AngleInput.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>

namespace GlmVisu {
	AngleInput::AngleInput(QWidget * parent, QString name, Qt::Orientation orientation) :
		QGroupBox(parent),
		orientation(orientation)
	{
		init();
		this->setAngleName(name);
	}
	AngleInput::~AngleInput()
	{
	}
	void AngleInput::setValuesType(AngleType::Types val)
	{
		this->slider->setValuesType(val);
	}
	AngleType::Types AngleInput::getValuesType() const
	{
		return this->slider->getValuesType();
	}
	void AngleInput::setAngleName(QString name)
	{
		this->setTitle(name);
	}
	QString AngleInput::getAngleName() const
	{
		return this->title();
	}
	double AngleInput::doubleValue()
	{
		return slider->doubleValue();
	}
	void AngleInput::setDoubleValue(double value)
	{
		this->slider->setDoubleValue(value);
	}
	void AngleInput::setRadiansValue(double radians)
	{
		this->setRadiansValue(radians);
	}
	void AngleInput::setDegreesValue(double degrees)
	{
		this->slider->setDegreesValue(degrees);
	}
	void AngleInput::changeAngleValue(double value) {

		QString valueOutput = QString::number(value, 'f', 2);
		//todo move to angleType
		if (slider->getValuesType() == AngleType::Types::degrees) {
			valueOutput.append("°");
		}
		else {
			valueOutput.append("rad");
		}
		this->value->setText(valueOutput);
	}
	void AngleInput::init()
	{
		QLayout * layout;
		if (orientation == Qt::Orientation::Horizontal)
			layout = (new QHBoxLayout());
		else
			layout = (new QVBoxLayout());
		this->slider = new AngleSlider(orientation);
		this->value = new QLabel();
		layout->addWidget(this->slider);
		layout->addWidget(this->value);

		this->setLayout(layout);


		connect(slider, &AngleSlider::angleValueChanged, this, &AngleInput::changeAngleValue);
		connect(slider, &AngleSlider::angleValueChanged, this, &AngleInput::angleValueChanged);
		connect(slider, &AngleSlider::degreeValueChanged, this, &AngleInput::degreeValueChanged);
		connect(slider, &AngleSlider::radiansValueChanged, this, &AngleInput::radiansValueChanged);
		changeAngleValue(this->slider->doubleValue());
	}
}