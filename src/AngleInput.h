#pragma once
#include "AngleSlider.h"
#include "AngleType.h"
#include <QGroupBox>
#include <QLabel>

#if defined GLM_VISU_EXPORT
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

namespace GlmVisu {
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


		double doubleValue();
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
		QLabel* value;
		Qt::Orientation orientation;
		AngleSlider* slider;
	};
}