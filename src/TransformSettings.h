#pragma once

#include "GlmVisuApi.h"

#include <QWidget>
#include <glm\glm.hpp>

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

		glm::mat4 m_mat;
		Ui::TransformSettings *m_ui;                 ///< Qt::Ui from .ui file
	};
}