#pragma once
#include <format>

/*!
@brief c++20 std::format wrapper for embarcadero C++ Builder string type AnsiString and UnicodeString

MIT License

Copyright (c) 2026 Laurent NAVARRO

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

/*!
@brief AnsiString std::format support throught std::string_view
*/
template <>
struct std::formatter<AnsiString, char> : std::formatter<std::string_view, char>
{
	auto format(const AnsiString& s, std::format_context& ctx) const
	{
		std::string_view sv(s.c_str(), s.Length());
		return std::formatter<std::string_view, char>::format(sv, ctx);
	}
};
/*!
@brief AnsiString std::format support throught std::string_view in a wchar_t* context
*/
template <>
struct std::formatter<AnsiString, wchar_t>
	: std::formatter<std::wstring_view, wchar_t>
{
	auto format(const AnsiString& s, std::wformat_context& ctx) const
	{
		UnicodeString us=s; // Convert AnsiString to UnicodeString
		std::wstring_view sv(us.c_str(), us.Length());
		return std::formatter<std::wstring_view, wchar_t>::format(sv, ctx);
	}
};

/*!
@brief UnicodeString std::format support throught std::string_view
*/
template <>
struct std::formatter<UnicodeString, wchar_t>
	: std::formatter<std::wstring_view, wchar_t>
{
	auto format(const UnicodeString& s, std::wformat_context& ctx) const
	{
		std::wstring_view sv(s.c_str(), s.Length());
		return std::formatter<std::wstring_view, wchar_t>::format(sv, ctx);
	}
};
/*!
@brief UnicodeString std::format support throught std::string_view in a char* context
*/
template <>
struct std::formatter<UnicodeString, char>
	: std::formatter<std::string_view, char>
{
	auto format(const UnicodeString& s, std::format_context& ctx) const
	{
		AnsiString utf8 = s;
		std::string_view sv(utf8.c_str(), utf8.Length());
		return std::formatter<std::string_view, char>::format(sv, ctx);
	}
};

/*!
@brief  Format version returning an AnsiString
@param fmt format string
@param args parameters for the format string
*/
template <class... Args>
inline AnsiString bcbformat(std::format_string<Args...> fmt, Args&&... args) {
    std::string s=std::format(fmt, std::forward<Args>(args)...);
    return AnsiString(s.c_str(),s.size());
}

/*!
@brief Format version returning an UnicodeString
@param fmt format string
@param args parameters for the format string
*/

template <class... Args>
inline UnicodeString bcbformat(std::wformat_string<Args...> fmt, Args&&... args) {
    std::wstring s=std::format(fmt, std::forward<Args>(args)...);
    return UnicodeString(s.c_str(),s.size());
}

