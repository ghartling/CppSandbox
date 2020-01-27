#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>

#include <array>


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SandboxUnitTest2019
{
	TEST_CLASS(SandboxUnitTest2019)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int size = 3;
			char testStr[size] = "12";
			char nullStr[size]{};

			sprintf_s(testStr, size, "12");

			Assert::AreEqual("12", testStr);
			//OutputDebugString("test");

			memset(testStr, NULL, size);
			Assert::AreEqual(nullStr, testStr);

			int x = 0;
			if (x == 4) {
				Assert::AreEqual(x, 4);
			}
		}

		TEST_METHOD(VectorTest)
		{

			vector<int> vInt;
			size_t vSize = 10;

			for (int i = 0; i < vSize; ++i) {
				vInt.push_back(i);
			}

			Assert::AreEqual(vSize, vInt.size());
			Assert::AreEqual(9, vInt.at(9));
		}

		TEST_METHOD(VectorInitTest) {

			vector<int> vInt = { 1,2,3 };
			size_t vSize = 3;

			for (int i = 0; i < vInt.size(); ++i) {
				cout << i << endl;
				char testStr[256] = {};

				sprintf_s(testStr, sizeof(testStr), "%d\n", vInt.at(i));
				Logger::WriteMessage(testStr);
			}

			Assert::AreEqual(vSize, vInt.size());
		}

		TEST_METHOD(VectorEraseTest) {

			vector<int> vInt;
			size_t vSize = 10;

			for (int i = 0; i < vSize; ++i) {
				vInt.push_back(i);
			}

			vInt.erase(vInt.begin());

			// first element should be removed
			Assert::AreEqual(vSize-1, vInt.size());
			Assert::AreEqual(1, vInt.at(0));

			// insert at first element
			vInt.insert(vInt.begin(), 0);
			Assert::AreEqual(vSize, vInt.size());
			Assert::AreEqual(0, vInt.at(0));

			// erase last element
			vInt.erase(vInt.end()-1);

			// first element should be removed
			Assert::AreEqual(vSize - 1, vInt.size());
			Assert::AreEqual(8, vInt.at(vInt.size()-1));

		}

		TEST_METHOD(StringTest)
		{

			vector<string> currentFaults;
			const size_t codeSize = 3;
			const size_t numCodes = 3;

			for (int i = 1; i <= numCodes; ++i) {
				char code[codeSize]{ 0 };

				sprintf_s(code, codeSize, "%02d", i);
				currentFaults.push_back(code);
			}

			Assert::AreEqual(numCodes, currentFaults.size());
	//		string expected = "01";
			Assert::AreEqual("01", currentFaults.at(0).c_str());

			currentFaults.clear();
			Assert::AreEqual((size_t)0, currentFaults.size());

			int from_port = 5;
			char buf[32];
			sprintf_s(buf, "port: %d", from_port);
			Assert::AreEqual("port: 5", buf);
		}

		TEST_METHOD(CharArrayTest) {
			char test[3] = {};
			Assert::IsTrue(test);

			test[0] = '0';
			Assert::IsTrue(test[0]);
		}

		TEST_METHOD(ArrayTest) {

			std::array<string, 3> a = { "a", "b", "c" };

			char test[3] = {};
			Assert::AreEqual(3, int(a.size()));

			Assert::AreEqual("a", a.at(0).c_str());
		}

	};

	class CSACARS_IN_RANGE_DATA 
	{
		/*STOP_SNAP*/
	private:
		float m_fEonNew;
		bool m_bMessageSent;
		bool m_bMessageArrived;

		//char m_achFltNo1[5];
		//char m_achFltNo2[5];
		//char m_achFltNo3[5];
		//char m_achFltNo4[5];
		//char m_achFltNo5[5];

		static const int NUM_FLIGHTS = 5;
		char m_achFltNo[NUM_FLIGHTS][5];

		char m_achLdgRwy[9];

	public:

		CSACARS_IN_RANGE_DATA() {
		}

		~CSACARS_IN_RANGE_DATA() {}
		//	int Snap(void);

			// getters/setters
		float GetEonNew() { return m_fEonNew; }
		void SetEonNew(float eon) { m_fEonNew = eon; }

		bool IsMessageSent() { return m_bMessageSent; }
		void SetMessageSent(bool isSent) { m_bMessageSent = isSent; }

		bool IsMessageArrived() { return m_bMessageArrived; }
		void SetMessageArrived(bool isArrived) { m_bMessageArrived = isArrived; }

		vector<std::string> GetFltNos() {
			vector<std::string> vStr;
			for (int i = 0; i < NUM_FLIGHTS; ++i) {
				vStr.push_back(m_achFltNo[i]);
			}

			return vStr;
		}

		std::string GetFlightNo1() {
			return std::string(m_achFltNo[0]);
		}
		void SetFlightNo1(char flight[]) {
			strcpy_s(m_achFltNo[0], flight);
		}

		std::string GetFlightNo2() {
			return std::string(m_achFltNo[1]);
		}
		void SetFlightNo2(char flight[]) {
			strcpy_s(m_achFltNo[1], flight);
		}

		std::string GetFlightNo3() {
			return std::string(m_achFltNo[2]);
		}
		void SetFlightNo3(char flight[]) {
			strcpy_s(m_achFltNo[2], flight);
		}

		std::string GetFlightNo4() {
			return std::string(m_achFltNo[3]);
		}
		void SetFlightNo4(char flight[]) {
			strcpy_s(m_achFltNo[3], flight);
		}

		std::string GetFlightNo5() {
			return std::string(m_achFltNo[4]);
		}

		void SetFlightNo5(char flight[]) {
			strcpy_s(m_achFltNo[4], flight);
		}

		std::string GetLdgRwy() {
			return std::string(m_achLdgRwy);
		}
		void SetLdgRwy(char flight[]) {
			strcpy_s(m_achLdgRwy, flight);
		}

		std::string BuildMsg()  {
			std::string s = "";
			return s;
		}

		/* ------------------------------------------------------------------------
		   @DS --
		   Function		: CanSend(void)
		   Author		: G. Hartling
		   History		: Original October 2019
		   Description	: This function indicates if the user is allowed to send a message.
		   @DE --
		   ------------------------------------------------------------------------ */

		/*START_SNAP*/
	};

}
