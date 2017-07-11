#include "AngleSlider.h"
#include <glm/glm.hpp>
#include <QDebug>

namespace GlmVisu {
	const double AngleSlider::dpi = 100.0;


	AngleSlider::AngleSlider(QWidget * parent) :
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
		double angleValue = this->value() / AngleSlider::dpi;
		if (this->valuesType == Values::degrees) {
			return angleValue * 3.14/180;
		}
		else {
			return angleValue;
		}
	}

	double AngleSlider::degreeValue()
	{
		return 0.0;
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