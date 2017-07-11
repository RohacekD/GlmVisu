#pragma once
#include <QWidget>
#include <glm\glm.hpp>

#if defined GLM_VISU_EXPORT
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

namespace Ui {
	class TransformSettings;
}

namespace GlmVisu {
	class TEST_COMMON_DLLSPEC TransformSettings : public QWidget
	{
		Q_OBJECT

	public:
		explicit TransformSettings(QWidget  *parent = 0);
	public slots:
		void updatedValue();
	signals:
		void matrixChanged(glm::mat4);
	private:
		glm::vec3 getTransforamtion();
		glm::vec3 getRotation();
		glm::vec3 getScale();
		glm::mat4 mat;
		Ui::TransformSettings *ui;                 ///< Qt::Ui from .ui file
	};
}