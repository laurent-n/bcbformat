## What is BCB Format 

BCB Format is a small library to wrap `std::format`  with Embarcadero C++ Builder string classes `AnsiString` and `UnicodeString`.

## Features

* Allows to use `AnsiString` and `UnicodeString` as parameters of `std::format`  
* Provide `std::format` like functions returning `AnsiString` and `UnicodeString` 

## Usage

Requires C++ Builder 13.0 or greater with modern C++ compiler supporting C++20

Nothing to install, just include the header file

```c++
#include <bcbformat.h>
```

Allows to use `AnsiString` and `UnicodeString` as parameters of `std::format`  

```c++
// Using AnsiString with std::format
std::format("The AnsiString is {}.", myAnsiString) ;
// Using UnicodeString with std::format on ASCII string
std::format("The UnicodeString is {} on ansi output.", myUnicodeString);

// Using AnsiString with std::format on Wide string ( L prefix on format string )
std::format(L"The AnsiString is {}.", myAnsiString);
// Using UnicodeString with std::format on Wide string ( L prefix on format string )
std::format(L"The UnicodeString is {}.", myUnicodeString);
```

Provide `std::format` like functions returning `AnsiString` and `UnicodeString`  depending on the type of the format parameter.

```c++
AnsiString as1=bcbformat("bcbformat on AnsiString {} - {} - {} ",123,myAnsiString,myUnicodeString);

UnicodeString us1=bcbformat(L"bcbformat on UnicodeString {} - {} - {} ",123,myAnsiString,myUnicodeString);
```

Usefull when you want to use `std::format` features but returning standard C++ Builder strings instead of `std::string`. 

Usefull to assign result of format to a property.

## License

The class is licensed under the [MIT License](https://opensource.org/licenses/MIT):

Copyright &copy; 2026 Laurent NAVARRO

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Contact

If you have questions regarding the library, I would like to invite you to [open an issue at GitHub](https://github.com/laurent-n/bcbformat/issues/new/choose). Please describe your request, problem, or question as detailed as possible.