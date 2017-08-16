#pragma once
#include <QObject>
#if defined GLM_VISU_EXPORT
#define TEST_COMMON_DLLSPEC Q_DECL_EXPORT
#else
#define TEST_COMMON_DLLSPEC Q_DECL_IMPORT
#endif

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