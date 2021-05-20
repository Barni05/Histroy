#pragma once
#include "CodeTile.h"
template <class Type>
class ValueTile : public CodeTile
{
public:
	inline Type GetValue() const { return mValue; }
	void SetValue(Type value);
private:
	Type mValue;
};

template<class Type>
inline void ValueTile<Type>::SetValue(Type value)
{
	mValue = value;
}
