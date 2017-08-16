#pragma once
#include <QGroupBox>
#include <glm\glm.hpp>
#include "AngleSlider.h"
#include "AngleType.h"
#include <QtUiPlugin/QDesignerExportWidget>

#if defined GLM_VISU_EXPORT
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

namespace GlmVisu {
	class TEST_COMMON_DLLSPEC RotationInput :
		public QGroupBox
	{
		Q_OBJECT
	public:
		RotationInput(QWidget *parent = Q_NULLPTR);
		RotationInput(Qt::Orientation orientation, QWidget *parent = Q_NULLPTR);
		~RotationInput();
		glm::vec3 getRotation();
		void setValue(glm::vec3);

		inline Qt::Orientation getOrientation() const;
		void setOrientation(Qt::Orientation);

		void setValuesType(AngleType::Types);

		inline AngleType::Types getValuesType() const { return this->_anglesType; };

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
		AngleType::Types _anglesType;
		Qt::Orientation orientation;
		AngleSlider* sliderX;
		AngleSlider* sliderY;
		AngleSlider* sliderZ;
	};
}
