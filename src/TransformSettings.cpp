#include "TransformSettings.h"
#include "ui_TransformSettings.h"
#include <QDebug>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>



namespace GlmVisu {
	TransformSettings::TransformSettings(QWidget  *parent) :
		QWidget(parent),
		m_ui(new Ui::TransformSettings)
	{
		m_ui->setupUi(this);
		setObjectName("mat4");
	}

	void TransformSettings::updatedValue() {
		glm::mat4 ret = glm::mat4(1.0f);
		ret = glm::translate(ret, this->getTransforamtion());

		glm::vec3 rotation = this->getRotation();
		if (rotation.x)
			ret = glm::rotate(ret, rotation.x, glm::vec3(1, 0, 0));
		if (rotation.y)
			ret = glm::rotate(ret, rotation.y, glm::vec3(0, 1, 0));
		if (rotation.z)
			ret = glm::rotate(ret, rotation.z, glm::vec3(0, 0, 1));

		ret = glm::scale(ret, this->getScale());
		emit(matrixChanged(ret));
	}
	glm::vec3 TransformSettings::getTransforamtion()
	{
		return glm::vec3(m_ui->translateX->text().toDouble(), m_ui->translateY->text().toDouble(), m_ui->translateZ->text().toDouble());
	}
	glm::vec3 TransformSettings::getRotation()
	{
		return m_ui->Rotate->getRotation();
	}
	glm::vec3 TransformSettings::getScale()
	{
		return glm::vec3(m_ui->scaleX->text().toDouble(), m_ui->scaleY->text().toDouble(), m_ui->scaleZ->text().toDouble());
	}
}
