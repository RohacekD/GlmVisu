#pragma once
#include <QSlider>
#include "AngleType.h"

#if defined GLM_VISU_EXPORT
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

namespace GlmVisu {
	class TEST_COMMON_DLLSPEC AngleSlider :
		public QSlider
	{
		Q_OBJECT
		Q_PROPERTY(AngleType::Types angleType READ getValuesType WRITE setValuesType)
	public:
		explicit AngleSlider(QWidget *parent = Q_NULLPTR);
		explicit AngleSlider(Qt::Orientation orientation, QWidget *parent = Q_NULLPTR);
		~AngleSlider();

		void setValuesType(AngleType::Types val);
		inline AngleType::Types getValuesType() const { return this->_angleType; }
		double radiansValue();
		double degreeValue();
		double doubleValue();
		void setDoubleValue(double);
		void setRadiansValue(double);
		void setDegreesValue(double);
	signals:
		void angleValueChanged(double value);
		void degreeValueChanged(double value);
		void radiansValueChanged(double value);

	public slots :
		void notifyValueChanged(int value);
	private:
		void setTypeRadians();
		void setTypeDegrees();
		AngleType::Types _angleType;
		static const double dpi;
	};
	
	
}