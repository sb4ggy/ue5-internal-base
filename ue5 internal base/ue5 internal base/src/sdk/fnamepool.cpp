#include "fnamepool.h"
#include <string>

std::string FName::GetName()
{
	auto entry = NamePool->Allocator.GetById(index);
	auto name = entry->String();
	if (number > 0) {
		name += '_' + std::to_string(number);
	}
	auto pos = name.rfind('/');
	if (pos != std::string::npos) {
		name = name.substr(pos + 1);
	}
	return name;
}

std::string FNameEntry::String()
{
	if (Header.bIsWide) { return std::string(); }
	return { AnsiName, Header.Len };
}

FNamePool* NamePool = 0;
