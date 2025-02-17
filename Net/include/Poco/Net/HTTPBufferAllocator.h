//
// HTTPBufferAllocator.h
//
// Library: Net
// Package: HTTP
// Module:  HTTPBufferAllocator
//
// Definition of the HTTPBufferAllocator class.
//
// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#ifndef Net_HTTPBufferAllocator_INCLUDED
#define Net_HTTPBufferAllocator_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/MemoryPool.h"
#include <ios>


namespace Poco {
namespace Net {


class Net_API HTTPBufferAllocator
	/// A BufferAllocator for HTTP streams.
{
public:
	static char* allocate(std::streamsize size);
	static void deallocate(char* ptr, std::streamsize size);
	static const Poco::MemoryPool& pool();

	enum
	{
		BUFFER_SIZE = 4096
	};

private:
	static Poco::MemoryPool _pool;
};


//
// inlines
//


inline const Poco::MemoryPool& HTTPBufferAllocator::pool()
{
	return _pool;
}


} } // namespace Poco::Net


#endif // Net_HTTPBufferAllocator_INCLUDED
