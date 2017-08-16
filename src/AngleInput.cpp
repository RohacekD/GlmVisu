#include "AngleInput.h"
#include "AngleSlider.h"
#include "AngleType.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <string>

namespace GlmVisu {
	AngleInput::AngleInput(QWidget * parent, QString name, Qt::Orientation orientation) :
		QGroupBox(parent),
		m_orientation(orientation)
	{
		init();
		this->setAngleName(name);
	}
	AngleInput::~AngleInput()
	{
	}
	void AngleInput::setValuesType(AngleType::Types val)
	{
		this->m_slider->setValuesType(val);
	}
	AngleType::Types AngleInput::getValuesType() const
	{
		return this->m_slider->getValuesType();
	}
	void AngleInput::setAngleName(QString name)
	{
		this->setTitle(name);
	}
	QString AngleInput::getAngleName() const
	{
		return this->title();
	}
	double AngleInput::doubleValue() const
	{
		return m_slider->doubleValue();
	}
	void AngleInput::setDoubleValue(double value)
	{
		this->m_slider->setDoubleValue(value);
	}
	void AngleInput::setRadiansValue(double radians)
	{
		this->m_slider->setRadiansValue(radians);
	}
	void AngleInput::setDegreesValue(double degrees)
	{
		this->m_slider->setDegreesValue(degrees);
	}
	void AngleInput::changeAngleValue(double value) {

		QString valueOutput = QString::number(value, 'f', 2);
		//todo move to angleType
		if (m_slider->getValuesType() == AngleType::Types::degrees) {
			valueOutput.append("°");
		}
		else {
			valueOutput.append("rad");
		}
		this->m_value->setText(valueOutput);
	}
	void AngleInput::init()
	{
		QLayout * layout;
		if (m_orientation == Qt::Orientation::Horizontal)
			layout = (new QHBoxLayout());
		else
			layout = (new QVBoxLayout());
		this->m_slider = new AngleSlider(m_orientation);
		this->m_value = new QLabel();
		layout->addWidget(this->m_slider);
		layout->addWidget(this->m_value);

		this->setLayout(layout);


		connect(m_slider, &AngleSlider::angleValueChanged, this, &AngleInput::changeAngleValue);
		connect(m_slider, &AngleSlider::angleValueChanged, this, &AngleInput::angleValueChanged);
		connect(m_slider, &AngleSlider::degreeValueChanged, this, &AngleInput::degreeValueChanged);
		connect(m_slider, &AngleSlider::radiansValueChanged, this, &AngleInput::radiansValueChanged);
		changeAngleValue(this->m_slider->doubleValue());
	}
}