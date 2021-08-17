#include "Line.h"


namespace LineString
{
	std::ostream& operator<<(std::ostream& os, const Line& data)
	{
		os << data.myStringObject;
		return os;
	}

	std::istream& operator>>(std::istream& in, const Line& data)
	{
		in.get(data.myStringObject, 1024, '\n');
		return in;
	}
}

using namespace LineString;

Line::Line()
{

}
Line::Line(const char* lineData)
{
	ui lineDataLength = this->getSize(lineData);
	
	this->copyString(lineData, myStringObject, lineDataLength);

}

void Line::operator=(const char* myString)
{
	myStringLength = this->getSize(myString);

	if (myStringLength > 0)
	{
		myStringObject = (char*)malloc(myStringLength * sizeof(char) + 1);

		if (myStringObject != nullptr)
		{
			for (ui index = 0; index < myStringLength; index++)
			{
				myStringObject[index] = myString[index];
			}
			myStringObject[myStringLength] = '\0';
		}
		else
		{
			perror("Assign char* Please...");
			exit(1);
		}
	}
	
}

ui Line::getLength()
{
	ui lenCounter = 0;
	myStringLength = this->getSize(myStringObject);

	for (ui index = 0; index < myStringLength; index++)
	{
		lenCounter++;
	}

	return lenCounter;
}

ui Line::wordCount()
{
	ui wordCounter = 0;
	ui charCounter = 0;

	for (ui index = 0; index < myStringLength; index++)
	{
		if (myStringObject[index] == ' ' && charCounter > 0)
		{
			wordCounter++;
			charCounter = 0;
		}
		else
		{
			charCounter++;
		}
	}

	return (wordCounter + 1);
}

ui Line::countSpecificChar(const char character)
{
	ui charCounter = 0;

	for (ui index = 0; index < myStringLength; index++)
	{
		if (character == myStringObject[index])
		{
			charCounter++;
		}
	}

	return charCounter;
}

char Line::toUpperChar(const char character)
{
	if (isLowerChar(character) && isAlpha(character))
	{
		return (char)(character - 32);
	}

	return character;
}

char Line::toLowerChar(const char character)
{
	if (isUpperChar(character) && isAlpha(character))
	{
		return (char)(character + 32);
	}

	return character;
}

inline bool Line::isUpperChar(const char character)
{
	bool result = character >= 'A' && character <= 'Z' ? true : false;

	return result;
}

inline bool Line::isLowerChar(const char character)
{
	bool result = character >= 'a' && character <= 'z' ? true : false;

	return result;
}

inline bool Line::isAlpha(const char character) 
{
	bool result = character >= 'a' && character <= 'z'
		|| character >= 'A' && character <= 'Z' ? true : false;

	return result;
}

inline bool Line::isNumber(const char character)
{
	bool result = character >= '0' && character <= '9' ? true : false;

	return result;
}


Line Line::upperCase()
{
	char* newStringObject = nullptr;

	if (myStringLength > 0)
	{
		newStringObject = (char*)malloc(myStringLength);

		if (newStringObject != nullptr)
		{
			for (ui index = 0; index < myStringLength; index++)
			{
				if (isLowerChar(myStringObject[index]))
				{
					newStringObject[index] = toUpperChar(myStringObject[index]);
				}
				else
				{
					newStringObject[index] = myStringObject[index];
				}
			}

			newStringObject[myStringLength] = '\0';
		}
		
		else
		{
			perror("We Have Problem in allocate memory in upperCase Method");
			exit(1);
		}
	}
	
	return Line(newStringObject);
}

char* Line::checkCondition(bool(Line::*ptrf)(const char))
{
	bool result = true;
	Line* functionCaller = new Line();

	for (ui index = 0; index < myStringLength; index++)
	{
		if (!((functionCaller->*ptrf)(myStringObject[index])))
		{
			result = false;
			break;
		}
	}

	if (result == false)
	{
		const char* resultMessage = "False";
		return (char*)resultMessage;
	}
	else
	{
		const char* resultMessage = "True";
		return (char*)resultMessage;
	}

	delete functionCaller;
	
}

Line Line::lowerCase()
{
	char* newStringObject = nullptr;

	if (myStringLength > 0)
	{
		newStringObject = (char*)malloc(myStringLength);

		if (newStringObject != nullptr)
		{
			for (ui index = 0; index < myStringLength; index++)
			{
				if (isUpperChar(myStringObject[index]))
				{
					newStringObject[index] = toLowerChar(myStringObject[index]);
				}
				else
				{
					newStringObject[index] = myStringObject[index];
				}
			}

			newStringObject[myStringLength] = '\0';
		}
		else
		{
			perror("We Have Problem in allocate memory in upperCase Method");
			exit(1);
		}
	}

	return Line(newStringObject);
}

char* Line::isDigitLine()
{
	return this->checkCondition(&Line::isNumber); // Check there is number in Line or not 
}

char* Line::isAlphaLine()
{
	return this->checkCondition(&Line::isAlpha); // check there is alpha in Line or not
}

char* Line::toCapitalize()
{
	bool isCapitalizeString = this->isLowerChar(myStringObject[0]) && this->isAlpha(myStringObject[0]) ? true : false;

	ui destinationLength = this->getSize(this->myStringObject);
	char* capitalizeStringObject = (char*)malloc(destinationLength);

	if (isCapitalizeString && capitalizeStringObject != NULL)
	{
		this->copyString(capitalizeStringObject, destinationLength);
		capitalizeStringObject[0] = (char)(capitalizeStringObject[0] - 32);
	}
	else
	{
		this->copyString(capitalizeStringObject, destinationLength);
	}

	return capitalizeStringObject;
}

void Line::copyString(char* destination, ui destinationLength)
{
	for (ui index = 0; index < destinationLength; index++)
	{
		destination[index] = this->myStringObject[index];
	}

	destination[destinationLength] = '\0';
}

ui Line::getSize(const char* message)
{
	ui size = 0;
	for (; *message != '\0'; message++)
	{
		size++;
	}

	return size;
}

char* Line::startWith(const char* line, ui startPos, ui endPos)
{
	
	if (endPos == -1)
	{
		endPos = this->getSize(this->myStringObject);
	}
	if (endPos > this->getSize(myStringObject) || endPos < 0)
	{
		perror("Your endPosition index is notEqual with LineObject Size");
		exit(1);
	}
	if (startPos > this->getSize(myStringObject) || startPos < 0)
	{
		perror("Your startPosition index is notEqual with LineObject Size");
		exit(1);
	}
	if (this->getSize(line) == 0)
	{
		perror("your LineObject is NULL");
		exit(1);
	}

	ui lineIndex = 0;
	bool lineFlag = true;


	for (ui index = startPos; index < endPos; index++)
	{
		if (lineIndex >= this->getSize(line))
		{
			break;
		}

		if (myStringObject[index] != line[lineIndex++])
		{
			lineFlag = false;
			break;
		}
	}

	if (lineFlag)
	{
		const char* lineMessage = "True";
		return (char*)lineMessage;
	}
	else
	{
		const char* lineMessage = "False";
		return (char*)lineMessage;
	}
}

Line Line::toTitle()
{
	this->myStringLength = this->getSize(myStringObject);
	char* newLineTitleObject = (char*)malloc(this->myStringLength);
	bool spaceFlag = true;

	if (newLineTitleObject != NULL)
	{
		this->copyString(newLineTitleObject, this->myStringLength);

		for (ui index = 0; index < this->myStringLength; index++)
		{
			if (this->isAlpha(newLineTitleObject[index]) && this->isLowerChar(newLineTitleObject[index]) && spaceFlag)
			{
				newLineTitleObject[index] = this->toUpperChar(newLineTitleObject[index]);
				spaceFlag = false;
			}
			else if (newLineTitleObject[index] == ' ')
			{
				spaceFlag = true;
			}
		}

		return Line(newLineTitleObject);
	}
	else
	{
		perror("Can not Allocate Dynamic memory to char* Object");
		exit(1);
	}

}

Line Line::toStrip(const char symbol)
{
	this->myStringLength = this->getSize(this->myStringObject);

	if (this->myStringLength > 0)
	{
		char* newLineStripObject = NULL;
		newLineStripObject = (char*)malloc(this->myStringLength * sizeof(char) + 1);

		if (newLineStripObject != NULL)
		{
			ui counterStrip = 0;
			for (ui index = 0; index < this->myStringLength; index++)
			{
				if (this->myStringObject[index] == symbol)
				{
					continue;
				}
				else
				{
					newLineStripObject[counterStrip++] = this->myStringObject[index];
				}
			}
			newLineStripObject[counterStrip] = '\0';

			return Line(newLineStripObject);
		}
		else
		{
			perror("Can not allocate memory");
			exit(1);
		}
	}
	else
	{
		perror("Your Line String object is null");
		exit(1);
	}
}

Line Line::fillLine(ui width, const char symbol)
{
	this->myStringLength = this->getLength();
	char* newFillLineObject = NULL;

	if (width > this->myStringLength)
	{
		newFillLineObject = (char*)malloc(width * sizeof(char));

		if (newFillLineObject != NULL)
		{
			for (ui index = 0; index < (width - this->myStringLength); index++)
			{
				#pragma warning( push )
				#pragma warning( disable : 6386 )
					newFillLineObject[index] = symbol;
				#pragma warning( pop )

				
			}

			ui fillCounter = (width - this->myStringLength);

			for (ui index = 0; index < myStringLength; index++)
			{
				newFillLineObject[fillCounter++] = this->myStringObject[index];
			}

			newFillLineObject[fillCounter] = '\0';

			return Line(newFillLineObject);
		}
		else
		{
			perror("Can not allocate memory");
			exit(1);
		}

	}
	else
	{
		return this->myStringObject;
	}
}

void Line::copyString(const char* source, char* destination, ui length)
{
	if (length > 0)
	{
		destination = NULL;
		myStringObject = (char*)malloc(length * sizeof(char) + 1);
		if (myStringObject != NULL)
		{
			for (ui index = 0; index < length; index++)
			{
				myStringObject[index] = source[index];
			}

			myStringObject[length] = '\0';

		}
		else
		{
			perror("Can not allocate memory");
			exit(1);
		}
	}
	else
	{
		perror("Line Object is free");
		exit(1);
	}
}

ui Line::getIndex(const char character)
{
	this->myStringLength = this->getSize(this->myStringObject);
	ui myIndex = -1;

	for (ui index = 0; index < this->myStringLength; index++)
	{
		if (this->myStringObject[index] == character)
		{
			myIndex = index;
		}
	}

	if (myIndex != -1)
	{
		return myIndex;
	}
	else
	{
		perror("Index not found");
		exit(1);
	}
}

Line Line::subLine(ui start, ui end)
{
	this->myStringLength = this->getSize(this->myStringObject);
	if(end == -1)
		end = this->myStringLength;

	if (start < 0 || start > this->myStringLength || end <= 0)
	{
		perror("the start or end parameter index is not true");
		exit(1);
	}

	if (this->myStringLength > 0)
	{
		char* newSubLineObject = NULL;
		ui subLineCounter = 0;

		newSubLineObject = (char*)malloc(this->myStringLength * sizeof(char));
		if (newSubLineObject != NULL)
		{
			for (ui index = start; index < end; index++)
			{
				newSubLineObject[subLineCounter++] = this->myStringObject[index];
			}

			newSubLineObject[subLineCounter] = '\0';
			

			return Line(newSubLineObject);
		}
		else
		{
			perror("Can not allocaate dynamic memory");
			exit(1);
		}
	}
	else
	{
		perror("the size of Line Object is NULL");
		exit(1);
	}
}