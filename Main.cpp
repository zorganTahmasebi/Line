#include <iostream>

#include "Line.h"

using namespace LineString;

int main(int argc, char* argv)
{

	Line one("amin");

	std::cin >> one; 


	std::cout << one << std::endl;

	/*std::cout << one << std::endl;
	std::cout << "The size of line is " << one.getLength() << std::endl;
	std::cout << "The number of word " << one.wordCount() << std::endl;
	std::cout << "Number of l " << one.countSpecificChar('l') << std::endl;

	std::cout << one.upperCase() << std::endl;
	std::cout << one.lowerCase() << std::endl;

	std::cout << one.isDigitLine() << std::endl;
	std::cout << one.isAlphaLine() << std::endl;*/

	/*std::cout << "To Capitalize " << one.toCapitalize() << std::endl;
	std::cout << one.startWith("amin", 0, 6);*/
	/*std::cout << one << std::endl;
	std::cout << one.toStrip('*') << std::endl;
	one = one.toStrip('*');
	*/
	//std::cout << one.toTitle() << std::endl;
	//
	//std::cout << one.fillLine(10, 'b') << std::endl;
	//std::cout << one.getIndex('a');

	std::cout << one.subLine(0).toTitle() << std::endl;

	std::cin.get();
	return EXIT_SUCCESS;
}