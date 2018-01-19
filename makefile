price: Embroids.o colors.o main.o Executive.o Shirts.o DuplicateEntryError.o NotFoundException.o PrecondViolatedExcep.o
	g++ -g -std=c++11 -g -Wall colors.o Embroids.o main.o Shirts.o Executive.o DuplicateEntryError.o NotFoundException.o PrecondViolatedExcep.o -o price

main.o: colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c main.cpp

Executive.o:  colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c Executive.cpp

Shirts.o: colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c Shirts.cpp

DuplicateEntryError.o:  colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c DuplicateEntryError.cpp

NotFoundException.o: colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c NotFoundException.cpp

PrecondViolatedExcep.o: colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

Embroids.o: colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c Embroids.cpp

colors.o: colors.h colors.cpp Embroids.cpp Embroids.h main.cpp Executive.cpp Executive.h Shirts.h Shirts.cpp Sorts.h Sorts.hpp BinaryNode.h BinaryNode.hpp BinarySearchTree.h BinarySearchTree.hpp BinaryTreeInterface.h DuplicateEntryError.cpp DuplicateEntryError.h NotFoundException.h NotFoundException.cpp PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -g -std=c++11 -g -Wall -c colors.cpp
	
clean:
	rm *.o price
