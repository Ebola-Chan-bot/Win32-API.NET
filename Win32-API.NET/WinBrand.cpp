#include "pch.h"
#include "WinBrand.h"
using namespace Win32APINET;
void WinBrand::加载(const wchar_t* DLL路径)
{
	库句柄 = LoadLibraryW(DLL路径);
}
WinBrand::WinBrand(String^ DLL路径)
{
	pin_ptr<const wchar_t> 钉住 = PtrToStringChars(DLL路径);
	加载(钉住);
}
String^ WinBrand::BrandingFormatString(String^ 格式字符串)
{
	if (!BrandingFormatString指针)
		BrandingFormatString指针 = (LPWSTR(*)(LPCWSTR))GetProcAddress(库句柄, "BrandingFormatString");
	pin_ptr<const wchar_t> 钉住 = PtrToStringChars(格式字符串);
	return Runtime::InteropServices::Marshal::PtrToStringUni(IntPtr(BrandingFormatString指针(钉住)));
}