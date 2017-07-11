#include "RotationInput.h"
#include <QGridLayout>
#include <QLabel>

namespace GlmVisu {
	RotationInput::RotationInput(QWidget *parent) :
		RotationInput(Qt::Orientation::Horizontal, parent)
	{
	}

	RotationInput::RotationInput(Qt::Orientation orientation, QWidget * parent) :
		QGroupBox(parent),
		valuesType(AngleSlider::Values::radians),
		orientation(orientation)
	{
		QGridLayout *layout = new QGridLayout(this);
		sliderX = new AngleSlider(orientation, this);
		sliderX->setObjectName("sliderX");
		sliderY = new AngleSlider(orientation, this);
		sliderY->setObjectName("sliderY");
		sliderZ = new AngleSlider(orientation, this);
		sliderZ->setObjectName("sliderZ");


		layout->addWidget(new QLabel("x", this), 0, 0);
		layout->addWidget(sliderX, 1, 0);
		layout->addWidget(new QLabel("y", this), 0, 1);
		layout->addWidget(sliderY, 1, 1);
		layout->addWidget(new QLabel("z", this), 0, 2);
		layout->addWidget(sliderZ, 1, 2);

		connect(sliderX, &AngleSlider::angleValueChanged, this, &RotationInput::changeX);
		connect(sliderY, &AngleSlider::angleValueChanged, this, &RotationInput::changeY);
		connect(sliderZ, &AngleSlider::angleValueChanged, this, &RotationInput::changeZ);
	}

	RotationInput::~RotationInput()
	{
	}

	glm::vec3 RotationInput::getRotation()
	{
		return glm::vec3(sliderX->doubleValue(), sliderY->doubleValue(), sliderZ->doubleValue());
	}

	void RotationInput::setValue(glm::vec3 value)
	{
		sliderX->setDoubleValue(value.x);
		sliderY->setDoubleValue(value.y);
		sliderZ->setDoubleValue(value.z);
	}

	inline Qt::Orientation RotationInput::getOrientation() const { return this->orientation; }

	void RotationInput::setOrientation(Qt::Orientation orientation)
	{
		this->orientation = orientation;
		sliderX->setOrientation(orientation);
		sliderY->setOrientation(orientation);
		sliderZ->setOrientation(orientation);
	}

	void RotationInput::setValuesType(AngleSlider::Values type)
	{
		this->valuesType = type;
		sliderX->setValuesType(type);
		sliderY->setValuesType(type);
		sliderZ->setValuesType(type);
	}

	inline AngleSlider::Values RotationInput::getValuesType() const { return this->valuesType; }

	void RotationInput::changeX(double xAngle)
	{
		emit(rotationChanged(getRotation()));
		emit(xAngleChanged(xAngle));
	}

	void RotationInput::changeY(double yAngle)
	{
		emit(rotationChanged(getRotation()));
		emit(yAngleChanged(yAngle));
	}

	void RotationInput::changeZ(double zAngle)
	{
		emit(rotationChanged(getRotation()));
		emit(zAngleChanged(zAngle));
	}
}