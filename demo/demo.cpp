#include <vcl.h>
#include <tchar.h>
#include <fcntl.h>
#include <bcbformat.h>



void write_wide(const std::wstring& ws) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	auto str_withCR=ws+L"\r\n";
	WriteConsoleW(h, str_withCR.c_str(), (DWORD)str_withCR.size(), nullptr, nullptr);
}

void write_ansi(const std::string& s) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	auto str_withCR=s+"\r\n";
	WriteConsoleA(h, str_withCR.c_str(), (DWORD)str_withCR.size(), nullptr, nullptr);
}


int _tmain(int argc, _TCHAR* argv[])
{
// Switch concole to UTF8
_setmode(_fileno(stdout), _O_U8TEXT);   // sortie UTF-8 (Windows CRT)
_setmode(_fileno(stderr), _O_U8TEXT);
SetConsoleOutputCP(CP_UTF8);
SetConsoleCP(CP_UTF8);
// Utility function to echo string on console
write_wide(L"Unicode output é 'こ'");
write_ansi("Ansi output");


AnsiString myAnsiString("myAnsiString");
UnicodeString myUnicodeString(L"myUnicodeString 'こ'");

// Using AnsiString with std::format
write_ansi(std::format("The AnsiString is {}.", myAnsiString) );

// Using UnicodeString with std::format on ASCII string
write_ansi(std::format("The UnicodeString is {} on ansi output.", myUnicodeString));

// Using myAnsiString with std::format on Wide string ( L prefix on format string )
write_wide(std::format(L"The AnsiString is {}.", myAnsiString));

// Using UnicodeString with std::format on Wide string ( L prefix on format string )
write_wide(std::format(L"The UnicodeString is {}.", myUnicodeString));

AnsiString as1=bcbformat("bcbformat on AnsiString {} - {} - {} ",123,myAnsiString,myUnicodeString);
write_ansi(as1.c_str());

UnicodeString us1=bcbformat(L"bcbformat on UnicodeString {} - {} - {} ",123,myAnsiString,myUnicodeString);
write_wide(us1.c_str());


getchar();

}
