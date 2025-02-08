#pragma once
#include <wchar.h> 
#include <locale>
#include <vector>
#include <Windows.h>
#include "fnamepool.h"

class UObject
{
public:
	uint64_t                                           vtable;                                                     // 0x0000   (0x0008)  
	int32_t                                       ObjectFlags;                                                // 0x0008   (0x0004)  
	int                                                InternalIndex;                                              // 0x000C   (0x0004)  
	class UClass* ClassPrivate;                                               // 0x0010   (0x0008)  
	struct FName                                              NamePrivate;                                                // 0x0018   (0x0008)  
	class UObject* OuterPrivate;                                               // 0x0020   (0x0008)  


	/// Functions
	// Function /Script/CoreUObject.Object.ExecuteUbergraph
	// void ExecuteUbergraph(int32_t EntryPoint);                                                                               // [0x17b99b0] Event|Public|BlueprintEvent 
	void ProcessEvent(void* fn, void* parms);
	std::string GetName();
	std::string GetFullName();
	std::uintptr_t GetProcessEventAddr() {
		auto vtable = *reinterpret_cast<void***>(this);

		return (uintptr_t)vtable[0x44];
	}
	size_t GetSize() const {
		return sizeof(*this);
	}
};

class UField : public UObject
{
public:
	class UField* Next;                                                       // 0x0028   (0x0008)  
};

class UStruct : public UField
{
public:
	class UStruct* SuperStruct;                                                // 0x0030   (0x0008)  
	class UField* Children;                                                   // 0x0038   (0x0008)  
	unsigned char                                      UnknownData00_7[0x70];                                      // 0x0040   (0x0070)  MISSED
};

class UClass : public UStruct
{
public:
	unsigned char                                      UnknownData00_1[0x180];                                     // 0x00B0   (0x0180)  MISSED
};

class TUObjectArray {
public:
	BYTE** Objects;
	BYTE* PreAllocatedObjects;
	int32_t MaxElements;
	int32_t NumElements;
	int32_t MaxChunks;
	int32_t NumChunks;

	UObject* GetObjectPtr(uint32_t id) const;
	UObject* FindObject(const char* name) const;
	template<typename T>
	T* FindObjectForClass(const char* name) const;
	UObject* FindMaterial(const std::string& name);

	UObject* FindObjectByString(const char* name);
	std::vector<UObject*> FindObjectsByString(const char* name);
};



//
template <class T>
class TArray 
{
public:
	T* Objects;
	int count;
	int size;
};



class FVector {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;

	FVector(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}

	FVector operator*(float scalar) const {
		return FVector(x * scalar, y * scalar, z * scalar);
	}

	FVector& operator+=(const FVector& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
};

class FVector2D {
public:
	float x = 0.0f, y = 0.0f;
};

class FRotator {
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;

	float Distance2D(const FRotator vec) {
		float diffY = x - vec.x;
		float diffX = y - vec.y;
		return sqrt((diffY * diffY) + (diffX * diffX));
	}
};

class F_String : TArray<wchar_t> {
public:
	F_String() = default;
	F_String(const wchar_t* other) {
		size = count = *other ? std::wcslen(other) + 1 : 0;
		if (size) {
			Objects = const_cast<wchar_t*>(other);
		}
	}

	bool is_valid() const {
		return Objects != nullptr;
	}

	const wchar_t* c_str() const {
		return Objects;
	}

	std::string to_string() const {
		const auto length = std::wcslen(Objects);
		std::string str(length, '\0');
		std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Objects, Objects + length, '?', &str[0]);

		return str;
	}
};

class FLinearColor {
public:
	float r, g, b, a;

	FLinearColor() : r{ 0.f }, g{ 0.f }, b{ 0.f }, a{ 0.f } {}
	FLinearColor(const float r, const float g, const float b, const float a) : r { r }, g{ g }, b{ b }, a{ a } {}
};