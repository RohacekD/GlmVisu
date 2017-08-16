#pragma once
#include "GlmVisuApi.h"
#include "AngleType.h"
#include <QGroupBox>

class QLabel;

namespace GlmVisu {
	class AngleSlider;

	class TEST_COMMON_DLLSPEC AngleInput : public QGroupBox
	{
		Q_OBJECT
		Q_PROPERTY(AngleType::Types valuesType READ getValuesType WRITE setValuesType)
	public:
		explicit AngleInput(
			QWidget *parent = Q_NULLPTR,
			QString name = "", 
			Qt::Orientation orientation = Qt::Orientation::Horizontal
		);
		~AngleInput();

		void setValuesType(AngleType::Types val);
		AngleType::Types getValuesType() const;
		void setAngleName(QString);
		QString getAngleName() const;


		double doubleValue() const;
		void setDoubleValue(double);
		void setRadiansValue(double);
		void setDegreesValue(double);

	signals:
		void angleValueChanged(double value);
		void degreeValueChanged(double value);
		void radiansValueChanged(double value);
	public slots:
		void changeAngleValue(double);

	private:
		void init();
		QLabel* m_value;
		Qt::Orientation m_orientation;
		AngleSlider* m_slider;
	};
}