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
		m_anglesType(AngleType::Types::radians),
		m_orientation(orientation)
	{
		QGridLayout *layout = new QGridLayout(this);
		m_sliderX = new AngleSlider(orientation, this);
		m_sliderX->setObjectName("sliderX");
		m_sliderY = new AngleSlider(orientation, this);
		m_sliderY->setObjectName("sliderY");
		m_sliderZ = new AngleSlider(orientation, this);
		m_sliderZ->setObjectName("sliderZ");


		layout->addWidget(new QLabel("x", this), 0, 0);
		layout->addWidget(m_sliderX, 1, 0);
		layout->addWidget(new QLabel("y", this), 0, 1);
		layout->addWidget(m_sliderY, 1, 1);
		layout->addWidget(new QLabel("z", this), 0, 2);
		layout->addWidget(m_sliderZ, 1, 2);


		this->setMinimumSize(300, 100);

		connect(m_sliderX, &AngleSlider::angleValueChanged, this, &RotationInput::changeX);
		connect(m_sliderY, &AngleSlider::angleValueChanged, this, &RotationInput::changeY);
		connect(m_sliderZ, &AngleSlider::angleValueChanged, this, &RotationInput::changeZ);
	}

	RotationInput::~RotationInput()
	{
	}

	glm::vec3 RotationInput::getRotation() const
	{
		return glm::vec3(m_sliderX->doubleValue(), m_sliderY->doubleValue(), m_sliderZ->doubleValue());
	}

	void RotationInput::setValue(glm::vec3 value)
	{
		m_sliderX->setDoubleValue(value.x);
		m_sliderY->setDoubleValue(value.y);
		m_sliderZ->setDoubleValue(value.z);
	}

	inline Qt::Orientation RotationInput::getOrientation() const { return this->m_orientation; }

	void RotationInput::setOrientation(Qt::Orientation orientation)
	{
		this->m_orientation = orientation;
		m_sliderX->setOrientation(orientation);
		m_sliderY->setOrientation(orientation);
		m_sliderZ->setOrientation(orientation);
	}

	void RotationInput::setValuesType(AngleType::Types type)
	{
		this->m_anglesType = type;
		m_sliderX->setValuesType(type);
		m_sliderY->setValuesType(type);
		m_sliderZ->setValuesType(type);
	}


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