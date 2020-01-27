#include <pch.h>

#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include <map>
#include <cassert>
#include <array>
#include <unordered_map>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

class  CSACARS_DATA {
protected:
	double	m_dSendTime;
public:
	CSACARS_DATA() {
		Logger::WriteMessage("CSACARS_DATA");
		m_dSendTime = 0.0;
	}
	~CSACARS_DATA() {}

	virtual double getSendTime() { return m_dSendTime; }
	virtual void setSendTime(double t) { m_dSendTime = t; }

	virtual void Redo() = 0;
	virtual std::string BuildMsg() = 0;

	virtual bool CanSend() {
		return (getSendTime() <= 0.0);
	}
};

// CDLK_DAL_IN_RANGE
class CSACARS_IN_RANGE_DATA : public CSACARS_DATA
{
private:
	float		fEONnew;

	/*STOP_SNAP*/
public:
	CSACARS_IN_RANGE_DATA() {
		Logger::WriteMessage("CSACARS_IN_RANGE_DATA");
	}
	~CSACARS_IN_RANGE_DATA() {}
	int Snap(void);

	float GetEonNew() { return fEONnew; }
	void SetEonNew(float eon) { fEONnew = eon; }

	void Redo() override {
		setSendTime(0.0);
	}

	std::string BuildMsg() override {
		std::string s = "";
		return s;
	}

	/*START_SNAP*/
};


namespace inheritance
{
	TEST_CLASS(InheritanceUnitTest)
	{
	public:
		
		TEST_METHOD(test1)
		{
			CSACARS_IN_RANGE_DATA data;
				Logger::WriteMessage("test1");
			
		}

	};

}
