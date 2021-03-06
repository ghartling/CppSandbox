#include "pch.h"

#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include <map>
#include <cassert>
#include <array>
#include <unordered_map>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MapUnitTest
{

//	using EntityStateMapper = std::map < string, std::tuple < const std::size_t(*)(double, std::size_t)>>;
	using EntityStateMapper = std::map < string, std::tuple <  std::size_t>>;

		// GET_POSITION


	TEST_CLASS(MapUnitTest)
	{
	public:


		TEST_METHOD(tupleTest) {
			EntityStateMapper entity_state_functions;

			entity_state_functions["test"] = std::make_tuple(mssv_GroundVehicle_set_array_spatial_position(1.0, 1));
		}

		const std::size_t   mssv_GroundVehicle_set_array_spatial_position(double x, int y) {
			return 1;
		}
		TEST_METHOD(mapTest)
		{
			char m_achDelayDesc[3][25];

			unordered_map<string, array<string, 3>> m;
			m["PPAX"] = {"Boarding not complete", "\0", "\0" };
			m["PATC"] = { "ATC/Weather", "\0", "\0" };
			m["PCLR"] = { "Push Clearance /" , "Ramp Congestion" , "\0" };

			// check if key is present
			string expected = "Boarding not complete";
			unordered_map<string, array<string, 3>>::iterator desc = m.find("PPAX");

			// should have found a match
			Assert::IsTrue(desc != m.end());
			Assert::AreEqual(desc->second.at(0).c_str(), expected.c_str());

			if (desc != m.end()) {
				Logger::WriteMessage("found\n");

				char msg[256] = { 0 };
				sprintf_s(msg, sizeof(msg), "value = %s\n", desc->second.at(0).c_str());
				Logger::WriteMessage(msg);

				// copy
				fillDesc(m_achDelayDesc, desc->second);
				Assert::AreEqual(m_achDelayDesc[0], expected.c_str());

			} else {
				Logger::WriteMessage("not found\n");
			}
		}

		void fillDesc(char dest[3][25], array<string, 3> source) {
			for (int i = 0; i < source.size(); ++i) {
				strcpy_s(dest[i], source.at(i).c_str());
			}
		}

	};
}
