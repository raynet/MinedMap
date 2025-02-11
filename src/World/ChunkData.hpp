// SPDX-License-Identifier: BSD-2-Clause
/*
  Copyright (c) 2015-2018, Matthias Schiffer <mschiffer@universe-factory.net>
  All rights reserved.
*/


#pragma once


#include "../Buffer.hpp"
#include "../UniqueCPtr.hpp"
#include "../Util.hpp"
#include "../NBT/CompoundTag.hpp"

#include <cstdint>


namespace MinedMap {
namespace World {

class ChunkData {
private:
	size_t len;
	UniqueCPtr<uint8_t[]> data;

	std::shared_ptr<const NBT::CompoundTag> root;

	void inflateChunk(Buffer buffer);
	void parseChunk();

public:
	ChunkData(Buffer buffer);

	const std::shared_ptr<const NBT::CompoundTag> & getRoot() const {
		return root;
	}
};

}
}
