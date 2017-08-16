#pragma once
#include <QSlider>
#include "GlmVisuApi.h"
#include "AngleType.h"

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
		inline AngleType::Types getValuesType() const { return this->m_angleType; }

		double radiansValue() const;
		double degreeValue() const;
		double doubleValue() const;

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
		AngleType::Types m_angleType;
		static const double s_dpi;
	};
}