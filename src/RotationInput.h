#pragma once
#include "GlmVisuApi.h"

#include <QGroupBox>
#include <glm\glm.hpp>
#include "AngleSlider.h"
#include "AngleType.h"
#include <QtUiPlugin/QDesignerExportWidget>

namespace GlmVisu {
	class TEST_COMMON_DLLSPEC RotationInput :
		public QGroupBox
	{
		Q_OBJECT
	public:
		RotationInput(QWidget *parent = Q_NULLPTR);
		RotationInput(Qt::Orientation orientation, QWidget *parent = Q_NULLPTR);
		~RotationInput();
		glm::vec3 getRotation() const;
		void setValue(glm::vec3);

		inline Qt::Orientation getOrientation() const;
		void setOrientation(Qt::Orientation);

		void setValuesType(AngleType::Types);

		inline AngleType::Types getValuesType() const { return this->m_anglesType; };

	signals:
		void rotationChanged(glm::vec3);
		void xAngleChanged(double);
		void yAngleChanged(double);
		void zAngleChanged(double);

	private slots:
		void changeX(double);
		void changeY(double);
		void changeZ(double);

	private:
		AngleType::Types m_anglesType;
		Qt::Orientation m_orientation;
		AngleSlider* m_sliderX;
		AngleSlider* m_sliderY;
		AngleSlider* m_sliderZ;
	};
}
