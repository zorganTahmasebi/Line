#pragma once

#include <iostream>
#include <functional>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


typedef unsigned int ui;

namespace LineString
{
	class Line
	{
	public:
		Line();
		Line(const char* line);

		void operator= (const char*);
		ui getLength();
		ui wordCount();
		ui countSpecificChar(const char);
		ui getIndex(const char);
		
		char* isDigitLine();
		char* isAlphaLine();
		char* toCapitalize();
		char* startWith(const char*, ui startPos = 0, ui endPos = -1);

		Line subLine(ui start = 0, ui end = -1);
		Line upperCase();
		Line lowerCase();
		Line toTitle();
		Line toStrip(const char symbol = ' ');
		Line fillLine(ui, const char symbol = '0');
		
		friend std::ostream& operator<<(std::ostream&, const Line&);
		friend std::istream& operator>>(std::istream&, const Line&);

	private:
		char* myStringObject = nullptr;
		ui myStringLength = 0;
		
		char toUpperChar(const char);
		char toLowerChar(const char);
		void copyString(char*, ui);
		void copyString(const char*, char*, ui);

		ui getSize(const char*);

		inline bool isUpperChar(const char);
		inline bool isLowerChar(const char);
		inline bool isAlpha(const char);
		inline bool isNumber(const char);


		char* checkCondition(bool(Line::*ptrf)(const char));

	};

};





