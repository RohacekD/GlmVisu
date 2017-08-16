#pragma once
#include <QObject>
#include <GlmVisuApi.h>

namespace GlmVisu {
	class TEST_COMMON_DLLSPEC AngleType : public QObject {
		Q_OBJECT
	public:
		enum Types {
			radians,
			degrees
		};
		Q_ENUM(Types)
	};
}