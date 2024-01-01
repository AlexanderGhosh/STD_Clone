#pragma once

namespace alx {
	// exists on the heap
	class MemoryPool
	{
		// each block will start by having a size of 1 
#define INITAL_NUM_BLOCKS 1
#define INITAL_BLOCK_SIZE 8
	private:
		using word_t = unsigned int;

		struct Block {
			bool used_;
			size_t size_;
			Block() : used_(false), size_(1) { }
			Block(size_t size) : used_(false), size_(size) { }
		};

		static Block* top_;
		static size_t numBlocks_;
		static void init();
	public:
		static Block* allocate(size_t size);
		static void  deallocate(Block* block);
		static void destroy();
	};
}