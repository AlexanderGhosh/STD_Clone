#include "MemoryPool.h"
#include <cstdlib>

alx::MemoryPool::Block* alx::MemoryPool::top_ = nullptr;
size_t alx::MemoryPool::numBlocks_ = 0;

void alx::MemoryPool::destroy()
{
    free(top_);
    top_ = nullptr;
}

void alx::MemoryPool::init()
{
    top_ = (Block*) malloc((sizeof(Block) + sizeof(word_t) * INITAL_BLOCK_SIZE) * INITAL_NUM_BLOCKS);
    numBlocks_ = INITAL_NUM_BLOCKS;

    char* ptr = (char*)top_; // is a char so the the ptr increments in chars not blocks
    size_t idx = 0;
    while (idx++ < numBlocks_) {
        Block* block = (Block*)ptr;
        *block = Block(INITAL_BLOCK_SIZE);
        ptr += block->size_ * sizeof(word_t) + sizeof(Block);
    }

}

alx::MemoryPool::Block* alx::MemoryPool::allocate(size_t size)
{
    if (top_ == nullptr) {
        init();
    }
    char* ptr = (char*) top_; // is a char so the the otr increments in chars not blocks
    size_t idx = 0;
    while (idx++ < numBlocks_) {
        Block* block = (Block*)ptr;
        if (!block->used_ && block->size_ < size) {
            return block;
        }
        ptr += block->size_ * sizeof(word_t) + sizeof(Block);
    }
    return nullptr;
}

void alx::MemoryPool::deallocate(Block* block)
{
    if (block == nullptr) return;
    block->used_ = false;
}
