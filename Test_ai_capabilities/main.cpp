
#include <iostream>

// Rem: windows.h defines RELATIVE and ABSOLUTE macros,
// which conflict with the Shift enum values. To avoid this conflict, we can either undefine these macros or avoid including windows.h in this file.

#include <windows.h>

//defined in wingdi.h (coordinate mode)
constexpr int WINDOWS_RELATIVE = RELATIVE;
constexpr int WINDOWS_ABSOLUTE = ABSOLUTE;

#undef RELATIVE
#undef ABSOLUTE

enum class Shift
{
	RELATIVE,
	ABSOLUTE,
//	IN,
//	OUT,
	GLOBAL
};

int main()
{
	std::cout << "Hello, World!" << std::endl;
	std::cout << WINDOWS_RELATIVE << std::endl;
	std::cout << WINDOWS_ABSOLUTE << std::endl;
	return 0;
}
