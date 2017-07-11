#include "Mat4.h"
#include "ui_Mat4.h"
#include <string>

namespace GlmVisu {
	/**
	* @brief      Constructs the object.
	*
	* @param      parent  The parent
	*/
	Mat4::Mat4(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::Mat4)
	{
		ui->setupUi(this);
		setObjectName("mat4");
		updateMatrix(glm::mat4(1.0f));
	}


	void Mat4::updateMatrix(glm::mat4 mat) { 
		this->mat = mat;

#define setColumn(A, B) ui->val##A##x##B->setText(QString::fromStdString(std::to_string(mat[A-1][B-1]).substr(0, 6)));

		setColumn(1, 1)
		setColumn(1, 2)
		setColumn(1, 3)
		setColumn(1, 4)

		setColumn(2, 1)
		setColumn(2, 2)
		setColumn(2, 3)
		setColumn(2, 4)

		setColumn(3, 1)
		setColumn(3, 2)
		setColumn(3, 3)
		setColumn(3, 4)

		setColumn(4, 1)
		setColumn(4, 2)
		setColumn(4, 3)
		setColumn(4, 4)
	}
	void Mat4::setName(std::string name)
	{
		this->ui->matBox->setTitle(QString::fromStdString(name));
	}
}