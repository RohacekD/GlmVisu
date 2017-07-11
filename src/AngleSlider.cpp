#include "AngleSlider.h"
#include <glm/glm.hpp>
#include <QDebug>

namespace GlmVisu {
	const double AngleSlider::dpi = 100.0;


	AngleSlider::AngleSlider(QWidget * parent) :
		AngleSlider(Qt::Orientation::Horizontal, parent)
	{
	}
	AngleSlider::AngleSlider(Qt::Orientation orientation, QWidget * parent) :
		QSlider(parent),
		valuesType(Values::radians)
	{
		setTypeRadians();
		connect(this, &QAbstractSlider::valueChanged, this, &AngleSlider::notifyValueChanged);
	}
	AngleSlider::~AngleSlider()
	{
	}

	void AngleSlider::setValuesType(Values valType) {
		if (this->valuesType != valType) {
			double value = static_cast<double>(this->value());
			if (valType == Values::radians) {
				setTypeRadians();
				setValue(glm::radians(value));
			}
			else {
				setTypeDegrees();
				setValue(glm::degrees(value));
			}
		}
	}

	double AngleSlider::radiansValue()
	{
		double angleValue = this->doubleValue();
		if (this->valuesType == Values::degrees) {
			return glm::radians(angleValue);
		}
		else {
			return angleValue;
		}
	}

	double AngleSlider::degreeValue()
	{
		double angleValue = this->doubleValue();
		if (this->valuesType == Values::degrees) {
			return angleValue;
		}
		else {
			return glm::degrees(angleValue);
		}
	}

	double AngleSlider::doubleValue()
	{
		return this->value() / AngleSlider::dpi;
	}

	void AngleSlider::setDoubleValue(double value)
	{
		setValue(static_cast<int>(value * AngleSlider::dpi));
	}

	void AngleSlider::setTypeRadians()
	{
		setMinimum(0);
		setMaximum((int)(glm::radians(360.0f) * AngleSlider::dpi));
	}

	void AngleSlider::setTypeDegrees()
	{
		setMinimum(0);
		setMaximum((int)(360 * AngleSlider::dpi));
	}

	void AngleSlider::notifyValueChanged(int value) {
		double angleValue = value / AngleSlider::dpi;
		emit(angleValueChanged(angleValue));
		if (this->valuesType == Values::degrees) {
			emit(degreeValueChanged(angleValue));
			emit(radiansValueChanged(angleValue * 3.14 / 180));
		}
		else {
			emit(radiansValueChanged(angleValue));
			emit(degreeValueChanged(angleValue * 180 / 3.14));
		}
	}
}