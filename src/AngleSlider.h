#pragma once
#include <QSlider>
#include "qslider.h"

namespace GlmVisu {
	class AngleSlider :
		public QSlider
	{
		Q_OBJECT
	public:
		enum Values {
			radians,
			degrees
		};
		Q_ENUM(Values)
		explicit AngleSlider(QWidget *parent = Q_NULLPTR);
		~AngleSlider();

		void setValuesType(Values val);
		inline Values getValuesType() const { return this->valuesType; }
		double radiansValue();
		double degreeValue();
	signals:
		void angleValueChanged(double value);
		void degreeValueChanged(double value);
		void radiansValueChanged(double value);

	public slots :
		void notifyValueChanged(int value);
	private:
		void setTypeRadians();
		void setTypeDegrees();
		Values valuesType = radians;
		static const double dpi;
	};
	
	
}