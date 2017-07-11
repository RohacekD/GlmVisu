#ifndef MAT4VISU_H
#define MAT4VISU_H

#include <QWidget>
#include <glm\glm.hpp>
#include <string>

#if defined GLM_VISU_EXPORT
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif


namespace Ui {
	class Mat4;
}

namespace GlmVisu {
	class TEST_COMMON_DLLSPEC Mat4 : public QWidget
	{
		Q_OBJECT

	public:
		explicit Mat4(QWidget  *parent = 0);
		void setName(std::string);

	public slots:
		void updateMatrix(glm::mat4);
	signals:
		void matrixChanged();
	

	private:
		glm::mat4 mat;
		Ui::Mat4 *ui;                 ///< Qt::Ui from .ui file
	};
}

#endif // MAT4VISU_H