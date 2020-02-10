#include <iostream> 
#include <string>
#include <ctime>
#include <list> 

class Block
{     
  public:
    int previous_proof_of_work;
    int current_hash;
    std::string block_data;
    int proof_of_work;
    Block(int hash);
    ~Block();
};

Block::Block(int hash)
{
  this->current_hash = hash;
  std::cout << "Block with hash " << this->current_hash << " created!" << std::endl;
}

Block::~Block()
{
}

class Blockchain
{
  private:
    std::list<Block> block_list;
  public:
    Blockchain();
    ~Blockchain();
    void create_new_block();
    void display_ledger();
};

Blockchain::Blockchain()
{
  std::cout << "Blockchain created!" << std::endl;
}

Blockchain::~Blockchain()
{
  std::cout << "Blockchain destroyed!" << std::endl;
}

void Blockchain::create_new_block()
{
  if (block_list.empty())
  {
    std::cout << "Creating the first block!" << std::endl;
    Block new_block(10); //Want some sort of hash here that is hard to find
    this->block_list.push_back(new_block);

  }
  else
  {
    std::cout << "Creating a new block" << std::endl;
    Block new_block(block_list.back().current_hash + 10); //Want some sort of hash here that is hard to find
    new_block.previous_proof_of_work = (block_list.back().current_hash / 10); //simulates previous_proof_of_work
    this->block_list.push_back(new_block);
  }
  
}

void Blockchain::display_ledger()
{
  std::list<Block>::iterator it;
  for (it = this->block_list.begin(); it != block_list.end(); it++)
  {
    std::cout << "Previous block's PoW: " << it->previous_proof_of_work << std::endl;
    std::cout << "Current block's hash: " << it->current_hash << std::endl;
  }
}

int main()
{
  std::cout << "Start of program!" << std::endl << std::endl;
  Blockchain test;
  int i;
  for (i = 0; i < 100; i++)
    test.create_new_block();
  test.display_ledger();
  std::cout << std::endl << "End of program!" << std::endl;  
}