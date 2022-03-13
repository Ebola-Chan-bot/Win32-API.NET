#pragma once
#include <Windows.h>
using namespace System;
namespace Win32APINET {
	public ref class WinBrand
	{
		HMODULE 库句柄;
		LPWSTR (*BrandingFormatString指针)(LPCWSTR) = nullptr;
		void 加载(const wchar_t* DLL路径);
	public:
		WinBrand()
		{
			加载(L"winbrand.dll");
		}
		WinBrand(String^ DLL路径);
		String^ BrandingFormatString(String^ 格式字符串);
	};
}
