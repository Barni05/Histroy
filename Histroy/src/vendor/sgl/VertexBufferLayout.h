#pragma once
#include "SGL.h"
#include <iostream>
#include <vector>
struct VertexElements {
	unsigned int count;
	bool bNormalized;
	unsigned int type;
	
};
class VertexBufferLayout
{
private:
	std::vector<VertexElements> mElements;
	unsigned int mStride;
public:

	VertexBufferLayout():mStride(0){}
	~VertexBufferLayout(){}

	inline static unsigned int GetSizeByType(int type)
	{
		switch (type)
		{
		case GL_FLOAT:
			return 4;
		case GL_UNSIGNED_INT:
			return 4;
		case GL_UNSIGNED_BYTE:
			return 1;
		case GL_INT:
			return 4;
		default:
			return -1;
			break;
		}
	}
	template<typename T>
	void PushLayout(unsigned int count, bool normalized)
	{
		static_assert(false);
	}
	template<>
	void PushLayout<float>(unsigned int count, bool normalized)
	{
		mElements.push_back({ count, normalized, GL_FLOAT });
		mStride += GetSizeByType(GL_FLOAT) * count;
	}

	template<>
	void PushLayout<unsigned int>(unsigned int count, bool normalized)
	{
		mElements.push_back({ count, normalized, GL_UNSIGNED_INT });
		mStride += GetSizeByType(GL_UNSIGNED_INT) * count;
	}

	template<>
	void PushLayout<char>(unsigned int count, bool normalized)
	{
		mElements.push_back({ count, normalized, GL_UNSIGNED_BYTE });
		mStride += GetSizeByType(GL_UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexElements>& GetElements()
	{
		return mElements;
	}
	inline unsigned int GetStride()
	{
		return mStride;
	}

};

