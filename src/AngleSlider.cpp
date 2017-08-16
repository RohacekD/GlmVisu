#include "AngleSlider.h"
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <QDebug>

namespace GlmVisu {
	const double AngleSlider::s_dpi = 100.0;


	AngleSlider::AngleSlider(QWidget * parent) :
		AngleSlider(Qt::Orientation::Horizontal, parent)
	{
	}
	AngleSlider::AngleSlider(Qt::Orientation orientation, QWidget * parent) :
		QSlider(orientation, parent),
		m_angleType(AngleType::Types::radians)
	{
		setTypeRadians();
		connect(this, &QAbstractSlider::valueChanged, this, &AngleSlider::notifyValueChanged);
	}
	AngleSlider::~AngleSlider()
	{
	}

	void AngleSlider::setValuesType(AngleType::Types valType) {
		if (this->m_angleType != valType) {
			double value = static_cast<double>(this->value());
			if (valType == AngleType::Types::radians) {
				setTypeRadians();
				setValue(glm::radians(value));
			}
			else {
				setTypeDegrees();
				setValue(glm::degrees(value));
			}
		}
	}


	double AngleSlider::radiansValue() const
	{
		double angleValue = this->doubleValue();
		if (this->m_angleType == AngleType::Types::degrees) {
			return glm::radians(angleValue);
		}
		else {
			return angleValue / glm::pi<double>();
		}
	}

	double AngleSlider::degreeValue() const
	{
		double angleValue = this->doubleValue();
		if (this->m_angleType == AngleType::Types::degrees) {
			return angleValue;
		}
		else {
			return glm::degrees(angleValue);
		}
	}

	double AngleSlider::doubleValue() const
	{
		return this->value() / AngleSlider::s_dpi;
	}

	void AngleSlider::setDoubleValue(double value)
	{
		setValue(static_cast<int>(value * AngleSlider::s_dpi));
	}

	void AngleSlider::setRadiansValue(double radians)
	{
		if (this->m_angleType == AngleType::degrees)
			this->setDoubleValue(glm::degrees(radians));
		else
			this->setDoubleValue(radians);
	}

	void AngleSlider::setDegreesValue(double degrees)
	{
		if (this->m_angleType == AngleType::radians)
			this->setDoubleValue(glm::radians(degrees));
		else
			this->setDoubleValue(degrees);
	}

	void AngleSlider::setTypeRadians()
	{
		setMinimum(0);
		setMaximum((int)(glm::radians(360.0f) * AngleSlider::s_dpi));
	}

	void AngleSlider::setTypeDegrees()
	{
		setMinimum(0);
		setMaximum((int)(360 * AngleSlider::s_dpi));
	}

	void AngleSlider::notifyValueChanged(int value) {
		double angleValue = doubleValue();
		emit(angleValueChanged(angleValue));
		emit(degreeValueChanged(degreeValue()));
		emit(radiansValueChanged(radiansValue()));
	}
}